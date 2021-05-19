#include "global_exam.h"
#include "gui_elements.h"
#include "gui_event.h"
#include "gui_setup.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

void global_exam()
{
    Font font;
    font.loadFromFile("times.ttf");
    vector<string> dictionary;
    dictionary.push_back("Нет");
    dictionary.push_back("Скорее нет, чем да");
    dictionary.push_back("Не знаю");
    dictionary.push_back("Скорее да, чем нет");
    dictionary.push_back("Да");
    vector<JButton> selection_list = generate_template_list(font, dictionary);
    vector<JScaleMettle> scale_list;
    vector<int> score_list(5, 0);
    string line;
    string path = "questions.txt";
    ifstream in(path);
    long unsigned int question = 0;
    int x_mouse = 0;
    int y_mouse = 0;
    bool flag_updating_scale = false;
    ostringstream score_point;
    RenderWindow window(
            VideoMode(W, H),
            "QuizRunner",
            sf::Style::Titlebar | sf::Style::Close);
    JButton NextSlide(
            500,
            400,
            20,
            0,
            Text(draw_russian("Следующий вопрос"), font, 15),
            "service");
    vector<JTextArea> questions_list = generate_questions_list(font, in);
    QuestionCounter counter
            = QuestionCounter(questions_list.size(), font, 15, 10, 10);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            event_key_press(event, window, x_mouse, y_mouse);
        }
        window.clear();
        if (question != questions_list.size()) {
            window.draw(questions_list[question].text);
            counter.update(question + 1);
            window.draw(counter.text);
            if (question == questions_list.size() - 1)
                NextSlide.button_text.setString(draw_russian("Завершить"));

            for (long unsigned int i = 0; i < selection_list.size(); i++) {
                window.draw(selection_list[i].rectangle);
                window.draw(selection_list[i].button_text);
                press_select_button(
                        selection_list, i, x_mouse, y_mouse, NextSlide);
            }

            window.draw(NextSlide.rectangle);
            window.draw(NextSlide.button_text);
            if (NextSlide.rectangle.getGlobalBounds().contains(x_mouse, y_mouse)
                && (NextSlide.select == false)) {
                question++;
                for (long unsigned int i = 0; i < selection_list.size(); i++) {
                    if (selection_list[i].select == true) {
                        add_score_scale(selection_list[i], score_list);
                        selection_list[i].select = false;
                    }
                    selection_list[i].ques = question;
                }
                NextSlide.select = true;
            }
        } else {
            if (!flag_updating_scale) {
                scale_list = generate_scale_list(font, score_list);
                flag_updating_scale = true;
            }
            for (long unsigned int i = 0; i < scale_list.size(); i++) {
                window.draw(scale_list[i].text);
                window.draw(scale_list[i].graphic_scale);
            }
        }
        window.display();
    }
}