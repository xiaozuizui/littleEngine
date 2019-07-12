// DebugCmd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Utility.h"
#include "Hash.h"
#include "Graphics/GraphicsCore.h"
#include "EngineCore.h"
#include "TestWindows.h"
#include "Model/Model.h"
#include "Graphics/BufferManager.h"
#include "Graphics/DepthBuffer.h"
#include "Graphics/ColorBuffer.h"
#include "Graphics/CommandContext.h"
#include "Graphics/TextureManager.h"

#include <windows.h>
#include "Math/Matrix4.h"

void TestUility()
{
	littleEngine::Utility::Printf("test string %d %d", 10, 10);
	littleEngine::Utility::PrintSubMessage("test PrintSubMessage %d", 10);

	int has = 10;

	size_t hashCode = littleEngine::Utility::HashState(&has);
	//littleEngine::Utility::HashRange()



}

void TestGame::Startup()
{
#ifdef _DEBUG
	//Model debugModel;
	littleEngine::Graphics::TextureManager::Initialize(L"Textures/");
	ASSERT(debugModel.Load("sponza.h3d"), "Failed to load model");
	ASSERT(debugModel.m_Header.meshCount > 0, "Model contains no meshes");
	float modelRadius = Length(debugModel.m_Header.boundingBox.max - debugModel.m_Header.boundingBox.min) * .5f;
	const Vector3 eye = (debugModel.m_Header.boundingBox.min + debugModel.m_Header.boundingBox.max) * .5f + Vector3(modelRadius * .5f, 0.0f, 0.0f);
	camera.SetEyeAtUp(eye, Vector3(kZero), Vector3(kYUnitVector));
	camera.SetZRange(1.0f, 10000.0f);
	camera.Update();
#endif

}

void TestGame::Cleanup()
{
	
}

void TestGame::Update(float deltaT)
{
	
}

void TestGame::RenderScene()
{

#ifdef _DEBUG

	GraphicsContext& context = GraphicsContext::Begin(L"debug model");
	
	context.SetUnlitPiplineState();
	context.SetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	context.SetIndexBuffer(debugModel.m_IndexBuffer.IndexBufferView());
	context.SetVertexBuffer(0, debugModel.m_VertexBuffer.VertexBufferView());
	
	context.TransitionResource(littleEngine::Graphics::g_SceneDepthBuffer, D3D12_RESOURCE_STATE_DEPTH_WRITE,true);
	context.TransitionResource(littleEngine::Graphics::g_SceneColorBuffer, D3D12_RESOURCE_STATE_RENDER_TARGET, true);
	context.ClearColor(littleEngine::Graphics::g_SceneColorBuffer);
	context.SetRenderTarget(littleEngine::Graphics::g_SceneColorBuffer.GetRTV(), littleEngine::Graphics::g_SceneDepthBuffer.GetDSV());
	uint32_t VertexStride = debugModel.m_VertexStride;

	struct VSConstants
	{
		Matrix4 modelToProjection;
		
	} vsConstants;
	vsConstants.modelToProjection = Matrix4(Vector4(-0.0477909967f, -1.13123345f, 8.82812237e-05f, -0.882723927f),
		Vector4(-4.04714058e-08f, 2.13240504f, 4.68909602e-05f, -0.468862712f),
		Vector4(-1.35715389f, 0.0398352668f, -3.10874680e-06f, 0.0310843587f),
		Vector4(0.0f, -144.797073f, 0.872433782f, 1276.53479f));
	

	context.SetDynamicConstantBufferView(0, sizeof(vsConstants), &vsConstants);

	for (uint32_t meshIndex = 0; meshIndex < debugModel.m_Header.meshCount; meshIndex++)
	{
		const Model::Mesh& mesh = debugModel.m_pMesh[meshIndex];

		uint32_t indexCount = mesh.indexCount;
		uint32_t startIndex = mesh.indexDataByteOffset / sizeof(uint16_t);
		uint32_t baseVertex = mesh.vertexDataByteOffset / VertexStride;

		
		context.SetDynamicDescriptors(2, 0, 6, debugModel.GetSRVs(mesh.materialIndex));
		context.DrawIndexed(indexCount, startIndex, baseVertex);
	}
	context.Finish(true);
#endif

}






CREATE_APPLICATION(TestGame)

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
