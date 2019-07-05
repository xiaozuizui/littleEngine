
#include "PresentRS.hlsli"

cbuffer VSConstants : register(b0)
{
	float4x4 modelToProjection;
};


struct VSInput
{
	float3 position : POSITION;
	float2 texcoord0 : TEXCOORD;
	float3 normal : NORMAL;
	float3 tangent : TANGENT;
	float3 bitangent : BITANGENT;
};

struct VSOutput
{
	float4 pos : SV_Position;
	float2 uv : TexCoord0;
};

[RootSignature(Standard_RootSig)]
VSOutput main(VSInput vsInput)
{
	VSOutput vsOutput;
	vsOutput.pos = mul(modelToProjection, float4(vsInput.position, 1.0));
	vsOutput.uv = vsInput.texcoord0;
	return vsOutput;
}


