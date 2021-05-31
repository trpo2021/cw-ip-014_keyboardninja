#include <gui_setup.h>
extern "C" {
#include <ctest.h>
}

CTEST(draw_string, draw_russian1)
{
    std::string russian_string = "Следующий вопрос";

    sf::String real_string = draw_russian(russian_string);
    sf::String expected_string = sf::String::fromUtf8(
            russian_string.begin(), russian_string.end());
    bool is_equal = real_string == expected_string;

    ASSERT_TRUE(is_equal);
}

CTEST(draw_string, draw_russian2)
{
    std::string russian_string = "Предыдущий вопрос";

    sf::String real_string = draw_russian(russian_string);
    sf::String expected_string = sf::String::fromUtf8(
            russian_string.begin(), russian_string.end());
    bool is_equal = real_string == expected_string;

    ASSERT_TRUE(is_equal);
}

CTEST(draw_string, draw_russian3)
{
    std::string russian_string = "Да";

    sf::String real_string = draw_russian(russian_string);
    sf::String expected_string = sf::String::fromUtf8(
            russian_string.begin(), russian_string.end());
    bool is_equal = real_string == expected_string;

    ASSERT_TRUE(is_equal);
}

CTEST(draw_string, draw_string_with_percent)
{
    int score = 75;
    std::string real_string = get_string_with_percents(score);
    std::string expected_string = "100";
    ASSERT_STR(real_string.c_str(), expected_string.c_str());
}

CTEST(draw_string, draw_string_with_percent2)
{
    int score = 55;
    std::string real_string = get_string_with_percents(score);
    std::string expected_string = "73";
    ASSERT_STR(real_string.c_str(), expected_string.c_str());
}

CTEST(draw_string, draw_string_with_percent3)
{
    int score = 25;
    std::string real_string = get_string_with_percents(score);
    std::string expected_string = "33";
    ASSERT_STR(real_string.c_str(), expected_string.c_str());
}