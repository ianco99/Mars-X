#pragma once
#include "raylib.h"

namespace OkamiIndustries
{
	struct Explorer
	{
		Rectangle body;
		Vector2 bodyOrigin;

		Color color;

		float rotation;
		float acceleration;
		float currentGravity;
	};

	void InitExplorer(Explorer& explorer, int id);
	void MoveExplorer(); 
	void MoveExplorer2(); 
	void DrawExplorer(); 
	void DrawExplorer2();
}