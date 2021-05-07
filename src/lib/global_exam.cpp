#include "global_exam.h"
#include "gui_elements.h"
#include "gui_setup.h"
#include "gui_event.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

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
    RenderWindow window(
            VideoMode(W, H),
            "QuizRunner",
            sf::Style::Titlebar | sf::Style::Close);
	string button_text_next_ques = "Next Question";
    JButton NextSlide(
            300, 300, 20, 0, Text(sf::String::fromUtf8(button_text_next_ques.begin(), button_text_next_ques.end()), font, 15), "service");//!!!
	vector<JTextArea> questions_list = generate_questions_list(font, in);
    

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
			event_key_press(event, window, x_mouse, y_mouse);
        }
        window.clear();

        window.draw(questions_list[question].text);

        for (int i = 0; (long unsigned int)i < selection_list.size(); i++) {
            window.draw(selection_list[i].rectangle);
            window.draw(selection_list[i].button_text);
			press_select_button(selection_list, i, x_mouse, y_mouse, NextSlide);
        }

        window.draw(NextSlide.rectangle);
        window.draw(NextSlide.button_text);
        if (NextSlide.rectangle.getGlobalBounds().contains(x_mouse, y_mouse) && (NextSlide.select == false)) {
            for (int i = 0; (long unsigned int)i < selection_list.size(); i++) {
                if (selection_list[i].select == true) {
                    score_list.push_back(selection_list[i].score);
                    selection_list[i].select = false;
                }
            }
            NextSlide.select = true;
            question++;
        }

        window.display();
    }
}