#include <gui_setup.h>
extern "C" {
#include <ctest.h>
}
#include <exam.h>
#include <gui_elements.h>
#include <vector>

CTEST(gen_template_list, selection_list)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<std::string> dictionary;
    dictionary.push_back("Нет");
    dictionary.push_back("Скорее нет, чем да");
    dictionary.push_back("Не знаю");
    dictionary.push_back("Скорее да, чем нет");
    dictionary.push_back("Да");
    std::vector<JButton> selection_list
            = generate_template_list(font, dictionary);
    sf::Text a(draw_russian(dictionary[0]), font, 15);
    bool result = a.getString() == selection_list[0].button_text.getString();
    ASSERT_TRUE(result);
}

CTEST(gen_template_list, wrong_strings)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<std::string> dictionary;
    dictionary.push_back("Нет");
    dictionary.push_back("Скорее нет, чем да");
    dictionary.push_back("Не знаю");
    dictionary.push_back("Скорее да, чем нет");
    dictionary.push_back("Да");
    std::vector<JButton> selection_list
            = generate_template_list(font, dictionary);
    sf::Text a(draw_russian(dictionary[1]), font, 15);
    bool result = a.getString() == selection_list[0].button_text.getString();
    ASSERT_FALSE(result);
}

CTEST(gen_template_list, buillding_template_list)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<std::string> dictionary;
    dictionary.push_back("Нет");
    dictionary.push_back("Скорее нет, чем да");
    dictionary.push_back("Не знаю");
    dictionary.push_back("Скорее да, чем нет");
    dictionary.push_back("Да");
    std::vector<JButton> selection_list1
            = generate_template_list(font, dictionary);
    std::vector<JButton> selection_list2;
    for (long unsigned int i = 0,
                           y_begin_coordinate = 200,
                           m = dictionary.size();
         i < dictionary.size();
         i++, y_begin_coordinate += 50, m--) {
        selection_list2.push_back(
                JButton(300,
                        y_begin_coordinate,
                        20,
                        m,
                        sf::Text(draw_russian(dictionary[i]), font, 15),
                        "select"));
    }
    bool result = true;
    for (unsigned long int i = 0; i < selection_list1.size(); i++) {
        if (selection_list1[0].button_text.getString()
            != selection_list2[0].button_text.getString())
            result = false;
    }
    ASSERT_TRUE(result);
}

CTEST(gen_template_list, fail_building_template_list)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<std::string> dictionary;
    dictionary.push_back("Нет");
    dictionary.push_back("Скорее нет, чем да");
    dictionary.push_back("Не знаю");
    dictionary.push_back("Скорее да, чем нет");
    dictionary.push_back("Да");
    std::vector<JButton> selection_list1
            = generate_template_list(font, dictionary);
    std::vector<JButton> selection_list2;
    for (long unsigned int i = 0,
                           y_begin_coordinate = 200,
                           m = dictionary.size();
         i < dictionary.size();
         i++, y_begin_coordinate += 50, m--) {
        selection_list2.push_back(
                JButton(300,
                        y_begin_coordinate,
                        20,
                        m,
                        sf::Text(draw_russian(dictionary[i + 1]), font, 15),
                        "select"));
    }
    bool result = true;
    for (unsigned long int i = 0; i < selection_list1.size(); i++) {
        if (selection_list1[0].button_text.getString()
            != selection_list2[0].button_text.getString())
            result = false;
    }
    ASSERT_FALSE(result);
}

CTEST(scale_drawing_suite, generate_scales_on_extraversion)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<int> score_list(5, 0);
    score_list[EXTRAVERSION] = 54;
    std::vector<JScaleMettle> scale_list
            = generate_scale_list(font, score_list);
    unsigned long int expected = 1;
    unsigned long int result = scale_list.size();
    ASSERT_EQUAL(expected, result);
}

CTEST(scale_drawing_suite, generate_scales_on_agreeableness)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<int> score_list(5, 0);
    score_list[AGREEABLENESS] = 32;
    std::vector<JScaleMettle> scale_list
            = generate_scale_list(font, score_list);
    unsigned long int expected = 1;
    unsigned long int result = scale_list.size();
    ASSERT_EQUAL(expected, result);
}

CTEST(scale_drawing_suite, generate_scales_on_concientiousness)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<int> score_list(5, 0);
    score_list[CONSCIENTIOUSNESS] = 61;
    std::vector<JScaleMettle> scale_list
            = generate_scale_list(font, score_list);
    unsigned long int expected = 1;
    unsigned long int result = scale_list.size();
    ASSERT_EQUAL(expected, result);
}

CTEST(scale_drawing_suite, generate_scales_on_neuroticism)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<int> score_list(5, 0);
    score_list[NEUROTICISM] = 23;
    std::vector<JScaleMettle> scale_list
            = generate_scale_list(font, score_list);
    unsigned long int expected = 1;
    unsigned long int result = scale_list.size();
    ASSERT_EQUAL(expected, result);
}

CTEST(scale_drawing_suite, generate_scales_on_opennesS)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<int> score_list(5, 0);
    score_list[OPENNESS] = 44;
    std::vector<JScaleMettle> scale_list
            = generate_scale_list(font, score_list);
    unsigned long int expected = 1;
    unsigned long int result = scale_list.size();
    ASSERT_EQUAL(expected, result);
}

CTEST(scale_drawing_suite, generate_all_scales)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<int> score_list(5, 0);
    score_list[EXTRAVERSION] = 54;
    score_list[CONSCIENTIOUSNESS] = 34;
    score_list[AGREEABLENESS] = 32;
    score_list[NEUROTICISM] = 42;
    score_list[OPENNESS] = 44;
    std::vector<JScaleMettle> scale_list
            = generate_scale_list(font, score_list);
    unsigned long int expected = 5;
    unsigned long int result = scale_list.size();
    ASSERT_EQUAL(expected, result);
}

