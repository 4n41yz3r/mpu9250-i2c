#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "MotionSensor.h"

#define delay_ms(a) usleep(a*1000)

int main() {
	if (ms_open() != 0)
		return 1;

	do {
		ms_update();
		printf("yaw: %2.1f\tpitch: %2.1f\troll: %2.1f\ttemp: %2.1f\tcomp: %2.1f, %2.1f, %2.1f\n",
			ypr[YAW], ypr[PITCH], ypr[ROLL], temp, compass[0], compass[1], compass[2]);
		delay_ms(5);
	}
	while(1);

	return 0;
}
