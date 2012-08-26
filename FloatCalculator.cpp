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
#include "FloatCalculator.h"

FloatCalculator::FloatCalculator():Calculator()
{
	this->operation = 0;
}

void FloatCalculator::getUserOperands(void)
{
	float x;
	cout << "Enter left operand : ";
	cin >> x;
	this->f1.set(x);
	cout << "Enter right operand: ";
	cin >> x;
	this->f2.set(x);
	return;
}

void FloatCalculator::setOperands(Float op1, Float op2)
{
	this->f1 = op1;
	this->f2 = op2;
	return;
}

void FloatCalculator::operatorDescriptions(char opChar, string &description)
{
	switch(opChar)
	{
		case '+':
			description = "Addition";
			break;
		case '-':
			description = "Subtraction";
			break;
		case '*':
			description = "Multiplication";
			break;
		case '/':
			description = "Division";
			break;
		default:
			description = "Invalid";
	}
	return;
}

void FloatCalculator::compute(void)
{
	switch(this->operation)
	{
		case '+':
			this->result = this->f1 + this->f2;
			break;
		case '-':
			this->result = this->f1 - this->f2;
			break;
		case '*':
			this->result = this->f1 * this->f2;
			break;
		case '/':
			this->result = this->f1 / this->f2;
			break;
		default:
			this->result = Float();	// set to a Float(0) if invalid operation
	}
	return;
}

void FloatCalculator::print(void)
{
	cout << this->f1.get() << " " << this->operation << " ";
	cout << this->f2.get() << " = ";
	cout << this->result.get() << endl;
	return;
}
