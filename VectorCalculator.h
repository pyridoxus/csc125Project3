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
#ifndef VECTORCALCULATOR_H_
#define VECTORCALCULATOR_H_
#include "Vector.h"
#include "Calculator.h"
#include <string>
#include <iostream>
using namespace std;

class VectorCalculator:public Calculator
{
	public:
		VectorCalculator();
		void getUserOperands(void);
		void setOperands(Vector op1, Vector op2);
		void operatorDescriptions(char opChar, string &description);
		void compute(void);
		void print(void);
	private:
		Vector f1;			// first operand
		Vector f2;			// second operand
		Vector result;	// result of operation
		float dotResult;// result of dot product
};

#endif /* VECTORCALCULATOR_H_ */
