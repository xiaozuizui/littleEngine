#pragma once
#include <windows.h>


class TestGame : public littleEngine::EngineCore::IGameApp
{
public:

	TestGame(void) {}

	virtual void Startup(void)  override;
	virtual void Cleanup(void) override;

	virtual void Update(float deltaT) override;
	virtual void RenderScene(void) override;

};
