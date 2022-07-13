#include "config.h"
#include "Clock.h"
#include "PixelConstants.h"

bool initializeGpio();

/**
 * @brief This test demonstrates how to display shapes on the led grid
 * 
 * @note  You should see three different shapes moving across the gride: a rainbow, a heart and a smiley face
 */
int main(int argv, char** argc) {
	if (!initializeGpio()) {
		return -1;
	}

	Apa102 lights(MATRIX_WIDTH, MATRIX_HEIGHT, CONFIGURATION_OPTION);
	int64_t lastLedUpdateTime = 0;

	lights.init(TEST_SPI_BUS, TEST_SPI_BAUD, 0);
	std::cout << "Apa102 initialized with: " << lights.getNumLeds() << " leds" << std::endl;

	Point shapesTopLeft = { 0, 10 };
	Shape rainbow = { 7, 10, Rainbow7x10 };
	Shape smiley = { 6, 5, Smiley6x5 };
	Shape heart = { 7, 5, Heart7x5 };

	while (true) {
		int64_t currentTime = Clock::instance().millis();

		if (currentTime >= TEST_RUN_TIME) {
			break;
		}

		if (lastLedUpdateTime + TEST_LED_INTERVAL <= currentTime) {
			lights.clear();
			lights.drawShape(shapesTopLeft, rainbow);
			lights.drawShape(Point { shapesTopLeft.x, 25 }, heart);
			lights.drawShape(Point { shapesTopLeft.x, 40 }, smiley);
			lights.show();

			shapesTopLeft.x = (shapesTopLeft.x + 1) % MATRIX_WIDTH;
			lastLedUpdateTime = currentTime;
		}

	std::cout << "Test complete.  Returning" << std::endl;
	return 1;
	}
}

bool initializeGpio() {
	if (gpioInitialise() < 0) {
		std::cout << "PI GPIO Initialization failed" << std::endl;
		return false;
	}
	else {
		std::cout << "PI GPIO Initialization successful" << std::endl;
		return true;
	}
}

