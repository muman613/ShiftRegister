/*
 * ShiftRegister.cpp
 *
 *  Created on: Aug 6, 2019
 *      Author: Michael Uman <michael.uman@wunderbar.com>
 */

#include <Arduino.h>
#include "ShiftRegister.h"

/**
 * Constructor
 */
ShiftRegister::ShiftRegister() {
	bInit = false;
}

/**
 * Constructor
 */
ShiftRegister::ShiftRegister(int dataPin, int clockPin, int latchPin, int order)
: _dp(dataPin),
  _cp(clockPin),
  _lp(latchPin),
  _order(order)
{
    Serial.print("ShiftRegister::ShiftRegister()");
}

/**
 * Destructor
 */
ShiftRegister::~ShiftRegister() {
    Serial.print("ShiftRegister::~ShiftRegister()");
}

bool ShiftRegister::begin(int dataPin, int clockPin, int latchPin, int order) {
	if (dataPin != -1) {
		_dp = dataPin;
	}
	if (clockPin != -1) {
		_cp = clockPin;
	}
	if (latchPin != -1) {
		_lp = latchPin;
	}
	if (_order != -1) {
		_order = order;
	}

	bInit = true;

	// Initialize to all LEDs off...
	write(0);

	return true;
}

/**
 * Shift data out to the shift-register
 */
void ShiftRegister::shiftOut(int val) {
	uint8_t i;

	if (!bInit) {
		// Device not initialized
		return;
	}

	for (i = 0; i < 8; i++) {
		if (_order == LSBFIRST)
			digitalWrite(_dp, (val & (1 << i)) ? HIGH : LOW);
		else
			digitalWrite(_dp, (val & (1 << (7 - i))) ? HIGH : LOW);

		digitalWrite(_cp, HIGH);
        delay(2);
		digitalWrite(_cp, LOW);
	}
}

/**
 *	Writes the value to the shift-register, ultimately displaying on the LED's
 */
void ShiftRegister::write(int value) {
	if (!bInit) {
		// Device not initialized
		return;
	}
	digitalWrite(_lp, LOW);
	shiftOut(value);
	digitalWrite(_lp, HIGH);
}
