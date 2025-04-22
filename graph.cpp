
#include "raylib.h"
#include <cmath>
#include <vector>
#include <iostream>

//void cord(std::vector<Vector4> &arr , std::vector<Vector2>& lines);
void Drawdots(std::vector<Vector2> dd, int max_num , std::vector<Vector2> num_cord);
void drawlines(std::vector<Vector2> ff, std::vector<Vector2> dd , std::vector<Vector2> num_cord);

int hAw = 900;

int center = hAw / 2;

int main()
{
	int center = hAw / 2;
	int r = 300;

	std::vector<Vector2> g = {  };
	std::vector<Vector2> cords;
	std::vector<Vector2> cord_num;

	int start;
	int finish;

	std::cout << "inputs : \n";

	while (true)
	{
		std::cin >> start;

		if (start <= 0)
		{
			break;
		}
		else
		{
			std::cin >> finish;

			if (finish <= 0)
			{
				break;
			}

			Vector2 hmm;
			hmm.x = start;
			hmm.y = finish;
			g.push_back(hmm);
		}
	}

	int max_number = 0;

	for (int i = 0; i < g.size(); i++)
	{
		if (g[i].x > max_number)
		{
			max_number = g[i].x;
		}

		if (g[i].y > max_number)
		{
			max_number = g[i].y;
		}
	}

	float angle = 180 - (((float)max_number - 2) * 180 / (float)max_number);

	float teta = 180;

	for (int i = 0; i < max_number; i++)
	{
		float y = r * cos(teta * PI / 180);
		float x = r * sin(teta * PI / 180);

		float num_y = (r + 30) * cos(teta * PI / 180);
		float num_x = (r + 30) * sin(teta * PI / 180);

		cords.push_back({ x + center , y + center });
		cord_num.push_back({num_x + center - 5 , num_y + center - 5});

		//DrawCircle(x + center, y + center, 5, WHITE);

		teta = teta - angle;

	}

	InitWindow(hAw, hAw, "booo");

	SetTargetFPS(60);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		Drawdots(cords, max_number , cord_num);
		drawlines(g, cords , cord_num);
		ClearBackground(BLACK);

		EndDrawing();
	}

}

void drawlines(std::vector<Vector2> ff, std::vector<Vector2> dd , std::vector<Vector2> num_cord)
{
	for (int i = 0; i < ff.size(); i++)
	{
		int first = ff[i].x;
		int second = ff[i].y;

		DrawLine(dd[first - 1].x, dd[first - 1].y, dd[second - 1].x, dd[second - 1].y, WHITE);

		float ddd = atan2(dd[second - 1].y - dd[first - 1].y, dd[second - 1].x - dd[first - 1].x) * 180 / PI;

		float d = ddd + 45;

		float dm25 = d + 55 + 5;
		float dp25 = d + 35 - 5;

		float x = dd[second - 1].x;
		float y = dd[second - 1].y;

		float fpx = 25 * sin(-dp25 * PI / 180);
		float fpy = 25 * cos(-dp25 * PI / 180);

		float fmx = 25 * sin(-dm25 * PI / 180);
		float fmy = 25 * cos(dm25 * PI / 180);
			
		Color temp = WHITE;

		if (first == second)
		{
			DrawCircleLines(dd[i].x, dd[i].y , 15 , BLUE);
		}
		else
		{
			DrawLine(x, y, fpx + x, fpy + y, temp);
			DrawLine(x, y, fmx + x, fmy + y, temp);
		}
		//DrawLine(dd[second - 1].x, dd[second - 1].y, 20 * sin(d) + center, 20 * cos(d) + center, WHITE);

	}
}

void Drawdots(std::vector<Vector2> dd, int max_num, std::vector<Vector2> num_cord)
{
	for (int i = 0; i < max_num; i++)
	{
		DrawCircle(dd[i].x, dd[i].y, 5, WHITE);
		DrawText(TextFormat("%i", i+1), num_cord[i].x, num_cord[i].y, 20, WHITE);
	}
}