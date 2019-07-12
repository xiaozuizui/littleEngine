#pragma once
#include <windows.h>
#include "Model/Model.h"
#include "Camrea.h"


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
	Model debugModel;
	littleEngine::EngineCore::Camera camera;
#endif

};
