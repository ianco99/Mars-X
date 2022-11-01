#include "CoreLoop.h"
#include "raylib.h"
#include "../Explorer/Explorer.h"
#include "../Obstacles/Obstacles.h"
#include "../MenuLoop/MenuLoop.h"


namespace OkamiIndustries
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    int SelectScene = 0;
    int SetScene = 0;

	void CoreLoop()
	{

        InitWindow(screenWidth, screenHeight, "Okami Industries - Mars X - V0.1");
        InitExplorer();
        InitObstacles();
        InitMenu();
               
        while (!WindowShouldClose())
        {

            switch (SetScene)
            {
                case 0:
                {
                    MenuLoop();
                    break;
                }

                case 1:
                {
                    MoveExplorer();
                    MoveObstacles();
                    break;
                }
            default:
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
                {
                    DrawExplorer();
                    DrawObstacles();
                    break;
                }
            default:
                break;
            }

            DrawText("V0.1", 30, 30, 20, RAYWHITE);

            EndDrawing();

        }
            
        CloseWindow(); 
    }

	
}