#include "obstacles.h"
#include "raylib.h"
#include "CoreLoop/core_loop.h"
#include "Explorer/explorer.h"
#include <iostream>

namespace OkamiIndustries
{
	const int maxObstacles = 3;

	const int distanceRandRangeMax = 1000;
	const int distanceRandRangeMin = 700;

	int speed = -300;
	Rectangle Obstacles[maxObstacles];
	Vector2 ObstaclesOrigin[maxObstacles]; 
	float ObstaclesRotation = 0;

	extern Texture2D obstacleSprite;

	extern Explorer explorer1;
	extern Explorer explorer2;

	extern bool isLive1;
	extern bool isLive2;

	extern int score;

	void InitObstacles()
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			Obstacles[i].x = static_cast <float>(GetScreenWidth() + i * 700);
			Obstacles[i].y = static_cast <float>((GetScreenHeight() / 10) * 7);
			Obstacles[i].width = 58;
			Obstacles[i].height = 146;
			ObstaclesOrigin[i] = { Obstacles[i].width / 2, Obstacles[i].height / 2 };
		}
	}

	void MoveObstacles()
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			Obstacles[i].x = Obstacles[i].x + speed * GetFrameTime();
			if (Obstacles[i].x < 0 - Obstacles[i].width)
			{
				Obstacles[i].x = static_cast <float>(GetScreenWidth()) + (rand() % distanceRandRangeMax) + distanceRandRangeMin;
				score++;
			}
		}
	}

	void DrawObstacles()
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			if ((CheckCollision(Obstacles[i], explorer1.body) && isLive1) || (CheckCollision(Obstacles[i], explorer2.body) && isLive2))
			{
				DrawTexturePro(obstacleSprite, { 0,0, static_cast<float>(obstacleSprite.width), static_cast<float>(obstacleSprite.height) }, { Obstacles[i].x, Obstacles[i].y, Obstacles[i].width + 40, Obstacles[i].height }, { 0,0 }, 0, RAYWHITE);
			}
			else
			{
				DrawTexturePro(obstacleSprite, { 0,0, static_cast<float>(obstacleSprite.width), static_cast<float>(obstacleSprite.height) }, { Obstacles[i].x, Obstacles[i].y, Obstacles[i].width + 40, Obstacles[i].height }, { 0,0 }, 0, RAYWHITE);
			}
		}
	}

}