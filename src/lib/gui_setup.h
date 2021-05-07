#ifndef GUI_SETUP_H_
#define GUI_SETUP_H_

#include "gui_elements.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

std::vector <JButton> generate_selection_list(sf::Font &font);

std::vector <JTextArea> generate_questions_list(sf::Font &font, ifstream &in);

std::vector <JScaleMettle> generate_scale_list(sf::Font &font);

#endif