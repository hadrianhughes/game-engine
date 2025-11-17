#ifndef RENDERER_H_
#define RENDERER_H_

#include <vector>

#include "raylib.h"

class Renderer {
  public:
    Renderer(Camera& camera, Shader& shader);
    void render(std::vector<Model>& objects);
    void add_object(Model& object);
  private:
    Camera& camera;
    Shader shader;
};

#endif
