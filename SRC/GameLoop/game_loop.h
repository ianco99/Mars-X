#pragma once
#include "raylib.h"

namespace OkamiIndustries
{
	struct BackgroundImage
	{
		int speed;
		Rectangle body;
		Texture2D sprite;
	};

	void GameLoop(bool singlePlayer);
	void InitGame();
	void DrawGame();
	void UnloadGame();
}