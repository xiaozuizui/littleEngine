#pragma once
#include "../EngineCore/Camrea.h"
#include "../EngineCore/Model/Model.h"



class TestGame : public littleEngine::EngineCore::IGameApp
{
public:

	TestGame(void) {}

	virtual void Startup(void)  override;
	virtual void Cleanup(void) override;

	virtual void Update(float deltaT) override;
	virtual void RenderScene(void) override;

private:
#ifdef _DEBUG
	
	littleEngine::EngineCore::Camera camera;
#endif

};
