#include "global_exam.h"
#include "gui_elements.h"
#include "gui_setup.h"
#include "gui_event.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using namespace sf;

void global_exam(){
    
    Font font;
    font.loadFromFile("times.ttf");
    vector<JButton> selection_list = generate_selection_list(font);
    vector<int> score_list;
    string line;
    string path = "questions.txt";
    ifstream in(path);
    int question = 0;
    int x_mouse = 0;
    int y_mouse = 0;
	bool flag_updating_scale = false;
	ostringstream score_point;
    RenderWindow window(
            VideoMode(W, H),
            "QuizRunner",
            sf::Style::Titlebar | sf::Style::Close);
	string button_text_next_ques = "Next Question";
    JButton NextSlide(
            300, 300, 20, 0, Text(sf::String::fromUtf8(button_text_next_ques.begin(), button_text_next_ques.end()), font, 15), "service");//!!!
	vector<JTextArea> questions_list = generate_questions_list(font, in);
	vector<JScaleMettle> scale_list = generate_scale_list(font);
    

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
			event_key_press(event, window, x_mouse, y_mouse);
        }
        window.clear();
		if ((long unsigned int)question != questions_list.size()) {
			window.draw(questions_list[question].text);

			for (int i = 0; (long unsigned int)i < selection_list.size(); i++) {
				window.draw(selection_list[i].rectangle);
				window.draw(selection_list[i].button_text);
				press_select_button(selection_list, i, x_mouse, y_mouse, NextSlide);
			}

			window.draw(NextSlide.rectangle);
			window.draw(NextSlide.button_text);
			if (NextSlide.rectangle.getGlobalBounds().contains(x_mouse, y_mouse) && (NextSlide.select == false)) {
				question++;
				for (int i = 0; (long unsigned int)i < selection_list.size(); i++) {
					if (selection_list[i].select == true) {
						add_score_scale(selection_list[i], scale_list);
						selection_list[i].select = false;
					}
					selection_list[i].ques = question;
				}
				NextSlide.select = true;
			}
		}
		else {
			if (!flag_updating_scale) {
				for (int i = 0; (long unsigned int)i < scale_list.size(); i++) {
					score_point << ((scale_list[i].current_score)/75)*100;
					scale_list[i].text.setString(scale_list[i].text.getString() + score_point.str() + " %");
					score_point.str("");
					score_point.clear();
				}
				flag_updating_scale = true;
			}
			for (int i = 0; (long unsigned int)i < scale_list.size(); i++) {
				window.draw(scale_list[i].text);
			}
		}

        window.display();
    }
}