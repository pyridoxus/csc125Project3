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
#include "VectorCalculator.h"

VectorCalculator::VectorCalculator():Calculator()
{
	this->dotResult = 0.0;
}

void VectorCalculator::setOperands(Vector op1, Vector op2)
{
	this->f1 = op1;
	this->f2 = op2;
	return;
}

void VectorCalculator::getUserOperands(void)
{
	float x, y, z;
	cout << "Enter left operand x : ";
	cin >> x;
	cout << "Enter left operand y : ";
	cin >> y;
	cout << "Enter left operand z : ";
	cin >> z;
	cout << "Left operand: <" << x << ", " << y << ", " << z << ">" << endl;
	this->f1.set(x, y, z);
	cout << "Enter right operand x : ";
	cin >> x;
	cout << "Enter right operand y : ";
	cin >> y;
	cout << "Enter right operand z : ";
	cin >> z;
	cout << "Right operand: <" << x << ", " << y << ", " << z << ">" << endl;
	this->f2.set(x, y, z);
	return;
}

void VectorCalculator::operatorDescriptions(char opChar, string &description)
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
			description = "Dot Multiplication";
			break;
		case '/':
			description = "Cross Multiplication";
			break;
		default:
			description = "Invalid";
	}
	return;
}

void VectorCalculator::compute(void)
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
			this->dotResult = this->f1 * this->f2;
			break;
		case '/':
			this->result = this->f1 / this->f2;
			break;
		default:
			this->result = Vector();	// set to a Vector(0) if invalid operation
	}
	return;
}

void VectorCalculator::print(void)
{
	cout << "<" << this->f1.getX() << ", " << this->f1.getY() << ", ";
	cout << this->f1.getZ() << "> " << this->operation << " <";
	cout << this->f2.getX() << ", " << this->f2.getY() << ", ";
	cout << this->f2.getZ() << "> = ";
	if(this->operation == '*')
	{
		cout << this->dotResult << endl;
	}
	else
	{
		cout << "<" << this->result.getX() << ", " << this->result.getY();
		cout << ", " << this->result.getZ() << ">" << endl;
	}
	return;
}
