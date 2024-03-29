//
// Created by Hossam Samir on 07/01/2023.
//

#ifndef GAME_ENGINE_MATH_MATRIX3D_H
#define GAME_ENGINE_MATH_MATRIX3D_H

#include "Vector3D.h"

struct Matrix3D {
private:
    float n[3][3];
public:
    Matrix3D() = default;

    Matrix3D(float n00, float n01, float n02,
             float n10, float n11, float n12,
             float n20, float n21, float n22) {
        n[0][0] = n00;
        n[0][1] = n10;
        n[0][2] = n20;
        n[1][0] = n01;
        n[1][1] = n11;
        n[1][2] = n21;
        n[2][0] = n02;
        n[2][1] = n12;
        n[2][2] = n22;
    }

    Matrix3D(const Vector3D &a, const Vector3D &b, const Vector3D &c) {
        n[0][0] = a.x;
        n[0][1] = a.y;
        n[0][2] = a.z;
        n[1][0] = b.x;
        n[1][1] = b.y;
        n[1][2] = b.z;
        n[2][0] = c.x;
        n[2][1] = c.y;
        n[2][2] = c.z;
    }


    float &operator()(int i, int j) {
        return n[j][i];
    }

    const float &operator()(int i, int j) const {
        return n[j][i];
    }

    Vector3D &operator[](int j) {
        return (*reinterpret_cast<Vector3D *>(n[j]));
    }

    const Vector3D &operator[](int j) const {
        return (*(reinterpret_cast<const Vector3D *>(n[j])));
    }
};


Matrix3D operator*(const Matrix3D &a, const Matrix3D &b) {
    return Matrix3D(a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0) + a(0, 2) * b(2, 0),
                    a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1) + a(0, 2) * b(2, 2),
                    a(0, 0) * b(0, 2) + a(0, 1) * b(1, 2) + a(0, 2) * b(2, 2),

                    a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0) + a(1, 2) * b(2, 0),
                    a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1) + a(1, 2) * b(2, 2),
                    a(1, 0) * b(0, 2) + a(1, 1) * b(1, 2) + a(1, 2) * b(2, 2),

                    a(2, 0) * b(0, 0) + a(2, 1) * b(1, 0) + a(2, 2) * b(2, 0),
                    a(2, 0) * b(0, 1) + a(2, 1) * b(1, 1) + a(2, 2) * b(2, 2),
                    a(2, 0) * b(0, 2) + a(2, 1) * b(1, 2) + a(2, 2) * b(2, 2));
}

Vector3D operator*(const Matrix3D &m, const Vector3D &v) {
    return Vector3D(m(0, 0) * v.x + m(0, 1) * v.y + m(0, 2) * v.z,
                    m(1, 0) * v.x + m(1, 1) * v.y + m(1, 2) * v.z,
                    m(2, 0) * v.x + m(2, 1) * v.y + m(2, 2) * v.z);
}

#endif //GAME_ENGINE_MATH_MATRIX3D_H
