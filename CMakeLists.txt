cmake_minimum_required(VERSION 3.12)
project(your_queue_library C)

set(CMAKE_C_STANDARD 11)

# Source files
file(GLOB SRC_FILES src/*.c)
file(GLOB HEADER_FILES include/*.h)

# Create a library
add_library(gblc STATIC ${SRC_FILES})

# Include directories
target_include_directories(gblc PUBLIC include)

# Test executable
add_executable(gblc_queue_test tests/gblc_queue_test.c)
target_link_libraries(gblc_queue_test PRIVATE gblc m)

# Install targets
install(TARGETS gblc DESTINATION lib)
install(FILES ${HEADER_FILES} DESTINATION include)
