//
// Created by Oleg Kushnarev on 02.11.2023.
//

#include "ball.h"


int8_t constraint(int8_t x, int8_t MAX, int8_t MIN) {
	if (x > MAX) x = MAX;
	if (x < MIN) x = MIN;
	
	return x;
}

void UpdateCenterPosition(Pixel* center, int16_t gx, int16_t gy) {
	
	uint8_t coeff = 1000;
	
	int8_t xCoord = center->x + gx / (3 * coeff);
	int8_t yCoord = center->y + gy / (2 * coeff);
	
	xCoord = constraint(xCoord, MAX_X, MIN_X);
	yCoord = constraint(yCoord, MAX_Y, MIN_Y);
	
	center->x = xCoord;
	center->y = yCoord;
	
	
}



void addPixel(uint8_t x1, uint8_t y1, Pixel PixContainer[], uint8_t* pixID) {
	PixContainer[*pixID].x = x1;
	PixContainer[*pixID].y = y1;

	*pixID += 1;
}


void circleToPixelsR2(int8_t x0, int8_t y0, Pixel PixContainer[3*4]){
	uint8_t pixelID = 0;
	uint8_t R = 2;
	for (int x = -1; x <= 1; ++x) {
		addPixel(x0 + x, y0 + R, PixContainer, &pixelID);
		addPixel(x0 + x, y0 - R, PixContainer, &pixelID);
	}
	for (int y = -1; y <= 1; ++y) {
		addPixel(x0 + R, y0 + y, PixContainer, &pixelID);
		addPixel(x0 - R, y0 - y, PixContainer, &pixelID);
	}
}