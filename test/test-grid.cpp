#include "config.h"
#include "Clock.h"
#include "PixelConstants.h"

bool initializeGpio();

/**
 * @brief This test helps to cofirm that an led grid is configured properly
 *
 * @note Red dots should move from top to bottom on either edge of the grid
 */
int main(int argv, char** argc) {
	if (!initializeGpio()) {
		return -1;
	}

	Apa102 lights(MATRIX_WIDTH, MATRIX_HEIGHT, CONFIGURATION_OPTION);
	int64_t lastLedUpdateTime = 0;

	lights.init(TEST_SPI_BUS, TEST_SPI_BAUD, 0);
	std::cout << "Apa102 initialized with: " << lights.getNumLeds() << " leds" << std::endl;

	int32_t x = 0;
	int32_t y = 0;

	while (true) {
		int64_t currentTime = Clock::instance().millis();

		if (currentTime >= TEST_RUN_TIME) {
			break;
		}

		if (lastLedUpdateTime + TEST_LED_INTERVAL <= currentTime) {
			lights.clear();
			lights.setPixel(Pixel { TEST_PIXEL_BRIGHTNESS, 0xFF, 0, 0 }, Point { x, y });
			lights.show();

			x = (x + 1) % MATRIX_WIDTH;
			y = ((x == 0) ? y + 1 : y) % MATRIX_HEIGHT;
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
