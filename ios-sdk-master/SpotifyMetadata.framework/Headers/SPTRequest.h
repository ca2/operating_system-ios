/*
 Copyright 2015 Spotify AB

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>
#import "SPTPartialObject.h"

/** Callback for requests
 
 @param error An optional error indicating that the operation failed, or `nil` if it succeeded.
 @param object The result of the operation
 */
typedef void (^SPTRequestCallback)(NSError *error, id object);

/** Callback for `SPTRequestHandlerProtocol` 
 
 @param error An optional error indicating that the request failed, or `nil` if it succeeded.
 @param response The `NSURLResponse` for the request
 @param data An `NSData` containing the result of the request
 */
typedef void (^SPTRequestDataCallback)(NSError *error, NSURLResponse *response, NSData *data);

/// Defines types of result objects that can be searched for.
typedef NS_ENUM(NSUInteger, SPTSearchQueryType) {
	/// Specifies that all search results will be of type `SPTTrack`.
	SPTQueryTypeTrack = 0,
	/// Specifies that all search results will be of type `SPTArtist`.
	SPTQueryTypeArtist,
	/// Specifies that all search results will be of type `SPTAlbum`.
	SPTQueryTypeAlbum,
	/// Specifies that all search results will be of type `SPTPartialPlaylist`.
	SPTQueryTypePlaylist,
};

FOUNDATION_EXPORT NSString * const SPTMarketFromToken;

/** Protocol for request handlers
 */
@protocol SPTRequestHandlerProtocol

/**
 Make a request
 
 @param request The NSURLRequest object for the request.
 @param block The callback to call when data has been received.
 */
-(void)performRequest:(NSURLRequest *)request callback:(SPTRequestDataCallback)block;

@end



/** This class provides convenience methods for talking to the Spotify Web API and wraps a customizable handler for requests which are used by those convenience methods.
 
 All the functions for direct access to the api inside this class has been deprecated and moved out to their respective classes, for getting track metadata, look at `SPTTrack`, for getting featured playlists in browse, look at `SPTBrowse` and so on.

 All model classes provide both convenience methods for getting content in the callback fashion, but also provides methods named `createRequestFor...` for creating `NSURLRequests` for calling the api directly with the request handler of choice, this allows you to do caching, cancellation and scheduling of calls in your own way. The model classes also provides methods for parsing a API Response back into a usable object, those are called `...fromData:withResponse:error`, pluralized methods for getting multiple entities at once are also available when appropriate.

 
 Example of using the API request creation / API response parser paradigm:
 
 ```
	// Getting the first two pages of a playlists for a user
 	NSURLRequest *playlistrequest = [SPTPlaylistList createRequestForGettingPlaylistsForUser:@"possan" withAccessToken:accessToken error:nil];
	[[SPTRequest sharedHandler] performRequest:playlistrequest callback:^(NSError *error, NSURLResponse *response, NSData *data) {
		if (error != nil) { Handle error }
		SPTPlaylistList *playlists = [SPTPlaylistList playlistListFromData:data withResponse:response error:nil];
		NSLog(@"Got possan's playlists, first page: %@", playlists);
		NSURLRequest *playlistrequest2 = [playlists createRequestForNextPageWithAccessToken:accessToken error:nil];
		[[SPTRequest sharedHandler] performRequest:playlistrequest2 callback:^(NSError *error2, NSURLResponse *response2, NSData *data2) {
			if (error2 != nil) { Handle error }
			SPTPlaylistList *playlists2 = [SPTPlaylistList playlistListFromData:data2 withResponse:response2 error:nil];
			NSLog(@"Got possan's playlists, second page: %@", playlists2);
		}];
	}];
 ```

 Example without response body:

 ```
 	// Following a user
	NSURLRequest *req = [SPTFollow createRequestForFollowingUsers:@[@"possan"]] withAccessToken:accessToken error:nil];
	[[SPTRequest sharedHandler] performRequest:req callback:^(NSError *error, NSURLResponse *response, NSData *data) {
		long statusCode = ((NSHTTPURLResponse*)response).statusCode;
		switch (statusCode) {
			case 204:
				NSLog(@"Successfully followed user.");
				break;
			case 401:
			case 403:
				NSLog(@"Failed to follow user, are you sure your token is valid and have the correct scopes?");
				break;
			default:
				NSLog(@"Bork bork!");
				break;
		}
	}];
 ``` 

 Example of using convenience methods:

 ```
	// Getting multiple artists
	[SPTArtist artistsWithURIs:@[
			[NSURL URLWithString:@"spotify:artist:30Y7JOpiNgAGEhnkYPdI1P"],
			[NSURL URLWithString:@"spotify:artist:0jO0TlgxW9Il5JphAWzhR4"],
			[NSURL URLWithString:@"spotify:artist:0AKlaf8M1k8NjJp1uCOlTA"]
		]
		accessToken:accessToken callback:^(NSError *error, id object) {
			NSLog(@"Got artists: %@", object);
		}];
 ```

 API Console: https://developer.spotify.com/web-api/console

 */
@interface SPTRequest : NSObject





///----------------------
/// @name Request handler
///----------------------

/**
 Get a request handler
 */
+ (id<SPTRequestHandlerProtocol>)sharedHandler;

/**
 Override the default request handler, this is where you'd implement your own if you want to, or use AFNetworking or similar
 
 @param handler New handler for requests
 */
+ (void)setSharedHandler:(id<SPTRequestHandlerProtocol>)handler;

///-------------------------------
/// @name Request creation helpers
///-------------------------------

/** Helper function for creates an authenticated `NSURLRequest` for a Spotify API resource.
 
 @param url The HTTPS URL to request, this is a Spotify API URL, not a spotify URI.
 @param accessToken A valid access token.
 @param httpMethod The HTTP method to use eg. `GET` `POST` etc.
 @param values The arguments to send to the URL
 @param encodeAsJSON Encode arguments as an JSON object in the body of the request instead of QueryString encoding them.
 @param dataAsQueryString Send arguments as a part of the query string instead of in the body of the request.
 @param error An optional `NSError` that will receive an error if request creation failed.
 @return A `NSURLRequest`
 */

+ (NSURLRequest *)createRequestForURL:(NSURL *)url
					  withAccessToken:(NSString *)accessToken
						   httpMethod:(NSString *)httpMethod
							   values:(id)values
					  valueBodyIsJSON:(BOOL)encodeAsJSON
				sendDataAsQueryString:(BOOL)dataAsQueryString
								error:(NSError **)error;


@end
