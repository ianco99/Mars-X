#pragma once
#include "raylib.h"

namespace OkamiIndustries
{
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