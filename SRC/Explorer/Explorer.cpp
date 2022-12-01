#include "explorer.h"

#include "CoreLoop/core_loop.h"

namespace OkamiIndustries
{
	extern Rectangle Obstacles[maxObstacles];
	extern Texture2D playerSprite;

	extern const int maxObstacles = 3;

	extern bool singlePlayer;
	extern bool hasLost;

	const int explorerOffset = 75;

	Vector2 explorerOrigin = { explorer1.body.width / 2, explorer1.body.height / 2 };

	float explorerRotation = 0;
	float gravity1 = 500;
	float gravity2 = 500;
	bool isLive1 = false;
	bool isLive2 = false;

	void InitExplorer(Explorer& explorer, int id)
	{
		explorer.color = RAYWHITE;

		explorer.body.width = 50;
		explorer.body.height = 100;

		explorer.currentGravity = 0;

		if (id == 0)
			explorer.body.x = static_cast <float>(GetScreenWidth() / 4);
		else
			explorer.body.x = static_cast <float>(GetScreenWidth() / 4 + explorerOffset * id);

		explorer.body.y = static_cast <float>((GetScreenHeight() / 8) * 7);
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
			if (CheckCollision(Obstacles[i], explorer1.body) && isLive1)
			{
				DrawTexturePro(playerSprite, { 0,0, static_cast<float>(playerSprite.width), static_cast<float>(playerSprite.height) }, explorer1.body, { 0,0 }, 0, explorer1.color);
				isLive1 = false;

				if (!isLive2)
					hasLost = true;
				break;
			}
			else
			{
				DrawTexturePro(playerSprite, { 0,0, static_cast<float>(playerSprite.width), static_cast<float>(playerSprite.height) }, explorer1.body, { 0,0 }, 0, explorer1.color);
			}

		}
	}

	void DrawExplorer2()
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			if (CheckCollision(Obstacles[i], explorer2.body) && isLive2)
			{
				DrawTexturePro(playerSprite, { 0,0, static_cast<float>(playerSprite.width), static_cast<float>(playerSprite.height) }, explorer2.body, { 0,0 }, 0, explorer2.color);
				isLive2 = false;

				if (!isLive1)
					hasLost = true;
				break;
			}
			else
			{
				DrawTexturePro(playerSprite, { 0,0, static_cast<float>(playerSprite.width), static_cast<float>(playerSprite.height) }, explorer2.body, { 0,0 }, 0, explorer2.color);
			}

		}
	}

}