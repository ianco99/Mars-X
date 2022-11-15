#include "Explorer.h"
#include "raylib.h"
#include "../CoreLoop/CoreLoop.h"

namespace OkamiIndustries
{
	float gravity = 500;
	Rectangle explorer;
	Vector2 explorerOrigin = { explorer.width / 2, explorer.height / 2 };
	float explorerRotation = 0;

	bool isLive = true;

	extern const int maxObstacles = 3;
	extern Rectangle Obstacles[maxObstacles];

	void InitExplorer()
	{
		explorer.width = 50;
		explorer.height = 50;

		explorer.x = static_cast <float>(GetScreenWidth() / 4);
		explorer.y = static_cast <float>((GetScreenHeight() / 4) * 3);
	}

	void MoveExplorer()
	{
		explorer.y = explorer.y + gravity * GetFrameTime();

		if (explorer.y > static_cast <float>((GetScreenHeight() / 4) * 3))
		{
			explorer.y = static_cast <float>((GetScreenHeight() / 4) * 3);
		}

		if (IsKeyPressed(KEY_SPACE))
		{
			if (explorer.y == static_cast <float>((GetScreenHeight() / 4) * 3))
			{
				gravity = -500;
			}
		}
		else
		{
			gravity += 500 * GetFrameTime();
		}

		
	}

	void DrawExplorer()
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			if (CheckCollision(Obstacles[i], explorer))
			{
				DrawRectanglePro(explorer, explorerOrigin, explorerRotation, RED);
				isLive = false;
				break;
			}
			else
			{
				DrawRectanglePro(explorer, explorerOrigin, explorerRotation, RAYWHITE);
			}

		}
	}

}