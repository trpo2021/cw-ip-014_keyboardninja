#include <SFML/Graphics.hpp>
#include <gui_elements.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
using namespace sf;

const int W = 500;
const int H = 500;

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
	RenderWindow window(VideoMode(W, H), "QuizRunner", sf::Style::Titlebar | sf::Style::Close);
	Font font;
	font.loadFromFile("times.ttf");

	Text text("No", font, 20);
	string answer_no = "Нет";
	string answer_maybe_no = "Скорее нет, чем да";
	string answer_dont_know = "Не знаю";
	string answer_maybe_yes = "Скорее да, чем нет";
	string answer_yes = "Да";
	SelectList.push_back(JButton(100,150,20,-2,Text(sf::String::fromUtf8(answer_no.begin(), answer_no.end()),font,15),"select"));
	SelectList.push_back(JButton(100,200,20,-1,Text(sf::String::fromUtf8(answer_maybe_no.begin(), answer_maybe_no.end()), font, 15), "select"));
	SelectList.push_back(JButton(100,250,20,0,Text(sf::String::fromUtf8(answer_dont_know.begin(), answer_dont_know.end()), font, 15), "select"));
	SelectList.push_back(JButton(100,300,20,1,Text(sf::String::fromUtf8(answer_maybe_yes.begin(), answer_maybe_yes.end()), font, 15), "select"));
	SelectList.push_back(JButton(100,350,20,2,Text(sf::String::fromUtf8(answer_yes.begin(), answer_yes.end()), font, 15), "select"));
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
			if ((event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) || (event.type == sf::Event::Closed)) {
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