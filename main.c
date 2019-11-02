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
		//printf("yaw: %3.1f pitch: %3.1f roll: %3.1f\t", ypr[YAW], ypr[PITCH], ypr[ROLL]);
		printf("q: %5.2f, %5.2f, %5.2f, %5.2f\t", quat[0], quat[1], quat[2], quat[3]);
		printf("acc: %8.1f, %8.1f, %8.1f\t", accel[0], accel[1], accel[2]);
		printf("gyro: %6.3f, %6.3f, %6.3f\t", gyro[0], gyro[1], gyro[2]);
		printf("mag: %6.1f, %6.1f, %6.1f\t", compass[0], compass[1], compass[2]);
		//printf("temp: %3.1f\t", temp);
		printf("\n");
		delay_ms(5);
	}
	while(1);

	return 0;
}
