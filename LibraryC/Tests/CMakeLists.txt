add_executable(TestArrayC array_test.c)

target_include_directories(TestArrayC PUBLIC ..)

target_link_libraries(TestArrayC LibraryC)

add_test(NAME TestArrayC COMMAND TestArrayC)
