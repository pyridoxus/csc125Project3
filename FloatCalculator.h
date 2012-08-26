//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#ifndef FLOATCALCULATOR_H_
#define FLOATCALCULATOR_H_
#include "Float.h"
#include "Calculator.h"
#include <string>
#include <iostream>
using namespace std;

class FloatCalculator:public Calculator
{
	public:
		FloatCalculator();
		void setOperands(Float op1, Float op2);
		void operatorDescriptions(char opChar, string &description);
		void compute(void);
		void print(void);
		void getUserOperands(void);
	private:
		Float f1;			// first operand
		Float f2;			// second operand
		Float result;	// result of operation
};

#endif /* FLOATCALCULATOR_H_ */
