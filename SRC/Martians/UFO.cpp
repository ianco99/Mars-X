#include "UFO.h"
#include <cmath>
#include "raylib.h"
#include "../GameLoop/GameLoop.h"
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
    extern Circle bullet2[Ammo];

    extern Texture2D ufoSprite;

    extern bool isLive1;
    extern bool isLive2;

    void InitUFO()
    {
        for (int i = 0; i < maxUFOs; i++)
        {
            UFOs[i].x = static_cast <float>(-500 * i);
            UFOs[i].y = static_cast <float>(100);
            UFOs[i].width = 128;
            UFOs[i].height = 108;
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
                    if ((CheckCollisionCircleRec(bullet[j].Position, static_cast <float>(bullet[j].Radius), UFOs[i])) ||
                        (CheckCollisionCircleRec(bullet2[j].Position, static_cast <float>(bullet2[j].Radius), UFOs[i])))
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
            DrawTexturePro(ufoSprite, { 0,0, static_cast<float>(ufoSprite.width), static_cast<float>(ufoSprite.height) }, UFOs[i], { 0,0 }, 0.0f, RAYWHITE);
            //DrawRectangle(static_cast <int>(UFOs[i].x), static_cast <int>(UFOs[i].y), static_cast <int>(UFOs[i].width), static_cast <int>(UFOs[i].height), SKYBLUE);
        }
	}

}