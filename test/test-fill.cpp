#include "config.h"
#include "Clock.h"
#include "PixelConstants.h"

bool initializeGpio();

/**
 * @brief This test can be used as an example of how the Apa102::fillArea method works
 */
int main(int argv, char** argc) {
	if (!initializeGpio()) {
		return -1;
	}

	Apa102 lights(MATRIX_WIDTH, MATRIX_HEIGHT, CONFIGURATION_OPTION);
	int64_t lastLedUpdateTime = 0;
	Point fillTopLeft = { 0, 10 };
	Point fillBottomRight = { 5, 25 };

	lights.init(TEST_SPI_BUS, TEST_SPI_BAUD, 0);
	std::cout << "Apa102 initialized with: " << lights.getNumLeds() << " leds" << std::endl;

	while (true) {
		int64_t currentTime = Clock::instance().millis();

		if (currentTime >= TEST_RUN_TIME) {
			break;
		}

		if (lastLedUpdateTime + TEST_LED_INTERVAL <= currentTime) {
			lights.clear();
			if (fillTopLeft.x > fillBottomRight.x) {
				lights.fillArea(Pixel { TEST_PIXEL_BRIGHTNESS, 0xFF, 0, 0 }, fillTopLeft, Point { MATRIX_WIDTH - 1, fillBottomRight.y });
				lights.fillArea(Pixel { TEST_PIXEL_BRIGHTNESS, 0xFF, 0, 0 }, Point { 0, fillTopLeft.y }, fillBottomRight);
			}
			else {
				lights.fillArea(Pixel { TEST_PIXEL_BRIGHTNESS, 0xFF, 0, 0 }, fillTopLeft, fillBottomRight);
			}
			lights.show();

			fillTopLeft.x = (fillTopLeft.x + 1) % MATRIX_WIDTH;
			fillBottomRight.x = (fillBottomRight.x + 1) % MATRIX_WIDTH;
			// on = !on;
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
