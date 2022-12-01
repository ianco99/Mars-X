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
	void InitMouse();
	void UpdateMouse();
	bool CheckCollision(Rectangle rec1, Rectangle rec2);
	void DrawMouse();
}