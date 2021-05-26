#include <gui_setup.h>
extern "C" {
#include <ctest.h>
}
#include <vector>
#include <gui_elements.h>

CTEST(gen_template_list, selection_list)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<std::string> dictionary;
    dictionary.push_back("Нет");
    dictionary.push_back("Скорее нет, чем да");
    dictionary.push_back("Не знаю");
    dictionary.push_back("Скорее да, чем нет");
    dictionary.push_back("Да");
    std::vector<JButton> selection_list
            = generate_template_list(font, dictionary);
    sf::Text a(draw_russian(dictionary[0]), font, 15);
    bool result = a.getString() == selection_list[0].button_text.getString();
    ASSERT_TRUE(result);
}

CTEST(gen_template_list, wrong_strings)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<std::string> dictionary;
    dictionary.push_back("Нет");
    dictionary.push_back("Скорее нет, чем да");
    dictionary.push_back("Не знаю");
    dictionary.push_back("Скорее да, чем нет");
    dictionary.push_back("Да");
    std::vector<JButton> selection_list
            = generate_template_list(font, dictionary);
    sf::Text a(draw_russian(dictionary[1]), font, 15);
    bool result = a.getString() == selection_list[0].button_text.getString();
    ASSERT_FALSE(result);
}

CTEST(gen_template_list, buillding_template_list)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<std::string> dictionary;
    dictionary.push_back("Нет");
    dictionary.push_back("Скорее нет, чем да");
    dictionary.push_back("Не знаю");
    dictionary.push_back("Скорее да, чем нет");
    dictionary.push_back("Да");
    std::vector<JButton> selection_list1
            = generate_template_list(font, dictionary);
     std::vector<JButton> selection_list2;
    for (long unsigned int i = 0,
                           y_begin_coordinate = 200,
                           m = dictionary.size();
         i < dictionary.size();
         i++, y_begin_coordinate += 50, m--) {
        selection_list2.push_back(
                JButton(300,
                        y_begin_coordinate,
                        20,
                        m,
                        sf::Text(draw_russian(dictionary[i]), font, 15),
                        "select"));
    }
    bool result = true;
    for(unsigned long int i = 0; i < selection_list1.size(); i++){
        if(selection_list1[0].button_text.getString() != selection_list2[0].button_text.getString()) result = false;
    }
    ASSERT_TRUE(result);
}

CTEST(gen_template_list, fail_building_template_list)
{
    sf::Font font;
    font.loadFromFile("times.ttf");
    std::vector<std::string> dictionary;
    dictionary.push_back("Нет");
    dictionary.push_back("Скорее нет, чем да");
    dictionary.push_back("Не знаю");
    dictionary.push_back("Скорее да, чем нет");
    dictionary.push_back("Да");
    std::vector<JButton> selection_list1
            = generate_template_list(font, dictionary);
     std::vector<JButton> selection_list2;
    for (long unsigned int i = 0,
                           y_begin_coordinate = 200,
                           m = dictionary.size();
         i < dictionary.size();
         i++, y_begin_coordinate += 50, m--) {
        selection_list2.push_back(
                JButton(300,
                        y_begin_coordinate,
                        20,
                        m,
                        sf::Text(draw_russian(dictionary[i+1]), font, 15),
                        "select"));
    }
    bool result = true;
    for(unsigned long int i = 0; i < selection_list1.size(); i++){
        if(selection_list1[0].button_text.getString() != selection_list2[0].button_text.getString()) result = false;
    }
    ASSERT_FALSE(result);
}