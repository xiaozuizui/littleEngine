#include "api.h"
#include "ModelViewer.h"
#include "../OBJLoader/OBJLoader.h"
#include "../EngineCore/Hash.h"
#include "../EngineCore/Graphics/GraphicsCore.h"
#include "../EngineCore/Graphics/TextRenderer.h"
#include "../EngineCore/Graphics/BufferManager.h"
#include "../EngineCore/Graphics/ColorBuffer.h"
#include <iostream>


static std::map<size_t, WaveOBJ> Objs;

extern"C" bool RENDERDLL_API InitModelViewer(HWND hwnd, int w, int h)
{
	littleEngine::EngineCore::g_hWnd = hwnd;

	littleEngine::Graphics::Initialize();
	return true;


}

extern"C" bool RENDERDLL_API LoadObj(char* name)
{
	std::cout <<"Loading"<< std::endl;
	
	WaveOBJ obj =  LoadWaveOBJ(std::string(name), "");
	if (obj.attrib.vertices.size() > 0)
	{
		size_t HashCode = littleEngine::Utility::HashState(&obj);
		std::cout << HashCode << std::endl;
		//HashCode = littleEngine::Utility::HashState(m_InputLayouts.get(), m_PSODesc.InputLayout.NumElements, HashCode);
		return true;
	}
		
	else
		return false;
}

extern"C" void RENDERDLL_API Prasent()
{
	GraphicsContext& text = GraphicsContext::Begin(L"Render UI");
	//text.ClearColor(Graphics::g_OverlayBuffer);
	text.TransitionResource(littleEngine::Graphics::g_OverlayBuffer, D3D12_RESOURCE_STATE_RENDER_TARGET, true);
	text.SetRenderTarget(littleEngine::Graphics::g_OverlayBuffer.GetRTV());
	text.SetViewportAndScissor(200, 200, littleEngine::Graphics::g_OverlayBuffer.GetWidth(), littleEngine::Graphics::g_OverlayBuffer.GetHeight());

	TextContext Text(text);
	Text.Begin();



	Text.ResetCursor(10.0f, 40.0f);
	Text.SetColor(Color(0.5f, 1.0f, 1.0f));
	Text.DrawString("Engine Tuning\n");
	Text.SetTextSize(20.0f);
	Text.End();
	text.Finish(true);


	littleEngine::Graphics::Present();
}