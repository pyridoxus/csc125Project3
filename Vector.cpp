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
#include "Vector.h"

Vector::Vector(float x, float y, float z)
{
	this->set(x, y, z);
	return;
}

void Vector::set(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	return;
}

void Vector::get(float &x, float &y, float &z)
{
	x = this->x;
	y = this->y;
	z = this->z;
	return;
}

float Vector::getX(void)
{
	return this->x;
}

float Vector::getY(void)
{
	return this->y;
}

float Vector::getZ(void)
{
	return this->z;
}

Vector operator +(Vector &a, Vector &b)
{
	return Vector(a.getX() + b.getX(),
								a.getY() + b.getY(),
								a.getZ() + b.getZ());
}

Vector operator -(Vector &a, Vector &b)
{
	return Vector(a.getX() - b.getX(),
								a.getY() - b.getY(),
								a.getZ() - b.getZ());
}

float operator *(Vector &a, Vector &b)
{
	return (float)( a.getX() * b.getX() +
									a.getY() * b.getY() +
									a.getZ() * b.getZ());
}

Vector operator /(Vector &a, Vector &b)
{
	return Vector(a.getY() * b.getZ() - a.getZ() * b.getY(),
								a.getZ() * b.getX() - a.getX() * b.getZ(),
								a.getX() * b.getY() - a.getY() * b.getX());
}
