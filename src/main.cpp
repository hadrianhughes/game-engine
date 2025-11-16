#include <iostream>
#include <ranges>

#include "raylib.h"
#include "raymath.h"

void draw_model_with_shader(Model model, Shader shader) {
  for (int i = 0;i < model.meshCount;i++) {
    int matIndex { model.meshMaterial[i] };
    Material &mat { model.materials[matIndex] };

    mat.shader = shader;

    Color color { mat.maps[MATERIAL_MAP_DIFFUSE].color };
    Vector4 diffuse {
      color.r / 255.0f,
      color.g / 255.0f,
      color.b / 255.0f,
      color.a / 255.0f
    };

    int locDiffuse { GetShaderLocation(shader, "matDiffuse") };
    SetShaderValue(shader, locDiffuse, &diffuse, SHADER_UNIFORM_VEC4);

    DrawMesh(model.meshes[i], mat, MatrixIdentity());
  }
}

int main() {
  const int screenWidth { 800 };
  const int screenHeight { 600 };

  InitWindow(screenWidth, screenHeight, "Game");
  SetTargetFPS(60);

  Camera camera {};
  camera.position = { -5.0f, 5.0f, 2.0f };
  camera.target = { 0.0f, 0.0f, 0.0f };
  camera.up = { 0.0f, 1.0f, 0.0f };
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Model cube { LoadModel("models/cube-materials.glb") };
  Shader lighting_shader { LoadShader("shaders/lighting.vertex.glsl", "shaders/lighting.fragment.glsl") };

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(BLACK);

      BeginMode3D(camera);
        draw_model_with_shader(cube, lighting_shader);
      EndMode3D();
    EndDrawing();
  }

  UnloadShader(lighting_shader);
  UnloadModel(cube);

  CloseWindow();

  return 0;
}
