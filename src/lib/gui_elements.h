#ifndef GUI_ELEMENTS_H_
#define GUI_ELEMENTS_H_

#include <iostream>

using namespace sf;
using namespace std;


struct JTextArea {
	int x;
	int y;
	Text text;
	JTextArea(int x, int y, Text text) {
		this->x = x;
		this->y = y;
		this->text = text;
		text.setFillColor(Color::White);
	}
};



struct JButton {
	RectangleShape rectangle;
	int x;
	int y;
	int size;
	int score;
	int ques;
	Text Answer;
	bool select;
	JButton(int x, int y, int size, int score, Text answer,  String type){
		this->x = x;
		this->y = y;
		this->size = size;
		this->Answer = answer;
		select = false;
		rectangle.setSize(Vector2f(size,size));
		rectangle.setFillColor(Color::Red);
		rectangle.setPosition(x,y);
		Answer.setPosition(x+20,y);
		if (type == "select") {
			this->score = score;
			ques = 1;
		}
		if (type == "service") {
			cout << "Part of Thread----->" << endl;
			this->select = true;
		}
	}
};

#endif