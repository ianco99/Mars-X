#pragma once
#include "raylib.h"

namespace OkamiIndustries
{
	struct Explorer
	{
		Rectangle body;
		Vector2 bodyOrigin;

		Color color;

		bool isAlive;
		float rotation;
		float acceleration;
		float currentGravity;
		int id;
	};

	void InitExplorer(Explorer& explorer, int id);
	void MoveExplorer(Explorer& explorer); 
	void DrawExplorer(Explorer& explorer); 
}