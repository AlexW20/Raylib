#include <iostream>
#include "model.h"
#include "view.h"
#include "raylib.h"
#include "shape.h"
#include <vector>
#include <string>
#include <cstdlib>  
#include <ctime>   
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;

void play();
int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Same Game");
    SetTargetFPS(60);

    play();

    CloseWindow();
}

void play() {
    GameBoard gb;
    view view(gb);
    int numberOfMoves = 0;
    string scoreText;
    while (!WindowShouldClose()) {
        BeginDrawing();

        view.display();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

            Vector2 mousePosition = GetMousePosition();
            if (gb.getColor(mousePosition.y / 200, mousePosition.x / 200) != Colors::Empty) {
                gb.remove(mousePosition.y / 200, mousePosition.x / 200);
                numberOfMoves++;
                string text = "Score: ";
                scoreText = text + std::to_string(numberOfMoves);
            }
        }
        while (gb.stillFloatingColors()) {
            continue;
        }

        DrawText(scoreText.c_str(), 5, 10, 50, BLACK);
        EndDrawing();
        while (!gb.stillColors() && !WindowShouldClose()) {
            view.display();
            BeginDrawing();
            string text = "Score: ";
            scoreText = text + std::to_string(numberOfMoves);
            DrawText(scoreText.c_str(), 5, 10, 50, RED);
            DrawText("Game Over", 300, 200, 50, BLACK);
            DrawText("Click Anywhere to end", 300, 300, 50, BLACK);
            EndDrawing();
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
                return;
            }
        }

    }
    EndDrawing();

    CloseWindow();

}
