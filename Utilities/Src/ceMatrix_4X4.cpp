#include "ceMatrix_3X3.h"
#include "ceMatrix_4X4.h"


namespace ceEngineSDK
{
	ceMatrix_4X4::ceMatrix_4X4()
	{
		//*this = Zero();
	}

	ceMatrix_4X4::ceMatrix_4X4(float fX0, float fY0, float fZ0, float fW0,
		float fX1, float fY1, float fZ1, float fW1,
		float fX2, float fY2, float fZ2, float fW2,
		float fX3, float fY3, float fZ3, float fW3)
	{
		m.X0 = fX0, m.Y0 = fY0, m.Z0 = fZ0, m.W0 = fW0;
		m.X1 = fX1, m.Y1 = fY1, m.Z1 = fZ1, m.W1 = fW1;
		m.X2 = fX2, m.Y2 = fY2, m.Z2 = fZ2, m.W2 = fW2;
		m.X3 = fX3, m.Y3 = fY3, m.Z3 = fZ3, m.W3 = fW3;
	}

	ceMatrix_4X4::~ceMatrix_4X4()
	{

	}

	ceMatrix_4X4 ceMatrix_4X4::operator+(const ceMatrix_4X4& M)
	{
		return ceMatrix_4X4(m.X0 + M.m.X0, m.Y0 + M.m.Y0, m.Z0 + M.m.Z0, m.W0 + M.m.W0,
			m.X1 + M.m.X1, m.Y1 + M.m.Y1, m.Z1 + M.m.Z1, m.W1 + M.m.W1,
			m.X2 + M.m.X2, m.Y2 + M.m.Y2, m.Z2 + M.m.Z2, m.W2 + M.m.W2,
			m.X3 + M.m.X3, m.Y3 + M.m.Y3, m.Z3 + M.m.Z3, m.W3 + M.m.W3);
	}

	ceMatrix_4X4 ceMatrix_4X4::operator-(const ceMatrix_4X4& M)
	{
		return ceMatrix_4X4(m.X0 - M.m.X0, m.Y0 - M.m.Y0, m.Z0 - M.m.Z0, m.W0 - M.m.W0,
			m.X1 - M.m.X1, m.Y1 - M.m.Y1, m.Z1 - M.m.Z1, m.W1 - M.m.W1,
			m.X2 - M.m.X2, m.Y2 - M.m.Y2, m.Z2 - M.m.Z2, m.W2 - M.m.W2,
			m.X3 - M.m.X3, m.Y3 - M.m.Y3, m.Z3 - M.m.Z3, m.W3 - M.m.W3);
	}

