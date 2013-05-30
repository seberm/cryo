set(CLIENT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/client")
set(CLIENT_BINARY_DIR "${PROJECT_BINARY_DIR}/client")
add_subdirectory(client)

set(SERVER_SOURCE_DIR "${PROJECT_SOURCE_DIR}/server")
set(SERVER_BINARY_DIR "${PROJECT_BINARY_DIR}/server")
add_subdirectory(server)
