#ifndef _CALC_H
#define _CALC_H

#include "stdint.h"
#include "mtVector.h"
#include "math.h"

int filterAX(int x, int Nb, int k);
int filterAY(int x, int Nb, int k);
int filterAZ(int x, int Nb, int k);
int filterGX(int x, int Nb, int k);
int filterGY(int x, int Nb, int k);
int filterGZ(int x, int Nb, int k);
int filterMX(int x, int Nb, int k);
int filterMY(int x, int Nb, int k);

int filterMZ(int x, int Nb, int k);
float filterEXP(int x, float Xfilt, float a);
void transformation_MAG(float uncalibrated_values[3]);
void transformation_AXEL(float uncalibrated_values[3]) ;
float Fi_Azimuth(MTVec3D axel, MTVec3D magn);
#endif
