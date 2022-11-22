#pragma once
#include "raylib.h"
namespace OkamiIndustries
{
	struct Explorer
	{
		Rectangle body;
		Vector2 bodyOrigin;

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