#pragma once
#include "raylib.h"

namespace OkamiIndustries
{
	enum class CoreScreens{MainMenu, Play1P, Play2P, CreditsMenu, Quit};

	struct Circle
	{
		Vector2 Position;
		int Radius;
	};

	void CoreLoop();
	bool CheckCollision(Rectangle rec1, Rectangle rec2);
	static void InitMouse();
	static void UpdateMouse();
	static void DrawMouse();
	static void InitAssets();
}