
#include <cePrerequisitesUtil.h>
#include <ceMath.h>
#include <ceVector3D.h>

using namespace ceEngineSDK;


int main()
{
	ceVector3D vect1(2, 2, 2);
	ceVector3D vect2(3, 4, 6);
	ceVector3D result = vect2 - vect1;

	assert(result == ceVector3D(1, 2, 4));

	return 0;
}