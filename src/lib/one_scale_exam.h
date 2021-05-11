#ifndef ONE_SCALE_EXAM_H_
#define ONE_SCALE_EXAM_H_

#include <SFML/Graphics.hpp>
#include <iostream>

enum Scales {
    EXTRAVERSION,
    AGREEABLENESS,
    CONSCIENTIOUSNESS,
    NEUROCISM,
    OPENNESS
};

void one_scale_exam(int scale);

#endif