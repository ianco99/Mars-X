#include "UFO.h"
#include <cmath>
#include "raylib.h"
#include "../CoreLoop/CoreLoop.h"



namespace OkamiIndustries
{
    const int maxUFOs = 3;
    Rectangle UFOs[maxUFOs];
    bool isTraveling[maxUFOs];
    bool isFlyUp[maxUFOs];
    bool isFlyDown[maxUFOs];
    int speedUFO = 100;

    extern int score;
    const int Ammo = 100;
    extern Circle bullet[Ammo];

    void initUFO()
    {
        for (int i = 0; i < maxUFOs; i++)
        {
            UFOs[i].x = static_cast <float>(-500 * i);
            UFOs[i].y = static_cast <float>(100);
            UFOs[i].width = 50;
            UFOs[i].height = 50;
            isTraveling[i] = true;
            isFlyUp[i] = false;
            isFlyDown[i] = true;
        }
    }

	void MoveUFO()
	{
        int maxLim = 300;
        int minLim = 10;
        int mov = 5;

        for (int i = 0; i < maxUFOs; i++)
        {
            if (isTraveling[i] == true)
            {
                for (int j = 0; j < Ammo; j++)
                {
                    if (CheckCollisionCircleRec(bullet[j].Position, static_cast <float>(bullet[j].Radius), UFOs[i]))
                    {
                        UFOs[i].x = -500 * maxUFOs - 1;
                        score++;
                    }
                }

                UFOs[i].x += speedUFO * GetFrameTime();

                if (isFlyUp[i] == true)
                {
                    UFOs[i].y -= static_cast <float>(sin(speedUFO * GetFrameTime()) * mov);

                    if (UFOs[i].y < minLim)
                    {
                        isFlyUp[i] = false;
                        isFlyDown[i] = true;
                    }

                }

                if (isFlyDown[i] == true)
                {
                    UFOs[i].y += static_cast <float>(sin(speedUFO * GetFrameTime()) * mov);

                    if (UFOs[i].y > maxLim)
                    {
                        isFlyUp[i] = true;
                        isFlyDown[i] = false;
                    }

                }

                if (UFOs[i].x > GetScreenWidth())
                {
                    UFOs[i].x = 0 - UFOs->width;
                }

            }
        }
	}

	void DrawUFO()
	{
        for (int i = 0; i < maxUFOs; i++)
        {
            DrawRectangle(static_cast <int>(UFOs[i].x), static_cast <int>(UFOs[i].y), static_cast <int>(UFOs[i].width), static_cast <int>(UFOs[i].height), SKYBLUE);
        }
	}

}