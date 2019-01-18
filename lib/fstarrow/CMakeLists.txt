
# define code files
set(libfstarrow_SRCS
	fstarrowtable.cpp
)

# declare fstarrow library
add_library(libfstarrow STATIC
    ${libfstarrow_SRCS}
)

# add fst and arrow library as dependencies
target_link_libraries(libfstarrow
	libfst
	libarrow
)

# exported include directories
target_include_directories(libfstarrow PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
