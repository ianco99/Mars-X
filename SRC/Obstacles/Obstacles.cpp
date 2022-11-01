#include "Obstacles.h"
#include "raylib.h"

namespace OkamiIndustries
{
	const int maxObstacles = 3;
	int speed = -300;
	Rectangle Obstacles[maxObstacles];
	Vector2 ObstaclesOrigin[maxObstacles]; 
	int ObstaclesRotation = 0;

	void InitObstacles()
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			Obstacles[i].x = static_cast <float>(GetScreenWidth() + i * 700);
			Obstacles[i].y = static_cast <float>((GetScreenHeight() / 4) * 3);
			Obstacles[i].width = 30;
			Obstacles[i].height = 30;
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
			}
		}

	}

	void DrawObstacles()
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			DrawRectanglePro(Obstacles[i], ObstaclesOrigin[i], static_cast <float>(ObstaclesRotation), RAYWHITE);
		}
	}

}