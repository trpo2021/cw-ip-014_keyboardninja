#ifndef GUI_ELEMENTS_H_
#define GUI_ELEMENTS_H_

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace sf;
using namespace std;

const int W = 800;
const int H = 500;

struct JScaleMettle {
    int x;
    int y;
    Text text;
    int score_percent;
    sf::RectangleShape graphic_scale;
    JScaleMettle(int x, int y, Text text, Color scale_color, int score_percent)
    {
        this->x = x;
        this->y = y;
        this->text = text;
        this->text.setFillColor(Color::White);
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
    Text text;
    JTextArea(int x, int y, Text text)
    {
        this->x = x;
        this->y = y;
        this->text = text;
        this->text.setFillColor(Color::White);
        this->text.setPosition(x, y);
    }
};

struct JButton {
    RectangleShape rectangle;
    int x;
    int y;
    int size;
    int score;
    int ques;
    Text button_text;
    bool select;
    JButton(int x, int y, int size, int score, Text _button_text, String type)
    {
        this->x = x;
        this->y = y;
        this->size = size;
        this->button_text = _button_text;
        select = false;
        rectangle.setSize(Vector2f(size, size));
        rectangle.setFillColor(Color::Red);
        rectangle.setPosition(x, y);
        this->button_text.setPosition(x + 20, y);
        if (type == "select") {
            this->score = score;
            ques = 0;
        }
        if (type == "service") {
            cout << "Part of Thread----->" << endl;
            this->select = true;
        }
    }
};

#endif