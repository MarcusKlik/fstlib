
# define code files
set(libarrow_SRCS
    arrow/array.cc
	arrow/builder.cc
    arrow/buffer.cc
    arrow/compare.cc
    arrow/memory_pool.cc
	arrow/pretty_print.cc
	arrow/record_batch.cc
    arrow/status.cc
    arrow/table.cc
	arrow/table_builder.cc
    arrow/tensor.cc
    arrow/type.cc
    arrow/visitor.cc
	arrow/util/bit-util.cc
	arrow/util/cpu-info.cc
	arrow/util/decimal.cc
	arrow/util/hash.cc
	arrow/util/key_value_metadata.cc
	arrow/util/logging.cc
)

add_definitions(-DARROW_EXPORTING)

# define DISABLE_SIMD environmental variable to disable SIMD
if(DEFINED ENV{DISABLE_SIMD})
	message(STATUS "Arrow library build with SIMD disabled")
	add_compile_definitions(ARROW_DISABLE_SIMD)
endif()

# declare arrow library
add_library(libarrow STATIC
    ${libarrow_SRCS}
)

# exported include directories
target_include_directories(libarrow PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../boost
)
