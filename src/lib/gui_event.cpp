#include "gui_event.h"
#include "exam.h"
#include "gui_elements.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool press_select_button(
        std::vector<Button>& selection_list,
        int i,
        int x_mouse_position,
        int y_mouse_position,
        Button& next_slide)
{
    if (selection_list[i].rectangle.getGlobalBounds().contains(
                x_mouse_position, y_mouse_position)
        && (selection_list[i].select == false)) {
        selection_list[i].select = true;
        for (int j = 0; (long unsigned int)j < selection_list.size(); j++) {
            if (i != j) {
                selection_list[j].select = false;
            }
        }
        next_slide.select = false;
        return true;
    }
    if (selection_list[i].select == true) {
        selection_list[i].rectangle.setFillColor(sf::Color::Blue);
    } else {
        selection_list[i].rectangle.setFillColor(sf::Color::Red);
    }
    return false;
}

void event_key_press(
        sf::Event& event,
        sf::RenderWindow& window,
        int& x_mouse_position,
        int& y_mouse_position)
{
    if ((event.type == sf::Event::KeyPressed
         && event.key.code == sf::Keyboard::Escape)
        || (event.type == sf::Event::Closed)) {
        window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        x_mouse_position = event.mouseButton.x;
        y_mouse_position = event.mouseButton.y;
    }
}

void add_score_scale(
        Button button, std::vector<int>& scale_list, int mode, int scale)
{
    if (mode == GLOBAL) {
        for (int i = 0; i < 5; i++) {
            if (button.ques % 5 == i) {
                scale_list[i] += button.score;
            }
        }
    } else {
        scale_list[scale] += button.score;
    }
}
