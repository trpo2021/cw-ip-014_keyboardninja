#ifndef GUI_EVENT_H_
#define GUI_EVENT_H_

#include "gui_elements.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

bool press_select_button(
        std::vector<JButton>& selection_list,
        int i,
        int x_mouse,
        int y_mouse,
        JButton& NextSlide);

void event_key_press(
        sf::Event& event, sf::RenderWindow& window, int& x_mouse, int& y_mouse);

void add_score_scale(
        JButton button, std::vector<int>& scale_list, int mode, int scale);
#endif