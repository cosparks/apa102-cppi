#include "config.h"
#include "Clock.h"
#include "PixelConstants.h"

bool initializeGpio();

/**
 * @brief This test can be used to verify that your led strip/strips are connected properly
 * 
 * @note  You should see a 7-pixel rainbow line move across your led strip
 */
int main(int argv, char** argc) {
	if (!initializeGpio()) {
		return -1;
	}

	Apa102 lights(MATRIX_WIDTH, MATRIX_HEIGHT, CONFIGURATION_OPTION);
	int64_t lastLedUpdateTime = 0;

	lights.init(TEST_SPI_BUS, TEST_SPI_BAUD, 0);
	std::cout << "Apa102 initialized with: " << lights.getNumLeds() << " leds" << std::endl;

	uint32_t currentLedIndex = 0;

	while (true) {
		int64_t currentTime = Clock::instance().millis();

		if (currentTime >= TEST_RUN_TIME) {
			break;
		}

		if (lastLedUpdateTime + TEST_LED_INTERVAL <= currentTime) {
			lights.clear();
			uint32_t r_i = currentLedIndex;
			uint32_t o_i = (currentLedIndex + 1) % lights.getNumLeds();
			uint32_t y_i = (currentLedIndex + 2) % lights.getNumLeds();
			uint32_t g_i = (currentLedIndex + 3) % lights.getNumLeds();
			uint32_t b_i = (currentLedIndex + 4) % lights.getNumLeds();
			uint32_t i_i = (currentLedIndex + 5) % lights.getNumLeds();
			uint32_t v_i = (currentLedIndex + 6) % lights.getNumLeds();
			lights.setPixel(Red, r_i); // r
			lights.setPixel(Orange, o_i); // o
			lights.setPixel(Yellow, y_i); // y
			lights.setPixel(Green, g_i); // g
			lights.setPixel(Blue, b_i); // b
			lights.setPixel(Indigo, i_i); // i
			lights.setPixel(Violet, v_i); // v
			currentLedIndex++;
			currentLedIndex = currentLedIndex % lights.getNumLeds();
			lights.show();
			lastLedUpdateTime = currentTime;
		}
	}

	std::cout << "Test complete.  Returning" << std::endl;
	gpioTerminate();
	return 1;
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
