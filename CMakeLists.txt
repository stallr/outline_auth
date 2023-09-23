cmake_minimum_required(VERSION 3.0.0)
project(outline_auth VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 89)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

aux_source_directory(src CPP_LIST)

add_executable(outline_auth ${CPP_LIST})

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_include_directories(${PROJECT_NAME} PRIVATE src/3rd/hv/include/hv)
target_link_directories(${PROJECT_NAME} PRIVATE src/3rd/hv/lib)
target_link_libraries(${PROJECT_NAME} hv_static)

target_include_directories(${PROJECT_NAME} PRIVATE src/3rd/jsoncpp/json)
target_link_directories(${PROJECT_NAME} PRIVATE src/3rd/jsoncpp/lib)
target_link_libraries(${PROJECT_NAME} jsoncpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
