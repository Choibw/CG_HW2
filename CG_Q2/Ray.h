#pragma once
#include <glm/glm.hpp>

// 단순 Ray: origin + direction
class Ray {
public:
    Ray() {}
    Ray(const glm::vec3& o, const glm::vec3& d)
        : origin(o), direction(glm::normalize(d)) {}

    // 파라미터 t로 광선 위의 점 반환
    glm::vec3 evaluate(float t) const {
        return origin + t * direction;
    }

    glm::vec3 origin;
    glm::vec3 direction;
};