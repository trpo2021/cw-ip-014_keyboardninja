#ifndef EXAM_H_
#define EXAM_H_
#include <iostream>
#include <SFML/Graphics.hpp>
enum Scale {
    EXTRAVERSION,
    AGREEABLENESS,
    CONSCIENTIOUSNESS,
    NEUROTICISM,
    OPENNESS,
    NONE
};

enum Mode { GLOBAL, ONE_SCALE };
void event_key_previos(
        sf::Event& event,
        bool flag,
        long unsigned int& ques);
void exam(int mode, int scale = -1);

#endif