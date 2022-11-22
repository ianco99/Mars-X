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
	extern Texture2D Parallax1Mountains;
	extern Texture2D Parallax2Clouds;
	extern Texture2D Parallax3Clouds;
	extern Texture2D FloorGame;
	Vector2 BackgroundPos = { 0,0 };
	Vector2 Parallax1pos = { 0,0 };
	Vector2 Parallax1pos2 = { static_cast<float>(GetScreenWidth()),0 };
	Vector2 Parallax2pos = { 0,0 };
	Vector2 Parallax2pos2 = { static_cast<float>(GetScreenWidth()),0 };
	Vector2 Parallax3pos = { 0,0 };
	Vector2 Parallax3pos2 = { static_cast<float>(GetScreenWidth()),0 };
	Vector2 Floorpos = { 0,0 };
	Vector2 Floorpos2 = { static_cast<float>(GetScreenWidth()),0 };

	int score = 0;
	extern bool isLive1;
	extern bool isLive2;

	void GameLoop(bool singlePlayer)
	{
		if (!isLive1)
		{
			InitExplorer1();
			InitObstacles();
			InitBullets();
			InitUFO();
			InitBackground();
			isLive1 = true;
			score = 0;
			if (singlePlayer)
			{
				score = 4;
			}
			else
			{
				score = 5;
			}
		}

		if (isLive1)
		{
			updateBackground();
			MoveExplorer();
			ShootExplorer();
			MoveObstacles();
			MoveUFO();
		}

		if (IsKeyPressed(KEY_ESCAPE))
		{
			SetScene = 0;
			isLive1 = false;
		}

		

	}

	void DrawGame()
	{
		DrawTextureEx(BackgroundGame, BackgroundPos, 0, 1, WHITE);
		DrawTextureEx(Parallax1Mountains, Parallax1pos, 0, 1, WHITE);
		DrawTextureEx(Parallax1Mountains, Parallax1pos2, 0, 1, WHITE);
		DrawTextureEx(Parallax2Clouds, Parallax2pos, 0, 1, WHITE);
		DrawTextureEx(Parallax2Clouds, Parallax2pos, 0, 1, WHITE);
		DrawTextureEx(Parallax3Clouds, Parallax3pos, 0, 1, WHITE);
		DrawTextureEx(Parallax3Clouds, Parallax3pos2, 0, 1, WHITE);
		DrawTextureEx(FloorGame, Floorpos, 0, 1, WHITE);
		DrawTextureEx(FloorGame, Floorpos2, 0, 1, WHITE);
		DrawText(TextFormat("Score: %i", score * 100), (GetScreenWidth() / 4) * 3, 30, 20, WHITE);

		DrawExplorer();
		DrawBullets();
		DrawObstacles();
		DrawUFO();

		if (!isLive1)
		{
			DrawText(TextFormat("Score: %05i", score * 100), GetScreenWidth() / 4, GetScreenHeight() / 2, 150, RED);
			DrawText("ESC to retun the menu", GetScreenWidth() / 3, GetScreenHeight() / 2 + 300, 50, WHITE);
		}

	}

	void InitGame()
	{
		BackgroundGame = LoadTexture("assets/Background.png");
		Parallax1Mountains = LoadTexture("assets/parallax 1.png");
		Parallax2Clouds = LoadTexture("assets/parallax 2.png");
		Parallax3Clouds = LoadTexture("assets/parallax 3.png");
		FloorGame = LoadTexture("assets/Floor.png");
	}

	void InitBackground()
	{
		BackgroundPos = { 0,0 };
		Parallax1pos = { 0,0 };
		Parallax1pos2 = { static_cast<float>(GetScreenWidth()),0 };
		Parallax2pos = { 0,0 };
		Parallax2pos2 = { static_cast<float>(GetScreenWidth()),0 };
		Parallax3pos = { 0,0 };
		Parallax3pos2 = { static_cast<float>(GetScreenWidth()),0 };
		Floorpos = { 0,0 };
		Floorpos2 = { static_cast<float>(GetScreenWidth()),0 };
	}

	static void updateBackground()
	{
		Parallax1pos.x -= 200 * GetFrameTime();
		Parallax1pos2.x -= 200 * GetFrameTime();
		Parallax2pos.x -= 400 * GetFrameTime();
		Parallax2pos2.x -= 400 * GetFrameTime();
		Parallax3pos.x -= 600 * GetFrameTime();
		Parallax3pos2.x -= 600 * GetFrameTime();
		Floorpos.x -= 800 * GetFrameTime();
		Floorpos2.x -= 800 * GetFrameTime();

		if (Parallax1pos.x < -static_cast<float>(GetScreenWidth()))
		{
			Parallax1pos.x = static_cast<float>(GetScreenWidth());
		}

		if (Parallax1pos2.x < -static_cast<float>(GetScreenWidth()))
		{
			Parallax1pos2.x = static_cast<float>(GetScreenWidth());
		}

		if (Parallax2pos.x < -static_cast<float>(GetScreenWidth()))
		{
			Parallax2pos.x = static_cast<float>(GetScreenWidth());
		}

		if (Parallax2pos2.x < -static_cast<float>(GetScreenWidth()))
		{
			Parallax2pos2.x = static_cast<float>(GetScreenWidth());
		}

		if (Parallax3pos.x < -static_cast<float>(GetScreenWidth()))
		{
			Parallax3pos.x = static_cast<float>(GetScreenWidth());
		}

		if (Parallax3pos2.x < -static_cast<float>(GetScreenWidth()))
		{
			Parallax3pos2.x = static_cast<float>(GetScreenWidth());
		}

		if (Floorpos.x < -static_cast<float>(GetScreenWidth()))
		{
			Floorpos.x = static_cast<float>(GetScreenWidth());
		}

		if (Floorpos2.x < -static_cast<float>(GetScreenWidth()))
		{
			Floorpos2.x = static_cast<float>(GetScreenWidth());
		}

	}
}