#include "global_exam.h"
#include "gui_elements.h"
#include "gui_event.h"
#include "gui_setup.h"
#include "one_scale_exam.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

vector<JButton> generate_menu_list(Font& font)
{
    vector<JButton> selection_list;
    selection_list.push_back(
            JButton(100,
                    150,
                    20,
                    5,
                    Text(draw_russian("Глобальное тестирование"), font, 15),
                    "select"));
    selection_list.push_back(
            JButton(100,
                    200,
                    20,
                    4,
                    Text(draw_russian("Тестирование по выбору"), font, 15),
                    "select"));
    selection_list.push_back(
            JButton(100,
                    250,
                    20,
                    3,
                    Text(draw_russian("Случайное тестирование"), font, 15),
                    "select"));
    selection_list.push_back(JButton(
            100, 300, 20, 2, Text(draw_russian("Выход"), font, 15), "select"));
    return selection_list;
}

void menu()
{
    Font font;
    font.loadFromFile("times.ttf");
    vector<JButton> selection_list = generate_menu_list(font);
    int x_mouse = 0;
    int y_mouse = 0;
    RenderWindow window(
            VideoMode(W, H),
            "QuizRunner",
            sf::Style::Titlebar | sf::Style::Close);
    JButton NextSlide(
            500,
            400,
            20,
            0,
            Text(draw_russian("Следующий вопрос"), font, 15),
            "service");
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            event_key_press(event, window, x_mouse, y_mouse);
        }
        window.clear();
        for (int i = 0; (long unsigned int)i < selection_list.size(); i++) {
            window.draw(selection_list[i].rectangle);
            window.draw(selection_list[i].button_text);
            press_select_button(selection_list, i, x_mouse, y_mouse, NextSlide);
        }
        if (selection_list[0].select) {
            window.close();
            global_exam();
        } else if (selection_list[1].select) {
            window.close();
            one_scale_exam(OPENNESS);
        } else if (selection_list[2].select) {
        } else if (selection_list[3].select) {
            window.close();
        }

        window.display();
    }
}