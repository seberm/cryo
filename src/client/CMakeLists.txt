project(cryo)
set(EXECUTABLE_NAME cryo_client)

# Set version of our project
set(cryo_client_VERSION_MAJOR 0)
set(cryo_client_VERSION_MINOR 1)

include_directories("${PROJECT_BINARY_DIR}")

set(SRCS
    "main.cpp"
)

add_executable(${EXECUTABLE_NAME} ${SRCS})

# SFML
#find_package(SFML 2 REQUIRED system window graphics network audio)
#if(SFML_FOUND)
#include_directories(${SFML_INCLUDE_DIR})
#target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
#endif()

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
if (OPENGL_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})
    # or: target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_gl_LIBRARY})
    #target_link_libraries(${EXECUTABLE_NAME} m)  # if you use maths.h
endif()

install(TARGETS ${EXECUTABLE_NAME}
        RUNTIME DESTIATION ${INSTALL_BINARY_DIR}
        PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

#include(InstallRequiredSystemLibraries)
#set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
#set(CPACK_PACKAGE_VERSION_MAJOR "${cryo_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${cryo_VERSION_MINOR}")
#include(CPack)
