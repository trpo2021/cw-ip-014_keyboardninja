#include "gui_setup.h"
#include "gui_elements.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

vector <JButton> generate_selection_list(Font& font){
    vector <JButton> selection_list;
    string button_text_no = "Нет";
	string button_text_maybe_no = "Скорее нет, чем да";
	string button_text_dont_know = "Не знаю";
	string button_text_maybe_yes = "Скорее да, чем нет";
	string button_text_yes = "Да";

    selection_list.push_back(JButton(
            100,
            150,
            20,
            -2,
            Text(sf::String::fromUtf8(button_text_no.begin(), button_text_no.end()),
                 font,
                 15),
            "select"));
    selection_list.push_back(JButton(
            100,
            200,
            20,
            -1,
            Text(sf::String::fromUtf8(
                         button_text_maybe_no.begin(), button_text_maybe_no.end()),
                 font,
                 15),
            "select"));
    selection_list.push_back(JButton(
            100,
            250,
            20,
            0,
            Text(sf::String::fromUtf8(
                         button_text_dont_know.begin(), button_text_dont_know.end()),
                 font,
                 15),
            "select"));
    selection_list.push_back(JButton(
            100,
            300,
            20,
            1,
            Text(sf::String::fromUtf8(
                         button_text_maybe_yes.begin(), button_text_maybe_yes.end()),
                 font,
                 15),
            "select"));
    selection_list.push_back(JButton(
            100,
            350,
            20,
            2,
            Text(sf::String::fromUtf8(button_text_yes.begin(), button_text_yes.end()),
                 font,
                 15),
            "select"));
            return selection_list;
}

vector <JTextArea>generate_questions_list(Font &font, ifstream &in) {
	vector <JTextArea> questions_list;
	string line;
	if (in.is_open()) {
		while (getline(in, line)) {
			Text text(sf::String::fromUtf8(line.begin(), line.end()), font, 20);
			questions_list.push_back(JTextArea(100, 100, text));
		}
	}
	in.close();
	return questions_list;
}



