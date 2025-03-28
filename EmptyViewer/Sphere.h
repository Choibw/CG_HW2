#pragma once
#include "Surface.h"
#include "Material.h"
#include <cmath>

class Sphere : public Surface {
public:
    Sphere(const glm::vec3& c, float r, const Material& m)
        : center(c), radius(r), material(m) {}

    bool intersect(const Ray& ray,
        float tMin, float tMax,
        float& tHit) const override
    {
        // 이차방정식 a·t^2 + b·t + c=0
        glm::vec3 oc = ray.origin - center;
        float a = glm::dot(ray.direction, ray.direction);
        float b = 2.0f * glm::dot(oc, ray.direction);
        float c_ = glm::dot(oc, oc) - radius * radius;

        float disc = b * b - 4 * a * c_;
        if (disc < 0.0f) return false; // 실근 없음

        float sqrtDisc = sqrtf(disc);
        float t1 = (-b - sqrtDisc) / (2 * a);
        float t2 = (-b + sqrtDisc) / (2 * a);
        if (t1 > t2) std::swap(t1, t2);

        // t1이 유효 범위에 있는지 확인
        if (t1 < tMin) t1 = t2; // t1이 너무 작으면 t2 사용
        if (t1 < tMin || t1 > tMax) return false;

        tHit = t1;
        return true;
    }

    glm::vec3 getNormal(const glm::vec3& point) const override {
        // 구의 표면 법선 = (p - center) / radius
        // point는 교차점
        return glm::normalize(point - center);
    }

    Material getMaterial() const override {
        return material;
    }

private:
    glm::vec3 center;
    float radius;
    Material material;
};
