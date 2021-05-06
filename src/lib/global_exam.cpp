#include "global_exam.h"
#include "gui_elements.h"
#include "gui_setup.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

void global_exam(){
    vector<JTextArea> questions_list;
    Font font;
    font.loadFromFile("times.ttf");
    vector<JButton> selection_list = generate_selection_list(font);
    vector<int> score_list;
    string line;
    string path = "questions.txt";
    ifstream in(path);
    int Question = 0;
    int x_mouse = 0;
    int y_mouse = 0;
    RenderWindow window(
            VideoMode(W, H),
            "QuizRunner",
            sf::Style::Titlebar | sf::Style::Close);
    JButton NextSlide(
            300, 300, 20, 0, Text("Next Question", font, 30), "service");

    window.setVerticalSyncEnabled(true);
    if (in.is_open()) {
        while (getline(in, line)) {
            Text ltext(sf::String::fromUtf8(line.begin(), line.end()), font, 20);
            questions_list.push_back(JTextArea(100, 100, ltext));
        }
    }
    in.close();

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if ((event.type == Event::KeyPressed
                 && event.key.code == Keyboard::Escape)
                || (event.type == sf::Event::Closed)) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                x_mouse = event.mouseButton.x;
                y_mouse = event.mouseButton.y;
                cout << x_mouse << "<----->" << y_mouse << endl;
            }
        }
        window.clear();
        window.draw(questions_list[Question].text);
        for (int i = 0; (long unsigned int)i < selection_list.size(); i++) {
            window.draw(selection_list[i].rectangle);
            window.draw(selection_list[i].button_text);
            if (selection_list[i].rectangle.getGlobalBounds().contains(x_mouse, y_mouse) && (selection_list[i].select == false)) {
                selection_list[i].select = true;
                for (int j = 0; (long unsigned int)j < selection_list.size(); j++) {
                    if (i != j) {
                        selection_list[j].select = false;
                    }
                }
                NextSlide.select = false;
            }
            if (selection_list[i].select == true) {
                selection_list[i].rectangle.setFillColor(Color::Blue);
            } else {
                selection_list[i].rectangle.setFillColor(Color::Red);
            }
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
            Question++;
        }

        window.display();
    }
}