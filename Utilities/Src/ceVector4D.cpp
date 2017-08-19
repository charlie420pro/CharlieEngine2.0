#include "ceVector4D.h"


namespace ceEngineSDK
{
	//! Default Constructor.
	ceVector4D::ceVector4D()
	{

	}

	//! Parameters Constructor.
	ceVector4D::ceVector4D(float InX, float InY, float InZ, float InW) : X(InX), Y(InY), Z(InZ), W(InW)
	{

	}

	//! Default Destructor.
	ceVector4D::~ceVector4D()
	{

	}

	//! This function return the magnitud of the vector given in the parameter.
	float ceVector4D::Magnitud(const ceVector4D & OtherVector)
	{
		return sqrt(pow(OtherVector.X, 2) +
			pow(OtherVector.Y, 2) +
			pow(OtherVector.Z, 2) +
			pow(OtherVector.W, 2));
	}

	//! This function realize the dot product between 2 vectors.
	float ceVector4D::Dot(const ceVector4D& OtherVector)
	{
		float escalar = (this->X * OtherVector.X) +
			(this->Y * OtherVector.Y) +
			(this->Z * OtherVector.Z) +
			(this->W * OtherVector.W);

		if (escalar <= ceMath::DELTA && escalar >= 0 - ceMath::DELTA)
		{
			escalar = 0;
		}

		return escalar;
	}

	//! This function return a perpendicular vector between 2 vectors.
	ceVector4D ceVector4D::Cross(const ceVector4D & VectorA, const ceVector4D & VectorB)
	{
		return ceVector4D((VectorA.Y * VectorB.Z - VectorA.Z * VectorB.Y),
			(VectorA.Z * VectorB.X - VectorA.X * VectorB.Z),
			(VectorA.X * VectorB.Y - VectorA.Y * VectorB.X),
			0);
	}

	//! This function reduce the magnitud of the vector given between 0 and 1.
	ceVector4D ceVector4D::Normalize(const ceVector4D & OtherVector)
	{
		return OtherVector / Magnitud(OtherVector);
	}

	//! This function compares if 2 vectors are the same.
	bool ceVector4D::Equals(const ceVector4D& OtherVector, float fTolerance) const
	{
		return	abs(X - OtherVector.X) < fTolerance &&
			abs(Y - OtherVector.Y) < fTolerance &&
			abs(Z - OtherVector.Z) < fTolerance &&
			abs(W - OtherVector.W) < fTolerance;
	}

	//! This is an operator to use + between 2 vectors.
	ceVector4D ceVector4D::operator+(const ceVector4D& OtherVector) const
	{
		return ceVector4D(X + OtherVector.X,
			Y + OtherVector.Y,
			Z + OtherVector.Z,
			W + OtherVector.W);
	}

	//! This is an operator to use - between 2 vectors.
	ceVector4D ceVector4D::operator-(const ceVector4D& OtherVector) const
	{
		return ceVector4D(X - OtherVector.X,
			Y - OtherVector.Y,
			Z - OtherVector.Z,
			W - OtherVector.W);
	}

	//! This is an operator to use * between 1 vector and 1 scalar value.
	ceVector4D ceVector4D::operator*(float Value) const
	{
		return ceVector4D(X * Value,
			Y * Value,
			Z * Value,
			W * Value);
	}

	//! This is an operator to use * between 2 vectors.
	ceVector4D ceVector4D::operator*(const ceVector4D& OtherVector) const
	{
		return ceVector4D(X * OtherVector.X,
			Y * OtherVector.Y,
			Z * OtherVector.Z,
			W * OtherVector.W);
	}

	//! This is an operator to use / between 1 vector and 1 scalar value.
	ceVector4D ceVector4D::operator/(float Value) const
	{
		const float RValue = 1.f / Value;
		return ceVector4D(X * RValue,
			Y * RValue,
			Z * RValue,
			W * RValue);
	}

	//! This is an operator to use / between 2 vectors.
	ceVector4D ceVector4D::operator/(const ceVector4D& OtherVector) const
	{
		return ceVector4D(X / OtherVector.X,
			Y / OtherVector.Y,
			Z / OtherVector.Z,
			W / OtherVector.W);
	}

