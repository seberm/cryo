project(cryo)

# Jmeno binarniho souboru klienta
set(EXECUTABLE_NAME cryo_client)

# Nastaveni verze klienta
set(cryo_client_VERSION_MAJOR 0)
set(cryo_client_VERSION_MINOR 0)
set(cryo_client_VERSION_PATCH 1)
set(cryo_client_VERSION
    ${cryo_client_VERSION_MAJOR}.${cryo_client_VERSION_MINOR}.${cryo_client_VERSION_PATCH})

# Konfiguracni soubor pro klienta
configure_file(
    "${CLIENT_SOURCE_DIR}/config.h.in"
    "${CLIENT_BINARY_DIR}/config.h"
)

# Adresar s vygenerovanym konf. souborem musime pridat do cesty s hlavickovymi soubory
include_directories("${CLIENT_BINARY_DIR}")

# Specifikace zdrojovych kodu
set(SRCS
    "main.cpp"
)

# Vytvoreni binarky programu
add_executable(${EXECUTABLE_NAME} ${SRCS})

# SFML
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
if (OPENGL_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})
    # or: target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_gl_LIBRARY})
    #target_link_libraries(${EXECUTABLE_NAME} m)  # if you use maths.h
endif()

install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${CLIENT_BINARY_DIR})
#install(TARGETS ${EXECUTABLE_NAME}
#        RUNTIME DESTINATION ${CLIENT_BINARY_DIR}
#        PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
#)
