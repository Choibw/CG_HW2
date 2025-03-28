#pragma once
#include "Ray.h"
#include "Material.h"

// Scene 내 모든 객체(Plane, Sphere)가 상속
class Surface {
public:
    virtual ~Surface() {}

    // 교차 함수:
    //  - ray: 광선
    //  - tMin, tMax: 교차 검사 범위
    //  - out tHit: 교차된 t값 (가장 가까운)
    // 반환값: 교차하면 true, 아니면 false
    virtual bool intersect(const Ray& ray,
        float tMin, float tMax,
        float& tHit) const = 0;

    // 법선 계산 함수
    virtual glm::vec3 getNormal(const glm::vec3& point) const = 0;

    virtual Material getMaterial() const = 0;
};
