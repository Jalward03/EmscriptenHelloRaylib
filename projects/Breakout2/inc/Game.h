#pragma once

class GameStateManager;
class IGameState;

class Game
{
public:
	const int windowWidth = 540;
	const int windowHeight = 800;
	const char* windowTitle = "BREAKOUT";
	bool shouldQuit = false;

public:

	Game();
	~Game();

	void Load();
	void UnLoad();

	void Update();
	void Draw();

	GameStateManager* GetGameStateManager()
	{
		return m_gameStateManager;
	}

protected:
private:

	GameStateManager* m_gameStateManager = nullptr;
};