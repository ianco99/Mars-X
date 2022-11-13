#include "Bullets.h"
#include "raylib.h"
#include <cmath>
#include "../SRC/CoreLoop/CoreLoop.h"

namespace OkamiIndustries
{
	extern Rectangle explorer;

	const int maxAmmo = 100;
	Circle bullet[maxAmmo];
	int currentBullet = 0;
	bool isBulletTravelling[maxAmmo];
	Vector2 trayectory[maxAmmo];
	float bulletAceleration = 1000.0f;
	float timer = 0;

	void initBullets()
	{
		currentBullet = 0;

		for (int i = 0; i < maxAmmo; i++)
		{
			bullet[i] = { Vector2 {-100, -100}, 4 };
			isBulletTravelling[i] = false;
			trayectory[i] = { 0,0 };
		}
	}

	void ShootExplorer()
	{
		Vector2 Dif = { 0,0 };
		Vector2 normalDir = { 0,0 };
		Dif.x = explorer.x - static_cast <float>(GetScreenWidth() / 4);
		Dif.y = explorer.y + 1000;

		float Module = static_cast <float>(sqrt(pow(Dif.x, 2) + pow(Dif.y, 2)));

		normalDir = { Dif.x / Module, Dif.y / Module };

		timer += GetFrameTime();
		if (IsKeyPressed(KEY_W))
		{
			if (timer > 0.1f)
			{
				trayectory[currentBullet] = normalDir;
				isBulletTravelling[currentBullet] = true;
				bullet[currentBullet].Position.x = explorer.x + explorer.width / 2;
				bullet[currentBullet].Position.y = explorer.y;
				currentBullet++;
				timer = 0;
				if (currentBullet >= maxAmmo)
				{
					currentBullet = 0;
				}
			}
		}

		for (int i = 0; i < maxAmmo; i++)
		{
			if (isBulletTravelling[i])
			{
				bullet[i].Position.x -= (trayectory[i].x * 2) * bulletAceleration * GetFrameTime();
				bullet[i].Position.y -= (trayectory[i].y * 2) * bulletAceleration * GetFrameTime();

				if (bullet[i].Position.y < 0)
				{
					isBulletTravelling[i] = false;
					bullet[i].Position.x = -100;
					bullet[i].Position.y = -100;
				}
			}
		}
	}

	void DrawBullets()
	{
		for (int i = 0; i < 100; i++)
		{
			DrawCircle(static_cast <int>(bullet[i].Position.x), static_cast <int>(bullet[i].Position.y), static_cast <float>(bullet[i].Radius), SKYBLUE);
		}
	}
}