#ifndef GUI_SETUP_H_
#define GUI_SETUP_H_

#include "gui_elements.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

sf::String
draw_russian(std::string line); //Используйте её для отрисовки русского текста

std::vector<JButton>
generate_template_list(sf::Font& font, const std::vector<std::string>& dictionary);

std::vector<JTextArea>
generate_questions_list(sf::Font& font, std::ifstream& in);

std::vector<JTextArea> generate_question_list_on_one_scale(
        std::vector<JTextArea> question_list, int scale_number);

std::vector<JScaleMettle>
generate_scale_list(sf::Font& font, std::vector<int> score_list);

std::string get_string_with_percents(int score);

int calculate_percent(int score);

#endif