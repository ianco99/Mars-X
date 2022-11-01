#pragma once
#include "raylib.h"

namespace OkamiIndustries
{
	void CoreLoop();
	bool CheckCollision(Rectangle rec1, Rectangle rec2);
	static void InitMouse();
	static void UpdateMouse();
	static void DrawMouse();
}