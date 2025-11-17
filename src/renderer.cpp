#include "renderer.h"
#include "raymath.h"
#include <raylib.h>
#include <vector>

void draw_model_with_shader(Model& model, Shader& shader) {
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

Renderer::Renderer(Camera& camera, Shader& shader) :
  camera(camera),
  shader(shader)
{
  SetTargetFPS(60);
}

void Renderer::render(std::vector<Model>& objects) {
  BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(camera);

      for (Model object : objects) {
        draw_model_with_shader(object, shader);
      }

    EndMode3D();
  EndDrawing();
}
