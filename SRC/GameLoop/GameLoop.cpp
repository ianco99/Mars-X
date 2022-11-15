#include "GameLoop.h"
#include "raylib.h"
#include "../Explorer/Explorer.h"
#include "../Obstacles/Obstacles.h"
#include "../Martians/UFO.h"
#include "../Explorer/Bullets/Bullets.h"


namespace OkamiIndustries
{

	extern int SetScene;
	extern Texture2D BackgroundGame;
	extern Texture2D Parallax1Game;
	extern Texture2D Parallax2Game;
	extern Texture2D Parallax3Game;
	extern Texture2D FloorGame;
	Vector2 BackgroundPos = { 0,0 };
	Vector2 Parallax1pos = { 0,0 };
	Vector2 Parallax1pos2 = { 1920,0 };
	Vector2 Parallax2pos = { 0,0 };
	Vector2 Parallax2pos2 = { 1920,0 };
	Vector2 Parallax3pos = { 0,0 };
	Vector2 Parallax3pos2 = { 1920,0 };
	Vector2 Floorpos = { 0,0 };
	Vector2 Floorpos2 = { 1920,0 };

	int score = 0;
	extern bool isLive;

	void GameLoop()
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			InitExplorer();
			InitObstacles();
			initBullets();
			initUFO();
			SetScene = 0;
			isLive = true;
			score = 0;
		}

		if (isLive)
		{
			updateBackground();
			MoveExplorer();
			ShootExplorer();
			MoveObstacles();
			MoveUFO();
		}
	}

	void DrawGame()
	{
		DrawTextureEx(BackgroundGame, BackgroundPos, 0, 1, WHITE);
		DrawTextureEx(Parallax1Game, Parallax1pos, 0, 1, WHITE);
		DrawTextureEx(Parallax1Game, Parallax1pos2, 0, 1, WHITE);
		DrawTextureEx(Parallax2Game, Parallax2pos, 0, 1, WHITE);
		DrawTextureEx(Parallax2Game, Parallax2pos, 0, 1, WHITE);
		DrawTextureEx(Parallax3Game, Parallax3pos, 0, 1, WHITE);
		DrawTextureEx(Parallax3Game, Parallax3pos2, 0, 1, WHITE);
		DrawTextureEx(FloorGame, Floorpos, 0, 1, WHITE);
		DrawTextureEx(FloorGame, Floorpos2, 0, 1, WHITE);
		DrawText(TextFormat("Score: %i", score * 100), (GetScreenWidth() / 4) * 3, 30, 20, WHITE);

		DrawExplorer();
		DrawBullets();
		DrawObstacles();
		DrawUFO();

		if (!isLive)
		{
			DrawText(TextFormat("Score: %05i", score * 100), GetScreenWidth() / 4, GetScreenHeight() / 2, 150, RED);
			DrawText("ESC to retun the menu", GetScreenWidth() / 3, GetScreenHeight() / 2 + 300, 50, WHITE);
		}

	}

	void InitGame()
	{
		BackgroundGame = LoadTexture("assets/Background.png");
		Parallax1Game = LoadTexture("assets/parallax 1.png");
		Parallax2Game = LoadTexture("assets/parallax 2.png");
		Parallax3Game = LoadTexture("assets/parallax 3.png");
		FloorGame = LoadTexture("assets/Floor.png");
		
	}

	static void updateBackground()
	{
		Parallax1pos.x -= 200* GetFrameTime();
		Parallax1pos2.x -= 200* GetFrameTime();
		Parallax2pos.x -= 400* GetFrameTime();
		Parallax2pos2.x -= 400* GetFrameTime();
		Parallax3pos.x -= 600* GetFrameTime();
		Parallax3pos2.x -= 600* GetFrameTime();
		Floorpos.x -= 800* GetFrameTime();
		Floorpos2.x -= 800* GetFrameTime();

		if (Parallax1pos.x < -1920)
		{
			Parallax1pos.x = 1920;
		}

		if (Parallax1pos2.x < -1920)
		{
			Parallax1pos2.x = 1920;
		}

		if (Parallax2pos.x < -1920)
		{
			Parallax2pos.x = 1920;
		}

		if (Parallax2pos2.x < -1920)
		{
			Parallax2pos2.x = 1920;
		}

		if (Parallax3pos.x < -1920)
		{
			Parallax3pos.x = 1920;
		}

		if (Parallax3pos2.x < -1920)
		{
			Parallax3pos2.x = 1920;
		}

		if (Floorpos.x < -1920)
		{
			Floorpos.x = 1920;
		}

		if (Floorpos2.x < -1920)
		{
			Floorpos2.x = 1920;
		}

	}
}