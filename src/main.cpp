#include <iostream>
#include <ranges>

#include "raylib.h"

int main() {
  const int screenWidth { 800 };
  const int screenHeight { 600 };

  InitWindow(screenWidth, screenHeight, "Game");
  SetTargetFPS(60);

  Camera camera {};
  camera.position = { 0.0f, 0.0f, 3.0f };
  camera.target = { 0.0f, 0.0f, 0.0f };
  camera.up = { 0.0f, 1.0f, 0.0f };
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Model monk { LoadModel("models/monk.glb") };

  Shader lighting_shader { LoadShader("shaders/lighting.vertex.glsl", "shaders/lighting.fragment.glsl") };
  Vector3 color { 1.0f, 1.0f, 1.0f };

  SetShaderValue(
    lighting_shader,
    GetShaderLocation(lighting_shader, "surfaceColor"),
    &color,
    SHADER_UNIFORM_VEC3
  );

  for (int i = 0;i < monk.materialCount;i++) {
    monk.materials[i].shader = lighting_shader;
  }

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

  UnloadShader(lighting_shader);
  UnloadModel(monk);

  CloseWindow();

  return 0;
}
