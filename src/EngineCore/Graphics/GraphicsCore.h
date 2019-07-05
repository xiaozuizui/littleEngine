#pragma once
#include "CommandContext.h"


#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")


namespace littleEngine
{
	namespace Graphics
	{
#ifndef RELEASE
		extern const GUID WKPDID_D3DDebugObjectName;
#endif

		using namespace Microsoft::WRL;

		void Initialize(void);
		void Resize(uint32_t width, uint32_t height);
		void Terminate(void);
		void Shutdown(void);
		void Present(void);

		extern uint32_t g_DisplayWidth;
		extern uint32_t g_DisplayHeight;

		// Returns the number of elapsed frames since application start
		uint64_t GetFrameCount(void);

		// The amount of time elapsed during the last completed frame.  The CPU and/or
		// GPU may be idle during parts of the frame.  The frame time measures the time
		// between calls to present each frame.
		float GetFrameTime(void);

		// The total number of frames per second
		float GetFrameRate(void);

		extern ID3D12Device* g_Device;
		extern CommandListManager g_CommandManager;
		extern ContextManager g_ContextManager;

		extern D3D_FEATURE_LEVEL g_D3DFeatureLevel;

		extern bool g_bTypedUAVLoadSupport_R11G11B10_FLOAT;
		extern bool g_bEnableHDROutput;

		extern DescriptorAllocator g_DescriptorAllocator[];
		D3D12_CPU_DESCRIPTOR_HANDLE AllocateDescriptor(D3D12_DESCRIPTOR_HEAP_TYPE Type, UINT Count = 1);
		

		//extern RootSignature g_GenerateMipsRS;
		//extern ComputePSO g_GenerateMipsLinearPSO[4];
		//extern ComputePSO g_GenerateMipsGammaPSO[4];

		enum eResolution { k720p, k900p, k1080p, k1440p, k1800p, k2160p };

		//extern BoolVar s_EnableVSync;
		//extern EnumVar TargetResolution;
		extern uint32_t g_DisplayWidth;
		extern uint32_t g_DisplayHeight;
	}
}
