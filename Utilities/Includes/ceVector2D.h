#pragma once
#include "ceMath.h"


namespace ceEngineSDK
{
	/**
	*	@brief Class to use a Vector in a 2D space.
	*/
	class CE_UTILITY_EXPORT ceVector2D
	{
	public:

		///**************************************************************************/
		///*						  Member Variables.								*/
		///**************************************************************************/

		/**
		*	@brief This variable store the position in X Axis.
		*/
		float X;

		/**
		*	@brief This variable store the position in Y Axis.
		*/
		float Y;

		///************************************************************************/
		///*                            Constructor & Destructor.                 */
		///************************************************************************/

		/**
		* @brief Constructor default.
		*/
		ceVector2D();

		/**
		*	@brief Constructor with parameters.
		*	@param float fPosX: Position in X axis.
		*	@param float fPosY: Position in Y axis.
		*/
		ceVector2D(float InX, float InY);

		/**
		* @brief Destructor default.
		*/
		~ceVector2D();


		///************************************************************************/
		///*						   Class Functions.							  */
		///************************************************************************/

		/**
		*	@brief This function return the magnitud of the vector given in the parameter.
		*	@param const ceVector2D& OtherVector: The vector.
		*	@return the magnitud of the vector.
		*/
		float Magnitud(const ceVector2D& OtherVector);

		/**
		*	@brief This function realize the dot product between 2 vectors.
		*	@param const ceVector2D& VectorA:
		*	@param const ceVector2D& VectorB:
		*	@return The projection from VectorA with VectorB.
		*/
		float Dot(const ceVector2D& VectorA, const ceVector2D& VectorB);

		/**
		*	@brief This function reduce the magnitud of the vector given between 0 and 1.
		*	@param const ceVector2D& OtherVector: The vector.
		*	@return The normalized vector.
		*/
		ceVector2D Normalize(const ceVector2D& OtherVector);

		///************************************************************************/
		///*						Arithmetic Operators.				          */
		///************************************************************************/

		/**
		*	@brief This is an operator to use + between 2 vectors.
		*	@param const ceVector2D& OtherVector: The vector to Add.
		*	@return the result of the addition.
		*/
		ceVector2D operator+(const ceVector2D& OtherVector) const;

		/**
		*	@brief This is an operator to use - between 2 vectors.
		*	@param const ceVector2D& OtherVector: The vector to subtract.
		*	@return the result of the subtraction.
		*/
		ceVector2D operator-(const ceVector2D& OtherVector) const;

		/**
		*	@brief This is an operator to use * between 1 vector and 1 scalar value.
		*	@param float Value: The value to multiply.
		*	@return the result of the multiplication.
		*/
		ceVector2D operator*(float Value) const;

		/**
		*	@brief This is an operator to use * between 2 vectors.
		*	@param const ceVector2D& OtherVector: The vector to multiply.
		*	@return the result of the multiplication.
		*/
		ceVector2D operator*(const ceVector2D& OtherVector) const;

		/**
		*	@brief This is an operator to use / between 1 vector and 1 scalar value.
		*	@param float Value: The value to divide.
		*	@return the result of the division.
		*/
		ceVector2D operator/(float Value) const;

		/**
		*	@brief This is an operator to use / between 2 vectors.
		*	@param const ceVector2D& OtherVector: The vector to divide.
		*	@return the result of the division.
		*/
		ceVector2D operator/(const ceVector2D& OtherVector) const;


		///************************************************************************/
		///*						Logical Operators.				              */
		///************************************************************************/

		/**
		*	@brief This operator compares that 2 vectors are the same.
		*	@param const ceVector2D& OtherVector: The vector to compare with this.
		*	@return true if the vector is the same that this, if not false.
		*/
		bool operator==(const ceVector2D& OtherVector) const;

