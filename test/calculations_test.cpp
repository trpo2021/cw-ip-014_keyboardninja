#include <gui_setup.h>
extern "C" {
#include <ctest.h>
}

CTEST(calculate_result, percent_value1)
{
    int score = 75;
    int result = calculate_percent(score);
    int expected = 100;
    ASSERT_EQUAL(expected, result);
}

CTEST(calculate_result, percent_value2)
{
    int score = 55;
    int result = calculate_percent(score);
    int expected = 73;
    ASSERT_EQUAL(expected, result);
}

CTEST(calculate_result, percent_value3)
{
    int score = 25;
    int result = calculate_percent(score);
    int expected = 33;
    ASSERT_EQUAL(expected, result);
}
