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
	};

	void InitExplorer1();
	void InitExplorer2();
	void MoveExplorer(); 
	void MoveExplorer2(); 
	void DrawExplorer(); 
	void DrawExplorer2();
}