		/**
		*	@brief This operator compares that 2 vectors are diferents
		*	@param const ceVector2D& OtherVector: The vector to compare with this.
		*	@return true if the vector is diferent that this, if not, false.
		*/
		bool operator!=(const ceVector2D& OtherVector) const;

		/**
		*	@brief This operator compares that this vector is lesser than other vector.
		*	@param const ceVector2D& OtherVector: The vector to compare with this.
		*	@return true if this vector is lesser than the other vector, if not, false.
		*/
		bool operator<(const ceVector2D& OtherVector) const;

		/**
		*	@brief This operator compares that this vector is greater than other vector.
		*	@param const ceVector2D& OtherVector: The vector to compare with this.
		*	@return true if this vector is greater than the other vector, if not, false.
		*/
		bool operator>(const ceVector2D& OtherVector) const;

		/**
		*	@brief This operator compares that this vector is lesser or equal than other vector.
		*	@param const ceVector2D& OtherVector: The vector to compare with this.
		*	@return true if this vector is lesser or equal than the other vector, if not, false.
		*/
		bool operator<=(const ceVector2D& OtherVector) const;

		/**
		*	@brief This operator compares that this vector is greater or equal than other vector.
		*	@param const ceVector2D& OtherVector: The vector to compare with this.
		*	@return true if this vector is greater or equal than the other vector, if not, false.
		*/
		bool operator>=(const ceVector2D& OtherVector) const;

		/**
		*	@brief This function compares if 2 vectors are the same.
		*	@param const ceVector2D& OtherVector: The vector to compare with this.
		*	@param float fTolerance: This variable is used as a tolerance for considering that 2 vectors are the same.
		*	@return true if this vector is the same that other vector., if not, false.
		*/
		bool Equals(const ceVector2D& OtherVector, float Tolerance) const;


		///************************************************************************/
		///*					Compound Assignment Operators.				      */
		///************************************************************************/

		/**
		*	@brief This operator add the values from other vector with this.
		*	@param const ceVector2D& OtherVector: The vector to add with this.
		*	@return this vector like a reference to actualize it's variables.
		*/
		ceVector2D& operator+=(const ceVector2D& OtherVector);

		/**
		*	@brief This operator subtract the values from other vector with this.
		*	@param const ceVector2D& OtherVector: The vector to subtract with this.
		*	@return this vector like a reference to actualize it's variables.
		*/
		ceVector2D& operator-=(const ceVector2D& OtherVector);

		/**
		*	@brief This operator multiply the values from this vector with a value.
		*	@param float Value: The value to multiply with this.
		*	@return this vector like a reference to actualize it's variables.
		*/
		ceVector2D& operator*=(float Value);

		/**
		*	@brief This operator divide the values from this vector with a value.
		*	@param float Value: The value to divide with this.
		*	@return this vector like a reference to actualize it's variables.
		*/
		ceVector2D& operator/=(float Value);

		/**
		*	@brief This operator multiply the values from other vector with this.
		*	@param const ceVector2D& OtherVector: The vector to multiply with this.
		*	@return this vector like a reference to actualize it's variables.
		*/
		ceVector2D& operator*=(const ceVector2D& OtherVector);

		/**
		*	@brief This operator divide the values from other vector with this.
		*	@param const ceVector2D& OtherVector: The vector to divide with this.
		*	@return this vector like a reference to actualize it's variables.
		*/
		ceVector2D& operator/=(const ceVector2D& OtherVector);

		/**
		*	@brief This operator return the dot product between this vector and other vector.
		*	@param const ceVector2D& OtherVector: The vector to apply the dot product with this.
		*	@return the result of the dot product.
		*/
		float operator|(const ceVector2D& OtherVector) const;

		/**
		*	@brief This operator return the cross product between this vector and other vector.
		*	@param const ceVector2D& OtherVector: The vector to apply the cross product with this.
		*	@return the result of the cross product.
		*/
		float operator^(const ceVector2D& OtherVector) const;
	};

}