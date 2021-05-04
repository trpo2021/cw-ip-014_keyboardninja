#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
using namespace sf;


const int W = 500;
const int H = 500;

struct JTextArea {
	int x;
	int y;
	Text text;
	JTextArea(int _x, int _y, Text _text) {
		x = _x;
		y = _y;
		text = _text;
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
	JButton(int _x, int _y, int _size, int _score, Text _answer,  String type){
		x = _x;
		y = _y;
		size = _size;
		Answer = _answer;
		select = false;
		rectangle.setSize(Vector2f(size,size));
		rectangle.setFillColor(Color::Red);
		rectangle.setPosition(x,y);
		Answer.setPosition(x+20,y);
		if (type == "select") {
			score = _score;
			ques = 1;
		}
		if (type == "service") {
			cout << "Part of Thread----->" << endl;
			select = true;
		}
	}
};


int main() {
	setlocale(LC_ALL, "Rus");
	vector <JTextArea>QuesList;
	vector <JButton>SelectList;
	vector <int>ScoreList;
	string line;
	string path = "questions.txt";
	ifstream in(path);
	int Question = 1;
	int x_mouse = 0;
	int y_mouse = 0;
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	int result4 = 0;
	int result5 = 0;
	RenderWindow window(VideoMode(W, H), "QuizRunner");
	Font font;
	font.loadFromFile("times.ttf");

	Text text("No", font, 20);
	SelectList.push_back(JButton(100,150,20,-2,Text("No",font,15),"select"));
	SelectList.push_back(JButton(100,200,20,-1,Text("Maybe No", font, 15), "select"));
	SelectList.push_back(JButton(100,250,20,0,Text("Yes and No", font, 15), "select"));
	SelectList.push_back(JButton(100,300,20,1,Text("Maybe Yes", font, 15), "select"));
	SelectList.push_back(JButton(100,350,20,2,Text("Yes", font, 15), "select"));
	JButton NextSlide(300, 300, 20, 0, Text("Next Question", font, 30), "service");

	window.setVerticalSyncEnabled(true);
	if (in.is_open())
	{
		while (getline(in, line))
		{
			Text ltext(line, font, 20);
			QuesList.push_back(JTextArea(100,100, ltext));
		}
	}
	in.close();     

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
				window.close();
			}
			if (event.type == Event::MouseButtonPressed) {
				x_mouse = event.mouseButton.x;
				y_mouse = event.mouseButton.y;
				cout << x_mouse << "<----->" << y_mouse << endl;
			}
		}
		window.clear();
		QuesList[Question-1].text.setPosition(QuesList[Question-1].x, QuesList[Question-1].y);
		window.draw(QuesList[Question-1].text);
		for (int i = 0;i < SelectList.size();i++) {
			window.draw(SelectList[i].rectangle);
			/*Text but("",font,15);
			if (SelectList[i].select) {
				but.setString("true");
			}
			else {
				but.setString("false");
			}
			but.setPosition(SelectList[i].x + 20, SelectList[i].y);*/
			window.draw(SelectList[i].Answer);
			if ((SelectList[i].x + SelectList[i].size > x_mouse) and (SelectList[i].x - SelectList[i].size < x_mouse) and (SelectList[i].y + SelectList[i].size > y_mouse) and (SelectList[i].y - SelectList[i].size < y_mouse) and (SelectList[i].select == false)) {
				SelectList[i].select = true;
				for (int j = 0;j < SelectList.size();j++) {
					if (i != j) {
						SelectList[j].select = false;
					}
				}
				NextSlide.select = false;
			}
			if (SelectList[i].select == true) {
				SelectList[i].rectangle.setFillColor(Color::Blue);
			}
			else {
				SelectList[i].rectangle.setFillColor(Color::Red);
			}
		}
		window.draw(NextSlide.rectangle);
		window.draw(NextSlide.Answer);
		if ((NextSlide.x + NextSlide.size > x_mouse) and (NextSlide.x - NextSlide.size < x_mouse) and (NextSlide.y + NextSlide.size > y_mouse) and (NextSlide.y - NextSlide.size < y_mouse) and (NextSlide.select == false)) {
			for(int i = 0;i < SelectList.size();i++){
				if (SelectList[i].select == true) {
					ScoreList.push_back(SelectList[i].score);
					SelectList[i].select = false;
				}
			}
			NextSlide.select = true;
			Question++;
		}

		window.display();
	}
}