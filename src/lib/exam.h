#ifndef EXAM_H_
#define EXAM_H_
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

void exam(int mode, int scale = -1);

#endif