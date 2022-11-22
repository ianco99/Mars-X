#include "Explorer.h"
#include "raylib.h"
#include "../CoreLoop/CoreLoop.h"

namespace OkamiIndustries
{
	Explorer explorer1;
	Explorer explorer2;
	
	Vector2 explorerOrigin = { explorer1.body.width / 2, explorer1.body.height / 2 };

	float explorerRotation = 0;
	float gravity1 = 500;
	float gravity2 = 500;

	bool isLive1 = false;
	bool isLive2 = false;

	extern const int maxObstacles = 3;
	extern Rectangle Obstacles[maxObstacles];

	void InitExplorer1()
	{
		explorer1.body.width = 50;
		explorer1.body.height = 50;

		gravity1 = 0;

		explorer1.body.x = static_cast <float>(GetScreenWidth() / 4);
		explorer1.body.y = static_cast <float>((GetScreenHeight() / 4) * 3);
	}

	void InitExplorer2()
	{
		explorer2.body.width = 50;
		explorer2.body.height = 50;

		gravity2 = 0;

		explorer2.body.x = static_cast <float>(GetScreenWidth() / 4);
		explorer2.body.y = static_cast <float>((GetScreenHeight() / 4) * 3);
	}

	void MoveExplorer()
	{
		explorer1.body.y = explorer1.body.y + gravity1 * GetFrameTime();

		if (explorer1.body.y > static_cast <float>((GetScreenHeight() / 4) * 3))
		{
			explorer1.body.y = static_cast <float>((GetScreenHeight() / 4) * 3);
		}

		if (IsKeyPressed(KEY_W))
		{
			if (explorer1.body.y == static_cast <float>((GetScreenHeight() / 4) * 3))
			{
				gravity1 = -500;
			}
		}
		else
		{
			gravity1 += 500 * GetFrameTime();
		}

		
	}
	
	void MoveExplorer2()
	{
		explorer2.body.y = explorer2.body.y + gravity2 * GetFrameTime();

		if (explorer2.body.y > static_cast <float>((GetScreenHeight() / 4) * 3))
		{
			explorer2.body.y = static_cast <float>((GetScreenHeight() / 4) * 3);
		}

		if (IsKeyPressed(KEY_UP))
		{
			if (explorer2.body.y == static_cast <float>((GetScreenHeight() / 4) * 3))
			{
				gravity2 = -500;
			}
		}
		else
		{
			gravity2 += 500 * GetFrameTime();
		}

		
	}

	void DrawExplorer()
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			if (CheckCollision(Obstacles[i], explorer1.body))
			{
				DrawRectanglePro(explorer1.body, explorer1.bodyOrigin, explorerRotation, RED);
				isLive1 = false;
				break;
			}
			else
			{
				DrawRectanglePro(explorer1.body, explorer1.bodyOrigin, explorerRotation, RAYWHITE);
			}

		}
	}

	void DrawExplorer2()
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			if (CheckCollision(Obstacles[i], explorer2.body))
			{
				DrawRectanglePro(explorer2.body, explorer2.bodyOrigin, explorerRotation, RED);
				isLive2 = false;
				break;
			}
			else
			{
				DrawRectanglePro(explorer2.body, explorer2.bodyOrigin, explorerRotation, RAYWHITE);
			}

		}
	}

}