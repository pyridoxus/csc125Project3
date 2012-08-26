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
#ifndef MAINMENU_H_
#define MAINMENU_H_
#include "FloatCalculator.h"
#include "FractionCalculator.h"
#include "VectorCalculator.h"
#include "Calculator.h"

class MainMenu
{
	public:
		MainMenu();
		~MainMenu();
		int useCalculator(void);
	private:
		void selectCalculator(void);
		void showOperations(void);
		void getOperation(void);
		void getOperands(void);
		void showResult(void);
		void cleanUp(void);
		void setCalculator(int calc);
		int testCalculator(void);
		int continueMenu(void);
		Calculator *calculator;
		char op;
		char opChoice[5];
		int calcType;
};

#endif /* MAINMENU_H_ */
