#pragma once
#include <glm/glm.hpp>

class Light {
public:
    Light(const glm::vec3& pos, const glm::vec3& color, const glm::vec3& ambient)
        : position(pos), lightColor(color), ambient(ambient) {}

    glm::vec3 getPosition() const { return position; }
    glm::vec3 getColor() const { return lightColor; }
    glm::vec3 getAmbient() const { return ambient; }

private:
    glm::vec3 position;
    glm::vec3 lightColor;
    glm::vec3 ambient;
};

