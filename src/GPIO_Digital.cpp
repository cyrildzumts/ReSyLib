#include "GPIO_Digital.h"
#include <string>

namespace RSL {
using namespace RSL;

GPIO_Digital::GPIO_Digital(GPIOPin pin) {
	this->pin = pin;
}

void GPIO_Digital::initialize() {
	using namespace std;
	exportPin(pin);

	string gpioPath = "/sys/class/gpio/gpio" + to_string((int) pin);

	directionFileStream.open((gpioPath + "/direction").c_str(),
			fstream::out | fstream::in);
	valueFileStream.open((gpioPath + "/value").c_str(),
			fstream::out | fstream::in);
}

void GPIO_Digital::shutdown() {
	directionFileStream.close();
	valueFileStream.close();
	unExportPin(pin);
}

void GPIO_Digital::setDirection(Direction direction) {
	switch (direction) {
	case INPUT:
		directionFileStream << "in";
		break;
	case INPUT_PULLDOWN:
		directionFileStream << "in";
		valueFileStream << "0";
		break;
	case INPUT_PULLUP:
		directionFileStream << "in";
		valueFileStream << "1";
		break;
	case OUTPUT:
		directionFileStream << "out";
		break;
	}

	directionFileStream.flush();
	valueFileStream.flush();
}

Direction GPIO_Digital::getDirection() {
	char dir;
	directionFileStream >> dir;
	switch (dir) {
	case 'i':
		return Direction::INPUT;
	default:
		return Direction::OUTPUT;
	}
}

void GPIO_Digital::setValue(GPIO_Digital::State value) {
	valueFileStream << value;
	valueFileStream.flush();
}

GPIO_Digital::State GPIO_Digital::getValue() {
	int val;
	valueFileStream >> val;
	return (State) val;
}

GPIO_Digital::~GPIO_Digital() {
	shutdown();
}
}
