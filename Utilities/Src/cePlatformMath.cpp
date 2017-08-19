#include "cePlatformMath.h"

#include <limits>

namespace ceEngineSDK
{
	const float cePlatformMath::PI = std::atan(1.f) * 4.f;	// ó  3.1415926535897932f;	//! Definicion de Pi constante.
	const float cePlatformMath::EULERS = (2.71828182845904523536f);	//! Definicion de Euler constante.
	const float cePlatformMath::PI_INV = 1.0f/cePlatformMath::PI;			//! Definicion de la inversa de Pi constante.
	const float cePlatformMath::PI_HALF = cePlatformMath::PI / 2.0f;			//! Definicion de la mitad de Pi constante.
	const float cePlatformMath::PI2 = cePlatformMath::PI * 2;
	const float cePlatformMath::INFINITE_NUM = std::numeric_limits<float>::infinity();						//! Definicion de un numero infinito.
	const float cePlatformMath::INVALIDATE_NUM = 0;
	const float cePlatformMath::DELTA = 0.00001f;
	const float cePlatformMath::EPSILON = std::numeric_limits<float>::epsilon();
	const float cePlatformMath::LARGE_NUM = (3.4e+38f);
	const float cePlatformMath::SMALL_NUM = (1.e-8f);
	const float cePlatformMath::MAX_FLOAT_PRESITION = 0.00000001f;
}
