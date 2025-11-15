#include <iostream>

#include "raylib.h"

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "Game");
  SetTargetFPS(60);

  Camera camera {};
  camera.position = { 0.0f, 0.0f, 3.0f };
  camera.target = { 0.0f, 0.0f, 0.0f };
  camera.up = { 0.0f, 1.0f, 0.0f };
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Model monk = LoadModel("models/monk.glb");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(camera);

    DrawModel(
        monk,
        { 0.0f, -1.5f, 0.0f },
        1.0f,
        WHITE
    );

    EndMode3D();
    EndDrawing();
  }

  UnloadModel(monk);

  CloseWindow();

  return 0;
}
