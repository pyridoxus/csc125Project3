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
#include "MainMenu.h"

MainMenu::MainMenu()
{
	char ops[] = "+-*/";
	int a;
	for(a = 0; a < 4; a++) this->opChoice[a] = ops[a];
	this->opChoice[a] = 0;
	this->calculator = 0;
	this->op = 0;
}

MainMenu::~MainMenu()
{
	this->cleanUp();
	return;
}

void MainMenu::cleanUp(void)
{
	if(this->calculator) delete this->calculator;
	return;
}

int MainMenu::testCalculator(void)
{
	if(this->calculator == 0)
	{
		cout << "Calculator not selected." << endl;
		return 0;
	}
	return -1;
}

void MainMenu::setCalculator(int calc)
{
	this->calcType = calc;
	switch(calc)
	{
		case 1:
			this->calculator = new FloatCalculator();
			break;
		case 2:
			this->calculator = new VectorCalculator();
			break;
		case 3:
			this->calculator = new FractionCalculator();
			break;
		default:
			this->calculator = 0;
	}
	return;
}

int MainMenu::useCalculator(void)
{
	int loop = 2;
	while(loop)
	{
		if(loop == 2) this->selectCalculator();
		this->showOperations();
		this->getOperation();
		this->getOperands();
		this->showResult();
		loop = this->continueMenu();
	}
	return 0;
}

int MainMenu::continueMenu(void)
{
	char c = 0;
	while((c < '1') || (c > '3'))
	{
		cout << "Options: " << endl;
		cout << " 1) Continue" << endl;
		cout << " 2) Change Calculator" << endl;
		cout << " 3) Exit" << endl;
		cout << "     Choice: ";
		cin >> c;
	}
	if(c == '3') return 0;
	return (int)c - 48;
}

void MainMenu::selectCalculator(void)
{
	char calc = 0;
	while((calc < '1') || (calc > '3'))
	{
		cout << "Select calculator type: " << endl;
		cout << "  1) Float Calculator" << endl;
		cout << "  2) Vector Calculator" << endl;
		cout << "  3) Fraction Calculator" << endl;
		cout << "        Choice: ";
		cin >> calc;
	}
	this->cleanUp();
	this->setCalculator((int)calc - 48);
	return;
}

void MainMenu::showOperations(void)
{
	char ch;
	string str;
	if(!this->testCalculator()) return;	// In case calculator is not defined yet
	cout << "Available operations: " << endl;
	for(int a = 0; a < 4; a++)
	{
		ch = this->opChoice[a];
		this->calculator->operatorDescriptions(ch, str);
		cout << ch << "\t" << str << endl;
	}
	return;
}

void MainMenu::getOperation(void)
{
	int a, done = 0;
	if(!this->testCalculator()) return;	// In case calculator is not defined yet
	while(!done)
	{
		cout << "Select operation: ";
		cin >> this->op;
		for(a = 0, done = 0; a < 4; a++)	// Make sure selection is valid
		{
			if(this->op == this->opChoice[a]) done++;	// Valid entry found
		}
		if(!done)
		{
			cout << "Invalid selection. Choose from " << this->opChoice << endl;
		}
	}
	this->calculator->setOperation(this->op);
	return;
}

void MainMenu::getOperands(void)
{
	if(!this->testCalculator()) return;	// In case calculator is not defined yet
	this->calculator->getUserOperands();
	return;
}

void MainMenu::showResult(void)
{
	cout << "Result: " << endl;
	this->calculator->compute();
	this->calculator->print();
	return;
}
