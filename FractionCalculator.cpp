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
#include "FractionCalculator.h"

FractionCalculator::FractionCalculator():Calculator()
{
	this->operation = 0;
}

void FractionCalculator::getUserOperands(void)
{
	int x, y;
	cout << "Enter left operand numerator  : ";
	cin >> x;
	cout << "Enter left operand denominator: ";
	cin >> y;
	cout << "Left operand: " << x << "/" << y << endl;
	this->f1.set(x, y);
	cout << "Enter right operand numerator  : ";
	cin >> x;
	cout << "Enter right operand denominator: ";
	cin >> y;
	cout << "Right operand: " << x << "/" << y << endl;
	this->f2.set(x, y);
	return;
}

void FractionCalculator::setOperands(Fraction op1, Fraction op2)
{
	this->f1 = op1;
	this->f2 = op2;
	return;
}

void FractionCalculator::operatorDescriptions(char opChar, string &description)
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

void FractionCalculator::compute(void)
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
			this->result = Fraction();	// set to a Fraction(0) if invalid operation
	}
	return;
}

void FractionCalculator::print(void)
{
	cout << this->f1.getNum() << "/" << this->f1.getDenom() << " ";
	cout << this->operation << " ";
	cout << this->f2.getNum() << "/" << this->f2.getDenom() << " = ";
	cout << this->result.getNum() << "/" << this->result.getDenom() << " " << endl;
	return;
}
