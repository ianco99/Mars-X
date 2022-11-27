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
	extern Texture2D buttonSprite;

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
				break;
			}
			else
			{
				hoverBackButton = false;
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
				DrawTexturePro(buttonSprite, { 0,0, static_cast<float>(buttonSprite.width), static_cast<float>(buttonSprite.height) }, creditsButton[0], creditsOriginButton[0], creditsButtonRotation, BEIGE);
				//DrawText(TextFormat(Button[i].text), static_cast<int>(Button[i].body.x + MeasureTextEx(GetFontDefault(), "PLAY (1P)", 42, 0).x / 2), static_cast<int>(Button[i].body.y + MeasureTextEx(GetFontDefault(), "PLAY (1P)", 42, 0).y / 2), 42, WHITE);
				//DrawRectanglePro(creditsButton[0], creditsOriginButton[0], creditsButtonRotation, RED);
			}
			else
			{
				DrawTexturePro(buttonSprite, { 0,0, static_cast<float>(buttonSprite.width), static_cast<float>(buttonSprite.height) }, creditsButton[0], creditsOriginButton[0], creditsButtonRotation, RAYWHITE);
			//	DrawText(TextFormat(Button[i].text), static_cast<int>(Button[i].body.x + MeasureTextEx(GetFontDefault(), "PLAY (1P)", 42, 0).x / 2), static_cast<int>(Button[i].body.y + MeasureTextEx(GetFontDefault(), "PLAY (1P)", 42, 0).y / 2), 42, WHITE);
				//DrawRectanglePro(creditsButton[0], creditsOriginButton[0], creditsButtonRotation, RAYWHITE);
			}
		}
	}
}
