#include "exam.h"
#include "gui_elements.h"
#include "gui_event.h"
#include "gui_setup.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void key_flip(
        sf::Event& event,
        bool flag,
        long unsigned int& ques,
        bool mode,
        bool press)
{
    if (event.type == event.MouseButtonReleased
        && event.mouseButton.button == sf::Mouse::Left && flag) {
        if (mode == 0) {
            if (ques > 0) {
                ques--;
            }
        } else {
            if (press) {
                ques++;
            }
        }
    }
}

void exam(int mode, int scale)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<std::string> dictionary;
    dictionary.push_back("Нет");
    dictionary.push_back("Скорее нет, чем да");
    dictionary.push_back("Не знаю");
    dictionary.push_back("Скорее да, чем нет");
    dictionary.push_back("Да");
    std::vector<Button> selection_list
            = generate_template_list(font, dictionary);
    std::vector<std::vector<Button>> slide_selection_list;
    std::vector<JScaleMettle> scale_list;
    std::vector<int> score_list(5, 0);
    std::string line;
    std::string path = "questions.txt";
    std::ifstream in(path);
    long unsigned int question = 0;
    bool press = false;
    int x_mouse_position = 0;
    int y_mouse_position = 0;
    bool flag_updating_scale = false;
    std::ostringstream score_point;
    sf::RenderWindow window(
            sf::VideoMode(W, H),
            "QuizRunner",
            sf::Style::Titlebar | sf::Style::Close);
    Button NextSlide(
            500,
            400,
            20,
            0,
            sf::Text(draw_russian("Следующий вопрос"), font, 15),
            "service");
    Button PrevSlide(
            80,
            400,
            20,
            0,
            sf::Text(draw_russian("Предыдущий вопрос"), font, 15),
            "service");
    std::vector<JTextArea> questions_list = generate_questions_list(font, in);
    if (mode != GLOBAL) {
        questions_list
                = generate_question_list_on_one_scale(questions_list, scale);
        slide_selection_list.resize(15);
        for (long unsigned int i = 0; i < slide_selection_list.size(); i++) {
            slide_selection_list[i].assign(
                    selection_list.begin(), selection_list.end());
        }

    } else {
        slide_selection_list.resize(75);
        for (long unsigned int i = 0; i < slide_selection_list.size(); i++) {
            slide_selection_list[i].assign(
                    selection_list.begin(), selection_list.end());
        }
    }
    QuestionCounter counter
            = QuestionCounter(questions_list.size(), font, 15, 10, 10);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            event_key_press(event, window, x_mouse_position, y_mouse_position);
            key_flip(
                    event,
                    PrevSlide.rectangle.getGlobalBounds().contains(
                            x_mouse_position, y_mouse_position),
                    question,
                    0,
                    press);
            key_flip(
                    event,
                    NextSlide.rectangle.getGlobalBounds().contains(
                            x_mouse_position, y_mouse_position),
                    question,
                    1,
                    press);
        }
        window.clear();
        if (question != questions_list.size()) {
            press = false;
            window.draw(questions_list[question].text);
            counter.update(question + 1);
            window.draw(counter.text);
            if (question == questions_list.size() - 1)
                NextSlide.button_text.setString(draw_russian("Завершить"));
            else {
                NextSlide.button_text.setString(
                        draw_russian("Следующий вопрос"));
            }
            for (long unsigned int j = 0;
                 j < slide_selection_list[question].size();
                 j++) {
                window.draw(slide_selection_list[question][j].rectangle);
                window.draw(slide_selection_list[question][j].button_text);
                press_select_button(
                        slide_selection_list[question],
                        j,
                        x_mouse_position,
                        y_mouse_position,
                        NextSlide);
            }
            for (long unsigned int j = 0;
                 j < slide_selection_list[question].size();
                 j++) {
                if (slide_selection_list[question][j].select) {
                    press = true;
                }
            }
            window.draw(NextSlide.rectangle);
            window.draw(NextSlide.button_text);
            if (question != 0) {
                window.draw(PrevSlide.rectangle);
                window.draw(PrevSlide.button_text);
            }
            if (NextSlide.rectangle.getGlobalBounds().contains(x_mouse_position, y_mouse_position)
                && (NextSlide.select == false)) {
                for (long unsigned int j = 0;
                     j < slide_selection_list[question].size();
                     j++) {
                    slide_selection_list[question][j].ques = question;
                }
                NextSlide.select = true;
            }
        } else {
            if (!flag_updating_scale) {
                for (long unsigned int i = 0; i < questions_list.size(); i++) {
                    for (long unsigned int j = 0;
                         j < slide_selection_list[i].size();
                         j++) {
                        if (slide_selection_list[i][j].select == true) {
                            add_score_scale(
                                    slide_selection_list[i][j],
                                    score_list,
                                    mode,
                                    scale);
                        }
                    }
                }
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
