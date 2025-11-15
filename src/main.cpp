#include <iostream>
#include <ranges>

#include "raylib.h"

int main() {
  const int screenWidth { 800 };
  const int screenHeight { 600 };

  InitWindow(screenWidth, screenHeight, "Game");
  SetTargetFPS(60);

  Camera camera {};
  camera.position = { -5.0f, 5.0f, 2.0f };
  camera.target = { 0.0f, 0.0f, 8.0f };
  camera.up = { 0.0f, 1.0f, 0.0f };
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Model cube { LoadModel("models/cube.glb") };
  Mesh mesh = cube.meshes[0];
  if (mesh.colors == NULL) {
    std::cout << "No mesh colours\n";
  } else {
    for (int i = 0;i < mesh.vertexCount;i++) {
      unsigned char r = mesh.colors[i * 4 + 0];
      unsigned char g = mesh.colors[i * 4 + 1];
      unsigned char b = mesh.colors[i * 4 + 2];
      unsigned char a = mesh.colors[i * 4 + 3];

      printf("Vertex: %d %d %d %d\n", r, g, b, a);
    }
  }

  Shader lighting_shader { LoadShader("shaders/lighting.vertex.glsl", "shaders/lighting.fragment.glsl") };
  for (int i = 0;i < cube.materialCount;i++) {
    cube.materials[i].shader = lighting_shader;
  }

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(BLACK);

      BeginMode3D(camera);

          DrawModel(
              cube,
              { 0.0f, 0.0f, 8.0f },
              1.0f,
              WHITE
          );

      EndMode3D();
    EndDrawing();
  }

  UnloadShader(lighting_shader);
  UnloadModel(cube);

  CloseWindow();

  return 0;
}
