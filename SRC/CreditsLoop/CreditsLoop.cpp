#include "raylib.h"
#include "CreditsLoop.h"

namespace OkamiIndustries
{
	float creditsButtonRotation = 0;
	const int maxButtons = 3;
	extern int SelectScene;
	extern int SetScene;
	extern bool QuitGame;

	bool hoverBackButton;

	Rectangle creditsButton[maxButtons];
	Vector2 creditsOriginButton[maxButtons];
	extern Rectangle Mouse;

	void InitCredits()
	{
		creditsButton[0].x = static_cast<float>((GetScreenWidth() / 6));
		creditsButton[0].y = static_cast<float>((GetScreenHeight() - GetScreenHeight() / 4));
		creditsButton[0].width = static_cast<float>(GetScreenWidth()) / 8;
		creditsButton[0].height = static_cast<float>(GetScreenHeight()) / 12;
		creditsOriginButton[0] = { 0, 0 };
	}

	void CreditsLoop()
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			SetScene = 0;
		}

		for (int i = 0; i < maxButtons; i++)
		{
			if (CheckCollisionRecs(Mouse, creditsButton[i]))
			{
				hoverBackButton = true;

				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					SetScene = 0;
				}
			}
		}
	}

	void DrawCredits()
	{
		DrawText("Lead Game Programmer:", static_cast<int>(GetScreenWidth()) / 2 - static_cast<int>(MeasureText("Lead Game Programmer:", 36)) / 2,	static_cast<int>(GetScreenHeight()) / 4, 36,RAYWHITE);
		DrawText("Tomas Porte Petit", static_cast<int>(GetScreenWidth()) / 2 - static_cast<int>(MeasureText("Tomas Porte Petit", 36)) / 2,	static_cast<int>(GetScreenHeight()) / 3, 36,RAYWHITE);

		DrawText("Game Programmer:", static_cast<int>(GetScreenWidth()) / 2 - static_cast<int>(MeasureText("Game Programmer:", 36)) / 2, static_cast<int>(GetScreenHeight()) / 4 + static_cast<int>(GetScreenHeight()) / 6, 36, RAYWHITE);
		DrawText("Ian Kuznicki", static_cast<int>(GetScreenWidth()) / 2 - static_cast<int>(MeasureText("Ian Kuznicki", 36)) / 2, static_cast<int>(GetScreenHeight()) / 3 + static_cast<int>(GetScreenHeight()) / 6, 36, RAYWHITE);

		for (int i = 0; i < maxButtons; i++)
		{
			if (hoverBackButton)
			{
				DrawRectanglePro(creditsButton[0], creditsOriginButton[0], creditsButtonRotation, RED);
			}
			else
			{

				DrawRectanglePro(creditsButton[0], creditsOriginButton[0], creditsButtonRotation, RAYWHITE);
			}
		}
	}
}
