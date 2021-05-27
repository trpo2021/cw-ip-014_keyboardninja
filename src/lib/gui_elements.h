#ifndef GUI_ELEMENTS_H_
#define GUI_ELEMENTS_H_

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const int W = 800;
const int H = 500;

struct JScaleMettle {
    int x;
    int y;
    sf::Text text;
    int score_percent;
    sf::RectangleShape graphic_scale;
    JScaleMettle(
            int x,
            int y,
            sf::Text text,
            sf::Color scale_color,
            int score_percent)
    {
        this->x = x;
        this->y = y;
        this->text = text;
        this->text.setFillColor(sf::Color::White);
        this->text.setPosition(x, y);
        sf::Vector2f scale_size;
        scale_size.x = 50;
        scale_size.y = -1.5 * score_percent;
        graphic_scale.setSize(scale_size);
        graphic_scale.setFillColor(scale_color);
        graphic_scale.setPosition(x + 50, y - 20);
    }
};

struct JTextArea {
    int x;
    int y;
    sf::Text text;
    JTextArea(int x, int y, sf::Text text)
    {
        this->x = x;
        this->y = y;
        this->text = text;
        this->text.setFillColor(sf::Color::White);
        this->text.setPosition(x, y);
    }
};

struct Button {
    sf::RectangleShape rectangle;
    int x;
    int y;
    int size;
    int score;
    int ques;
    sf::Text button_text;
    bool select;
    Button(int x,
            int y,
            int size,
            int score,
            sf::Text _button_text,
            sf::String type)
    {
        this->x = x;
        this->y = y;
        this->size = size;
        this->button_text = _button_text;
        select = false;
        rectangle.setSize(sf::Vector2f(size, size));
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(x, y);
        this->button_text.setPosition(x + 20, y);
        if (type == "select") {
            this->score = score;
            ques = 0;
        }
        if (type == "service") {
            std::cout << "Part of Thread----->" << std::endl;
            this->select = true;
        }
    }
};

struct QuestionCounter {
    int total_amount_of_questions;
    sf::Text text;
    QuestionCounter(
            int total_amount_of_questions,
            sf::Font& font,
            int font_size,
            int x,
            int y)
    {
        this->total_amount_of_questions = total_amount_of_questions;
        text = sf::Text("", font, font_size);
        text.setFillColor(sf::Color::White);
        text.setPosition(x, y);
    }
    void update(int number_of_current_question)
    {
        text.setString(
                std::to_string(number_of_current_question) + "/"
                + std::to_string(total_amount_of_questions));
    }
};

#endif