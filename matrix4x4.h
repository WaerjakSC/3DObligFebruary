﻿#ifndef MATRIX4X4_H
#define MATRIX4X4_H
#include "vector4d.h"
#include <array>
#include <iostream>
namespace jl
{

class Matrix4x4
{
private:
    // Keep track of sizes
    static constexpr unsigned int MATRIX_SIZE{4 * 4};
    static constexpr unsigned int MATRIX_ROWS{4};
    static constexpr unsigned int MATRIX_COLUMNS{4};
    // Should be column-major ordering
    float matrix[MATRIX_COLUMNS][MATRIX_ROWS];
    void pivot(int k);
    void rotate(const Matrix4x4 &m);

public:
    explicit Matrix4x4(float id);
    Matrix4x4(const Vector4d &vA = Vector4d{1.f}, const Vector4d &vB = Vector4d{0.f, 1.f},
              const Vector4d &vC = Vector4d{0.f, 0.f, 1.f}, const Vector4d &vD = Vector4d{0.f, 0.f, 0.f, 1.f});
    Matrix4x4(float xyzw[MATRIX_COLUMNS][MATRIX_ROWS]);
    Matrix4x4(const Matrix4x4 &mat);
    Matrix4x4(const std::array<float, MATRIX_SIZE> &numbers);
    ~Matrix4x4();
    Matrix4x4(float x1, float y1, float z1, float w1,
              float x2, float y2, float z2, float w2,
              float x3, float y3, float z3, float w3,
              float x4, float y4, float z4, float w4);

    // Returns const pointer to the underlying array
    const float *constData() { return *matrix; }

    void setToIdentity();
    void LU();

    Vector4d solve(Vector4d &vec4) const;

    void scale(float xScale, float yScale, float zScale);

    Matrix4x4 &rotate(const Vector3d &vec, float angle); // Rotate the angle (return as angle, not radians)
    void rotate(float angle, float x, float y, float z);

    Matrix4x4 &translate(float xDir, float yDir, float zDir);
    Matrix4x4 &translate(Vector3d vec);

    Matrix4x4 &perspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane);

    Matrix4x4 lookAt(const Vector3d &eye, const Vector3d &at, const Vector3d &up);

    void frustum(float left, float right, float bottom, float top, float near, float far);

    float determinant(float matrix[MATRIX_COLUMNS][MATRIX_ROWS]);
    float determinant(float matrix[MATRIX_COLUMNS][MATRIX_ROWS], int n);

    float at(unsigned int indexOne, unsigned int indexTwo) const;

    Matrix4x4 transpose();
    static Matrix4x4 sLookAt(const Vector3d &eye, const Vector3d &at, const Vector3d &up = Vector3d{0, 1, 0});
    static Matrix4x4 translation(const Vector4d &v);
    // Math functions
    Matrix4x4 operator*(float c) const;
    Matrix4x4 operator+(const Matrix4x4 &mat);     // Addition
    Matrix4x4 operator-(const Matrix4x4 &v) const; // Subtraction
    Vector4d operator*(const Vector4d &v) const;   // M4x4 * Vector4d
    Matrix4x4 operator*(const Matrix4x4 &v) const; // M4x4 * M4x4
    Matrix4x4 &operator=(const Matrix4x4 &v);

    // In/Out overloading
    friend std::ostream &operator<<(std::ostream &out, const Matrix4x4 &c);
    friend std::istream &operator>>(std::istream &in, Matrix4x4 &point);
    friend class Scenetwo;
};
std::ostream &operator<<(std::ostream &out, const Matrix4x4 &c);
std::istream &operator>>(std::istream &in, Matrix4x4 &point);
} // namespace jl
#endif // MATRIX4X4_H
