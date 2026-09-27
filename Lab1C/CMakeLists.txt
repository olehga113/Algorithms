add_executable(AlternatingSum alternating_sum.c)
target_include_directories(AlternatingSum PUBLIC ../LibraryC)
target_link_libraries(AlternatingSum LibraryC)

add_executable(MostFrequentC most_frequent.c)
target_include_directories(MostFrequentC PUBLIC ../LibraryC)
target_link_libraries(MostFrequentC LibraryC)

add_test(
    NAME AlternatingSumTest1
    COMMAND AlternatingSum ${CMAKE_CURRENT_SOURCE_DIR}/sum_input_1.txt
)

set_tests_properties(
    AlternatingSumTest1
    PROPERTIES PASS_REGULAR_EXPRESSION "^20"
)

add_test(
    NAME AlternatingSumTest2
    COMMAND AlternatingSum ${CMAKE_CURRENT_SOURCE_DIR}/sum_input_2.txt
)

set_tests_properties(
    AlternatingSumTest2
    PROPERTIES PASS_REGULAR_EXPRESSION "^-3"
)

add_test(
    NAME AlternatingSumTest3
    COMMAND AlternatingSum ${CMAKE_CURRENT_SOURCE_DIR}/sum_input_3.txt
)

set_tests_properties(
    AlternatingSumTest3
    PROPERTIES PASS_REGULAR_EXPRESSION "^42"
)

add_test(
    NAME MostFrequentTest1
    COMMAND MostFrequentC ${CMAKE_CURRENT_SOURCE_DIR}/frequent_input_1.txt
)

set_tests_properties(
    MostFrequentTest1
    PROPERTIES PASS_REGULAR_EXPRESSION "^4"
)

add_test(
    NAME MostFrequentTest2
    COMMAND MostFrequentC ${CMAKE_CURRENT_SOURCE_DIR}/frequent_input_2.txt
)

set_tests_properties(
    MostFrequentTest2
    PROPERTIES PASS_REGULAR_EXPRESSION "^0"
)

add_test(
    NAME MostFrequentTest3
    COMMAND MostFrequentC ${CMAKE_CURRENT_SOURCE_DIR}/frequent_input_3.txt
)

set_tests_properties(
    MostFrequentTest3
    PROPERTIES PASS_REGULAR_EXPRESSION "^1"
)
