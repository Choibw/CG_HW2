#pragma once
#include "Surface.h"
#include <vector>
#include <limits>

class Scene {
public:
    void addObject(Surface* obj) {
        objects.push_back(obj);
    }

    // ray와 장면의 모든 오브젝트 교차 -> 가장 가까운 교차 찾기
    // 교차 없으면 nullptr
    Surface* trace(const Ray& ray, float tMin, float tMax, float& tHit) const
    {
        Surface* hitSurf = nullptr;
        float closest = std::numeric_limits<float>::max();

        for (auto obj : objects) {
            float tempT;
            if (obj->intersect(ray, tMin, tMax, tempT)) {
                if (tempT < closest) {
                    closest = tempT;
                    hitSurf = obj;
                }
            }
        }

        if (hitSurf) {
            tHit = closest;
        }
        return hitSurf;
    }

private:
    std::vector<Surface*> objects;
};
