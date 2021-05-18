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

void temper_menu()
{
    Font font;
    font.loadFromFile("times.ttf");
    vector<string> dictionary;
    dictionary.push_back("Экстраверсия");
    dictionary.push_back("Доброжелательность");
    dictionary.push_back("Добросовестность");
    dictionary.push_back("Невротизм");
    dictionary.push_back("Открытость");
    vector<JButton> selection_list = generate_button_list(font, dictionary);
    int x_mouse = 0;
    int y_mouse = 0;
    RenderWindow window(
            VideoMode(W, H),
            "QuizRunner",
            sf::Style::Titlebar | sf::Style::Close);
    JButton NextSlide(
            500, 400, 20, 0, Text(draw_russian(" "), font, 15), "service");
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            event_key_press(event, window, x_mouse, y_mouse);
        }
        window.clear();
        for (long unsigned int i = 0; i < selection_list.size(); i++) {
            window.draw(selection_list[i].rectangle);
            window.draw(selection_list[i].button_text);
            press_select_button(selection_list, i, x_mouse, y_mouse, NextSlide);
        }
        if (selection_list[0].select) {
            window.close();
            one_scale_exam(EXTRAVERSION);
        } else if (selection_list[1].select) {
            window.close();
            one_scale_exam(AGREEABLENESS);
        } else if (selection_list[2].select) {
            window.close();
            one_scale_exam(CONSCIENTIOUSNESS);
        } else if (selection_list[3].select) {
            window.close();
            one_scale_exam(NEUROCISM);
        } else if (selection_list[4].select) {
            window.close();
            one_scale_exam(OPENNESS);
        }

        window.display();
    }
}

void menu()
{
    Font font;
    font.loadFromFile("times.ttf");
    vector<string> dictionary;
    dictionary.push_back("Глобальное тестирование");
    dictionary.push_back("Тестирование по выбору");
    dictionary.push_back("Случайное тестирование");
    dictionary.push_back("Выйти");
    vector<JButton> selection_list = generate_button_list(font, dictionary);
    int x_mouse = 0;
    int y_mouse = 0;
    RenderWindow window(
            VideoMode(W, H),
            "QuizRunner",
            sf::Style::Titlebar | sf::Style::Close);
    JButton NextSlide(
            500, 400, 20, 0, Text(draw_russian(" "), font, 15), "service");
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            event_key_press(event, window, x_mouse, y_mouse);
        }
        window.clear();
        for (long unsigned int i = 0; i < selection_list.size(); i++) {
            window.draw(selection_list[i].rectangle);
            window.draw(selection_list[i].button_text);
            press_select_button(selection_list, i, x_mouse, y_mouse, NextSlide);
        }
        if (selection_list[0].select) {
            window.close();
            global_exam();
        } else if (selection_list[1].select) {
            window.close();
            temper_menu();
        } else if (selection_list[2].select) {
            // random test
        } else if (selection_list[3].select) {
            window.close();
        }

        window.display();
    }
}