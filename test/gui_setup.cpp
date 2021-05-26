#include <gui_setup.h>
extern "C" {
#include <ctest.h>
}

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
