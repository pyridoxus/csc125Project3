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
#include "Fraction.h"

int reduce(int &n, int &d)
{
    int k, modnum, moddenom, common;
    int loop;   // Flag to continue on the same factor
    common = 1; // Set up the least common multiple
    for(k = 2; k <= d / 2; k++)
    {
        do
        {
            modnum = n % k;        // Find if nicely divisible
            moddenom = d % k;
            if((modnum == 0) && (moddenom == 0))
            {
                common *= k; // "Store" the factor
                n /= k; // "Remove" the factor from the numerator
                d /= k; // "Remove" the factor from the denominator
                loop = -1; // Repeat on this factor again
            }
            else loop = 0; // Don't repeat on this factor again
        } while(loop);
    }
    return common;	// Return the greatest common factor, in case it's needed.
}

Fraction::Fraction(int numerator, int denominator)
{
	this->set(numerator, denominator);
	return;
}

void Fraction::set(int numerator, int denominator)
{
	this->num = numerator;
	this->denom = denominator;
	return;
}

int Fraction::getNum(void)			// return the numerator
{
	return this->num;
}

int Fraction::getDenom(void)		// return the denominator
{
	return this->denom;
}

Fraction operator +(Fraction &a, Fraction &b)
{
	int num, denom;
	num = a.getNum() * b.getDenom() + a.getDenom() * b.getNum();
	denom = a.getDenom() * b.getDenom();
	reduce(num, denom);
	return Fraction(num, denom);
}

Fraction operator -(Fraction &a, Fraction &b)
{
	int num, denom;
	num = a.getNum() * b.getDenom() - a.getDenom() * b.getNum();
	denom = a.getDenom() * b.getDenom();
	reduce(num, denom);
	return Fraction(num, denom);
}

Fraction operator *(Fraction &a, Fraction &b)
{
	int num, denom;
	num = a.getNum() * b.getNum();
	denom = a.getDenom() * b.getDenom();
	reduce(num, denom);
	return Fraction(num, denom);
}

Fraction operator /(Fraction &a, Fraction &b)
{
	int num, denom;
	num = a.getNum() * b.getDenom();
	denom = a.getDenom() * b.getNum();
	reduce(num, denom);
	return Fraction(num, denom);
}

