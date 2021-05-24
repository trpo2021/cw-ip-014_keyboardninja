#include "gui_event.h"
#include "exam.h"
#include "gui_elements.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool press_select_button(
        std::vector<JButton>& selection_list,
        int i,
        int x_mouse,
        int y_mouse,
        JButton& NextSlide)
{
    if (selection_list[i].rectangle.getGlobalBounds().contains(x_mouse, y_mouse)
        && (selection_list[i].select == false)) {
        selection_list[i].select = true;
        for (int j = 0; (long unsigned int)j < selection_list.size(); j++) {
            if (i != j) {
                selection_list[j].select = false;
            }
        }
        NextSlide.select = false;
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
        sf::Event& event, sf::RenderWindow& window, int& x_mouse, int& y_mouse)
{
    if ((event.type == sf::Event::KeyPressed
         && event.key.code == sf::Keyboard::Escape)
        || (event.type == sf::Event::Closed)) {
        window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        x_mouse = event.mouseButton.x;
        y_mouse = event.mouseButton.y;
        std::cout << x_mouse << "<----->" << y_mouse << "\n";
    }
}

void add_score_scale(
        JButton button, std::vector<int>& scale_list, int mode, int scale)
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
