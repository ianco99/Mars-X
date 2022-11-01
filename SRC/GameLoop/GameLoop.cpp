#include "GameLoop.h"
#include "raylib.h"
#include "../Explorer/Explorer.h"
#include "../Obstacles/Obstacles.h"


namespace OkamiIndustries
{

	extern int SetScene;
	extern Texture2D BackgroundGame;
	Vector2 BackgroundPos = { 0,0 };

	void GameLoop()
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			SetScene = 0;
		}
		MoveExplorer();
		MoveObstacles();
	}

	void DrawGame()
	{
		DrawTextureEx(BackgroundGame, BackgroundPos, 0, 1, WHITE);
		DrawExplorer();
		DrawObstacles();
	}

	void InitGame()
	{
		BackgroundGame = LoadTexture("../assets/Background.png");
	}

}