#include "gui_menu.h"
#include "exam.h"
#include "gui_elements.h"
#include "gui_event.h"
#include "gui_setup.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void temper_menu()
{
    sf::Texture background_texture;
    background_texture.loadFromFile("backgroundmenu.jpg");
    sf::Sprite backround_sprite;
    backround_sprite.setTexture(background_texture);
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<std::string> dictionary;
    dictionary.push_back("Экстраверсия");
    dictionary.push_back("Доброжелательность");
    dictionary.push_back("Добросовестность");
    dictionary.push_back("Невротизм");
    dictionary.push_back("Открытость");
    std::vector<Button> selection_list
            = generate_template_list(font, dictionary);
    int x_mouse_position = 0;
    int y_mouse_position = 0;
    sf::RenderWindow window(
            sf::VideoMode(W, H),
            "QuizRunner",
            sf::Style::Titlebar | sf::Style::Close);
    Button NextSlide(
            500, 400, 20, 0, sf::Text(draw_russian(" "), font, 15), "service");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            event_key_press(event, window, x_mouse_position, y_mouse_position);
        }

        window.clear();
        window.draw(backround_sprite);
        for (long unsigned int i = 0; i < selection_list.size(); i++) {
            window.draw(selection_list[i].rectangle);
            window.draw(selection_list[i].button_text);
            press_select_button(
                    selection_list,
                    i,
                    x_mouse_position,
                    y_mouse_position,
                    NextSlide);
        }

        if (selection_list[EXTRAVERSION].select) {
            window.close();
            exam(ONE_SCALE, EXTRAVERSION);
        } else if (selection_list[AGREEABLENESS].select) {
            window.close();
            exam(ONE_SCALE, AGREEABLENESS);
        } else if (selection_list[CONSCIENTIOUSNESS].select) {
            window.close();
            exam(ONE_SCALE, CONSCIENTIOUSNESS);
        } else if (selection_list[NEUROTICISM].select) {
            window.close();
            exam(ONE_SCALE, NEUROTICISM);
        } else if (selection_list[OPENNESS].select) {
            window.close();
            exam(ONE_SCALE, OPENNESS);
        }

        window.display();
    }
}

void menu()
{
    sf::Texture background_texture;
    background_texture.loadFromFile("backgroundmenu.jpg");
    sf::Sprite backround_sprite;
    backround_sprite.setTexture(background_texture);
    srand(time(NULL));
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<std::string> dictionary;
    dictionary.push_back("Глобальное тестирование");
    dictionary.push_back("Тестирование по выбору");
    dictionary.push_back("Случайное тестирование");
    dictionary.push_back("Выйти");
    std::vector<Button> selection_list
            = generate_template_list(font, dictionary);
    int x_mouse_position = 0;
    int y_mouse_position = 0;
    sf::RenderWindow window(
            sf::VideoMode(W, H),
            "QuizRunner",
            sf::Style::Titlebar | sf::Style::Close);
    Button NextSlide(
            500, 400, 20, 0, sf::Text(draw_russian(" "), font, 15), "service");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            event_key_press(event, window, x_mouse_position, y_mouse_position);
        }
        window.clear();
        window.draw(backround_sprite);
        for (long unsigned int i = 0; i < selection_list.size(); i++) {
            window.draw(selection_list[i].rectangle);
            window.draw(selection_list[i].button_text);
            press_select_button(
                    selection_list,
                    i,
                    x_mouse_position,
                    y_mouse_position,
                    NextSlide);
        }
        if (selection_list[0].select) {
            window.close();
            exam(GLOBAL);
        } else if (selection_list[1].select) {
            window.close();
            temper_menu();
        } else if (selection_list[2].select) {
            window.close();
            int rand_num = rand() % 5;
            exam(ONE_SCALE, rand_num);
        } else if (selection_list[3].select) {
            window.close();
        }
        window.display();
    }
}