#include "GameLoop.h"
#include "raylib.h"
#include "../Explorer/Explorer.h"
#include "../Obstacles/Obstacles.h"
#include "../Martians/UFO.h"
#include "../Explorer/Bullets/Bullets.h"
#include <iostream>


namespace OkamiIndustries
{
	void UnloadSounds();
	void UnloadTextures();

	extern int SetScene;

	extern Texture2D BackgroundGame;
	extern Texture2D Parallax1Mountains;
	extern Texture2D Parallax2Clouds;
	extern Texture2D Parallax3Clouds;
	extern Texture2D FloorGame;

	Texture2D playerSprite;
	Texture2D obstacleSprite;
	Texture2D ufoSprite;

	Rectangle backgroundImages[8];

	Vector2 BackgroundPos = { 0,0 };


	int score = 0;
	extern bool isLive1;
	extern bool isLive2;

	bool isPlaying = false;
	bool hasLost = false;

	void GameLoop(bool singlePlayer)
	{
		if (!isPlaying && !hasLost)	//Inits
		{
			isPlaying = true;
			isLive1 = true;
			InitExplorer1();
			InitObstacles();
			InitBullets();
			InitUFO();
			InitBackground();
			score = 0;

			if (!singlePlayer)
			{
				isLive2 = true;
				InitExplorer2();
				InitBullets2();
			}
		}

		if (isPlaying)
		{
			updateBackground();
			MoveObstacles();
			MoveUFO();
			if (isLive1)
			{
				MoveExplorer();
				ShootExplorer();
			}
			if (!singlePlayer)
			{
				if (isLive2)
				{
					MoveExplorer2();
					ShootExplorer2();
				}
			}

			if (!isLive1 && !isLive2)
			{
				isPlaying = false;
			}

		}


		if (IsKeyPressed(KEY_ESCAPE))
		{
			SetScene = 0;
			isLive1 = false;
			isLive2 = false;
			isPlaying = false;
			hasLost = false;

			UnloadSounds();
			UnloadTextures();

		}
		else if (IsKeyDown(KEY_SPACE) && hasLost)
		{
			UnloadSounds();
			UnloadTextures();
			hasLost = false;
		}
	}

	void UnloadSounds()
	{

	}

	void UnloadTextures()
	{
		UnloadTexture(ufoSprite);
		UnloadTexture(obstacleSprite);
		UnloadTexture(playerSprite);

		
		UnloadTexture(BackgroundGame);
		UnloadTexture(Parallax1Mountains);
		UnloadTexture(Parallax2Clouds);
		UnloadTexture(Parallax3Clouds);
		UnloadTexture(FloorGame);
	}

	void DrawGame()
	{
		DrawTextureEx(BackgroundGame, BackgroundPos, 0, 1, WHITE);

		DrawTexturePro(Parallax1Mountains, { 0,0, static_cast<float>(Parallax1Mountains.width), static_cast<float>(Parallax1Mountains.height) }, backgroundImages[0], { 0,0 }, 0, WHITE);
		DrawTexturePro(Parallax1Mountains, { 0,0, static_cast<float>(Parallax1Mountains.width), static_cast<float>(Parallax1Mountains.height) }, backgroundImages[4], { 0,0 }, 0, WHITE);
		DrawTexturePro(Parallax2Clouds, { 0,0, static_cast<float>(Parallax2Clouds.width), static_cast<float>(Parallax2Clouds.height) }, backgroundImages[1], { 0,0 }, 0, WHITE);
		DrawTexturePro(Parallax2Clouds, { 0,0, static_cast<float>(Parallax2Clouds.width), static_cast<float>(Parallax2Clouds.height) }, backgroundImages[5], { 0,0 }, 0, WHITE);
		DrawTexturePro(Parallax3Clouds, { 0,0, static_cast<float>(Parallax3Clouds.width), static_cast<float>(Parallax3Clouds.height) }, backgroundImages[2], { 0,0 }, 0, WHITE);
		DrawTexturePro(Parallax3Clouds, { 0,0, static_cast<float>(Parallax3Clouds.width), static_cast<float>(Parallax3Clouds.height) }, backgroundImages[6], { 0,0 }, 0, WHITE);
		DrawTexturePro(FloorGame, { 0,0, static_cast<float>(FloorGame.width), static_cast<float>(FloorGame.height) }, backgroundImages[3], { 0,0 }, 0, WHITE);
		DrawTexturePro(FloorGame, { 0,0, static_cast<float>(FloorGame.width), static_cast<float>(FloorGame.height) }, backgroundImages[7], { 0,0 }, 0, WHITE);


		//DrawTextureEx(Parallax1Mountains, Parallax1pos, 0, 1, WHITE);
		//DrawTextureEx(Parallax1Mountains, Parallax1pos2, 0, 1, WHITE);
		//DrawTextureEx(Parallax2Clouds, Parallax2pos, 0, 1, WHITE);
		//DrawTextureEx(Parallax2Clouds, Parallax2pos, 0, 1, WHITE);
		//DrawTextureEx(Parallax3Clouds, Parallax3pos, 0, 1, WHITE);
		//DrawTextureEx(Parallax3Clouds, Parallax3pos2, 0, 1, WHITE);
		//DrawTextureEx(FloorGame, Floorpos, 0, 1, WHITE);
		//DrawTextureEx(FloorGame, Floorpos2, 0, 1, WHITE);
		DrawText(TextFormat("Score: %i", score * 100), (GetScreenWidth() / 4) * 3, 30, 40, WHITE);

		if (isLive1)
		{
			DrawExplorer();
			DrawBullets();
		}

		if (isLive2)
		{
			DrawExplorer2();
			DrawBullets2();
		}

		DrawObstacles();
		DrawUFO();

		if (!isLive1 && !isLive2 && hasLost)
		{

			DrawText(TextFormat("Score: %05i", score * 100), GetScreenWidth() / 4, GetScreenHeight() / 2, 150, RED);
			DrawText("ESC to return the menu", GetScreenWidth() / 3, GetScreenHeight() / 2 + 300, 50, WHITE);
			DrawText("SPACE to play again", GetScreenWidth() / 3, GetScreenHeight() / 2 + 350, 50, WHITE);
		}

	}

