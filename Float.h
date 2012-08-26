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
#ifndef FLOAT_H_
#define FLOAT_H_

class Float
{
	public:
		Float(float value = 0.0);
		void set(float value);
		float get(void);
		friend Float operator +(Float &op1, Float &op2);
		friend Float operator -(Float &op1, Float &op2);
		friend Float operator *(Float &op1, Float &op2);
		friend Float operator /(Float &op1, Float &op2);
	private:
		float f;
};

#endif /* FLOAT_H_ */
