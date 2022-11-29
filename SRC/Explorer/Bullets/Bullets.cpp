#include <cmath>
#include "Bullets.h"
#include "raylib.h"
#include "CoreLoop/CoreLoop.h"
#include "Explorer/Explorer.h"

namespace OkamiIndustries
{
	extern Explorer explorer1;
	extern Explorer explorer2;

	const int maxAmmo = 100;

	Vector2 bulletErasedPos = { -100, -100 };
	Vector2 trayectory[maxAmmo];
	Vector2 trayectory2[maxAmmo];

	Circle bullet[maxAmmo];
	Circle bullet2[maxAmmo];
	
	int currentBullet = 0;
	int currentBullet2 = 0;
	bool isBulletTravelling[maxAmmo];
	bool isBulletTravelling2[maxAmmo];

	
	float bulletAceleration = 1000.0f;
	float timer = 0;
	float timer2 = 0;

	void InitBullets()
	{
		currentBullet = 0;

		for (int i = 0; i < maxAmmo; i++)
		{
			bullet[i] = { bulletErasedPos, 4 };
			isBulletTravelling[i] = false;
			trayectory[i] = { 0,0 };
		}
	}

	void InitBullets2()
	{
		currentBullet2 = 0;

		for (int i = 0; i < maxAmmo; i++)
		{
			bullet2[i] = { bulletErasedPos, 4 };
			isBulletTravelling2[i] = false;
			trayectory2[i] = { 0,0 };
		}
	}

	void ShootExplorer()
	{
		Vector2 Dif = { 0,0 };
		Vector2 normalDir = { 0,0 };
		Dif.x = explorer1.body.x - static_cast <float>(GetScreenWidth() / 4);
		Dif.y = explorer1.body.y + 1000;

		float Module = static_cast <float>(sqrt(pow(Dif.x, 2) + pow(Dif.y, 2)));

		normalDir = { Dif.x / Module, Dif.y / Module };

		timer += GetFrameTime();

		if (IsKeyPressed(KEY_LEFT_CONTROL))
		{
			if (timer > 0.1f)
			{
				trayectory[currentBullet] = normalDir;
				isBulletTravelling[currentBullet] = true;
				bullet[currentBullet].Position.x = explorer1.body.x + explorer1.body.width / 2;
				bullet[currentBullet].Position.y = explorer1.body.y;
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
					bullet[i].Position = bulletErasedPos;
				}
			}
		}
	}

	void ShootExplorer2()
	{
		Vector2 Dif = { 0,0 };
		Vector2 normalDir = { 0,0 };
		Dif.x = explorer2.body.x - static_cast <float>(GetScreenWidth() / 4);
		Dif.y = explorer2.body.y + 1000;

		float Module = static_cast <float>(sqrt(pow(Dif.x, 2) + pow(Dif.y, 2)));

		normalDir = { Dif.x / Module, Dif.y / Module };

		timer2 += GetFrameTime();

		if (IsKeyPressed(KEY_RIGHT_CONTROL))
		{
			if (timer2 > 0.1f)
			{
				trayectory2[currentBullet2] = normalDir;
				isBulletTravelling2[currentBullet2] = true;
				bullet2[currentBullet2].Position.x = explorer2.body.x + explorer2.body.width / 2;
				bullet2[currentBullet2].Position.y = explorer2.body.y;
				currentBullet2++;
				timer2 = 0;
				if (currentBullet2 >= maxAmmo)
				{
					currentBullet2 = 0;
				}
			}
		}

		for (int i = 0; i < maxAmmo; i++)
		{
			if (isBulletTravelling2[i])
			{
				bullet2[i].Position.x -= (trayectory2[i].x * 2) * bulletAceleration * GetFrameTime();
				bullet2[i].Position.y -= (trayectory2[i].y * 2) * bulletAceleration * GetFrameTime();

				if (bullet2[i].Position.y < 0)
				{
					isBulletTravelling2[i] = false;
					bullet2[i].Position = bulletErasedPos;
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

	void DrawBullets2()
	{
		for (int i = 0; i < 100; i++)
		{
			DrawCircle(static_cast <int>(bullet2[i].Position.x), static_cast <int>(bullet2[i].Position.y), static_cast <float>(bullet2[i].Radius), GREEN);
		}
	}
}