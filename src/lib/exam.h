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
    NONE = -1
};

enum Mode { GLOBAL, ONE_SCALE };

void key_flip(
        sf::Event& event,
        bool flag,
        long unsigned int& ques,
        bool mode,
        bool press);

void exam(int mode, int scale = NONE);

#endif