#include "core_loop.h"

#include "MenuLoop/menu_loop.h"
#include "CreditsLoop/credits_loop.h"
#include "GameLoop/game_loop.h"


namespace OkamiIndustries
{

	CoreScreens SetScene = CoreScreens::MainMenu;

	Rectangle Mouse;
	Vector2 MouseOrigin = { 0,0 };

	Texture2D menuBackgroundSprite;
	Texture2D BackgroundGame;
	Texture2D Parallax1Mountains;
	Texture2D Parallax2Clouds;
	Texture2D Parallax3Clouds;
	Texture2D FloorGame;
	Texture2D buttonSprite;
	
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	bool stillRunning = true;
	int SelectScene = 0;

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

		UnloadGame();
		UnloadMenu();

		CloseWindow();
	}

	void InitMouse()
	{
		int mouseWidth = 5;
		int mouseHeight = 5;

		Mouse.x = GetMousePosition().x;
		Mouse.y = GetMousePosition().y;
		Mouse.width = static_cast<float>(mouseWidth);
		Mouse.height = static_cast<float>(mouseHeight);
	}

	void UpdateMouse()
	{
		Mouse.x = GetMousePosition().x;
		Mouse.y = GetMousePosition().y;
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

	void DrawMouse()
	{
		DrawRectanglePro(Mouse, MouseOrigin, 0, YELLOW);
	}

}