#pragma once

/**
* Includes
**/
#include "cePrerequisitesUtil.h"

namespace ceEngineSDK
{

	class CE_UTILITY_EXPORT  cePlatformMath
	{
	public:
		/**
		 * Constantes basicas
		 **/
		static const float PI;	// ó  3.1415926535897932f;	//! Definicion de Pi constante.
		static const float EULERS;	//! Definicion de Euler constante.
		static const float PI_INV;			//! Definicion de la inversa de Pi constante.
		static const float PI_HALF;			//! Definicion de la mitad de Pi constante.
		static const float PI2;
		static const float INFINITE_NUM;						//! Definicion de un numero infinito.
		static const float INVALIDATE_NUM;
		static const float DELTA;
		static const float EPSILON;
		static const float LARGE_NUM;
		static const float SMALL_NUM;
		static const float MAX_FLOAT_PRESITION;


		/************************************************************************/
		/* Funciones Basicas                                                    */
		/************************************************************************/
		static FORCEINLINE float Sqrt(float Value) { return sqrtf(Value); }
		static FORCEINLINE float InvSqrt(float F) { return 1.0f / sqrtf(F); }
		static FORCEINLINE float Exp(float Value) { return expf(Value); }
		static FORCEINLINE float Pow(float A, float B) { return powf(A, B); }
		static FORCEINLINE float Loge(float Value) { return logf(Value); }
		static FORCEINLINE float LogX(float Base, float Value) { return Loge(Value) / Loge(Base); }


		static FORCEINLINE int32 Trunc(float F) { return (int32)F; }	//! Trunca un entero a 32 bits.
		static FORCEINLINE float TruncFloat(float F) { return (float)Trunc(F); }	//! Trunca un flotante a 32 bits.
		static FORCEINLINE int32 Floor(float F) { return Trunc(floorf(F)); }
		static FORCEINLINE int32 Round(float F) { return Floor(F + 0.5f); }
		static FORCEINLINE int32 Ceil(float F) { return Trunc(ceilf(F)); }

		/************************************************************************/
		/*Funciones Trigonometricas                                             */
		/************************************************************************/

		static FORCEINLINE float Sin(float Value) { return sinf(Value); }
		static FORCEINLINE float Cos(float Value) { return cosf(Value); }
		static FORCEINLINE float Tan(float Value) { return tanf(Value); }

		static FORCEINLINE float Asin(float Value) { return asinf((Value < -1.f) ? -1.f : ((Value < 1.f) ? Value : 1.f)); }
		static FORCEINLINE float Acos(float Value) { return acosf((Value < -1.f) ? -1.f : ((Value < 1.f) ? Value : 1.f)); }
		static FORCEINLINE float Atan(float Value) { return atanf(Value); }


		/************************************************************************/
		/* Funcion para sacar el valor absoluto                                 */
		/************************************************************************/
		template< class T >
		static FORCEINLINE T Abs(const T A)
		{
			return (A >= (T)0) ? A : -A;
		}

		/************************************************************************/
		/* Funcion para sacar el valor maximo entre 2 valores					*/
		/************************************************************************/
		template< class T >
		static FORCEINLINE T Max(const T A, const T B)
		{
			return (A >= B) ? A : B;
		}
		/************************************************************************/
		/*Saca el valor minimo entre 2 valores									*/
		/************************************************************************/
		template< class T >
		static FORCEINLINE T Min(const T A, const T B)
		{
			return (A <= B) ? A : B;
		}
		/************************************************************************/
		/*Saca el valor maximo de 3 valores										*/
		/************************************************************************/
		template< class T >
		static FORCEINLINE T Max3(const T A, const T B, const T C)
		{
			return Max(Max(A, B), C);
		}
		/************************************************************************/
		/*Saca el valor minimo de 3 valores										*/
		/************************************************************************/
		template< class T >
		static FORCEINLINE T Min3(const T A, const T B, const T C)
		{
			return Min(Min(A, B), C);
		}
		/************************************************************************/
		/* Funcion clamp														*/
		/************************************************************************/
		template< class T >
		static FORCEINLINE T Clamp(const T X, const T Min, const T Max)
		{
			return X < Min ? Min : X < Max ? X : Max;
		}
		/************************************************************************/
		/* Funcion para interpolacion lineal									*/
		/************************************************************************/
		template<class T>
		static FORCEINLINE T Lerp(const T A, const T B, const T Time)
		{
			return A + (B - A)* Time;
		}
		/************************************************************************/
		/* Funcion para interpolacion esferica									*/
		/************************************************************************/
		template<class T>
		static FORCEINLINE T Slerp(const T A, const T B, const T Time)
		{
			return Sqrt(A) + (Sqrt(B) - Sqrt(A))* Time;
		}
	};
}
