#ifndef GUI_ELEMENTS_H_
#define GUI_ELEMENTS_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace sf;
using namespace std;

const int W = 500;
const int H = 500;

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
		this->text.setPosition(x,y);
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

void do_nothing();

#endif