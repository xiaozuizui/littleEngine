#include "PresentRS.hlsli"

struct VSOutput
{
	float4 pos : SV_Position;
	float2 uv : TexCoord0;
};

Texture2D<float4>    texDiffuse        : register(t0);
SamplerState        sampler0        : register(s0);

[RootSignature(Standard_RootSig)]
float4 main(VSOutput vsOutput): SV_Target
{
	return texDiffuse.Sample(sampler0, vsOutput.uv);
}