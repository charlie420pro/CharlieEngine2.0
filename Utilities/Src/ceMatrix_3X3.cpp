#include "ceMatrix_3X3.h"


namespace ceEngineSDK
{
	ceMatrix_3X3::ceMatrix_3X3()
	{

	}

	ceMatrix_3X3::ceMatrix_3X3(float fX0, float fY0, float fZ0,
		float fX1, float fY1, float fZ1,
		float fX2, float fY2, float fZ2)
	{
		m.X0 = fX0, m.Y0 = fY0, m.Z0 = fZ0;
		m.X1 = fX1, m.Y1 = fY1, m.Z1 = fZ1;
		m.X2 = fX2, m.Y2 = fY2, m.Z2 = fZ2;
	}

	ceMatrix_3X3::~ceMatrix_3X3()
	{
	}

	ceMatrix_3X3 ceMatrix_3X3::operator+(const ceMatrix_3X3& M)
	{
		return ceMatrix_3X3(m.X0 + M.m.X0, m.Y0 + M.m.Y0, m.Z0 + M.m.Z0,
			m.X1 + M.m.X1, m.Y1 + M.m.Y1, m.Z1 + M.m.Z1,
			m.X2 + M.m.X2, m.Y2 + M.m.Y2, m.Z2 + M.m.Z2);
	}

	ceMatrix_3X3 ceMatrix_3X3::operator-(const ceMatrix_3X3& M)
	{
		return ceMatrix_3X3(m.X0 - M.m.X0, m.Y0 - M.m.Y0, m.Z0 - M.m.Z0,
			m.X1 - M.m.X1, m.Y1 - M.m.Y1, m.Z1 - M.m.Z1,
			m.X2 - M.m.X2, m.Y2 - M.m.Y2, m.Z2 - M.m.Z2);
	}