	void InitGame()
	{
		playerSprite = LoadTexture("assets/player.png");
		obstacleSprite = LoadTexture("assets/obstacle.png");
		ufoSprite = LoadTexture("assets/ufo.png");

		BackgroundGame = LoadTexture("assets/Background.png");
		Parallax1Mountains = LoadTexture("assets/parallax 1.png");
		Parallax2Clouds = LoadTexture("assets/parallax 2.png");
		Parallax3Clouds = LoadTexture("assets/parallax 3.png");
		FloorGame = LoadTexture("assets/Floor.png");
	}

	void InitBackground()
	{
		//background = { 0,0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };

		for (int i = 0; i < 4; i++)
		{
			backgroundImages[i] = { 0,0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
		}

		for (int i = 4; i < 8; i++)
		{
			backgroundImages[i] = { static_cast<float>(GetScreenWidth()),0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
		}

		//BackgroundPos = { 0,0 };
		//Parallax1pos = { 0,0 };
		//Parallax1pos2 = { static_cast<float>(GetScreenWidth()),0 };
		//Parallax2pos = { 0,0 };
		//Parallax2pos2 = { static_cast<float>(GetScreenWidth()),0 };
		//Parallax3pos = { 0,0 };
		//Parallax3pos2 = { static_cast<float>(GetScreenWidth()),0 };
		//Floorpos = { 0,0 };
		//Floorpos2 = { static_cast<float>(GetScreenWidth()),0 };
	}

	static void updateBackground()
	{
		//Parallax1pos.x -= 200 * GetFrameTime();
		//Parallax1pos2.x -= 200 * GetFrameTime();
		//Parallax2pos.x -= 400 * GetFrameTime();
		//Parallax2pos2.x -= 400 * GetFrameTime();
		//Parallax3pos.x -= 600 * GetFrameTime();
		//Parallax3pos2.x -= 600 * GetFrameTime();
		//Floorpos.x -= 800 * GetFrameTime();
		//Floorpos2.x -= 800 * GetFrameTime();



		backgroundImages[0].x -= 200 * GetFrameTime();
		backgroundImages[1].x -= 400 * GetFrameTime();
		backgroundImages[2].x -= 600 * GetFrameTime();
		backgroundImages[3].x -= 800 * GetFrameTime();

		backgroundImages[4].x -= 200 * GetFrameTime();
		backgroundImages[5].x -= 400 * GetFrameTime();
		backgroundImages[6].x -= 600 * GetFrameTime();
		backgroundImages[7].x -= 800 * GetFrameTime();

		for (int i = 0; i < 8; i++)
		{
			if (backgroundImages[i].x + backgroundImages[i].width <= 0)
			{
				if (i < 4)
					backgroundImages[i].x = backgroundImages[i + 4].x + backgroundImages[i + 4].width;
				else
					backgroundImages[i].x = backgroundImages[i - 4].x + backgroundImages[i - 4].width;
			}
		}

		//if (Parallax2pos.x < 0)
		//{
		//	Parallax1pos.x = static_cast<float>(GetScreenWidth());
		//	Parallax2pos.x = static_cast<float>(GetScreenWidth() * 2);
		//}

		//if (Parallax1pos2.x < -static_cast<float>(GetScreenWidth()))
		//{
		//	Parallax1pos2.x = static_cast<float>(GetScreenWidth());
		//}

		//if (Parallax2pos.x < -static_cast<float>(GetScreenWidth()))
		//{
		//	Parallax2pos.x = static_cast<float>(GetScreenWidth());
		//}

		//if (Parallax2pos2.x < -static_cast<float>(GetScreenWidth()))
		//{
		//	Parallax2pos2.x = static_cast<float>(GetScreenWidth());
		//}

		//if (Parallax3pos.x < -static_cast<float>(GetScreenWidth()))
		//{
		//	Parallax3pos.x = static_cast<float>(GetScreenWidth());
		//}

		//if (Parallax3pos2.x < -static_cast<float>(GetScreenWidth()))
		//{
		//	Parallax3pos2.x = static_cast<float>(GetScreenWidth());
		//}

		//if (Floorpos.x < -static_cast<float>(GetScreenWidth()))
		//{
		//	Floorpos.x = static_cast<float>(GetScreenWidth());
		//}

		//if (Floorpos2.x < -static_cast<float>(GetScreenWidth()))
		//{
		//	Floorpos2.x = static_cast<float>(GetScreenWidth());
		//}

	}
}