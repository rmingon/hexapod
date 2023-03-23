#ifndef LIDAR_H
#define LIDAR_H

#include <Arduino.h>

class Lidar {
	private:
		bool _active;
		int _motor_enabled_pin;
		int _motor_speed_pin;
	public:
		Lidar();
		void init();
		void rotationSpeed(int);
};

#endif