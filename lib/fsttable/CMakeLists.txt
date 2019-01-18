
# define code files
set(libfsttable_SRCS
	fsttable.cpp
)

# declare fsttable library
add_library(libfsttable STATIC
    ${libfsttable_SRCS}
)

# add fst library as dependency
target_link_libraries(libfsttable
	libfst
)

# exported include directories
target_include_directories(libfsttable PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
