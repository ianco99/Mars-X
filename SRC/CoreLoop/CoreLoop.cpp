#include "CoreLoop.h"
#include "raylib.h"
#include "Explorer/Explorer.h"
#include "Obstacles/Obstacles.h"
#include "MenuLoop/MenuLoop.h"
#include "CreditsLoop/CreditsLoop.h"
#include "GameLoop/GameLoop.h"
#include "Martians/UFO.h"
#include "Explorer/Bullets/Bullets.h"


namespace OkamiIndustries
{
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	bool stillRunning = true;

	Texture2D menuBackgroundSprite;

	Texture2D BackgroundGame;
	Texture2D Parallax1Mountains;
	Texture2D Parallax2Clouds;
	Texture2D Parallax3Clouds;
	Texture2D FloorGame;

	Texture2D buttonSprite;

	int SelectScene = 0;
	CoreScreens SetScene = CoreScreens::MainMenu;
	Rectangle Mouse;
	Vector2 MouseOrigin = { 0,0 };

	void CoreLoop()
	{
		InitWindow(screenWidth, screenHeight, "Okami Industries - Mars X - V1.1");
		SetExitKey(KEY_NULL);
		HideCursor();
		InitGame();
		InitMenu();
		InitCredits();
		InitMouse();

		while (!WindowShouldClose() && stillRunning)
		{
			UpdateMouse();

			switch (SetScene)
			{
			case CoreScreens::MainMenu:
			{
				MenuLoop();
				break;
			}

			case CoreScreens::Play1P:
			{
				GameLoop(true);
				break;
			}
			case CoreScreens::Play2P:
			{
				GameLoop(false);
				break;
			}
			case CoreScreens::CreditsMenu:
			{
				CreditsLoop();
				break;
			}
			default:

				SetScene = CoreScreens::Play1P;
				break;
			}

			BeginDrawing();

			ClearBackground(BLACK);

			switch (SetScene)
			{
			case CoreScreens::MainMenu:
			{
				DrawMenu();
				break;
			}

			case CoreScreens::Play1P:
			case CoreScreens::Play2P:
			{
				DrawGame();
				break;
			}
			case CoreScreens::CreditsMenu:
			{
				DrawCredits();
				break;
			}
			case CoreScreens::Quit:
			{
				stillRunning = false;
				break;
			}

			default:
				break;
			}

			DrawMouse();
			DrawText("V1.1", 30, 30, 20, RAYWHITE);

			EndDrawing();

		};

		CloseWindow();
	}


	bool CheckCollision(Rectangle rec1, Rectangle rec2)
	{
		if (rec1.x < rec2.x + rec2.width &&
			rec1.x + rec1.width > rec2.x&&
			rec1.y < rec2.y + rec2.height &&
			rec1.height + rec1.y > rec2.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static void InitMouse()
	{
		int mouseWidth = 5;
		int mouseHeight = 5;

		Mouse.x = GetMousePosition().x;
		Mouse.y = GetMousePosition().y;
		Mouse.width = mouseWidth;
		Mouse.height = mouseHeight;
	}

	static void UpdateMouse()
	{
		Mouse.x = GetMousePosition().x;
		Mouse.y = GetMousePosition().y;
	}

	static void DrawMouse()
	{
		DrawRectanglePro(Mouse, MouseOrigin, 0, YELLOW);
	}

}