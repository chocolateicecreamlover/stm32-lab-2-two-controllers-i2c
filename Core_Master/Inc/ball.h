//
// Created by Oleg Kushnarev on 02.11.2023.
//

#ifndef LB_1_1_SLIDING_DOT_BALL_H
#define LB_1_1_SLIDING_DOT_BALL_H


#include "display.h"

#define MATR_X 32            // число светодиодов по х
#define MATR_Y 16            // число светодиодов по у

#define MAX_X MATR_X-1 - 2
#define MAX_Y MATR_Y-1 - 2

#define MIN_X 2
#define MIN_Y 2


void UpdateCenterPosition(Pixel* center, int16_t gx, int16_t gy);

void circleToPixelsR2(int8_t x0, int8_t y0, Pixel PixContainer[3*4]);

#endif //LB_1_1_SLIDING_DOT_BALL_H
