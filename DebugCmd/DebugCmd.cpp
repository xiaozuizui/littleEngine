// DebugCmd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Utility.h"
#include "Hash.h"
#include "Graphics/GraphicsCore.h"
#include "EngineCore.h"
#include "TestWindows.h"
#include "Model/Model.h"

#include <windows.h>

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
	Model debugModel;
	ASSERT(debugModel.Load("sponza.h3d"), "Failed to load model");
	ASSERT(debugModel.m_Header.meshCount > 0, "Model contains no meshes");
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
