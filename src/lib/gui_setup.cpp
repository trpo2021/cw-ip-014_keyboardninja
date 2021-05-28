#include "gui_setup.h"
#include "exam.h"
#include "gui_elements.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::vector<JButton> generate_template_list(
        sf::Font& font, const std::vector<std::string>& dictionary)
{
    std::vector<JButton> selection_list;
    for (long unsigned int i = 0,
                           y_begin_coordinate = 200,
                           m = dictionary.size();
         i < dictionary.size();
         i++, y_begin_coordinate += 50, m--) {
        selection_list.push_back(
                JButton(300,
                        y_begin_coordinate,
                        20,
                        m,
                        sf::Text(draw_russian(dictionary[i]), font, 15),
                        "select"));
    }
    return selection_list;
}

std::vector<JTextArea>
generate_questions_list(sf::Font& font, std::ifstream& in)
{
    std::vector<JTextArea> questions_list;
    std::string line;
    if (in.is_open()) {
        while (getline(in, line)) {
            sf::Text text(draw_russian(line), font, 20);
            questions_list.push_back(JTextArea(100, 100, text));
        }
    }
    in.close();
    return questions_list;
}

std::vector<JScaleMettle>
generate_scale_list(sf::Font& font, std::vector<int> score_list)
{
    std::vector<JScaleMettle> scale_list;
    int scale_number = 0;
    if (score_list[EXTRAVERSION]) {
        scale_list.push_back(JScaleMettle(
                10,
                300,
                sf::Text(draw_russian("Экстраверсия "), font, 15),
                sf::Color::Green,
                calculate_percent(score_list[EXTRAVERSION])));
        std::string score_percent
                = get_string_with_percents(score_list[EXTRAVERSION]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    if (score_list[AGREEABLENESS]) {
        scale_list.push_back(JScaleMettle(
                150,
                300,
                sf::Text(draw_russian("Привязанность "), font, 15),
                sf::Color::Magenta,
                calculate_percent(score_list[AGREEABLENESS])));
        std::string score_percent
                = get_string_with_percents(score_list[AGREEABLENESS]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    if (score_list[CONSCIENTIOUSNESS]) {
        scale_list.push_back(JScaleMettle(
                300,
                300,
                sf::Text(draw_russian("Самоконтроль "), font, 15),
                sf::Color::Yellow,
                calculate_percent(score_list[CONSCIENTIOUSNESS])));
        std::string score_percent
                = get_string_with_percents(score_list[CONSCIENTIOUSNESS]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    if (score_list[NEUROTICISM]) {
        scale_list.push_back(JScaleMettle(
                450,
                300,
                sf::Text(draw_russian("Эмоциональная неуст. "), font, 15),
                sf::Color::Blue,
                calculate_percent(score_list[NEUROTICISM])));
        std::string score_percent
                = get_string_with_percents(score_list[NEUROTICISM]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    if (score_list[OPENNESS]) {
        scale_list.push_back(JScaleMettle(
                630,
                300,
                sf::Text(draw_russian("Экспрессивность "), font, 15),
                sf::Color::Red,
                calculate_percent(score_list[OPENNESS])));
        std::string score_percent
                = get_string_with_percents(score_list[OPENNESS]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    return scale_list;
}

std::string get_string_with_percents(int score)
{
    return std::to_string(calculate_percent(score));
}

int calculate_percent(int score)
{
    return (score / 0.01 / 75);
}

sf::String draw_russian(std::string line)
{
    return sf::String::fromUtf8(line.begin(), line.end());
}

std::vector<JTextArea> generate_question_list_on_one_scale(
        std::vector<JTextArea> question_list, int scale_number)
{ //Номер шкалы от 0 до 4
    std::vector<JTextArea> new_question_list;
    int current_question_number = scale_number;
    while (current_question_number < 75) {
        new_question_list.push_back(question_list[current_question_number]);
        current_question_number += 5;
    }
    return new_question_list;
}

JTextArea generate_diagnostic_text(sf::Font& font, std::vector<int> score_list)
{
    int max_scale_mettle = 0;
    for (auto tmp_score : score_list) {
        if (tmp_score > max_scale_mettle) {
            max_scale_mettle = tmp_score;
        }
    }
    if (max_scale_mettle == score_list[EXTRAVERSION]) {
        sf::Text text(
                draw_russian("Вы предрасположены к личностному фактору "
                             "темперамента: Экстраверсия\nТипичные экстраверты "
                             "отличаются общительностью, любят развлечения и "
                             "коллективные мероприятия"),
                font,
                15);
        return JTextArea(50, 400, text);
    }
    if (max_scale_mettle == score_list[AGREEABLENESS]) {
        sf::Text text(
                draw_russian("Вы предрасположены к личностному фактору "
                             "темперамента: Привязанность\nТакие лица "
                             "испытывают потребность быть рядом с другими "
                             "людьми. Как правило, это добрые,\nотзывчивые "
                             "люди, они хорошо понимают других людей"),
                font,
                15);
        return JTextArea(50, 400, text);
    }
    if (max_scale_mettle == score_list[CONSCIENTIOUSNESS]) {
        sf::Text text(
                draw_russian("Вы предрасположены к личностному фактору "
                             "темперамента: Самоконтроль\nТакие люди любят "
                             "порядок и комфорт, они настойчивы в деятельности "
                             "и обычно достигают\nв ней высоких результатов"),
                font,
                15);
        return JTextArea(50, 400, text);
    }
    if (max_scale_mettle == score_list[NEUROTICISM]) {
        sf::Text text(
                draw_russian(
                        "Вы предрасположены к личностному фактору "
                        "темперамента: Эмоциональная неустойчивость\nВысокие "
                        "значения по этому фактору характеризуют лиц, "
                        "неспособных контролировать\nсвои эмоции и "
                        "импульсивные влечения"),
                font,
                15);
        return JTextArea(50, 400, text);
    }
    if (max_scale_mettle == score_list[OPENNESS]) {
        sf::Text text(
                draw_russian("Вы предрасположены к личностному фактору "
                             "темперамента: Экспрессивность\nТакой человек "
                             "часто не отличает вымысел от реальностей жизни. "
                             "Он чаще доверяет своим\nчувствам и интуиции, чем "
                             "здравому смыслу"),
                font,
                15);
        return JTextArea(50, 400, text);
    }
    return JTextArea(50, 400, sf::Text("", font, 20));
    ;
}