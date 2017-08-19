#include "ceVector2D.h"


namespace ceEngineSDK
{
	//! Default Constructor.
	ceVector2D::ceVector2D()
	{

	}

	//! Constructor with parameters.
	ceVector2D::ceVector2D(float InX, float InY) : X(InX), Y(InY)
	{

	}

	//! Default Destructor.
	ceVector2D::~ceVector2D()
	{

	}

	//! This function return the magnitud of the vector given in the parameter.
	float ceVector2D::Magnitud(const ceVector2D & OtherVector)
	{
		return sqrt(pow(OtherVector.X, 2) + pow(OtherVector.Y, 2));
	}

	//! This function reduce the magnitud of the vector given between 0 and 1.
	ceVector2D ceVector2D::Normalize(const ceVector2D & OtherVector)
	{
		return OtherVector / Magnitud(OtherVector);
	}

	//! This function realize the dot product between 2 vectors.
	float ceVector2D::Dot(const ceVector2D& VectorA, const ceVector2D& VectorB)
	{
		return VectorA | VectorB;
	}

	//! This is an operator to use + between 2 vectors.
	ceVector2D ceVector2D::operator+(const ceVector2D& OtherVector) const
	{
		return ceVector2D(X + OtherVector.X, Y + OtherVector.Y);
	}

	//! This is an operator to use - between 2 vectors.
	ceVector2D ceVector2D::operator-(const ceVector2D& OtherVector) const
	{
		return ceVector2D(X - OtherVector.X, Y - OtherVector.Y);
	}

	//! This is an operator to use * between 1 vector and 1 scalar value.
	ceVector2D ceVector2D::operator*(float Value) const
	{
		return ceVector2D(X * Value, Y * Value);
	}

	//! This is an operator to use * between 2 vectors.
	ceVector2D ceVector2D::operator*(const ceVector2D& OtherVector) const
	{
		return ceVector2D(X * OtherVector.X, Y * OtherVector.Y);
	}

	//! This is an operator to use / between 1 vector and 1 scalar value.
	ceVector2D ceVector2D::operator/(float Value) const
	{
		const float RScale = 1.f / Value;
		return ceVector2D(X * RScale, Y * RScale);
	}

	//! This is an operator to use / between 2 vectors.
	ceVector2D ceVector2D::operator/(const ceVector2D& OtherVector) const
	{
		return ceVector2D(X / OtherVector.X, Y / OtherVector.Y);
	}

	//! This operator compares that 2 vectors are the same.
	bool ceVector2D::operator==(const ceVector2D& OtherVector) const
	{
		return X == OtherVector.X && Y == OtherVector.Y;
	}

	//! This operator compares that 2 vectors are diferents.
	bool ceVector2D::operator!=(const ceVector2D& OtherVector) const
	{
		return X != OtherVector.X || Y != OtherVector.Y;
	}

	//! This operator compares that this vector is lesser than other vector.
	bool ceVector2D::operator<(const ceVector2D& OtherVector) const
	{
		return X < OtherVector.X && Y < OtherVector.Y;
	}

	//! This operator compares that this vector is greater than other vector.
	bool ceVector2D::operator>(const ceVector2D& OtherVector) const
	{
		return X > OtherVector.X && Y > OtherVector.Y;
	}

	//! This operator compares that this vector is lesser or equal than other vector.
	bool ceVector2D::operator<=(const ceVector2D& OtherVector) const
	{
		return X <= OtherVector.X && Y <= OtherVector.Y;
	}

	//! This operator compares that this vector is greater or equal than other vector.
	bool ceVector2D::operator>=(const ceVector2D& OtherVector) const
	{
		return X >= OtherVector.X && Y >= OtherVector.Y;
	}

	//! This function compares if 2 vectors are the same.
	bool ceVector2D::Equals(const ceVector2D& OtherVector, float Tolerance) const
	{
		return abs(X - OtherVector.X) < Tolerance && abs(Y - OtherVector.Y) < Tolerance;
	}

	//! This operator add the values from other vector with this.
	ceVector2D& ceVector2D::operator+=(const ceVector2D& OtherVector)
	{
		X += OtherVector.X; Y += OtherVector.Y;
		return *this;
	}

	//! This operator subtract the values from other vector with this.
	ceVector2D& ceVector2D::operator-=(const ceVector2D& OtherVector)
	{
		X -= OtherVector.X; Y -= OtherVector.Y;
		return *this;
	}

	//! This operator multiply the values from this vector with a value.
	ceVector2D& ceVector2D::operator*=(float Value)
	{
		X *= Value; Y *= Value;
		return *this;
	}

	//! This operator divide the values from this vector with a value.
	ceVector2D& ceVector2D::operator/=(float Value)
	{
		const float RV = 1.f / Value;
		X *= RV; Y *= RV;
		return *this;
	}

	//! This operator multiply the values from other vector with this.
	ceVector2D& ceVector2D::operator*=(const ceVector2D& OtherVector)
	{
		X *= OtherVector.X; Y *= OtherVector.Y;
		return *this;
	}

	//! This operator divide the values from other vector with this.
	ceVector2D& ceVector2D::operator/=(const ceVector2D& OtherVector)
	{
		X /= OtherVector.X; Y /= OtherVector.Y;
		return *this;
	}

	//!This operator return the dot product between this vector and other vector.
	float ceVector2D::operator|(const ceVector2D& OtherVector) const
	{
		return (X * OtherVector.X) + (Y * OtherVector.Y);
	}

	//! This operator return the cross product between this vector and other vector.
	float ceVector2D::operator^(const ceVector2D& OtherVector) const
	{
		return (X * OtherVector.Y) - (Y * OtherVector.X);
	}

}