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

CTEST(draw_string, diagnostic_text_test1)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<int> score_list(5, 0);

    score_list[0] = 73;
    score_list[1] = 54;
    score_list[2] = 45;
    score_list[3] = 22;
    score_list[4] = 65;
    JTextArea real_diagnostic_text = generate_diagnostic_text(font, score_list);

    sf::Text diagnostic_text(
            draw_russian("Вы предрасположены к личностному фактору "
                         "темперамента: Экстраверсия\nТипичные экстраверты "
                         "отличаются общительностью, любят развлечения и "
                         "коллективные мероприятия"),
            font,
            15);
    JTextArea expected_diagnostic_text(100, 100, diagnostic_text);
    bool is_equal = expected_diagnostic_text.text.getString()
            == real_diagnostic_text.text.getString();
    ASSERT_TRUE(is_equal);
}

CTEST(draw_string, diagnostic_text_test2)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<int> score_list(5, 0);

    score_list[0] = 34;
    score_list[1] = 72;
    score_list[2] = 45;
    score_list[3] = 22;
    score_list[4] = 65;
    JTextArea real_diagnostic_text = generate_diagnostic_text(font, score_list);

    sf::Text diagnostic_text(
            draw_russian("Вы предрасположены к личностному фактору "
                         "темперамента: Привязанность\nТакие лица "
                         "испытывают потребность быть рядом с другими "
                         "людьми. Как правило, это добрые,\nотзывчивые "
                         "люди, они хорошо понимают других людей"),
            font,
            15);
    JTextArea expected_diagnostic_text(100, 100, diagnostic_text);
    bool is_equal = expected_diagnostic_text.text.getString()
            == real_diagnostic_text.text.getString();
    ASSERT_TRUE(is_equal);
}

CTEST(draw_string, diagnostic_text_test3)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<int> score_list(5, 0);

    score_list[0] = 34;
    score_list[1] = 32;
    score_list[2] = 68;
    score_list[3] = 22;
    score_list[4] = 65;
    JTextArea real_diagnostic_text = generate_diagnostic_text(font, score_list);

    sf::Text diagnostic_text(
            draw_russian("Вы предрасположены к личностному фактору "
                         "темперамента: Самоконтроль\nТакие люди любят "
                         "порядок и комфорт, они настойчивы в деятельности "
                         "и обычно достигают\nв ней высоких результатов"),
            font,
            15);
    JTextArea expected_diagnostic_text(100, 100, diagnostic_text);
    bool is_equal = expected_diagnostic_text.text.getString()
            == real_diagnostic_text.text.getString();
    ASSERT_TRUE(is_equal);
}

CTEST(draw_string, diagnostic_text_test4)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<int> score_list(5, 0);

    score_list[0] = 34;
    score_list[1] = 32;
    score_list[2] = 44;
    score_list[3] = 71;
    score_list[4] = 65;
    JTextArea real_diagnostic_text = generate_diagnostic_text(font, score_list);

    sf::Text diagnostic_text(
            draw_russian("Вы предрасположены к личностному фактору "
                         "темперамента: Эмоциональная неустойчивость\nВысокие "
                         "значения по этому фактору характеризуют лиц, "
                         "неспособных контролировать\nсвои эмоции и "
                         "импульсивные влечения"),
            font,
            15);
    JTextArea expected_diagnostic_text(100, 100, diagnostic_text);
    bool is_equal = expected_diagnostic_text.text.getString()
            == real_diagnostic_text.text.getString();
    ASSERT_TRUE(is_equal);
}

CTEST(draw_string, diagnostic_text_test5)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<int> score_list(5, 0);

    score_list[0] = 34;
    score_list[1] = 32;
    score_list[2] = 44;
    score_list[3] = 58;
    score_list[4] = 65;
    JTextArea real_diagnostic_text = generate_diagnostic_text(font, score_list);

    sf::Text diagnostic_text(
            draw_russian("Вы предрасположены к личностному фактору "
                         "темперамента: Экспрессивность\nТакой человек "
                         "часто не отличает вымысел от реальностей жизни. "
                         "Он чаще доверяет своим\nчувствам и интуиции, чем "
                         "здравому смыслу"),
            font,
            15);
    JTextArea expected_diagnostic_text(100, 100, diagnostic_text);
    bool is_equal = expected_diagnostic_text.text.getString()
            == real_diagnostic_text.text.getString();
    ASSERT_TRUE(is_equal);
}