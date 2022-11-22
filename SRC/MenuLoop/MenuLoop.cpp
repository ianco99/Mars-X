#include "MenuLoop.h"
#include "raylib.h"
#include "../CoreLoop/CoreLoop.h"

namespace OkamiIndustries
{
	const int maxButtons = 4;
	float ButtonRotation = 0;
	extern int SelectScene;
	extern int SetScene;
	extern bool QuitGame;
	Rectangle Button[maxButtons];
	Vector2 originButton[maxButtons];
	extern Rectangle Mouse;

	void InitMenu()
	{
		for (int i = 0; i < maxButtons; i++)
		{
			Button[i].width = static_cast<float>(GetScreenWidth()) / 6;
			Button[i].height = static_cast<float>(GetScreenHeight()) / 12;
			Button[i].x = static_cast<float>((GetScreenWidth() / 2)) - Button[i].width / 2;
			Button[i].y = static_cast<float>((GetScreenHeight() / 8) * (i * 1.5f) + GetScreenHeight() / 3) - Button[i].height / 2;
			originButton[i] = { 0, 0};
		}
	}

	void MenuLoop()
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			QuitGame = false;
		}

		for (int i = 0; i < maxButtons; i++)
		{
			if (CheckCollisionRecs(Mouse, Button[i]))
			{
				SelectScene = i;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					SetScene = SelectScene + 1;
				}
			}
		}
	}

	void DrawMenu()
	{

		DrawTitle(TextFormat("MARS - X"));

		for (int i = 0; i < maxButtons; i++)
		{
			if (SelectScene == i)
			{
				DrawRectanglePro(Button[i], originButton[i], ButtonRotation, RED);
			}
			else
			{

				DrawRectanglePro(Button[i], originButton[i], ButtonRotation, RAYWHITE);
			}
		}
	}

	void DrawTitle(const char* text)
	{
		DrawText(text,
			static_cast<int>(GetScreenWidth()) / 2 - static_cast<int>(MeasureText(text, 46)) / 2,
			static_cast<int>(GetScreenHeight()) / 7,
			48,
			RAYWHITE);
	}
}