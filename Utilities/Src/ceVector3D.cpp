#include "ceMatrix_3X3.h"
#include "ceVector3D.h"

namespace ceEngineSDK
{
	//! Default Constructor.
	ceVector3D::ceVector3D()
	{

	}

	//! Parameters Constructor.
	ceVector3D::ceVector3D(float InX, float InY, float InZ)
	{
		X = InX;
		Y = InY;
		Z = InZ;
	}

	//! Default Destructor.
	ceVector3D::~ceVector3D()
	{

	}

	//! This function return the magnitude of the vector given in the parameter.
	float ceVector3D::Magnitude()
	{
		return sqrt(pow(this->X, 2) +
			pow(this->Y, 2) +
			pow(this->Z, 2));
	}
	//! This function return the magnitude of the vector given in the parameter.
	float ceVector3D::StaticMagnitude(const ceVector3D OtherVector)
	{
		return sqrt(pow(OtherVector.X, 2) +
			pow(OtherVector.Y, 2) +
			pow(OtherVector.Z, 2));
	}

	//! This function realize the dot product between 2 vectors.
	float ceVector3D::Dot(const ceVector3D& VectorA, const ceVector3D& VectorB)
	{
		return VectorA | VectorB;
	}

	//! This function return a perpendicular vector between 2 vectors.
	ceVector3D ceVector3D::Cross3(const ceVector3D& VectorA, const ceVector3D& VectorB)
	{
		return ceVector3D((VectorA.Y * VectorB.Z - VectorA.Z * VectorB.Y),
			(-1 * (VectorA.X * VectorB.Z - VectorA.Z * VectorB.X)),
			(VectorA.X * VectorB.Y - VectorA.Y * VectorB.X));
	}

	//! This function reduce the magnitud of the vector given between 0 and 1.
	void ceVector3D::Normalize()
	{
		*this /= StaticMagnitude(*this);
	}

	//! This function compares if 2 vectors are the same.
	bool ceVector3D::Equals(const ceVector3D& OtherVector, float Tolerance) const
	{
		return	abs(X - OtherVector.X) < Tolerance &&
			abs(Y - OtherVector.Y) < Tolerance &&
			abs(Z - OtherVector.Z) < Tolerance;
	}

	//! This is an operator to use + between 2 vectors.
	ceVector3D ceVector3D::operator+(const ceVector3D& OtherVector) const
	{
		return ceVector3D(X + OtherVector.X,
			Y + OtherVector.Y,
			Z + OtherVector.Z);
	}

	//! This is an operator to use - between 2 vectors.
	ceVector3D ceVector3D::operator-(const ceVector3D& OtherVector) const
	{
		return ceVector3D(X - OtherVector.X,
			Y - OtherVector.Y,
			Z - OtherVector.Z);
	}

	//! This is an operator to use * between 1 vector and 1 scalar value.
	ceVector3D ceVector3D::operator*(float Value) const
	{
		return ceVector3D(X * Value,
			Y * Value,
			Z * Value);
	}

	//! This is an operator to use * between 2 vectors.
	ceVector3D ceVector3D::operator*(const ceVector3D& OtherVector) const
	{
		return ceVector3D(X * OtherVector.X,
			Y * OtherVector.Y,
			Z * OtherVector.Z);
	}

	ceVector3D ceVector3D::operator*(const ceMatrix_3X3 & M)
	{
		return ceVector3D((M.m.X0 * X + M.m.Y0  * X + M.m.Z0 * X),
			              (M.m.X1 * Y + M.m.Y1  *Y + M.m.Z1 * Y),
			              (M.m.X2 * Z + M.m.Y2  *Z + M.m.Z2 * Z));
	}

	//! This is an operator to use / between 1 vector and 1 scalar value.
	ceVector3D ceVector3D::operator/(float Value) const
	{
		const float RScale = 1.f / Value;
		return ceVector3D(X * RScale,
			Y * RScale,
			Z * RScale);
	}

	//! This is an operator to use / between 2 vectors.
	ceVector3D ceVector3D::operator/(const ceVector3D& OtherVector) const
	{
		return ceVector3D(X / OtherVector.X,
			Y / OtherVector.Y,
			Z / OtherVector.Z);
	}

