#include "Explorer.h"
#include "raylib.h"

namespace OkamiIndustries
{
	float gravity = 500;
	Rectangle explorer;
	Vector2 explorerOrigin = { explorer.width / 2, explorer.height / 2 };
	int explorerRotation = 0;

	void InitExplorer()
	{
		explorer.width = 50;
		explorer.height = 50;

		explorer.x = static_cast <float>(GetScreenWidth() / 4);
		explorer.y = static_cast <float>((GetScreenHeight() / 4) * 3);
	}

	void MoveExplorer()
	{
		explorer.y = explorer.y + gravity * GetFrameTime();
		if (explorer.y > static_cast <float>((GetScreenHeight() / 4) * 3))
		{
			explorer.y = static_cast <float>((GetScreenHeight() / 4) * 3);
		}

		if (IsKeyPressed(' '))
		{
			gravity = -500;
			
		}
		else
		{
			gravity += 500 * GetFrameTime();
		}

		
	}


	void DrawExplorer()
	{
		DrawRectanglePro(explorer, explorerOrigin, static_cast <float>(explorerRotation), RAYWHITE);
	}
}