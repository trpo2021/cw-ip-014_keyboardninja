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

    selection_list.push_back(JButton(
            100, 150, 20, 5, Text(draw_russian("Нет"), font, 15), "select"));
    selection_list.push_back(
            JButton(100,
                    200,
                    20,
                    4,
                    Text(draw_russian("Скорее нет, чем да"), font, 15),
                    "select"));
    selection_list.push_back(
            JButton(100,
                    250,
                    20,
                    3,
                    Text(draw_russian("Не знаю"), font, 15),
                    "select"));
    selection_list.push_back(
            JButton(100,
                    300,
                    20,
                    2,
                    Text(draw_russian("Скорее да, чем нет"), font, 15),
                    "select"));
    selection_list.push_back(JButton(
            100, 350, 20, 1, Text(draw_russian("Да"), font, 15), "select"));
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
    int scale_number = 0;
    if (score_list[0] > 0) {
        scale_list.push_back(JScaleMettle(
                100, 150, Text(draw_russian("Экстраверсия   "), font, 15)));
        string score_percent = get_string_with_percents(score_list[0]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    if (score_list[1] > 0) {
        scale_list.push_back(JScaleMettle(
                100, 200, Text(draw_russian("Привязанность   "), font, 15)));
        string score_percent = get_string_with_percents(score_list[1]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    if (score_list[2] > 0) {
        scale_list.push_back(JScaleMettle(
                100, 250, Text(draw_russian("Самоконтроль   "), font, 15)));
        string score_percent = get_string_with_percents(score_list[2]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    if (score_list[3] > 0) {
        scale_list.push_back(JScaleMettle(
                100,
                300,
                Text(draw_russian("Эмоциональная устройчивость   "),
                     font,
                     15)));
        string score_percent = get_string_with_percents(score_list[3]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    if (score_list[4] > 0) {
        scale_list.push_back(JScaleMettle(
                100, 350, Text(draw_russian("Экспрессивность   "), font, 15)));
        string score_percent = get_string_with_percents(score_list[4]);
        scale_list[scale_number].text.setString(
                scale_list[scale_number].text.getString() + " " + score_percent
                + " " + "%");
        scale_number++;
    }
    return scale_list;
}

string get_string_with_percents(int score)
{
    return to_string(int(score * 75 / 100));
}

sf::String draw_russian(string line)
{
    return sf::String::fromUtf8(line.begin(), line.end());
}