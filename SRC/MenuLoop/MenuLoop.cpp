#include "MenuLoop.h"
#include "raylib.h"


namespace OkamiIndustries
{
	const int maxButtons = 4;
	float ButtonRotation = 0;
	Rectangle Button[maxButtons];
	Vector2 originButton[maxButtons];

	void InitMenu()
	{
		for (int i = 0; i < maxButtons; i++)
		{
			Button[i].width = 400;
			Button[i].height = 100;
			Button[i].x = static_cast <float>((GetScreenWidth() / 2));
			Button[i].y = static_cast <float>((GetScreenHeight() / 8) * (i * 1.5f) + GetScreenHeight() / 3);
			originButton[i] = { Button[i].width / 2, Button[i].height / 2 };
		}
	}

	void MenuLoop()
	{

	}

	void DrawMenu()
	{
		for (int i = 0; i < maxButtons; i++)
		{
			DrawRectanglePro(Button[i], originButton[i], ButtonRotation, RAYWHITE);
		}
	}
}