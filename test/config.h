#ifndef _TEST_CONFIG_H_
#define _TEST_CONFIG_H_

#include <iostream>
#include <stdint.h>
#include <pigpio.h>

#include "Apa102.h"

// Required test parameters
// you MUST set your led matrix size and configuration option in order to run the tests
#define MATRIX_WIDTH 10
#define MATRIX_HEIGHT 10
#define CONFIGURATION_OPTION Apa102::HorizontalTopLeft

// Optional test parameters
#define TEST_PIXEL_BRIGHTNESS 31	// apa102 brightness
#define TEST_LED_INTERVAL 80		// led test update interval
#define TEST_RUN_TIME 20000			// led test duration in milliseconds

// GPIO
#define TEST_SPI_BAUD 6000000		// apa102 spi baud rate
#define TEST_SPI_BUS 0				// pi's spi bus to use for tests

#endif