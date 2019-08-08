/*
 * ShiftRegister.h
 *
 *  Created on: Aug 6, 2019
 *      Author: muman
 */

#ifndef SHIFTREGISTER_H_
#define SHIFTREGISTER_H_

// Shift order
// typedef enum {
// 	// Shift order
// 	LSBFIRST,
// 	MSBFIRST,
// } SHIFT_ORDER;


class ShiftRegister {
public:
	ShiftRegister();
	ShiftRegister(int dataPin, int clockPin, int latchPin, int order = MSBFIRST);
	~ShiftRegister();

	bool 		begin(int dataPin = -1, int clockPin = -1, int latchPin = -1, int order = -1);
	void 		write(int value);

private:

//	void	 	digitalWrite(int pin, GPIO_PinState value);
	void		shiftOut(int val);

	bool 		bInit   = false;
	int 		_dp 	= -1;	// data pin
	int 		_cp 	= -1;	// clock pin
	int 		_lp 	= -1;	// latch pin
	int         _order 	= MSBFIRST;
};

#endif /* SHIFTREGISTER_H_ */
