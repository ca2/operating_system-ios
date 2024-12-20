#pragma once


namespace multimedia
{


   namespace audio_mixer_audio_core
   {


      class CLASS_DECL_AUDIO_MIXER_MMSYSTEM control :
         virtual public ::audio_mixer::control
      {
      public:


         enum Styles
         {
            StyleV001 = 1
         };


         MIXERCONTROL                     m_mixercontrol;
         MIXERCONTROLDETAILS              m_mixercontroldetails;


         control(sp(::base::application) papp);
         control(control & control);
         virtual ~control();

         using ::audio_mixer::user::control_ptr_array::add;
         virtual int_ptr add(::audio_mixer::user::control * pcontrol);

         bool control_type(::audio_mixer::e_control econtrol) const;
         bool OnCommand(WPARAM wParam, LPARAM lParam);
         ::audio_mixer::control_data * GetWindowDataByDlgCtrlID(uint32_t nID);
         ::audio_mixer::user::control * GetControlByDlgCtrlID(uint32_t nID);
         //   bool OnNotify(uint32_t nID, LPNMHDR lpnmhdr);
         void OnVHScroll(uint32_t nSBCode, uint32_t nPos, sp(::user::interaction) pScrollBar);
         ::audio_mixer::control_data * GetWindowData(int32_t iType);
         void OnMixerControlChange();
         ::audio_mixer::user::control * GetControl(int32_t iType);
         ::audio_mixer::user::control * GetControlByIndex(::collection::index iIndex);
         void Prepare();
         bool CreateWindowsVolumeV001(sp(::user::interaction) pParent, uint32_t nStartID, uint32_t * nNextID);

         //  bool _001CreateMuteControl(sp(::user::interaction) pParent, CRuntimeClass * pruntimeclassMuteControl, uint32_t nStartID, uint32_t * nNextID);
         bool _001CreateMuteControl(sp(::user::interaction) pParent, uint32_t nStartID, uint32_t * nNextID);

         bool CreateWindows(sp(::user::interaction) pParent, int32_t iStyle);

         control & operator =(const control & control);


         MIXERCONTROL & GetMixerControl();
         MIXERCONTROLDETAILS & GetMixerControlDetails();


      };


   } // namespace audio_mixer_audio_core


} // namespace multimedia




