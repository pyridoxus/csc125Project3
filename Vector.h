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
#ifndef VECTOR_H_
#define VECTOR_H_

class Vector
{
	public:
		Vector(float x = 0.0, float y = 0.0, float z = 0.0);
		void set(float x, float y, float z);
		void get(float &x, float &y, float &z);
		float getX(void);
		float getY(void);
		float getZ(void);
    friend Vector operator +(Vector &a, Vector &b);
    friend Vector operator -(Vector &a, Vector &b);
    friend float operator *(Vector &a, Vector &b);
    friend Vector operator /(Vector &a, Vector &b);
	private:
		float x;
		float y;
		float z;
};

#endif /* VECTOR_H_ */
