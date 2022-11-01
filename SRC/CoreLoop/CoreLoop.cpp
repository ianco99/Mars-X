#include "CoreLoop.h"
#include "raylib.h"
#include "../Explorer/Explorer.h"
#include "../Obstacles/Obstacles.h"


namespace OkamiIndustries
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

	void CoreLoop()
	{

        InitWindow(screenWidth, screenHeight, "Okami Industries - Mars X - V0.1");
        InitExplorer();
        InitObstacles();
               
        while (!WindowShouldClose())
        {
            MoveExplorer();
            MoveObstacles();

            BeginDrawing();

            ClearBackground(BLACK);

            DrawExplorer();
            DrawObstacles();

            DrawText("V0.1", 30, 30, 20, RAYWHITE);

            EndDrawing();

        }
            
        CloseWindow(); 
    }

	
}