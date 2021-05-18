#ifndef GUI_MENU
#define GUI_MENU

vector<JButton> generate_menu_list(Font& font);
vector<JButton>
generate_button_list(Font& font, const vector<string>& dictionary);
void temper_menu();
void menu();

#endif