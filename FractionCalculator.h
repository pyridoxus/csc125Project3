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
#ifndef FRACTIONCALCULATOR_H_
#define FRACTIONCALCULATOR_H_
#include "Fraction.h"
#include "Calculator.h"
#include <string>
#include <iostream>
using namespace std;

class FractionCalculator:public Calculator
{
	public:
		FractionCalculator();
		void getUserOperands(void);
		void setOperands(Fraction op1, Fraction op2);
		void operatorDescriptions(char opChar, string &description);
		void compute(void);
		void print(void);
	private:
		Fraction f1;			// first operand
		Fraction f2;			// second operand
		Fraction result;	// result of operation
};

#endif /* FRACTIONCALCULATOR_H_ */
