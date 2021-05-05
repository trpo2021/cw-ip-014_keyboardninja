#include <SFML/Graphics.hpp>
#include <fstream>
#include <gui_elements.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

const int W = 500;
const int H = 500;

int main()
{
    setlocale(LC_ALL, "Rus");
    vector<JTextArea> questions_list;
    vector<JButton> selection_list;
    vector<int> score_list;
    string line;
    string path = "questions.txt";
    ifstream in(path);
    int Question = 1;
    int x_mouse = 0;
    int y_mouse = 0;
    /*int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    int result4 = 0;
    int result5 = 0;
    */
    RenderWindow window(
            VideoMode(W, H),
            "QuizRunner",
            sf::Style::Titlebar | sf::Style::Close);
    Font font;
    font.loadFromFile("times.ttf");

    Text text("No", font, 20);
    string answer_no = "Нет";
    string answer_maybe_no = "Скорее нет, чем да";
    string answer_dont_know = "Не знаю";
    string answer_maybe_yes = "Скорее да, чем нет";
    string answer_yes = "Да";
    selection_list.push_back(JButton(
            100,
            150,
            20,
            -2,
            Text(sf::String::fromUtf8(answer_no.begin(), answer_no.end()),
                 font,
                 15),
            "select"));
    selection_list.push_back(JButton(
            100,
            200,
            20,
            -1,
            Text(sf::String::fromUtf8(
                         answer_maybe_no.begin(), answer_maybe_no.end()),
                 font,
                 15),
            "select"));
    selection_list.push_back(JButton(
            100,
            250,
            20,
            0,
            Text(sf::String::fromUtf8(
                         answer_dont_know.begin(), answer_dont_know.end()),
                 font,
                 15),
            "select"));
    selection_list.push_back(JButton(
            100,
            300,
            20,
            1,
            Text(sf::String::fromUtf8(
                         answer_maybe_yes.begin(), answer_maybe_yes.end()),
                 font,
                 15),
            "select"));
    selection_list.push_back(JButton(
            100,
            350,
            20,
            2,
            Text(sf::String::fromUtf8(answer_yes.begin(), answer_yes.end()),
                 font,
                 15),
            "select"));
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
        questions_list[Question - 1].text.setPosition(
                questions_list[Question - 1].x, questions_list[Question - 1].y);
        window.draw(questions_list[Question - 1].text);
        for (int i = 0; (long unsigned int)i < selection_list.size(); i++) {
            window.draw(selection_list[i].rectangle);
            /*Text but("",font,15);
            if (selection_list[i].select) {
                    but.setString("true");
            }
            else {
                    but.setString("false");
            }
            but.setPosition(selection_list[i].x + 20, selection_list[i].y);*/
            window.draw(selection_list[i].Answer);
            if ((selection_list[i].x + selection_list[i].size > x_mouse)
                and (selection_list[i].x - selection_list[i].size < x_mouse)
                and (selection_list[i].y + selection_list[i].size > y_mouse)
                and (selection_list[i].y - selection_list[i].size < y_mouse)
                and (selection_list[i].select == false)) {
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
        window.draw(NextSlide.Answer);
        if ((NextSlide.x + NextSlide.size > x_mouse)
            and (NextSlide.x - NextSlide.size < x_mouse)
            and (NextSlide.y + NextSlide.size > y_mouse)
            and (NextSlide.y - NextSlide.size < y_mouse)
            and (NextSlide.select == false)) {
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