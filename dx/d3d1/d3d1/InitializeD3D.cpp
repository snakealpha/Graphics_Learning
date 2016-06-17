// Sample code from book <3D Game Programming With DircetX11>

#include <Windows.h>
#include <dxgi.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <iostream>

using namespace std;
using namespace DirectX;

int main()
{
	// Initialize Device and Context
	UINT createDeviceFlags = 0;

#if defined(DEBUG) || defined(_DEBUG)
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	D3D_FEATURE_LEVEL featureLevel;
	ID3D11Device* md3dDevice;
	ID3D11DeviceContext* md3dImmediateContext;
	HRESULT hr = D3D11CreateDevice(
		0,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		createDeviceFlags,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		&md3dDevice,
		&featureLevel,
		&md3dImmediateContext
	);

	if(FAILED(hr))
	{
		MessageBoxW(0, L"D3D11CreateDevice Failed.", 0, 0);
		return 0;
	}

	if(featureLevel != D3D_FEATURE_LEVEL_11_0)
	{
		MessageBoxW(0, L"D3D Level 11 unsupported.", 0, 0);
		return 0;
	}

	// Check feature
	UINT m4xMsaaQuality;
	md3dDevice->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &m4xMsaaQuality);

	char i;
	cin >> i;
}