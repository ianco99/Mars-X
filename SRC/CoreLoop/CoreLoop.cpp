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
    int SetScene = 1;

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
}