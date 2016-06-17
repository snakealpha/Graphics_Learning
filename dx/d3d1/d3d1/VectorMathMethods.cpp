// Sample code from book <3D Game Programming With DircetX11>

#include <Windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>

using  namespace std;
using namespace DirectX;

ostream& operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);
	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

int v_main()
{
	cout.setf(ios_base::boolalpha);

	// Check CPU support of SSE2
	if(!XMVerifyCPUSupport())
	{
		cout << "XNA Math not support" << endl;
		return 0;
	}

	XMVECTOR n = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR p = XMVectorZero();
	XMVECTOR q = XMVectorSplatOne();
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorReplicate(-2.0f);
	XMVECTOR w = XMVectorSplatZ(u);

	XMVECTOR a = u + v;
	XMVECTOR b = u - v;
	XMVECTOR c = 10.0f*u;
	XMVECTOR L = XMVector3Length(u);
	XMVECTOR d = XMVector3Normalize(u);
	XMVECTOR s = XMVector3Dot(u, v);
	XMVECTOR e = XMVector3Cross(u, v);

	XMVECTOR t = XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);
	XMVECTOR projT, perpT;
	XMVector3ComponentsFromNormal(&projT, &perpT, t, n);
	bool equal = XMVector3Equal(projT + perpT, t) != 0;
	bool notEqual = XMVector3NotEqual(projT + perpT, t) != 0;
	XMVECTOR angleVec = XMVector3AngleBetweenVectors(projT, perpT);
	float angleRadians = XMVectorGetX(angleVec);
	float angleDegrees = XMConvertToDegrees(angleRadians);

	return 0;
}