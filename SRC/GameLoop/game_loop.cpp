#include "game_loop.h"

#include <iostream>

#include "Explorer/explorer.h"
#include "Obstacles/obstacles.h"
#include "Martians/ufo.h"
#include "CoreLoop/core_loop.h"
#include "Explorer/Bullets/bullets.h"


namespace OkamiIndustries
{

	extern CoreScreens SetScene;

	extern Texture2D BackgroundGame;
	extern Texture2D Parallax1Mountains;
	extern Texture2D Parallax2Clouds;
	extern Texture2D Parallax3Clouds;
	extern Texture2D FloorGame;

	Explorer explorer1;
	Explorer explorer2;
	BackgroundImage backgroundImages[8];

	Texture2D playerSprite;
	Texture2D obstacleSprite;
	Texture2D ufoSprite;


	Vector2 BackgroundPos = { 0,0 };

	int score = 0;
	extern bool isLive1;
	extern bool isLive2;

	bool isPlaying = false;
	bool hasLost = false;

	void GameLoop(bool singlePlayer)
	{
		if (!isPlaying && !hasLost)	
		{
			isPlaying = true;
			isLive1 = true;
			InitExplorer(explorer1, 0);
			InitObstacles();
			InitBullets();
			InitUFO();
			InitBackground();
			score = 0;

			if (!singlePlayer)
			{
				isLive2 = true;
				InitExplorer(explorer2, 1);
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
				MoveExplorer(explorer1);
				ShootExplorer();
			}
			if (!singlePlayer)
			{
				if (isLive2)
				{
					MoveExplorer(explorer2);
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
			SetScene = CoreScreens::MainMenu;
			isLive1 = false;
			isLive2 = false;
			isPlaying = false;
			hasLost = false;

		}
		else if (IsKeyDown(KEY_SPACE) && hasLost)
		{
			hasLost = false;
		}
	}

	void DrawGame()
	{
		DrawTextureEx(BackgroundGame, BackgroundPos, 0, 1, WHITE);

		DrawTexturePro(Parallax1Mountains, { 0,0, static_cast<float>(Parallax1Mountains.width), static_cast<float>(Parallax1Mountains.height) }, backgroundImages[0].body, { 0,0 }, 0, WHITE);
		DrawTexturePro(Parallax1Mountains, { 0,0, static_cast<float>(Parallax1Mountains.width), static_cast<float>(Parallax1Mountains.height) }, backgroundImages[4].body, { 0,0 }, 0, WHITE);
		DrawTexturePro(Parallax2Clouds, { 0,0, static_cast<float>(Parallax2Clouds.width), static_cast<float>(Parallax2Clouds.height) }, backgroundImages[1].body, { 0,0 }, 0, WHITE);
		DrawTexturePro(Parallax2Clouds, { 0,0, static_cast<float>(Parallax2Clouds.width), static_cast<float>(Parallax2Clouds.height) }, backgroundImages[5].body, { 0,0 }, 0, WHITE);
		DrawTexturePro(Parallax3Clouds, { 0,0, static_cast<float>(Parallax3Clouds.width), static_cast<float>(Parallax3Clouds.height) }, backgroundImages[2].body, { 0,0 }, 0, WHITE);
		DrawTexturePro(Parallax3Clouds, { 0,0, static_cast<float>(Parallax3Clouds.width), static_cast<float>(Parallax3Clouds.height) }, backgroundImages[6].body, { 0,0 }, 0, WHITE);
		DrawTexturePro(FloorGame, { 0,0, static_cast<float>(FloorGame.width), static_cast<float>(FloorGame.height) }, backgroundImages[3].body, { 0,0 }, 0, WHITE);
		DrawTexturePro(FloorGame, { 0,0, static_cast<float>(FloorGame.width), static_cast<float>(FloorGame.height) }, backgroundImages[7].body, { 0,0 }, 0, WHITE);

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

	void UnloadGame()
	{
		UnloadTexture(playerSprite);
		UnloadTexture(obstacleSprite);
		UnloadTexture(ufoSprite);
		UnloadTexture(BackgroundGame);
		UnloadTexture(Parallax1Mountains);
		UnloadTexture(Parallax2Clouds);
		UnloadTexture(Parallax3Clouds);
		UnloadTexture(FloorGame);
	}

	void InitBackground()
	{
		int counter = 1;
		for (int i = 0; i < 4; i++)
		{
			backgroundImages[i].body = { 0,0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
			backgroundImages[i].speed = 200 * counter;
			counter++;
		}
		counter = 1;
		for (int i = 4; i < 8; i++)
		{
			backgroundImages[i].body = { static_cast<float>(GetScreenWidth()),0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
			backgroundImages[i].speed = 200 * counter;
			counter++;
		}
	}

	static void updateBackground()
	{

		for (int i = 0; i < 8; i++)
		{
			backgroundImages[i].body.x -= backgroundImages[i].speed * GetFrameTime();
		}

		for (int i = 0; i < 8; i++)
		{
			if (backgroundImages[i].body.x + backgroundImages[i].body.width <= 0)
			{
				if (i < 4)
					backgroundImages[i].body.x = backgroundImages[i + 4].body.x + backgroundImages[i + 4].body.width;
				else
					backgroundImages[i].body.x = backgroundImages[i - 4].body.x + backgroundImages[i - 4].body.width;
			}
		}
	}
}