	ceMatrix_3X3 ceMatrix_3X3::operator*(const ceMatrix_3X3 & M)
	{
		int32 i, j, k;
		///inicializamos en 0 la matriz.
		ceMatrix_3X3 R = Zero();

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				for (k = 0; k < 3; k++)
				{
					R.LikeMatrix[i][j] += LikeMatrix[j][k] * M.LikeMatrix[k][i];
				}
			}
		}

		return R;
	}

	ceMatrix_3X3 ceMatrix_3X3::operator*(float fValue)
	{
		return ceMatrix_3X3(m.X0 * fValue, m.Y0 * fValue, m.Z0 * fValue,
			m.X1 * fValue, m.Y1 * fValue, m.Z1 * fValue,
			m.X2 * fValue, m.Y2 * fValue, m.Z2 * fValue);
	}

	ceMatrix_3X3 ceMatrix_3X3::operator/(float fValue)
	{
		ceMatrix_3X3 R = Zero();

		if (fValue != 0)
		{
			for (int32 i = 0; i < 3; ++i)
			{
				for (int32 j = 0; j < 3; ++j)
				{
					R.LikeMatrix[i][j] = LikeMatrix[i][j] / fValue;
				}
			}
		}

		return R;
	}

	ceMatrix_3X3 ceMatrix_3X3::operator*(const ceVector3D & V)
	{
		ceMatrix_3X3 R = Zero();

		R.m.X0 = m.X0 * V.X + m.X0 * V.Y + m.X0 * V.Z;
		R.m.Y0 = m.Y0 * V.X + m.Y0 * V.Y + m.Y0 * V.Z;
		R.m.Z0 = m.Z0 * V.X + m.Z0 * V.Y + m.Z0 * V.Z;

		R.m.X1 = m.X1 * V.X + m.X1 * V.Y + m.X1 * V.Z;
		R.m.Y1 = m.Y1 * V.X + m.Y1 * V.Y + m.Y1 * V.Z;
		R.m.Z1 = m.Z1 * V.X + m.Z1 * V.Y + m.Z1 * V.Z;

		R.m.X2 = m.X2 * V.X + m.X2 * V.Y + m.X2 * V.Z;
		R.m.Y2 = m.Y2 * V.X + m.Y2 * V.Y + m.Y2 * V.Z;
		R.m.Z2 = m.Z2 * V.X + m.Z2 * V.Y + m.Z2 * V.Z;

		return R;
	}

	ceMatrix_3X3 ceMatrix_3X3::operator*=(const ceVector3D & V)
	{
		return *this = *this * V;
	}

	ceMatrix_3X3& ceMatrix_3X3::operator+=(const ceMatrix_3X3 & M)
	{
		return *this = *this + M;
	}

	ceMatrix_3X3& ceMatrix_3X3::operator-=(const ceMatrix_3X3 & M)
	{
		return *this = *this - M;
	}

	ceMatrix_3X3& ceMatrix_3X3::operator*=(const ceMatrix_3X3& M)
	{
		return *this = *this * M;
	}

	bool ceMatrix_3X3::operator==(ceMatrix_3X3 M)
	{
		///contador que nos indica si coincidieron todas las casillas.
		int32 count = 0;

		for (int32 i = 0; i < 3; i++)
		{
			for (int32 j = 0; j < 3; j++)
			{
				if (LikeMatrix[i][j] == M.LikeMatrix[i][j])
				{
					count++;
				}
			}
		}

		return (count == 9);
	}

	ceMatrix_3X3 ceMatrix_3X3::Zero()
	{
		ceMatrix_3X3 mZero;
		for (int32 i = 0; i < 9; ++i)
			mZero.LikeArray[i] = 0;
		return mZero;
	}

	ceMatrix_3X3 ceMatrix_3X3::Identity()
	{
		ceMatrix_3X3 identity;
		identity = Zero();
		identity.m.X0 = 1;
		identity.m.Y1 = 1;
		identity.m.Z2 = 1;
		return identity;
	}

	ceMatrix_3X3 ceMatrix_3X3::Transpose(const ceMatrix_3X3 & A)
	{
		ceMatrix_3X3 MatTemp;
		MatTemp = Zero();
		for (int32 i = 0; i < 3; ++i)
			for (int32 j = 0; j < 3; ++j)
				MatTemp.LikeMatrix[j][i] = A.LikeMatrix[i][j];
		return MatTemp;
	}

	ceMatrix_3X3 ceMatrix_3X3::RotateX(float fValue)
	{
		ceMatrix_3X3 M;
		M = Identity();
		M.m.Y1 = ceMath::Cos(fValue);
		M.m.Z1 = -ceMath::Sin(fValue);
		M.m.Y2 = ceMath::Sin(fValue);
		M.m.Z2 = ceMath::Cos(fValue);
		return M;
	}

	ceMatrix_3X3 ceMatrix_3X3::RotateY(float fValue)
	{
		ceMatrix_3X3 M;
		M = Identity();
		M.m.X0 = ceMath::Cos(fValue);
		M.m.Z0 = ceMath::Sin(fValue);
		M.m.X2 = -ceMath::Sin(fValue);
		M.m.Z2 = ceMath::Cos(fValue);
		return M;
	}

	ceMatrix_3X3 ceMatrix_3X3::RotateZ(float fValue)
	{
		ceMatrix_3X3 M;
		M = Identity();
		M.m.X0 = ceMath::Cos(fValue);
		M.m.Y0 = -ceMath::Sin(fValue);
		M.m.X1 = ceMath::Sin(fValue);
		M.m.Y1 = ceMath::Cos(fValue);
		return M;
	}


	ceMatrix_3X3 ceMatrix_3X3::Rotate(float fValue)
	{
		return (RotateX(fValue) * RotateY(fValue) * RotateZ(fValue));
	}

	ceMatrix_3X3 ceMatrix_3X3::Translation(const ceVector3D & V)
	{
		return ceMatrix_3X3(1, 0, 0,
			0, 1, 0,
			V.X, V.Y, V.Z);
	}

	ceMatrix_3X3 ceMatrix_3X3::Scaling(const ceVector3D & V)
	{
		return ceMatrix_3X3(V.X, 0, 0,
			0, V.Y, 0,
			0, 0, V.Z);
	}

	void ceMatrix_3X3::Inverse()
	{
		float determinante = 0;
		ceMatrix_3X3 TransposedMatrix;
		ceMatrix_3X3 AdjunctedMatrix;

		/// Calculate the determinante.
		determinante =
			(LikeMatrix[0][0] * LikeMatrix[1][1] * LikeMatrix[2][2]) +
			(LikeMatrix[0][2] * LikeMatrix[1][0] * LikeMatrix[2][1]) +
			(LikeMatrix[2][0] * LikeMatrix[0][1] * LikeMatrix[1][2]) -
			(LikeMatrix[2][0] * LikeMatrix[1][1] * LikeMatrix[0][2]) -
			(LikeMatrix[0][0] * LikeMatrix[1][2] * LikeMatrix[2][1]) -
			(LikeMatrix[2][2] * LikeMatrix[0][1] * LikeMatrix[1][0]);

		/// Check if we can draw the inverse.
		if (determinante != 0)
		{

			/// Calculated the transpose.
			TransposedMatrix = Transpose(*this);
			///We calculated the enclosed matrix once it was transposed.
			AdjunctedMatrix = Adjunct(TransposedMatrix);

			*this = AdjunctedMatrix / determinante;
		}
	}

	//! 
	ceMatrix_3X3 ceMatrix_3X3::Adjunct(ceMatrix_3X3 M)
	{
		ceMatrix_3X3 adjunct;
		/// Initialize the matrix adjunct like 0.
		adjunct = Zero();

		///We calculate each place of the adjunct.
		for (int32 i = 0; i < 3; ++i)
			for (int32 j = 0; j < 3; ++j)
				adjunct.LikeMatrix[i][j] = Determinant(M, i, j);

		///return the adjunct matrix.
		return adjunct;
	}

	//! 
	float ceMatrix_3X3::Determinant(ceMatrix_3X3 M, int32 iCol, int32 iRow)
	{

		float fValues[4];
		///contador para llenar fValues
		int32 iCount = 0;

		///guardamos los valores que no están en la columna ni en la fila dada.	
		for (int32 i = 0; i < 3; ++i)
			for (int32 j = 0; j < 3; ++j)
			{
				if (i != iCol && j != iRow)
				{
					fValues[iCount] = M.LikeMatrix[i][j];
					iCount++;
				}
			}

		///Calculamos la adjunta del lugar dado.
		float fElevated = ceMath::Pow(-1.0f, (float)((iCol + 1) + (iRow + 1)));
		return fElevated * (fValues[0] * fValues[3] - fValues[1] * fValues[2]);
	}

}