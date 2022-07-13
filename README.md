# apa102-cppi
C++ Apa102 Library for Raspberry Pi

After doing a bit of research into rpi libraries to control apa102 leds, I found that other libraries were dependent on the [now-deprecated](https://hackaday.com/2019/09/18/wiringpi-library-to-be-deprecated/) WiringPi library.  For this reason, I decided to create my own Apa102 library using pigpio, which has a simple and elegant interface, and, most importantly, is still actively maintained!

## Getting set up:
#### Clone the Repo
```
$ git clone https://github.com/cosparks/apa102-cppi.git
```
#### Build and Install PIGPIO
* If don't already have pigpio installed, run the package-installer script (this will install packages necessary to build and install pigpio)
```
$ cd scripts
$ sudo ./package-installer.sh
```
#### Run Tests (Optional)
* Open test/config.h the test folder and enter your led grid parameters
* Build and run the tests:
```
$ cd tests
$ make all
$ sudo test-grid
...
```
#### Add this library to your project
* apa102-cppi is currently meant to be used as a static library.  If you want to compile it as a shared library, then you will need to write your own makefile

#### Dependencies
pigpio
