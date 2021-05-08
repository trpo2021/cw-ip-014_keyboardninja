#include "gui_setup.h"
#include "gui_elements.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

vector<JButton> generate_selection_list(Font& font)
{
    vector<JButton> selection_list;
    string button_text_no = "Нет";
    string button_text_maybe_no = "Скорее нет, чем да";
    string button_text_dont_know = "Не знаю";
    string button_text_maybe_yes = "Скорее да, чем нет";
    string button_text_yes = "Да";

    selection_list.push_back(
            JButton(100,
                    150,
                    20,
                    5,
                    Text(sf::String::fromUtf8(
                                 button_text_no.begin(), button_text_no.end()),
                         font,
                         15),
                    "select"));
    selection_list.push_back(
            JButton(100,
                    200,
                    20,
                    4,
                    Text(sf::String::fromUtf8(
                                 button_text_maybe_no.begin(),
                                 button_text_maybe_no.end()),
                         font,
                         15),
                    "select"));
    selection_list.push_back(
            JButton(100,
                    250,
                    20,
                    3,
                    Text(sf::String::fromUtf8(
                                 button_text_dont_know.begin(),
                                 button_text_dont_know.end()),
                         font,
                         15),
                    "select"));
    selection_list.push_back(
            JButton(100,
                    300,
                    20,
                    2,
                    Text(sf::String::fromUtf8(
                                 button_text_maybe_yes.begin(),
                                 button_text_maybe_yes.end()),
                         font,
                         15),
                    "select"));
    selection_list.push_back(JButton(
            100,
            350,
            20,
            1,
            Text(sf::String::fromUtf8(
                         button_text_yes.begin(), button_text_yes.end()),
                 font,
                 15),
            "select"));
    return selection_list;
}

vector<JTextArea> generate_questions_list(Font& font, ifstream& in)
{
    vector<JTextArea> questions_list;
    string line;
    if (in.is_open()) {
        while (getline(in, line)) {
            Text text(sf::String::fromUtf8(line.begin(), line.end()), font, 20);
            questions_list.push_back(JTextArea(100, 100, text));
        }
    }
    in.close();
    return questions_list;
}

vector<JScaleMettle> generate_scale_list(Font& font, vector<int> score_list)
{
    vector<JScaleMettle> scale_list;
    string text_extroversion_ru = "Экстраверсия   ";
    string text_agreeableness_ru = "Привязанность   ";
    string text_conscientiousness_ru = "Самоконтроль   ";
    string text_neuroticism_ru = "Эмоциональная устройчивость   ";
    string text_openness_ru = "Экспрессивность   ";
    int scale_number = 0;
    if (score_list[0] > 0) {
        scale_list.push_back(JScaleMettle(
                100,
                150,
                Text(sf::String::fromUtf8(
                             text_extroversion_ru.begin(),
                             text_extroversion_ru.end()),
                     font,
                     15)));
        int score_percent = int(score_list[0] * 75 / 100);

        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " "
                + to_string(score_percent) + " " + "%");
        scale_number++;
    }
    if (score_list[1] > 0) {
        scale_list.push_back(JScaleMettle(
                100,
                200,
                Text(sf::String::fromUtf8(
                             text_agreeableness_ru.begin(),
                             text_agreeableness_ru.end()),
                     font,
                     15)));
        int score_percent = int(score_list[1] * 75 / 100);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " "
                + to_string(score_percent) + " " + "%");
        scale_number++;
    }
    if (score_list[2] > 0) {
        scale_list.push_back(JScaleMettle(
                100,
                250,
                Text(sf::String::fromUtf8(
                             text_conscientiousness_ru.begin(),
                             text_conscientiousness_ru.end()),
                     font,
                     15)));
        int score_percent = int(score_list[2] * 75 / 100);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " "
                + to_string(score_percent) + " " + "%");
        scale_number++;
    }
    if (score_list[3] > 0) {
        scale_list.push_back(JScaleMettle(
                100,
                300,
                Text(sf::String::fromUtf8(
                             text_neuroticism_ru.begin(),
                             text_neuroticism_ru.end()),
                     font,
                     15)));
        int score_percent = int(score_list[3] * 75 / 100);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " "
                + to_string(score_percent) + " " + "%");
        scale_number++;
    }
    if (score_list[4] > 0) {
        scale_list.push_back(JScaleMettle(
                100,
                350,
                Text(sf::String::fromUtf8(
                             text_openness_ru.begin(), text_openness_ru.end()),
                     font,
                     15)));
        int score_percent = int(score_list[4] * 75 / 100);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " "
                + to_string(score_percent) + " " + "%");
        scale_number++;
    }
    return scale_list;
}
