#include "raylib.h"
#include "CreditsLoop.h"
#include "MenuLoop/MenuLoop.h"
#include "CoreLoop/CoreLoop.h"

namespace OkamiIndustries
{
	float creditsButtonRotation = 0;
	const int maxButtons = 3;
	extern int SelectScene;
	extern CoreScreens SetScene;
	extern bool stillRunning;

	bool hoverBackButton;

	button creditsButton[maxButtons];
	Vector2 creditsOriginButton[maxButtons];
	extern Rectangle Mouse;
	extern Texture2D buttonSprite;

	void InitCredits()
	{
		InitBackButton();

		//Background art hyperlink
		creditsButton[1].body = { static_cast<float>(GetScreenWidth() / 5 - static_cast<float>(MeasureText("ansimuz", 36)),  (static_cast<float>(GetScreenHeight()) / 8) * 5 + 50 , static_cast<float>(MeasureTextEx(GetFontDefault(),"ansimuz", 36,0).x, static_cast<float>(MeasureTextEx(GetFontDefault(),"ansimuz", 36,0).y))) };
			//static_cast<int>(GetScreenWidth()) / 5 - static_cast<int>(MeasureText("ansimuz", 36)) / 2, (static_cast<int>(GetScreenHeight()) / 8) * 5 + 50
	}

	void InitBackButton()
	{
		creditsButton[0].body.x = static_cast<float>((GetScreenWidth() / 6));
		creditsButton[0].body.y = static_cast<float>((GetScreenHeight() - GetScreenHeight() / 4));
		creditsButton[0].body.width = static_cast<float>(GetScreenWidth()) / 8;
		creditsButton[0].body.height = static_cast<float>(GetScreenHeight()) / 12;
		creditsOriginButton[0] = { 0, 0 };

		creditsButton[0].text = "BACK";
	}

