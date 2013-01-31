# YAPIMPL_INCLUDE_DIRS

if(YAPIMPL_DIR)
    set(YAPIMPL_INSTALL_PATH ${YAPIMPL_DIR}/..)
else()
    message(FATAL_ERROR "Cannot find yapimpl installation.")
endif()

set(YAPIMPL_INCLUDE_DIRS ${YAPIMPL_INSTALL_PATH}/include)
