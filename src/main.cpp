#include <iostream>

#include "raylib.h"

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "Game");
  SetTargetFPS(60);

  Camera camera {};
  camera.position = { 1.0f, 3.0f, 3.0f };
  camera.target = { 0.0f, 0.0f, 0.0f };
  camera.up = { 0.0f, 1.0f, 0.0f };
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(camera);

    DrawCube(
        { 0.0f, 0.5f, 0.0f },
        1.0f,
        1.0f,
        1.0f,
        GREEN
    );

    EndMode3D();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
