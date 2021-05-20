#ifndef EXAM_H_
#define EXAM_H_
#include <iostream>
enum Scale {
    EXTRAVERSION,
    AGREEABLENESS,
    CONSCIENTIOUSNESS,
    NEUROCISM,
    OPENNESS,
    NONE
};

enum Mode { GLOBAL, ONE_SCALE };

void exam(int mode, int scale = NONE);

#endif