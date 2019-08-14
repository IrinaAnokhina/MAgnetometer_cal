#ifndef _SENSORS_H
#define _SENSORS_H

#include "stdint.h"
struct SAccValue
{
	int16_t x;
	int16_t y;
	int16_t z;
};

struct SMagValue
{
	int16_t x;
	int16_t y;
	int16_t z;
};

void init_sensors(void);
void read_acc(void);
void read_mag(void);
#endif