	//! This operator compares that 2 vectors are the same.
	bool ceVector3D::operator==(const ceVector3D& OtherVector) const
	{
		return	X == OtherVector.X &&
			Y == OtherVector.Y &&
			Z == OtherVector.Z;
	}

	//! This operator compares that 2 vectors are diferents.
	bool ceVector3D::operator!=(const ceVector3D& OtherVector) const
	{
		return	X != OtherVector.X ||
			Y != OtherVector.Y ||
			Z != OtherVector.Z;
	}

	//! This operator compares that this vector is lesser than other vector.
	bool ceVector3D::operator<(const ceVector3D& OtherVector) const
	{
		return	X < OtherVector.X &&
			Y < OtherVector.Y &&
			Z < OtherVector.Z;
	}

	//! This operator compares that this vector is greater than other vector.
	bool ceVector3D::operator>(const ceVector3D& OtherVector) const
	{
		return	X > OtherVector.X &&
			Y > OtherVector.Y &&
			Z > OtherVector.Z;
	}

	//! This operator compares that this vector is lesser or equal than other vector.
	bool ceVector3D::operator<=(const ceVector3D& OtherVector) const
	{
		return	X <= OtherVector.X &&
			Y <= OtherVector.Y &&
			Z <= OtherVector.Z;
	}

	//! This operator compares that this vector is greater or equal than other vector.
	bool ceVector3D::operator>=(const ceVector3D& OtherVector) const
	{
		return	X >= OtherVector.X &&
			Y >= OtherVector.Y &&
			Z >= OtherVector.Z;
	}

	//! This operator assigns the values from other vector with this.
	ceVector3D & ceVector3D::operator=(const ceVector3D & OtherVector)
	{
		X = OtherVector.X;
		Y = OtherVector.Y;
		Z = OtherVector.Z;

		return *this;
	}

	//!	This operator add the values from other vector with this.
	ceVector3D& ceVector3D::operator+=(const ceVector3D& OtherVector)
	{
		X += OtherVector.X;
		Y += OtherVector.Y;
		Z += OtherVector.Z;

		return *this;
	}

	//! This operator subtract the values from other vector with this.
	ceVector3D& ceVector3D::operator-=(const ceVector3D& OtherVector)
	{
		X -= OtherVector.X;
		Y -= OtherVector.Y;
		Z -= OtherVector.Z;

		return *this;
	}

	//! This operator multiply the values from this vector with a value.
	ceVector3D& ceVector3D::operator*=(float Value)
	{
		X *= Value;
		Y *= Value;
		Z *= Value;

		return *this;
	}

	ceVector3D & ceVector3D::operator*=(const ceMatrix_3X3 & M)
	{
		return *this = *this * M;
	}

	//! This operator divide the values from this vector with a value.
	ceVector3D& ceVector3D::operator/=(float Value)
	{
		const float RV = 1.f / Value;

		X *= RV;
		Y *= RV;
		Z *= RV;

		return *this;
	}

	//! This operator multiply the values from other vector with this.
	ceVector3D& ceVector3D::operator*=(const ceVector3D& OtherVector)
	{
		X *= OtherVector.X;
		Y *= OtherVector.Y;
		Z *= OtherVector.Z;

		return *this;
	}

	//! This operator divide the values from other vector with this.
	ceVector3D& ceVector3D::operator/=(const ceVector3D& OtherVector)
	{
		X /= OtherVector.X;
		Y /= OtherVector.Y;
		Z /= OtherVector.Z;

		return *this;
	}

	//! This operator return the dot product between this vector and other vector.
	float ceVector3D::operator|(const ceVector3D& OtherVector) const
	{
		return	X * OtherVector.X +
			Y * OtherVector.Y +
			Z * OtherVector.Z;
	}

	//! This operator return the cross product between this vector and other vector.
	float ceVector3D::operator^(const ceVector3D& OtherVector) const
	{
		return ((Y * OtherVector.Z - Z * OtherVector.Y) -
			(X * OtherVector.Z - Z * OtherVector.X) +
			(X * OtherVector.Y - Y * OtherVector.X));
	}
}