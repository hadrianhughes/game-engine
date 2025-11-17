#include <iostream>
#include <ranges>
#include <vector>

#include "raylib.h"
#include "raymath.h"

#include "renderer.h"

int main() {
  const int screenWidth { 800 };
  const int screenHeight { 600 };

  InitWindow(screenWidth, screenHeight, "Game");

  Camera camera {};
  camera.position = { -5.0f, 5.0f, 2.0f };
  camera.target = { 0.0f, 0.0f, 0.0f };
  camera.up = { 0.0f, 1.0f, 0.0f };
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Model cube { LoadModel("models/cube.glb") };
  Shader lighting_shader { LoadShader("shaders/lighting.vertex.glsl", "shaders/lighting.fragment.glsl") };

  Renderer renderer { camera, lighting_shader };

  std::vector<Model> objects { cube };

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(BLACK);
      BeginMode3D(camera);
        renderer.render(objects);
      EndMode3D();
    EndDrawing();
  }

  UnloadShader(lighting_shader);
  UnloadModel(cube);

  CloseWindow();

  return 0;
}
