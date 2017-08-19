#pragma once
#include "ceMath.h"
#include "ceVector3D.h"

namespace ceEngineSDK
{
	/**
	*	@brief This class is a 3 dimensional matrix.
	*/
	class CE_UTILITY_EXPORT ceMatrix_3X3
	{
	public:

		///**************************************************************************/
		///*						  Member Variables.								*/
		///**************************************************************************/

		union
		{
			struct
			{
				float X0, Y0, Z0,
					X1, Y1, Z1,
					X2, Y2, Z2;
			}m;

			float LikeArray[9];
			float LikeMatrix[3][3];
		};

		///************************************************************************/
		///*                            Constructor & Destructor.                 */
		///************************************************************************/

		/**
		*	@brief Default Constructor.
		*/
		ceMatrix_3X3();

		/**
		*	@brief Default Destructor.
		*/
		~ceMatrix_3X3();

		/**
		*	@brief Constructor based on parameters.
		*/
		ceMatrix_3X3(float fX0, float fY0, float fZ0,
			float fX1, float fY1, float fZ1,
			float fX2, float fY2, float fZ2);

		///************************************************************************/
		///*						Arithmetic Operators.				           */
		///************************************************************************/

		/**
		*	@brief This is an operator that uses + between 2 matrices.
		*	@param const ceMatrix_3X3& M: The matrix to add.
		*	@return the result of the addition.
		*/
		ceMatrix_3X3 operator+(const ceMatrix_3X3& M);

		/**
		*	@brief This is an operator that uses - between 2 matrices.
		*	@param const ceMatrix_3X3& M: The matrix to substract.
		*	@return the result of the substraction.
		*/
		ceMatrix_3X3 operator-(const ceMatrix_3X3& M);

		/**
		*	@brief This is an operator that uses * between 2 matrices.
		*	@param const ceMatrix_3X3& M: The matrix to multiply.
		*	@return the result of the multiplication.
		*/
		ceMatrix_3X3 operator*(const ceMatrix_3X3& M);

		/**
		*	@brief This is an operator that uses * between a matrix and a float.
		*	@param float value: The value to multiply the matrix.
		*	@return the result of the multiplication.
		*/
		ceMatrix_3X3 operator*(float Value);

		/**
		*	@brief This is an operator that uses / between a matrix and a float.
		*	@param float value: The value to divide the matrix by.
		*	@return the result of the division.
		*/
		ceMatrix_3X3 operator/(float Value);

		/**
		*	@brief This is an operator that uses * between a matrix and a 3D vector.
		*	@param const ceVector3D V: The vector that will multiply the matrix.
		*	@return the result of the multiplication.
		*/
		ceMatrix_3X3 operator*(const ceVector3D& V);

		/**
		*	@brief This is an operator that uses *= between a matrix and a 3D vector.
		*	@param const ceVector3D V: The vector that will multiply the matrix.
		*	@return the result of the multiplication.
		*/
		ceMatrix_3X3 operator*=(const ceVector3D& V);

		/**
		*	@brief This is an operator that uses += between 2 matrices.
		*	@param const ceMatrix_3X3 M: The matrix that will be added.
		*	@return the result of the addition.
		*/
		ceMatrix_3X3& operator+=(const ceMatrix_3X3& M);

		/**
		*	@brief This is an operator that uses -= between 2 matrices.
		*	@param const ceMatrix_3X3 M: The matrix that will be substracted.
		*	@return the result of the substraction.
		*/
		ceMatrix_3X3& operator-=(const ceMatrix_3X3& M);

		/**
		*	@brief This is an operator that uses *= between 2 matrices.
		*	@param const ceMatrix_3X3 M: The matrix that will be multiplied.
		*	@return the result of the multiplication.
		*/
		ceMatrix_3X3& operator*=(const ceMatrix_3X3& M);

		/**
		*	@brief This is an operator that uses == between 2 matrices.
		*	@param ceMatrix_3X3 M: The matrix that will be compared.
		*	@return true if both matrices are the same.
		*/
		bool operator==(ceMatrix_3X3 M);

		///************************************************************************/
		///*						   Class Functions.							  */
		///************************************************************************/

		/**
		*	@brief Used to equalize a matrix to 0.
		*	@return A new matrix with all it's components assigned to 0.
		*/
		static ceMatrix_3X3 Zero();

		/**
		*	@brief Used to equalize a matrix to it's identity.
		*	@return A new identity matrix.
		*/
		static ceMatrix_3X3 Identity();

		/**
		*	@brief Rotates a matrix on the X axis.
		*	@param float fValue: The angle to rotate the matrix.
		*	@return The rotated matrix.
		*/
		static ceMatrix_3X3 RotateX(float fValue);

		/**
		*	@brief Rotates a matrix on the Y axis.
		*	@param float fValue: The angle to rotate the matrix.
		*	@return The rotated matrix.
		*/
		static ceMatrix_3X3 RotateY(float fValue);

		/**
		*	@brief Rotates a matrix on the Z axis.
		*	@param float fValue: The angle to rotate the matrix.
		*	@return The rotated matrix.
		*/
		static ceMatrix_3X3 RotateZ(float fValue);

		/**
		*	@brief Rotates a matrix on all of the axis.
		*	@param float fValue: The angle to rotate each axis of the matrix.
		*	@return The rotated matrix.
		*/
		static ceMatrix_3X3 Rotate(float fValue);

		/**
		*	@brief Transposes a matrix.
		*	@param const ceMatrix_3X3 A: The matrix to be transposed.
		*	@return The transposed matrix.
		*/
		ceMatrix_3X3 Transpose(const ceMatrix_3X3& A);

		/**
		*	@brief Calculates the adjunct of a given matrix.
		*	@param ceMatrix_3X3 M: The matrix to be adjuncted.
		*	@return The adjuncted matrix.
		*/
		ceMatrix_3X3 Adjunct(ceMatrix_3X3 M);

		/**
		*	@brief Calculates the inverse of the matrix.
		*/
		void Inverse();

		/**
		*	@brief Calculates the determinant of a given matrix.
		*	@param ceMatrix_3X3 M: The matrix used for the determinant.
		*	@param int32 iCol: The column that will be ignored.
		*	@param int32 iRow: The row that will be ignored.
		*	@return The value for the place given of the matrix.
		*/
		float Determinant(ceMatrix_3X3 M, int32 iCol, int32 iRow);

		/**
		*	@brief Translades a matrix in a 3D space.
		*	@param const ceVector3D V: The position where we want to move the matrix.
		*	@return The translated matrix.
		*/
		ceMatrix_3X3 Translation(const ceVector3D& V);

		/**
		*	@brief Scales a matrix.
		*	@param ceVector3D V: The scale that we want for the matrix.
		*	@return The sclaed matrix.
		*/
		ceMatrix_3X3 Scaling(const ceVector3D& V);
	};
}

