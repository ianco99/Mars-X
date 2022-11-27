#include "Obstacles.h"
#include "raylib.h"
#include "../CoreLoop/CoreLoop.h"
#include "../Explorer/Explorer.h"

namespace OkamiIndustries
{
	const int maxObstacles = 3;
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
			Obstacles[i].width = 98;
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
				Obstacles[i].x = static_cast <float>(GetScreenWidth());
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
				DrawTexturePro(obstacleSprite, { 0,0, static_cast<float>(obstacleSprite.width), static_cast<float>(obstacleSprite.height) }, Obstacles[i], { 0,0 }, 0, RAYWHITE);
			}
			else
			{
				DrawTexturePro(obstacleSprite, { 0,0, static_cast<float>(obstacleSprite.width), static_cast<float>(obstacleSprite.height) }, Obstacles[i], { 0,0 }, 0, RAYWHITE);
			}
		}
	}

}