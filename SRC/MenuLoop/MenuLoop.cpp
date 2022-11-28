#include "MenuLoop.h"
#include "raylib.h"
#include "../CoreLoop/CoreLoop.h"

namespace OkamiIndustries
{
	const int maxButtons = 4;
	float ButtonRotation = 0;
	extern int SelectScene;
	extern int SetScene;
	extern bool stillRunning;
	button Button[maxButtons];
	Vector2 originButton[maxButtons];
	extern Rectangle Mouse;
	extern Texture2D buttonSprite;
	extern Texture2D menuBackgroundSprite;

	void InitMenu()
	{
		buttonSprite = LoadTexture("assets/button.png");
		menuBackgroundSprite = LoadTexture("assets/menuBackground.png");
		for (int i = 0; i < maxButtons; i++)
		{
			Button[i].body.width = static_cast<float>(GetScreenWidth()) / 6;
			Button[i].body.height = static_cast<float>(GetScreenHeight()) / 12;
			Button[i].body.x = static_cast<float>((GetScreenWidth() / 2)) - Button[i].body.width / 2;
			Button[i].body.y = static_cast<float>((GetScreenHeight() / 8) * (i * 1.5f) + GetScreenHeight() / 3) - Button[i].body.height / 2;
			originButton[i] = { 0, 0};
		}

		Button[0].text = "PLAY (1P)";
		Button[1].text = "PLAY (2P)";
		Button[2].text = "CREDITS";
		Button[3].text = "QUIT";
	}

	void MenuLoop()
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			stillRunning = false;
		}

		for (int i = 0; i < maxButtons; i++)
		{
			if (CheckCollisionRecs(Mouse, Button[i].body))
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

		DrawTexturePro(menuBackgroundSprite, { 0,0, static_cast<float>(menuBackgroundSprite.width), static_cast<float>(menuBackgroundSprite.height) }, { 0,0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) }, { 0,0 },  0, GRAY);
		
		DrawTitle(TextFormat("MARS - X"));

		for (int i = 0; i < maxButtons; i++)
		{
			if (SelectScene == i)
			{
				DrawTexturePro(buttonSprite, { 0,0, static_cast<float>(buttonSprite.width), static_cast<float>(buttonSprite.height) }, Button[i].body, originButton[i], ButtonRotation, BEIGE);
				DrawText(TextFormat(Button[i].text), static_cast<int>(Button[i].body.x + Button[i].body.width / 2 - MeasureTextEx(GetFontDefault(), Button[i].text, 42, 0).x / 2), static_cast<int>(Button[i].body.y + MeasureTextEx(GetFontDefault(), Button[i].text, 42, 0).y / 2), 42, WHITE);
			}
			else
			{
				DrawTexturePro(buttonSprite, { 0,0, static_cast<float>(buttonSprite.width), static_cast<float>(buttonSprite.height) }, Button[i].body, originButton[i], ButtonRotation, RAYWHITE);
				DrawText(TextFormat(Button[i].text), static_cast<int>(Button[i].body.x + Button[i].body.width / 2 - MeasureTextEx(GetFontDefault(), Button[i].text, 42, 0).x / 2), static_cast<int>(Button[i].body.y + MeasureTextEx(GetFontDefault(), Button[i].text, 42, 0).y / 2), 42, WHITE);
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