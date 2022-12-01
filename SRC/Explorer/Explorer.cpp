#include "explorer.h"

#include "CoreLoop/core_loop.h"

namespace OkamiIndustries
{
	void DetectInput(Explorer& explorer);

	extern const int maxObstacles = 3;

	extern Rectangle Obstacles[maxObstacles];
	extern Texture2D playerSprite;

	extern bool singlePlayer;
	extern bool hasLost;

	const int explorerOffset = 75;

	float explorerRotation = 0;
	float gravity1 = 500;
	float gravity2 = 500;
	bool isLive1 = false;
	bool isLive2 = false;

	void InitExplorer(Explorer& explorer, int id)
	{
		explorer.isAlive = true;

		if (id == 0)
			explorer.color = RAYWHITE;
		else if (id == 1)
			explorer.color = LIGHTGRAY;

		explorer.body.width = 50;
		explorer.body.height = 100;

		explorer.currentGravity = 0;


		if (id == 0)
			explorer.body.x = static_cast <float>(GetScreenWidth() / 4);
		else 
			explorer.body.x = static_cast <float>(GetScreenWidth() / 4 + explorerOffset * id);

		explorer.body.y = static_cast <float>((GetScreenHeight() / 8) * 7);

		explorer.id = id;
	}

	void MoveExplorer(Explorer& explorer)
	{
		explorer.body.y = explorer.body.y + explorer.currentGravity * GetFrameTime();

		if (explorer.body.y > static_cast <float>((GetScreenHeight() / 4) * 3))
		{
			explorer.body.y = static_cast <float>((GetScreenHeight() / 4) * 3);
		}

		DetectInput(explorer);
	}

	void DetectInput(Explorer& explorer)
	{
		if (explorer.id == 0)
		{
			if (IsKeyPressed(KEY_W))
			{
				if (explorer.body.y == static_cast <float>((GetScreenHeight() / 4) * 3))
				{
					explorer.currentGravity = -500;
				}
			}
			else
			{
				explorer.currentGravity += 500 * GetFrameTime();
			}
		}
		else if (explorer.id == 1)
		{
			if (IsKeyPressed(KEY_UP))
			{
				if (explorer.body.y == static_cast <float>((GetScreenHeight() / 4) * 3))
				{
					explorer.currentGravity = -500;
				}
			}
			else
			{
				explorer.currentGravity += 500 * GetFrameTime();
			}
		}
	}

	void DrawExplorer(Explorer& explorer)
	{
		for (int i = 0; i < maxObstacles; i++)
		{
			if (CheckCollision(Obstacles[i], explorer.body) && explorer.isAlive)
			{
				//DrawTexturePro(playerSprite, { 0,0, static_cast<float>(playerSprite.width), static_cast<float>(playerSprite.height) }, explorer.body, { 0,0 }, 0, explorer.color);
				explorer.isAlive = false;

				//if (!isLive2)
				//	hasLost = true;
				break;
			}
			else if(explorer.isAlive)
			{
				DrawTexturePro(playerSprite, { 0,0, static_cast<float>(playerSprite.width), static_cast<float>(playerSprite.height) }, explorer.body, { 0,0 }, 0, explorer.color);
			}

		}
	}

	//void DrawExplorer2()
	//{
	//	for (int i = 0; i < maxObstacles; i++)
	//	{
	//		if (CheckCollision(Obstacles[i], explorer2.body) && isLive2)
	//		{
	//			DrawTexturePro(playerSprite, { 0,0, static_cast<float>(playerSprite.width), static_cast<float>(playerSprite.height) }, explorer2.body, { 0,0 }, 0, explorer2.color);
	//			isLive2 = false;

	//			if (!isLive1)
	//				hasLost = true;
	//			break;
	//		}
	//		else
	//		{
	//			DrawTexturePro(playerSprite, { 0,0, static_cast<float>(playerSprite.width), static_cast<float>(playerSprite.height) }, explorer2.body, { 0,0 }, 0, explorer2.color);
	//		}

	//	}
	//}

}