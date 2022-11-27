#pragma once
#include <iostream>
#include "raylib.h"

namespace OkamiIndustries
{
	struct button
	{
		Rectangle body;
		const char* text;
	};

	void MenuLoop();
	void DrawMenu();
	void InitMenu();

	void DrawTitle(const char* text);
}