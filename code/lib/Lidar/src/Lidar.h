#ifndef LIDAR_H
#define LIDAR_H

#include <Arduino.h>

class Lidar {
	private:
		bool _active;
	public:
		Lidar();
		void init();
		void rotationSpeed(uint8_t);
		void stop();
		void start();
};

#endif