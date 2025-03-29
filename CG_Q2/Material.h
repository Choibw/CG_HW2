#pragma once
#include <glm/glm.hpp>

struct Material {
    glm::vec3 ka;       // ambient reflectance
    glm::vec3 kd;       // diffuse reflectance
    glm::vec3 ks;       // specular reflectance
    float shininess;    // specular exponent
};
