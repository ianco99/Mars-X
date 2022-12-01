#pragma once
#include <iostream>
#include "raylib.h"

namespace OkamiIndustries
{
	struct button
	{
		Rectangle body;
		const char* text;
		const char* link;
	};

	void MenuLoop();
	void DrawMenu();
	void InitMenu();
	void UnloadMenu();
	void DrawTitle(const char* text);
}