	ceMatrix_4X4 ceMatrix_4X4::operator*(const ceMatrix_4X4 & M)
	{
		///enteros que se usan para los for.
		int32 i, j, k;
		///inicializamos en 0 la matriz.
		ceMatrix_4X4 R = Zero();

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				for (k = 0; k < 4; k++)
				{
					R.LikeMatrix[i][j] += LikeMatrix[j][k] * M.LikeMatrix[k][i];
				}
			}
		}

		return R;
	}

	ceMatrix_4X4 ceMatrix_4X4::operator*(float Value)
	{
		return ceMatrix_4X4(m.X0 * Value, m.Y0 * Value, m.Z0 * Value, m.W0 * Value,
			m.X1 * Value, m.Y1 * Value, m.Z1 * Value, m.W1 * Value,
			m.X2 * Value, m.Y2 * Value, m.Z2 * Value, m.W2 * Value,
			m.X3 * Value, m.Y3 * Value, m.Z3 * Value, m.W3 * Value);
	}

	//! Operador para multiplicar la matriz por un vector.
	ceVector4D ceMatrix_4X4::operator*(const ceVector4D& V)
	{
		return ceVector4D((m.X0 * V.X + m.Y0 * V.X + m.Z0 * V.X + m.W0 * V.W),
			(m.X1 * V.Y + m.Y1 * V.Y + m.Z1 * V.Y + m.W1 * V.W),
			(m.X2 * V.Z + m.Y2 * V.Z + m.Z2 * V.Z + m.W2 * V.W),
			(m.X3 * V.Z + m.Y3 * V.Z + m.Z3 * V.Z + m.W3 * V.W));
	}

	ceMatrix_4X4 ceMatrix_4X4::operator/(float fValue)
	{
		ceMatrix_4X4 R = Zero();

		if (fValue != 0)
		{
			for (int32 i = 0; i < 4; ++i)
			{
				for (int32 j = 0; j < 4; ++j)
				{
					R.LikeMatrix[i][j] = LikeMatrix[i][j] / fValue;
				}
			}
		}

		return R;
	}

	ceMatrix_4X4& ceMatrix_4X4::operator+=(const ceMatrix_4X4 & M)
	{
		return *this = *this + M;
	}

	ceMatrix_4X4& ceMatrix_4X4::operator-=(const ceMatrix_4X4 & M)
	{
		return *this = *this - M;
	}

	ceMatrix_4X4& ceMatrix_4X4::operator*=(const ceMatrix_4X4& M)
	{
		return *this = *this * M;
	}

	ceMatrix_4X4 ceMatrix_4X4::Zero(void)
	{
		ceMatrix_4X4 mZero;
		for (int32 i = 0; i < 16; i++)
			mZero.LikeArray[i] = 0;
		return mZero;
	}

	ceMatrix_4X4 ceMatrix_4X4::Identity(void)
	{
		ceMatrix_4X4 identity;
		identity = Zero();
		identity.m.X0 = 1;
		identity.m.Y1 = 1;
		identity.m.Z2 = 1;
		identity.m.W3 = 1;
		return identity;
	}

	ceMatrix_4X4 ceMatrix_4X4::Transposed()
	{
		ceMatrix_4X4 MatTemp;
		for (int32 i = 0; i < 4; ++i)
			for (int32 j = 0; j < 4; ++j)
				MatTemp.LikeMatrix[i][j] = this->LikeMatrix[j][i];

		return MatTemp;
	}

	void ceMatrix_4X4::Inverse()
	{
		float determinante = 0;
		ceMatrix_4X4 TransposedMatrix;
		ceMatrix_4X4 AdjunctedMatrix;

		//TODO: al quitar una columna o una hilera, quedan 4 matrices 3D a las que les
		//Sacamos su determinante.
		/// Calculamos la determinante.
		determinante =
			(LikeMatrix[0][0] * LikeMatrix[1][1] * LikeMatrix[2][2]) + (LikeMatrix[0][2] * LikeMatrix[1][0] * LikeMatrix[2][1]) +
			(LikeMatrix[2][0] * LikeMatrix[0][1] * LikeMatrix[1][2]) - (LikeMatrix[2][0] * LikeMatrix[1][1] * LikeMatrix[0][2]) -
			(LikeMatrix[0][0] * LikeMatrix[1][2] * LikeMatrix[2][1]) - (LikeMatrix[2][2] * LikeMatrix[0][1] * LikeMatrix[1][0]);

		/// Revisamos que se pueda sacar su inversa.
		if (determinante != 0)
		{
			///Es posible
			/// Calculamos la transpuesta.
			TransposedMatrix = Transposed();
			///Calculamos la adjunta de la matriz una vez que ya fue transpuessta.
			AdjunctedMatrix = GetAdjunct(TransposedMatrix);

			*this = AdjunctedMatrix / determinante;
		}
	}

	ceMatrix_4X4 ceMatrix_4X4::GetAdjunct(ceMatrix_4X4 M)
	{
		ceMatrix_4X4 Adjunct;
		/// Inicializamos en 0 la matriz adjunta.
		Adjunct = Zero();

		///Calculamos cada lugar de la adjunta.
		for (int32 i = 0; i < 4; ++i)
			for (int32 j = 0; j < 4; ++j)
				Adjunct.LikeMatrix[i][j] = GetDeterminant(M, i, j);

		///La regresamos.
		return Adjunct;
	}

	float ceMatrix_4X4::GetDeterminant(ceMatrix_4X4 M, int32 col, int32 row)
	{
		///Los valores que hay en la matriz cuando se ignoran la col y la row dada.
		ceMatrix_3X3 determinantMatrix;
		float fValues[9];
		///contador para llenar fValues
		int32 iCount = 0;

		///guardamos los valores que no están en la columna ni en la fila dada.	
		for (int32 i = 0; i < 4; ++i)
			for (int32 j = 0; j < 4; ++j)
			{
				if (i != col && j != row)
				{
					//TODO: meter esto a una matriz 3x3, y calcular el determinante
					// de dicha matriz. Con las determinantes que se obtengan de la
					// matriz 3x3, obtener la determinante de esta matriz 4x4.
					fValues[iCount] = M.LikeMatrix[i][j];
					iCount++;
				}
			}

		///Calculamos la adjunta del lugar dado.
		float fElevated = ceMath::Pow(-1, ((col + 1) + (row + 1)));
		//TODO: corregir esto.
		return fElevated * (fValues[0] * fValues[3] - fValues[1] * fValues[2]);
	}

	void ceMatrix_4X4::PerspectiveFOVLH(float zNear, float zFar, float FOV, float AspectRatio)
	{
		float yScale = 1.0f / ceMath::Tan(FOV * 0.5f);
		float xScale = yScale / AspectRatio;

		this->m.X0 = xScale, this->m.Y0 = 0, this->m.Z0 = 0, this->m.W0 = 0;
		this->m.X1 = 0, this->m.Y1 = yScale, this->m.Z1 = 0, this->m.W1 = 0;
		this->m.X2 = 0, this->m.Y2 = 0, this->m.Z2 = zFar*zNear / (zFar - zNear), this->m.W2 = 1;
		this->m.X3 = 0, this->m.Y3 = 0, this->m.Z3 = -zNear*zFar / (zFar - zNear), this->m.W3 = 0;
	}

	void ceMatrix_4X4::LookAtLeftH(const ceVector4D EyePos, const ceVector4D Target, const ceVector4D Up)
	{
		ceVector4D xDir, yDir, zDir;

		zDir = Target - EyePos;
		zDir = zDir.Normalize(zDir);

		xDir = xDir.Cross(Up, zDir);
		xDir = xDir.Normalize(xDir);

		yDir = zDir.Cross(zDir, xDir);
		yDir = yDir.Normalize(yDir);

		this->m.X0 = xDir.X, this->m.Y0 = yDir.X, this->m.Z0 = zDir.X, this->m.W0 = 0;
		this->m.X1 = xDir.Y, this->m.Y1 = yDir.Y, this->m.Z1 = zDir.Y, this->m.W1 = 0;
		this->m.X2 = xDir.Z, this->m.Y2 = yDir.Z, this->m.Z2 = zDir.Z, this->m.W2 = 0;
		this->m.X3 = -xDir.Dot(EyePos), this->m.Y3 = -yDir.Dot(EyePos), this->m.Z3 = -zDir.Dot(EyePos), this->m.W3 = 1;

	}

	void ceMatrix_4X4::Translation(const ceVector4D & V)
	{
		this->m.X0 = 1, this->m.Y0 = 0, this->m.Z0 = 0, this->m.W0 = 0;
		this->m.X1 = 0, this->m.Y1 = 1, this->m.Z1 = 0, this->m.W1 = 0;
		this->m.X2 = 0, this->m.Y2 = 0, this->m.Z2 = 1, this->m.W2 = 0;
		this->m.X3 = V.X, this->m.Y3 = V.Y, this->m.Z3 = V.Z, this->m.W3 = V.W;
	}

	void ceMatrix_4X4::Scaling(const ceVector4D & V)
	{
		this->m.X0 = V.X, this->m.Y0 = 0, this->m.Z0 = 0, this->m.W0 = 0;
		this->m.X1 = 0, this->m.Y1 = V.Y, this->m.Z1 = 0, this->m.W1 = 0;
		this->m.X2 = 0, this->m.Y2 = 0, this->m.Z2 = V.Z, this->m.W2 = 0;
		this->m.X3 = 0, this->m.Y3 = 0, this->m.Z3 = 0, this->m.W3 = V.W;

	}

	ceMatrix_4X4 ceMatrix_4X4::Rotate(const ceVector4D & V)
	{
		ceMatrix_4X4 FinalRotation;
		FinalRotation = RotateX(V.X) * RotateY(V.Y) * RotateZ(V.Z);

		return FinalRotation;
	}

	//!
	ceMatrix_4X4 ceMatrix_4X4::RotateX(float fValue)
	{
		/// The final rotation.
		ceMatrix_4X4 FR;

		FR.m.X0 = 1, FR.m.Y0 = 0, FR.m.Z0 = 0, FR.m.W0 = 0;
		FR.m.X1 = 0, FR.m.Y1 = ceMath::Cos(fValue), FR.m.Z1 = ceMath::Sin(fValue), FR.m.W1 = 0;
		FR.m.X2 = 0, FR.m.Y2 = -ceMath::Sin(fValue), FR.m.Z2 = ceMath::Cos(fValue), FR.m.W2 = 0;
		FR.m.X3 = 0, FR.m.Y3 = 0, FR.m.Z3 = 0, FR.m.W3 = 1;

		return FR;
	}

	//!
	ceMatrix_4X4 ceMatrix_4X4::RotateY(float fValue)
	{
		/// The final rotation.
		ceMatrix_4X4 FR;

		FR.m.X0 = ceMath::Cos(fValue), FR.m.Y0 = 0, FR.m.Z0 = -ceMath::Sin(fValue), FR.m.W0 = 0;
		FR.m.X1 = 0, FR.m.Y1 = 1, FR.m.Z1 = 0, FR.m.W1 = 0;
		FR.m.X2 = ceMath::Sin(fValue), FR.m.Y2 = 0, FR.m.Z2 = ceMath::Cos(fValue), FR.m.W2 = 0;
		FR.m.X3 = 0, FR.m.Y3 = 0, FR.m.Z3 = 0, FR.m.W3 = 1;

		return FR;
	}

	//! 
	ceMatrix_4X4 ceMatrix_4X4::RotateZ(float fValue)
	{
		/// The final rotation.
		ceMatrix_4X4 FR;

		FR.m.X0 = ceMath::Cos(fValue), FR.m.Y0 = ceMath::Sin(fValue), FR.m.Z0 = 0, FR.m.W0 = 0;
		FR.m.X1 = -ceMath::Sin(fValue), FR.m.Y1 = ceMath::Cos(fValue), FR.m.Z1 = 0, FR.m.W1 = 0;
		FR.m.X2 = 0, FR.m.Y2 = 0, FR.m.Z2 = 1, FR.m.W2 = 0;
		FR.m.X3 = 0, FR.m.Y3 = 0, FR.m.Z3 = 0, FR.m.W3 = 1;

		return FR;
	}

}