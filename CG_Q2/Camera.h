#pragma once
#include "Ray.h"

class Camera {
public:
    // 예: eye=(0,0,0), U=(1,0,0), V=(0,1,0), W=(0,0,1)
    // (l,r,b,t,d) = (-0.1,0.1, -0.1,0.1, 0.1)
    // (nx, ny)= 512,512
    Camera(const glm::vec3& e,
        const glm::vec3& u,
        const glm::vec3& v,
        const glm::vec3& w,
        float left, float right,
        float bottom, float top,
        float dist,
        int nx, int ny)
        : eye(e), U(u), V(v), W(w),
        l(left), r(right), b(bottom), t(top),
        d(dist), Nx(nx), Ny(ny) {}

    Ray getRay(int i, int j) const
    {
        // 픽셀 중심
        float u_ = l + (r - l) * ((i + 0.5f) / (float)Nx);
        float v_ = b + (t - b) * ((j + 0.5f) / (float)Ny);

        // 스크린 평면상 좌표
        glm::vec3 screenPos = eye - d * W + u_ * U + v_ * V;
        glm::vec3 dir = glm::normalize(screenPos - eye);

        return Ray(eye, dir);
    }

private:
    glm::vec3 eye;
    glm::vec3 U, V, W;
    float l, r, b, t, d;
    int Nx, Ny;
};

