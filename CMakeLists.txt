cmake_minimum_required(VERSION 3.18...3.31)

project(program LANGUAGES C)

set(OPENSSL_DIRS /opt/local/lib/release/cmake /opt/local/lib/debug/cmake )
find_package(OpenSSL 3.4 CONFIG REQUIRED NO_DEFAULT_PATH HINTS ${OPENSSL_DIRS})

include(CMakePrintHelpers)
foreach(
    V
    OpenSSL_DIR
    OPENSSL_INCLUDE_DIR
    OPENSSL_CRYPTO_LIBRARY
    OPENSSL_CRYPTO_LIBRARIES
    OPENSSL_SSL_LIBRARY
    OPENSSL_SSL_LIBRARIES
    OPENSSL_LIBRARIES
    OPENSSL_VERSION
    OPENSSL_APPLINK_SOURCE
)
    cmake_print_variables(${V})
endforeach()

cmake_print_properties(
    TARGETS OpenSSL::Crypto OpenSSL::SSL
    PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES
        IMPORTED_CONFIGURATIONS
        IMPORTED_LINK_INTERFACE_LANGUAGES
        IMPORTED_IMPLIB
        IMPORTED_LOCATION
        IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE
        IMPORTED_LOCATION_RELEASE
        IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG
        IMPORTED_LOCATION_DEBUG
        INTERFACE_LINK_LIBRARIES
)
#XXX cmake_print_properties(TARGETS OpenSSL::applink PROPERTIES INTERFACE_SOURCES)

add_executable(program program.c)
target_include_directories(program PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(program PRIVATE OpenSSL::Crypto)

enable_testing()
set(CMAKE_SKIP_TEST_ALL_DEPENDENCY NO)
add_test(NAME run-program COMMAND program)
