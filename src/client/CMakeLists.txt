project(cryo_client)

# Jmeno binarniho souboru klienta
set(EXECUTABLE_NAME ${PROJECT_NAME})

# Cesta ke zdrojovym souborum + cesta k adresari, do ktereho se budou generovat binarni data
set(CLIENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CLIENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

# Nastaveni verze klienta
set(${PROJECT_NAME}_VERSION_MAJOR 0)
set(${PROJECT_NAME}_VERSION_MINOR 0)
set(${PROJECT_NAME}_VERSION_REVISION 1)
set(${PROJECT_NAME}_VERSION
    ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_REVISION}
)

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
    "gboard.cpp"
    "gplayer.cpp"
)

# Specifikace hlavickovych souboru
set(HDRS
    "gboard.h"
    "gplayer.h"
)

# Vytvoreni binarky programu
add_executable(${EXECUTABLE_NAME} ${SRCS} ${HDRS})

# Vyhledani knihoven SFML
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# Vyhledani knihoven OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
if (OPENGL_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})
endif()

# Instalace hlavniho binarniho souboru programu
install(TARGETS ${EXECUTABLE_NAME}
        DESTINATION ${INSTALL_BINARY_DIR}
        PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)


#if (UNIX)
#install(FILES cesta/k/souboru/foo.xyz
#DESTINATION ${INSTALL_DATA_DIR}/icons/xyz/slozka
#)
#endif(UNIX)

#if (WIN32)
#endif(UNIX)

#if (APPLE)
#endif(UNIX)
