// Sample code from book <3D Game Programming With DircetX11>

#include <Windows.h>
#include <DirectXMath.h>
#include <iostream>

using namespace std;
using namespace DirectX;

int m_main()
{
	cout.setf(ios_base::boolalpha);

	if(!XMVerifyCPUSupport())
	{
		cout << "Need support of SSE2";
		return 0;
	}

	XMMATRIX A(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 4.0f, 0.0f,
		1.0f, 2.0f, 3.0f, 1.0f
	);

	auto B = XMMatrixIdentity();
	auto C = A * B;
	auto D = XMMatrixTranspose(A);
	auto det = XMMatrixDeterminant(A);
	auto E = XMMatrixInverse(&det, A);
	auto F = A * E;

	return 0;
}