#include "ceVector2DI.h"

namespace ceEngineSDK

{
	//! Default Constructor.
	ceVector2DI::ceVector2DI()
	{

	}

	//! Constructor with parameters.
	ceVector2DI::ceVector2DI(int32 InX, int32 InY) : X(InX), Y(InY)
	{

	}

	//! Default Destructor.
	ceVector2DI::~ceVector2DI()
	{

	}

	//! This function return the magnitud of the vector given in the parameter.
	int32 ceVector2DI::Magnitud(const ceVector2DI & OtherVector)
	{
		return (int32)sqrt(pow(OtherVector.X, 2) + pow(OtherVector.Y, 2));
	}

	//! This function realize the dot product between 2 vectors.
	int32 ceVector2DI::Dot(const ceVector2DI& VectorA, const ceVector2DI& VectorB)
	{
		return VectorA | VectorB;
	}

	//! This function reduce the magnitud of the vector given between 0 and 1.
	ceVector2DI ceVector2DI::Normalize(const ceVector2DI & OtherVector)
	{
		return OtherVector / Magnitud(OtherVector);
	}

	//! This is an operator to use + between 2 vectors.
	ceVector2DI ceVector2DI::operator+(const ceVector2DI& OtherVector) const
	{
		return ceVector2DI(X + OtherVector.X, Y + OtherVector.Y);
	}

	//! This is an operator to use - between 2 vectors.
	ceVector2DI ceVector2DI::operator-(const ceVector2DI& OtherVector) const
	{
		return ceVector2DI(X - OtherVector.X, Y - OtherVector.Y);
	}

	//! This is an operator to use * between 1 vector and 1 scalar value.
	ceVector2DI ceVector2DI::operator*(int32 Value) const
	{
		return ceVector2DI(X * Value, Y * Value);
	}

	//! This is an operator to use * between 2 vectors.
	ceVector2DI ceVector2DI::operator*(const ceVector2DI& OtherVector) const
	{
		return ceVector2DI(X * OtherVector.X, Y * OtherVector.Y);
	}

	//! This is an operator to use / between 1 vector and 1 scalar value.
	ceVector2DI ceVector2DI::operator/(int32 Value) const
	{
		const int32 RScale = 1 / Value;
		return ceVector2DI(X * RScale, Y * RScale);
	}

	//! This is an operator to use / between 2 vectors.
	ceVector2DI ceVector2DI::operator/(const ceVector2DI& OtherVector) const
	{
		return ceVector2DI(X / OtherVector.X, Y / OtherVector.Y);
	}

	//! This operator compares that 2 vectors are the same.
	bool ceVector2DI::operator==(const ceVector2DI& OtherVector) const
	{
		return X == OtherVector.X && Y == OtherVector.Y;
	}

	//! This operator compares that 2 vectors are diferents.
	bool ceVector2DI::operator!=(const ceVector2DI& OtherVector) const
	{
		return X != OtherVector.X || Y != OtherVector.Y;
	}

	//! This operator compares that this vector is lesser than other vector.
	bool ceVector2DI::operator<(const ceVector2DI& OtherVector) const
	{
		return X < OtherVector.X && Y < OtherVector.Y;
	}

	//! This operator compares that this vector is greater than other vector.
	bool ceVector2DI::operator>(const ceVector2DI& OtherVector) const
	{
		return X > OtherVector.X && Y > OtherVector.Y;
	}

	//! This operator compares that this vector is lesser or equal than other vector.
	bool ceVector2DI::operator<=(const ceVector2DI& OtherVector) const
	{
		return X <= OtherVector.X && Y <= OtherVector.Y;
	}

	//! This operator compares that this vector is greater or equal than other vector.
	bool ceVector2DI::operator>=(const ceVector2DI& OtherVector) const
	{
		return X >= OtherVector.X && Y >= OtherVector.Y;
	}

	//! This function compares if 2 vectors are the same.
	bool ceVector2DI::Equals(const ceVector2DI& OtherVector, int32 Tolerance) const
	{
		return abs(X - OtherVector.X) < Tolerance && abs(Y - OtherVector.Y) < Tolerance;
	}

	//! This operator add the values from other vector with this.
	ceVector2DI& ceVector2DI::operator+=(const ceVector2DI& OtherVector)
	{
		X += OtherVector.X; Y += OtherVector.Y;
		return *this;
	}

	//! This operator subtract the values from other vector with this.
	ceVector2DI& ceVector2DI::operator-=(const ceVector2DI& OtherVector)
	{
		X -= OtherVector.X; Y -= OtherVector.Y;
		return *this;
	}

	//! This operator multiply the values from this vector with a value.
	ceVector2DI& ceVector2DI::operator*=(int32 Value)
	{
		X *= Value; Y *= Value;
		return *this;
	}

	//! This operator divide the values from this vector with a value.
	ceVector2DI& ceVector2DI::operator/=(int32 Value)
	{
		const int32 RV = 1 / Value;
		X *= RV; Y *= RV;
		return *this;
	}

	//! This operator multiply the values from other vector with this.
	ceVector2DI& ceVector2DI::operator*=(const ceVector2DI& OtherVector)
	{
		X *= OtherVector.X; Y *= OtherVector.Y;
		return *this;
	}

	//! This operator divide the values from other vector with this.
	ceVector2DI& ceVector2DI::operator/=(const ceVector2DI& OtherVector)
	{
		X /= OtherVector.X; Y /= OtherVector.Y;
		return *this;
	}

	//!This operator return the dot product between this vector and other vector.
	int32 ceVector2DI::operator|(const ceVector2DI& OtherVector) const
	{
		return (X * OtherVector.X) + (Y * OtherVector.Y);
	}

	//! This operator return the cross product between this vector and other vector.
	int32 ceVector2DI::operator^(const ceVector2DI& OtherVector) const
	{
		return (X * OtherVector.Y) - (Y * OtherVector.X);
	}

}