CTEST(questions_list, generate_list_with_all_questions)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::ifstream input;
    std::vector<JTextArea> real_questions_list
            = generate_questions_list(font, input);
    std::vector<JTextArea> expected_questions_list;
    std::string line;
    if (input.is_open()) {
        while (getline(input, line)) {
            sf::Text text(draw_russian(line), font, 20);
            expected_questions_list.push_back(JTextArea(100, 100, text));
        }
    }
    input.close();
    bool is_equal = true;
    for (unsigned long int i = 0; i < expected_questions_list.size(); i++) {
        if (expected_questions_list[i].text.getString()
            != real_questions_list[i].text.getString())
            is_equal = false;
    }
    ASSERT_TRUE(is_equal);
}

CTEST(questions_list, generating_questions_list_on_one_scale_agreeableness)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::ifstream input("questions.txt");
    std::vector<JTextArea> global_questions_list
            = generate_questions_list(font, input);
    std::vector<JTextArea> real_extraversion_scale_questions_list
            = generate_question_list_on_one_scale(
                    global_questions_list, AGREEABLENESS);
    std::vector<JTextArea> expected_question_list;
    int current_question_number = AGREEABLENESS;
    while (current_question_number < 75) {
        expected_question_list.push_back(
                global_questions_list[current_question_number]);
        current_question_number += 5;
    }
    bool is_equal = true;

    for (unsigned long int i = 0;
         i < real_extraversion_scale_questions_list.size();
         i++) {
        if (real_extraversion_scale_questions_list[i].text.getString()
            != expected_question_list[i].text.getString())
            is_equal = false;
    }

    ASSERT_TRUE(is_equal);
}

CTEST(questions_list, generating_questions_list_on_one_scale_conscientiousness)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::ifstream input("questions.txt");
    std::vector<JTextArea> global_questions_list
            = generate_questions_list(font, input);
    std::vector<JTextArea> real_extraversion_scale_questions_list
            = generate_question_list_on_one_scale(
                    global_questions_list, CONSCIENTIOUSNESS);
    std::vector<JTextArea> expected_question_list;
    int current_question_number = CONSCIENTIOUSNESS;
    while (current_question_number < 75) {
        expected_question_list.push_back(
                global_questions_list[current_question_number]);
        current_question_number += 5;
    }
    bool is_equal = true;

    for (unsigned long int i = 0;
         i < real_extraversion_scale_questions_list.size();
         i++) {
        if (real_extraversion_scale_questions_list[i].text.getString()
            != expected_question_list[i].text.getString())
            is_equal = false;
    }

    ASSERT_TRUE(is_equal);
}

CTEST(questions_list, generating_questions_list_on_one_scale_neuroticism)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::ifstream input("questions.txt");
    std::vector<JTextArea> global_questions_list
            = generate_questions_list(font, input);
    std::vector<JTextArea> real_extraversion_scale_questions_list
            = generate_question_list_on_one_scale(
                    global_questions_list, NEUROTICISM);
    std::vector<JTextArea> expected_question_list;
    int current_question_number = NEUROTICISM;
    while (current_question_number < 75) {
        expected_question_list.push_back(
                global_questions_list[current_question_number]);
        current_question_number += 5;
    }
    bool is_equal = true;

    for (unsigned long int i = 0;
         i < real_extraversion_scale_questions_list.size();
         i++) {
        if (real_extraversion_scale_questions_list[i].text.getString()
            != expected_question_list[i].text.getString())
            is_equal = false;
    }

    ASSERT_TRUE(is_equal);
}

CTEST(questions_list, generating_questions_list_on_one_scale_openness)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::ifstream input("questions.txt");
    std::vector<JTextArea> global_questions_list
            = generate_questions_list(font, input);
    std::vector<JTextArea> real_extraversion_scale_questions_list
            = generate_question_list_on_one_scale(
                    global_questions_list, OPENNESS);
    std::vector<JTextArea> expected_question_list;
    int current_question_number = OPENNESS;
    while (current_question_number < 75) {
        expected_question_list.push_back(
                global_questions_list[current_question_number]);
        current_question_number += 5;
    }
    bool is_equal = true;

    for (unsigned long int i = 0;
         i < real_extraversion_scale_questions_list.size();
         i++) {
        if (real_extraversion_scale_questions_list[i].text.getString()
            != expected_question_list[i].text.getString())
            is_equal = false;
    }

    ASSERT_TRUE(is_equal);
}

CTEST(questions_list, generating_questions_list_on_one_scale_agreableness)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::ifstream input("questions.txt");
    std::vector<JTextArea> global_questions_list
            = generate_questions_list(font, input);
    std::vector<JTextArea> real_extraversion_scale_questions_list
            = generate_question_list_on_one_scale(
                    global_questions_list, AGREEABLENESS);
    std::vector<JTextArea> expected_question_list;
    int current_question_number = AGREEABLENESS;
    while (current_question_number < 75) {
        expected_question_list.push_back(
                global_questions_list[current_question_number]);
        current_question_number += 5;
    }
    bool is_equal = true;

    for (unsigned long int i = 0;
         i < real_extraversion_scale_questions_list.size();
         i++) {
        if (real_extraversion_scale_questions_list[i].text.getString()
            != expected_question_list[i].text.getString())
            is_equal = false;
    }

    ASSERT_TRUE(is_equal);
}
