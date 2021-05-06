#include "gui_elements.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void do_nothing()
{
    return;
}

//void set_select_button(vector <JButton> &selection_list, int x, int y, int font_size, int rect_size, Font font) {
//	string button_text_no = "Нет";
//	string button_text_maybe_no = "Скорее нет, чем да";
//	string button_text_dont_know = "Не знаю";
//	string button_text_maybe_yes = "Скорее да, чем нет";
//	string button_text_yes = "Да";
//	
//	selection_list.push_back(JButton(
//		x,
//		y,
//		rect_size,
//		5,
//		Text(sf::String::fromUtf8(button_text_no.begin(), button_text_no.end()),
//			font,
//			font_size),
//		"select"));
//	
//	selection_list.push_back(JButton(
//		x,
//		y+50,
//		rect_size,
//		4,
//		Text(sf::String::fromUtf8(
//			button_text_maybe_no.begin(), button_text_maybe_no.end()),
//			font,
//			font_size),
//		"select"));
//	selection_list.push_back(JButton(
//		x,
//		y + 100,
//		rect_size,
//		3,
//		Text(sf::String::fromUtf8(
//			button_text_dont_know.begin(), button_text_dont_know.end()),
//			font,
//			font_size),
//		"select"));
//	selection_list.push_back(JButton(
//		x,
//		y + 150,
//		rect_size,
//		2,
//		Text(sf::String::fromUtf8(
//			button_text_maybe_yes.begin(), button_text_maybe_yes.end()),
//			font,
//			font_size),
//		"select"));
//	selection_list.push_back(JButton(
//		x,
//		y + 200,
//		rect_size,
//		1,
//		Text(sf::String::fromUtf8(button_text_yes.begin(), button_text_yes.end()),
//			font,
//			font_size),
//		"select"));
//
//}