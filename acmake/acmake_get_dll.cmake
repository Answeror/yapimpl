function(acmake_get_dll DLLS DLLS_DEBUG DLLS_RELEASE)
    set(ACC)
    set(ACC_DEBUG)
    set(ACC_RELEASE)
    set(SUFFIX "")
    foreach(LIB ${ARGN})
        if(LIB MATCHES ^debug$)
            set(SUFFIX "_DEBUG")
        elseif(LIB MATCHES ^optimized$)
            set(SUFFIX "_RELEASE")
        else()
            string(REPLACE ".lib" ".dll" DLL ${LIB})
            if(NOT EXISTS ${DLL})
                get_filename_component(LIB_FOLDER ${LIB} PATH)
                get_filename_component(ROOT_FOLDER ${LIB_FOLDER} PATH)
                get_filename_component(DLL_NAME ${DLL} NAME)
                set(DLL ${ROOT_FOLDER}/bin/${DLL_NAME})
            endif()
            if(NOT EXISTS ${DLL})
                get_filename_component(LIB_FOLDER ${LIB} PATH)
                get_filename_component(CONF_FOLDER ${LIB_FOLDER} PATH)
                get_filename_component(CONF_NAME ${LIB_FOLDER} NAME)
                get_filename_component(ROOT_FOLDER ${CONF_FOLDER} PATH)
                get_filename_component(DLL_NAME ${DLL} NAME)
                set(DLL ${ROOT_FOLDER}/bin/${CONF_NAME}/${DLL_NAME})
            endif()
            if(EXISTS ${DLL})
                list(APPEND ACC${SUFFIX} ${DLL})
            endif()
            set(SUFFIX "")
        endif()
    endforeach()
    foreach(SUFFIX "" _DEBUG _RELEASE)
        set(${DLLS${SUFFIX}} ${ACC${SUFFIX}} PARENT_SCOPE)
    endforeach()
endfunction()
