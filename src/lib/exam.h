#ifndef EXAM_H_
#define EXAM_H_
#include <SFML/Graphics.hpp>
#include <iostream>
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
        long unsigned int& ques,
        bool mode,
        bool press);

void exam(int mode, int scale = -1);

#endif