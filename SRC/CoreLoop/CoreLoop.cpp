#include "CoreLoop.h"
#include "raylib.h"
#include "../Explorer/Explorer.h"
#include "../Obstacles/Obstacles.h"
#include "../MenuLoop/MenuLoop.h"
#include "../CreditsLoop/CreditsLoop.h"
#include "../GameLoop/GameLoop.h"
#include "../Martians/UFO.h"
#include "../Explorer/Bullets/Bullets.h"


namespace OkamiIndustries
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    bool QuitGame = true;

    Texture2D BackgroundGame;
    Texture2D Parallax1Mountains;
    Texture2D Parallax2Clouds;
    Texture2D Parallax3Clouds;
    Texture2D FloorGame;

    int SelectScene = 0;
    int SetScene = 0;
    Rectangle Mouse;
    Vector2 MouseOrigin = { 0,0 };

    void CoreLoop()
    {
        InitWindow(screenWidth, screenHeight, "Okami Industries - Mars X - V0.3");
        SetExitKey(KEY_NULL);
        HideCursor();
        //InitExplorer();
        //InitObstacles();
        //InitBullets();
        //InitUFO();
        InitMenu();
        InitCredits();
        InitMouse();
        InitGame();

        while (!WindowShouldClose() && QuitGame)
        {
            UpdateMouse();

            switch (SetScene)
            {
            case 0:
            {
                MenuLoop();
                break;
            }

            case 1:
            {
                GameLoop(true);
                break;
            }
            case 2:
            {
                GameLoop(false);
                break;
            }
            case 3:
            {
                CreditsLoop();
                break;
            }
            default:
                SetScene = 1;
                break;
            }

            BeginDrawing();

            ClearBackground(BLACK);

            switch (SetScene)
            {
            case 0:
            {
                DrawMenu();
                break;
            }

            case 1:
            case 2:
            {
                DrawGame();
                break;
            }
            case 3:
            {
                DrawCredits();
                break;
            }
            default:
                //SetScene = 1;
                break;
            }

            DrawMouse();
            DrawText("V0.3", 30, 30, 20, RAYWHITE);

            EndDrawing();

        };

        CloseWindow();
    }

	
    bool CheckCollision(Rectangle rec1, Rectangle rec2)
    {
        if (rec1.x < rec2.x + rec2.width &&
            rec1.x + rec1.width > rec2.x &&
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
        Mouse.x = GetMousePosition().x;
        Mouse.y = GetMousePosition().y;
        Mouse.width = 5;
        Mouse.height = 5;
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