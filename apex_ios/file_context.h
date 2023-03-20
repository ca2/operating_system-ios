#pragma once


namespace apex_ios
{


   class CLASS_DECL_APEX file_context :
      virtual public ::file_context
   {
   public:

      
      ::pointer < dir_system >      m_pdirsystem;
      ::pointer < file_system >     m_pfilesystem;


      file_context();
      ~file_context() override;

      virtual void initialize(::object * pobject) override;
      
      //virtual void update_module_path() override;

      virtual ::payload length(const ::file::path & path, ::payload * pvarQuery) override;
      
      virtual ::file_pointer get_file(const ::payload & payloadFile, ::file::e_open eopen) override;
      void calculate_main_resource_memory() override;

   };


} // namespace apex_ios