	void CreditsLoop()
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			SetScene = CoreScreens::MainMenu;
		}

		for (int i = 0; i < maxButtons; i++)
		{
			if (CheckCollisionRecs(Mouse, creditsButton[i].body))
			{
				hoverBackButton = true;

				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					if (i == 0)
						SetScene = CoreScreens::MainMenu;


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
		DrawText("Lead Game Programmer:", static_cast<int>(GetScreenWidth()) / 2 - static_cast<int>(MeasureText("Lead Game Programmer:", 36)) / 2, static_cast<int>(GetScreenHeight()) / 4, 36, RAYWHITE);
		DrawText("Tomas Porte Petit", static_cast<int>(GetScreenWidth()) / 2 - static_cast<int>(MeasureText("Tomas Porte Petit", 36)) / 2, static_cast<int>(GetScreenHeight()) / 3, 36, RAYWHITE);

		DrawText("Game Programmer:", static_cast<int>(GetScreenWidth()) / 2 - static_cast<int>(MeasureText("Game Programmer:", 36)) / 2, static_cast<int>(GetScreenHeight()) / 4 + static_cast<int>(GetScreenHeight()) / 6, 36, RAYWHITE);
		DrawText("Ian Kuznicki", static_cast<int>(GetScreenWidth()) / 2 - static_cast<int>(MeasureText("Ian Kuznicki", 36)) / 2, static_cast<int>(GetScreenHeight()) / 3 + static_cast<int>(GetScreenHeight()) / 6, 36, RAYWHITE);

		DrawText("Astronaut Art:", static_cast<int>(GetScreenWidth()) - static_cast<int>(GetScreenWidth()) / 4 - static_cast<int>(MeasureText("Astronaut Art:", 36)) / 2, (static_cast<int>(GetScreenHeight()) / 8) * 5, 36, RAYWHITE);
		DrawText("Nathan_4312", static_cast<int>(GetScreenWidth()) - static_cast<int>(GetScreenWidth()) / 4 - static_cast<int>(MeasureText("Nathan_4312", 36)) / 2, (static_cast<int>(GetScreenHeight()) / 8) * 5 + 50, 36, SKYBLUE);

		DrawText("Alien Art:", static_cast<int>(GetScreenWidth()) / 3 - static_cast<int>(MeasureText("Alien Art:", 36)) / 2, (static_cast<int>(GetScreenHeight()) / 8) * 5, 36, RAYWHITE);
		DrawText("raghuram8892", static_cast<int>(GetScreenWidth()) / 3 - static_cast<int>(MeasureText("raghuram8892", 36)) / 2, (static_cast<int>(GetScreenHeight()) / 8) * 5 + 50, 36, SKYBLUE);

		DrawText("Ufo Art:", static_cast<int>(GetScreenWidth()) / 2 - static_cast<int>(MeasureText("Ufo Art:", 36)) / 2, (static_cast<int>(GetScreenHeight()) / 8) * 5, 36, RAYWHITE);
		DrawText("bevouliin.com", static_cast<int>(GetScreenWidth()) / 2 - static_cast<int>(MeasureText("bevouliin.com", 36)) / 2, (static_cast<int>(GetScreenHeight()) / 8) * 5 + 50, 36, SKYBLUE);

		DrawText("UI Buttons Art:", static_cast<int>(GetScreenWidth()) - static_cast<int>(GetScreenWidth()) / 3 - static_cast<int>(MeasureText("UI Buttons Art:", 36)) / 2, (static_cast<int>(GetScreenHeight()) / 8) * 6, 36, RAYWHITE);
		DrawText("Kenney", static_cast<int>(GetScreenWidth()) - static_cast<int>(GetScreenWidth()) / 3 - static_cast<int>(MeasureText("Kenney", 36)) / 2, (static_cast<int>(GetScreenHeight()) / 8) * 6 + 50, 36, SKYBLUE);

		DrawText("Background Art:", static_cast<int>(GetScreenWidth()) - static_cast<int>(GetScreenWidth()) / 5 * 3 - static_cast<int>(MeasureText("Background art:", 36)) / 2, (static_cast<int>(GetScreenHeight()) / 8) * 6, 36, RAYWHITE);
		DrawText("ansimuz", static_cast<int>(GetScreenWidth()) - static_cast<int>(GetScreenWidth()) / 5 * 3 - static_cast<int>(MeasureText("ansimuz", 36)) / 2, (static_cast<int>(GetScreenHeight()) / 8) * 6 + 50, 36, SKYBLUE);

		if (hoverBackButton)
		{
			DrawTexturePro(buttonSprite, { 0,0, static_cast<float>(buttonSprite.width), static_cast<float>(buttonSprite.height) }, creditsButton[0].body, creditsOriginButton[0], creditsButtonRotation, BEIGE);
			DrawText(TextFormat(creditsButton[0].text), static_cast<int>(creditsButton[0].body.x + creditsButton[0].body.width / 2 - MeasureTextEx(GetFontDefault(), creditsButton[0].text, 42, 0).x / 2), static_cast<int>(creditsButton[0].body.y + MeasureTextEx(GetFontDefault(), "BACK", 42, 0).y / 2), 42, WHITE);
			//DrawRectanglePro(creditsButton[0], creditsOriginButton[0], creditsButtonRotation, RED);
		}
		else
		{
			DrawTexturePro(buttonSprite, { 0,0, static_cast<float>(buttonSprite.width), static_cast<float>(buttonSprite.height) }, creditsButton[0].body, creditsOriginButton[0], creditsButtonRotation, RAYWHITE);
			DrawText(TextFormat(creditsButton[0].text), static_cast<int>(creditsButton[0].body.x + creditsButton[0].body.width / 2 - MeasureTextEx(GetFontDefault(), creditsButton[0].text, 42, 0).x / 2), static_cast<int>(creditsButton[0].body.y + MeasureTextEx(GetFontDefault(), "BACK", 42, 0).y / 2), 42, WHITE);
			//DrawRectanglePro(creditsButton[0], creditsOriginButton[0], creditsButtonRotation, RAYWHITE);
		}


	}
}
