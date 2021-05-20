#include "gui_setup.h"
#include "exam.h"
#include "gui_elements.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

vector<JButton>
generate_template_list(Font& font, const vector<string>& dictionary)
{
    vector<JButton> selection_list;
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
                        Text(draw_russian(dictionary[i]), font, 15),
                        "select"));
    }
    return selection_list;
}

vector<JTextArea> generate_questions_list(Font& font, ifstream& in)
{
    vector<JTextArea> questions_list;
    string line;
    if (in.is_open()) {
        while (getline(in, line)) {
            Text text(draw_russian(line), font, 20);
            questions_list.push_back(JTextArea(100, 100, text));
        }
    }
    in.close();
    return questions_list;
}

vector<JScaleMettle> generate_scale_list(Font& font, vector<int> score_list)
{
    vector<JScaleMettle> scale_list;
    int scale_number = 0;
    if (score_list[EXTRAVERSION]) {
        scale_list.push_back(JScaleMettle(
                10,
                300,
                Text(draw_russian("Экстраверсия "), font, 15),
                sf::Color::Green,
                calculate_percent(score_list[EXTRAVERSION])));
        string score_percent
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
                Text(draw_russian("Привязанность "), font, 15),
                sf::Color::Magenta,
                calculate_percent(score_list[AGREEABLENESS])));
        string score_percent
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
                Text(draw_russian("Самоконтроль "), font, 15),
                sf::Color::Yellow,
                calculate_percent(score_list[CONSCIENTIOUSNESS])));
        string score_percent
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
                Text(draw_russian("Эмоциональная уст. "), font, 15),
                sf::Color::Blue,
                calculate_percent(score_list[NEUROTICISM])));
        string score_percent = get_string_with_percents(score_list[NEUROTICISM]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    if (score_list[OPENNESS]) {
        scale_list.push_back(JScaleMettle(
                630,
                300,
                Text(draw_russian("Экспрессивность "), font, 15),
                sf::Color::Red,
                calculate_percent(score_list[OPENNESS])));
        string score_percent = get_string_with_percents(score_list[OPENNESS]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    return scale_list;
}

string get_string_with_percents(int score)
{
    return to_string(calculate_percent(score));
}

int calculate_percent(int score)
{
    return (score / 0.01 / 75);
}

sf::String draw_russian(string line)
{
    return sf::String::fromUtf8(line.begin(), line.end());
}

std::vector<JTextArea> generate_question_list_on_one_scale(
        vector<JTextArea> question_list, int scale_number)
{ //Номер шкалы от 0 до 4
    vector<JTextArea> new_question_list;
    int current_question_number = scale_number;
    while (current_question_number < 75) {
        new_question_list.push_back(question_list[current_question_number]);
        current_question_number += 5;
    }
    return new_question_list;
}