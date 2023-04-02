set(LIB_TARGET weave)

# Sources & Includes
get_filename_component(LIB_INCLUDE_PATH ".." ABSOLUTE)
get_filename_component(LIB_PATH "." ABSOLUTE)

message(STATUS ${LIB_INCLUDE_PATH})

file(GLOB_RECURSE LIB_CXX_SOURCES ${LIB_PATH}/*.cpp)
file(GLOB_RECURSE LIB_HEADERS ${LIB_PATH}/*.hpp)

add_library(${LIB_TARGET} STATIC ${LIB_CXX_SOURCES} ${LIB_HEADERS})
target_include_directories(${LIB_TARGET} PUBLIC ${LIB_INCLUDE_PATH})

# --------------------------------------------------------------------

# Dependencies
if(UNIX)
  set(LIB_DEPENDENCIES pthread)
endif()

message(STATUS "Dependencies: ${LIB_DEPENDENCIES}")

target_link_libraries(${LIB_TARGET} PUBLIC ${LIB_DEPENDENCIES})

# If header only
set_target_properties(${LIB_TARGET} PROPERTIES LINKER_LANGUAGE CXX)