	//! This operator compares that 2 vectors are the same.
	bool ceVector4D::operator==(const ceVector4D& OtherVector) const
	{
		return	X == OtherVector.X &&
			Y == OtherVector.Y &&
			Z == OtherVector.Z &&
			W == OtherVector.W;
	}

	//! This operator compares that 2 vectors are diferents
	bool ceVector4D::operator!=(const ceVector4D& OtherVector) const
	{
		return	X != OtherVector.X ||
			Y != OtherVector.Y ||
			Z != OtherVector.Z ||
			W != OtherVector.W;
	}

	//! This operator compares that this vector is lesser than other vector.
	bool ceVector4D::operator<(const ceVector4D& OtherVector) const
	{
		return	X < OtherVector.X &&
			Y < OtherVector.Y &&
			Z < OtherVector.Z &&
			W < OtherVector.W;
	}

	//! his operator compares that this vector is greater than other vector.
	bool ceVector4D::operator>(const ceVector4D& OtherVector) const
	{
		return	X > OtherVector.X &&
			Y > OtherVector.Y &&
			Z > OtherVector.Z &&
			W > OtherVector.W;
	}

	//! This operator compares that this vector is lesser or equal than other vector.
	bool ceVector4D::operator<=(const ceVector4D& OtherVector) const
	{
		return	X <= OtherVector.X &&
			Y <= OtherVector.Y &&
			Z <= OtherVector.Z &&
			W <= OtherVector.W;
	}

	//! This operator compares that this vector is greater or equal than other vector.
	bool ceVector4D::operator>=(const ceVector4D& OtherVector) const
	{
		return	X >= OtherVector.X &&
			Y >= OtherVector.Y &&
			Z >= OtherVector.Z &&
			W >= OtherVector.W;
	}

	//! This operator add the values from other vector with this.
	ceVector4D& ceVector4D::operator+=(const ceVector4D& OtherVector)
	{
		X += OtherVector.X;
		Y += OtherVector.Y;
		Z += OtherVector.Z;
		W += OtherVector.W;

		return *this;
	}

	//! This operator subtract the values from other vector with this.
	ceVector4D& ceVector4D::operator-=(const ceVector4D& OtherVector)
	{
		X -= OtherVector.X;
		Y -= OtherVector.Y;
		Z -= OtherVector.Z;
		W -= OtherVector.W;

		return *this;
	}

	//! This operator multiply the values from this vector with a value.
	ceVector4D& ceVector4D::operator*=(float Value)
	{
		X *= Value;
		Y *= Value;
		Z *= Value;
		W *= Value;

		return *this;
	}

	//! This operator divide the values from this vector with a value.
	ceVector4D& ceVector4D::operator/=(float Value)
	{
		const float RV = 1.f / Value;

		X *= RV;
		Y *= RV;
		Z *= RV;
		W *= RV;

		return *this;
	}

	//! This operator multiply the values from other vector with this.
	ceVector4D& ceVector4D::operator*=(const ceVector4D& OtherVector)
	{
		X *= OtherVector.X;
		Y *= OtherVector.Y;
		Z *= OtherVector.Z;
		W *= OtherVector.W;

		return *this;
	}

	//! This operator divide the values from other vector with this.
	ceVector4D& ceVector4D::operator/=(const ceVector4D& OtherVector)
	{
		X /= OtherVector.X;
		Y /= OtherVector.Y;
		Z /= OtherVector.Z;
		W /= OtherVector.W;

		return *this;
	}

	//! his operator return the dot product between this vector and other vector.
	float ceVector4D::operator|(const ceVector4D& OtherVector) const
	{
		return	X * OtherVector.X +
			Y * OtherVector.Y +
			Z * OtherVector.Z +
			W * OtherVector.W;
	}

	//! This operator return the cross product between this vector and other vector.
	float ceVector4D::operator^(const ceVector4D& V) const
	{
		//TODO: Implementar el operador.
		return 0.0f;
	}

}