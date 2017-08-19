#pragma once
#include "ceMath.h"
#include "ceVector4D.h"

namespace ceEngineSDK
{
	///**************************************************************************/
	///*						  Forward Declarations.							*/
	///**************************************************************************/
	class ceVector4D;
	class ceVector3D;

	/**
	*	@brief This class is a 4 dimensional matrix.
	*/
	class CE_UTILITY_EXPORT ceMatrix_4X4
	{
	public:

		///**************************************************************************/
		///*						  Member Variables.								*/
		///**************************************************************************/
		union
		{
			struct
			{

				float X0, Y0, Z0, W0,
					X1, Y1, Z1, W1,
					X2, Y2, Z2, W2,
					X3, Y3, Z3, W3;
			}m;
			float LikeArray[16];
			float LikeMatrix[4][4];
		};

		///************************************************************************/
		///*                            Constructor & Destructor.                 */
		///************************************************************************/

		/**
		*	@brief Default Constructor.
		*/
		ceMatrix_4X4();

		/**
		*	@brief Default destructor.
		*/
		~ceMatrix_4X4();

		/**
		*	@brief Constructor with parameters.
		*/
		ceMatrix_4X4(float fX0, float fY0, float fZ0, float fW0,
			float fX1, float fY1, float fZ1, float fW1,
			float fX2, float fY2, float fZ2, float fW2,
			float fX3, float fY3, float fZ3, float fW3);

		///************************************************************************/
		///*						Arithmetic Operators.				           */
		///************************************************************************/

		/**
		*	@brief This is an operator that uses + between 2 matrices.
		*	@param const ceMatrix_4X4& M: The matrix to add.
		*	@return the result of the addition.
		*/
		ceMatrix_4X4 operator+(const ceMatrix_4X4& M);

		/**
		*	@brief This is an operator that uses - between 2 matrices.
		*	@param const ceMatrix_4X4& M: The matrix to substract.
		*	@return the result of the substraction.
		*/
		ceMatrix_4X4 operator-(const ceMatrix_4X4& M);

		/**
		*	@brief This is an operator that uses * between 2 matrices.
		*	@param const ceMatrix_4X4& M: The matrix to multiply.
		*	@return the result of the multiplication.
		*/
		ceMatrix_4X4 operator*(const ceMatrix_4X4& M);

		/**
		*	@brief This is an operator that uses * between a matrix and a float.
		*	@param float value: The value to multiply the matrix.
		*	@return the result of the multiplication.
		*/
		ceMatrix_4X4 operator*(float Value);

		/**
		*	@brief This is an operator that uses * between a matrix and a 4D vector.
		*	@param const ceVector4D& V: The vector that will multiply the matrix.
		*	@return the result of the multiplication.
		*/
		ceVector4D operator*(const ceVector4D& V);

		/**
		*	@brief This is an operator that uses / between a matrix and a float.
		*	@param float fValue: The value to divide the matrix.
		*	@return the result of the division.
		*/
		ceMatrix_4X4 operator/(float fValue);

		/**
		*	@brief This is an operator that uses += between 2 matrices.
		*	@param const ceMatrix_4X4 M: The matrix that will be added.
		*	@return the result of the addition.
		*/
		ceMatrix_4X4& operator+=(const ceMatrix_4X4& M);

		/**
		*	@brief This is an operator that uses -= between 2 matrices.
		*	@param const ceMatrix_4X4 M: The matrix that will be substracted.
		*	@return the result of the substraction.
		*/
		ceMatrix_4X4& operator-=(const ceMatrix_4X4& M);

		/**
		*	@brief This is an operator that uses *= between 2 matrices.
		*	@param const ceMatrix_4X4 M: The matrix that will be multiplied.
		*	@return the result of the multiplication.
		*/
		ceMatrix_4X4& operator*=(const ceMatrix_4X4& M);

		/**
		*	@brief Transposes a matrix.
		*	@return The transposed matrix.
		*/
		ceMatrix_4X4 Transposed();

		/**
		*	@brief Used to equalize a matrix to it's identity.
		*	@return A new identity matrix.
		*/
		static ceMatrix_4X4 Identity(void);

		/**
		*	@brief Used to equalize a matrix to 0.
		*	@return A new matrix with all it's components assigned to 0.
		*/
		static ceMatrix_4X4 Zero(void);

		/**
		*	@brief Calculates the perspective field of view.
		*	@param float zNear: the near plane.
		*	@param float zFar: far plane.
		*	@param float FOV: the opening angle.
		*	@param AspectRatio: the width minus the height.
		*/
		void PerspectiveFOVLH(float zNear, float zFar, float FOV, float AspectRatio);

		/**
		*	@brief Calculates the inverse of the matrix.
		*/
		void Inverse();

		/**
		*	@brief Gets the adjunct of a given matrix.
		*	@param ceMatrix_4X4 M: The matrix to calculate the adjunct.
		*/
		static ceMatrix_4X4 GetAdjunct(ceMatrix_4X4 M);

		/**
		*	@brief Gets the determinant of a given matrix on a given position.
		*	@param ceMatrix_4X4 M: The matrix to get the determinant from.
		*	@param int32 col: the column where the determinant is.
		*	@param int32 row: the row where the determinant is.
		*/
		static float GetDeterminant(ceMatrix_4X4 M, int32 col, int32 row);

		/**
		*	@brief Looks at a given target on the desired position.
		*	@param const ceVector4D EyePos: Where the eye will be placed.
		*	@param const ceVector4D Target: Where the eye will be looking at.
		* @param const ceVector4D Up: which axis is going to be upwards.
		*/
		void LookAtLeftH(const ceVector4D EyePos, const ceVector4D Target, const ceVector4D Up);

		/**
		*	@brief Translates a matrix to a given position.
		*	@param const ceVector4D V: The position that we want to translate to.
		*/
		void Translation(const ceVector4D& V);

		/**
		*	@brief Scales the matrix to a given scale.
		*	@param const ceVector4D V: the scale that the matrix will have.
		*/
		void Scaling(const ceVector4D& V);

		/**
		*	@brief Rotates the matrix in the axis given
		*	@param const ceVector4D V: how many angles it will rotate in every axis.
		*	@return The rotated matrix.
		*/
		ceMatrix_4X4 Rotate(const ceVector4D& V);

		/**
		*	@brief Rotates the matrix in the X axis.
		*	@param float fValue: how many angles it will rotate.
		*	@return The rotated matrix.
		*/
		static ceMatrix_4X4 RotateX(float fValue);

		/**
		*	@brief Rotates the matrix in the Y axis.
		*	@param float fValue: how many angles it will rotate.
		*	@return The rotated matrix.
		*/
		static ceMatrix_4X4 RotateY(float fValue);

		/**
		*	@brief Rotates the matrix in the Z axis.
		*	@param float fValue: how many angles it will rotate.
		*	@return The rotated matrix.
		*/
		static ceMatrix_4X4 RotateZ(float fvalue);
	};

}