#include "matrix4x4.h"
#include <cmath>
#include <iomanip>
#include <vector>
namespace jl
{
Matrix4x4::Matrix4x4(float xyzw[4][4])
{
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            matrix[i][j] = xyzw[i][j];
        }
    }
}

Matrix4x4::Matrix4x4(const Matrix4x4 &mat)
{
    for (unsigned int col{0}; col < MATRIX_COLUMNS; ++col)
    {
        for (unsigned int row{0}; row < MATRIX_ROWS; ++row)
        {
            matrix[col][row] = mat.matrix[col][row];
        }
    }
}

Matrix4x4::Matrix4x4(const Vector4d &vA, const Vector4d &vB, const Vector4d &vC, const Vector4d &vD)
{
    std::vector<Vector4d> vecs{vA, vB, vC, vD};
    for (unsigned int column{0}; column < vecs.size(); column++)
    {
        std::vector<float> arrCopy{vecs.at(column).arr()};
        for (unsigned int i{0}; i < arrCopy.size(); i++)
        {
            matrix[column][i] = arrCopy.at(i);
        }
    }
}
Matrix4x4::Matrix4x4(const std::array<float, MATRIX_SIZE> &numbers)
{
    for (unsigned int col{0}; col < MATRIX_COLUMNS; col++)
    {
        for (unsigned int row{0}; row < MATRIX_ROWS; row++)
        {
            matrix[col][row] = numbers.at(row + col * MATRIX_COLUMNS);
        }
    }
}
// Initialize an identity matrix multiplied by float id
Matrix4x4::Matrix4x4(float id) : Matrix4x4(Vector4d{id}, Vector4d{0.f, id}, Vector4d{0.f, 0.f, id}, Vector4d{0.f, 0.f, 0.f, 1.f})
{
}
Matrix4x4::~Matrix4x4()
{
}
// Simple for-loop to set the matrix to its identity.
void Matrix4x4::setToIdentity()
{
    for (unsigned int i = 0; i < MATRIX_COLUMNS; i++)
    {
        for (unsigned int j = 0; j < MATRIX_ROWS; j++)
        {
            if (j == i)
            {
                matrix[i][j] = 1.0f;
            }
            else
                matrix[i][j] = 0.0f;
        }
    }
}
void Matrix4x4::pivot(int r) // r for row
{
    int lPos{0};     // Row position of largest number in column
    int initPos = r; // Initial row
    for (int i = r; i < (sizeof(matrix) / sizeof(*matrix)) - 1; i++)
    {
        if (fabs(matrix[i][r]) < fabs(matrix[i + 1][r])) // if absolute of [r][i] is smaller than absolute of [r][i + 1]
        {
            lPos = i + 1;
        }
    }

    if (lPos > initPos)
    {
        for (int j = 0; j < (sizeof(matrix) / sizeof(*matrix)); j++)
            std::swap(matrix[initPos][j], matrix[lPos][j]); // Swap rows so that the largest number is on top
    }
}

float Matrix4x4::determinant(float matrix[4][4], int m)
{
    float det = 0;
    float submatrix[4][4];
    if (m == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else
    {
        for (int x = 0; x < m; x++)
        {
            int subi = 0;
            for (int i = 1; i < m; i++)
            {
                int subj = 0;
                for (int j = 0; j < m; j++)
                {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (powf(-1, x) * matrix[0][x] * determinant(submatrix, m - 1));
        }
    }
    return det;
}

float Matrix4x4::at(unsigned int iOne, unsigned int iTwo) const
{
    return matrix[iOne][iTwo];
}
void Matrix4x4::LU() // LU-factorization
{
    float det = determinant(matrix, 4);
    std::cout << "Determinant of the matrix is " << det << "\n";

    if (det != 0) // No point performing LU factorization if det is 0
    {
        for (int row = 0; row < MATRIX_ROWS - 1; row++) // Row
        {
            pivot(row);
            for (int column = row; column < MATRIX_COLUMNS - 1; column++) // Column
            {
                float c = (matrix[column + 1][row] / matrix[row][row]);
                for (int j = 0; j <= MATRIX_ROWS; j++) // the elements to the right of the pivot
                    matrix[column + 1][j] -= c * matrix[row][j];
            }
        }
        transpose();
    }
    else
    {
        std::cout << "Det is 0, can't be solved.\n";
    }
}

Vector4d Matrix4x4::solve(Vector4d &vec4) const
{
    Vector4d x;
    for (int k = 0; k < MATRIX_COLUMNS; k++)
    {
        for (int i = k + 1; i < MATRIX_ROWS; i++)
            vec4[i] = vec4[i] - matrix[i][k] * vec4[k];
    }
    for (int i = MATRIX_COLUMNS - 1; i >= 0; i--)
    {
        x[i] = vec4[i];
        for (int j = i + 1; j < MATRIX_ROWS; j++)
            x[i] -= matrix[i][j] * x[j];
        x[i] = x[i] / matrix[i][i];
    }
    return x;
}

void Matrix4x4::scale(float xScale, float yScale, float zScale) // Scale by the XYZ values
{
    for (unsigned int i = 0; i < MATRIX_COLUMNS; i++)
    {
        matrix[i][0] = matrix[i][0] * xScale;
        matrix[i][1] = matrix[i][1] * yScale;
        matrix[i][2] = matrix[i][2] * zScale;
    }
}
Matrix4x4 Matrix4x4::transpose()
{
    Vector4d params[4];
    for (unsigned int row{0}; row < 4; row++)
    {
        params[row] = Vector4d{matrix[0][row], matrix[1][row], matrix[2][row], matrix[3][row]};
    }
    return Matrix4x4{params[0], params[1], params[2], params[3]};
}
void Matrix4x4::rotate(float angle, float x, float y, float z)
{
    if (angle == 0.0f)
        return;
    float c, s;
    if (angle == 90.0f || angle == -270.0f)
    {
        s = 1.0f;
        c = 0.0f;
    }
    else if (angle == -90.0f || angle == 270.0f)
    {
        s = -1.0f;
        c = 0.0f;
    }
    else if (angle == 180.0f || angle == -180.0f)
    {
        s = 0.0f;
        c = -1.0f;
    }
    else
    {
        const float PI = 3.1415927;
        float a = angle * (PI / 180); // From degrees to radians for sine/cosine
        c = std::cos(a);
        s = std::sin(a);
    }
    if (x == 0.0f)
    {
        if (y == 0.0f)
        {
            if (z != 0.0f)
            {
                // Rotate around the Z axis.
                if (z < 0)
                    s = -s;
                float tmp;
                matrix[0][0] = (tmp = matrix[0][0]) * c + matrix[1][0] * s;
                matrix[1][0] = matrix[1][0] * c - tmp * s;
                matrix[0][1] = (tmp = matrix[0][1]) * c + matrix[1][1] * s;
                matrix[1][1] = matrix[1][1] * c - tmp * s;
                matrix[0][2] = (tmp = matrix[0][2]) * c + matrix[1][2] * s;
                matrix[1][2] = matrix[1][2] * c - tmp * s;
                matrix[0][3] = (tmp = matrix[0][3]) * c + matrix[1][3] * s;
                matrix[1][3] = matrix[1][3] * c - tmp * s;
                return;
            }
        }
        else if (z == 0.0f)
        {
            // Rotate around the Y axis.
            if (y < 0)
                s = -s;
            float tmp;
            matrix[2][0] = (tmp = matrix[2][0]) * c + matrix[0][0] * s;
            matrix[0][0] = matrix[0][0] * c - tmp * s;
            matrix[2][1] = (tmp = matrix[2][1]) * c + matrix[0][1] * s;
            matrix[0][1] = matrix[0][1] * c - tmp * s;
            matrix[2][2] = (tmp = matrix[2][2]) * c + matrix[0][2] * s;
            matrix[0][2] = matrix[0][2] * c - tmp * s;
            matrix[2][3] = (tmp = matrix[2][3]) * c + matrix[0][3] * s;
            matrix[0][3] = matrix[0][3] * c - tmp * s;
            return;
        }
    }
    else if (y == 0.0f && z == 0.0f)
    {
        // Rotate around the X axis.
        if (x < 0)
            s = -s;
        float tmp;
        matrix[1][0] = (tmp = matrix[1][0]) * c + matrix[2][0] * s;
        matrix[2][0] = matrix[2][0] * c - tmp * s;
        matrix[1][1] = (tmp = matrix[1][1]) * c + matrix[2][1] * s;
        matrix[2][1] = matrix[2][1] * c - tmp * s;
        matrix[1][2] = (tmp = matrix[1][2]) * c + matrix[2][2] * s;
        matrix[2][2] = matrix[2][2] * c - tmp * s;
        matrix[1][3] = (tmp = matrix[1][3]) * c + matrix[2][3] * s;
        matrix[2][3] = matrix[2][3] * c - tmp * s;
        return;
    }
    double len = double(x) * double(x) +
                 double(y) * double(y) +
                 double(z) * double(z);

    len = std::sqrt(len);
    x = float(double(x) / len);
    y = float(double(y) / len);
    z = float(double(z) / len);
    float ic = 1.0f - c;
    Matrix4x4 rot; // The "1" says to not load the identity.
    rot.matrix[0][0] = x * x * ic + c;
    rot.matrix[1][0] = x * y * ic - z * s;
    rot.matrix[2][0] = x * z * ic + y * s;
    rot.matrix[3][0] = 0.0f;
    rot.matrix[0][1] = y * x * ic + z * s;
    rot.matrix[1][1] = y * y * ic + c;
    rot.matrix[2][1] = y * z * ic - x * s;
    rot.matrix[3][1] = 0.0f;
    rot.matrix[0][2] = x * z * ic - y * s;
    rot.matrix[1][2] = y * z * ic + x * s;
    rot.matrix[2][2] = z * z * ic + c;
    rot.matrix[3][2] = 0.0f;
    rot.matrix[0][3] = 0.0f;
    rot.matrix[1][3] = 0.0f;
    rot.matrix[2][3] = 0.0f;
    rot.matrix[3][3] = 1.0f;
    *this = *this * rot;
}
Matrix4x4 &Matrix4x4::rotate(const Vector3d &vec, float angle)
{
    if (angle == 0.0f)
        return *this;
    float cosa, sina;
    if (angle == 90.0f || angle == -270.0f)
    {
        cosa = 0.0f;
        sina = 1.0f;
    }
    else if (angle == -90.0f || angle == 270.0f)
    {
        cosa = 0.0f;
        sina = -1.0f;
    }
    else if (angle == 180.0f || angle == -180.0f)
    {
        cosa = -1.0f;
        sina = 0.0f;
    }
    else
    {
        const float PI = 3.1415927;
        float rad = angle * (PI / 180); // From degrees to radians for sine/cosine
        cosa = cosf(rad);
        sina = sinf(rad);
    }
    // Transposed
    if (vec.getX() == 0.0f) // [0.0, X, X]
    {
        if (vec.getY() == 0.0f) // [0.0, 0.0, X]
        {
            if (vec.getZ() == 1.0f) // [0.0, 0.0, 1.0]
            {
                Matrix4x4 elMatrixZ(Vector4d{cosa, sina},
                                    Vector4d{-sina, cosa},
                                    Vector4d{0, 0, 1},
                                    Vector4d{0, 0, 0, 1});
                return *this = *this * elMatrixZ;
            }
        }
        else if (vec.getZ() == 0.0f) // [0.0, 1.0, 0.0]
        {
            Matrix4x4 elMatrixY(Vector4d{cosa, 0, -sina},
                                Vector4d{0, 1},
                                Vector4d{sina, 0, cosa},
                                Vector4d{0, 0, 0, 1});
            return *this = *this * elMatrixY;
        }
        else
        {
            std::cout << "Invalid vector or [0.0, 0.0, 0.0] vector.\n";
            return *this;
        }
    }
    else if (vec.getX() == 1.0f && vec.getY() == 0.0f && vec.getZ() == 0.0f)
    {
        Matrix4x4 elMatrixX(Vector4d{1},
                            Vector4d{0, cosa, sina},
                            Vector4d{0, -sina, cosa},
                            Vector4d{0, 0, 0, 1});
        return *this = *this * elMatrixX;
    }
    else
    {
        throw std::out_of_range{"rotate function can't handle more than one axis at once."};
        return *this;
    }
    return *this;
}

Matrix4x4 &Matrix4x4::translate(float xDir, float yDir, float zDir)
{
    // Create translation matrix
    Matrix4x4 translate{{1.f}, {0.f, 1.f}, {0.f, 0.f, 1.f}, {xDir, yDir, zDir, 1.f}};
    // Multiply matrix by translation matrix
    return *this = *this * translate;
}
Matrix4x4 &Matrix4x4::translate(Vector3d vec)
{
    // Create translation matrix
    Matrix4x4 translate{{1.f}, {0.f, 1.f}, {0.f, 0.f, 1.f}, {vec.getX(), vec.getY(), vec.getZ(), 1.f}};
    // Multiply matrix by translation matrix
    return *this = *this * translate;
}
Matrix4x4 Matrix4x4::lookAt(const Vector3d &eye, const Vector3d &at, const Vector3d &up)
{
    Matrix4x4 M(1);
    Vector3d v = up;
    v.normalize();         // y-akse i kameraframe
    Vector3d n = eye - at; // (from - to)
    n.normalize();         // z-akse i kameraframe
    Vector3d u = v ^ n;    // cross of up and forward(eye-at)
    u.normalize();         // x-akse i kameraframe
    v = n ^ u;             // final up
    v.normalize();
    M.matrix[0][0] = u.getX();
    M.matrix[0][1] = u.getY();
    M.matrix[0][2] = u.getZ();
    M.matrix[1][0] = v.getX();
    M.matrix[1][1] = v.getY();
    M.matrix[1][2] = v.getZ();
    M.matrix[2][0] = n.getX();
    M.matrix[2][1] = n.getY();
    M.matrix[2][2] = n.getZ();
    M.translate(-eye.getX(), -eye.getY(), -eye.getZ());

    return *this * M; // *this * M
}
Matrix4x4 Matrix4x4::sLookAt(const Vector3d &eye, const Vector3d &at, const Vector3d &up)
{
    Vector3d finalUp = up;
    finalUp.normalize();                                 // y-akse i kameraframe
    Vector3d direction = (eye - at).normalized();        // (from - to)
    Vector3d right = (finalUp ^ direction).normalized(); // cross of up and forward(eye-at)
    finalUp = (direction ^ right).normalized();          // final up
    Vector3d dotProd = Vector3d(-(right * eye), -(finalUp * eye), -(direction * eye));
    return Matrix4x4{Vector4d(right, dotProd.getX()), Vector4d(finalUp, dotProd.getY()), Vector4d(direction, dotProd.getZ()), Vector4d(0, 0, 0, 1)};
}

Matrix4x4 Matrix4x4::translation(const Vector4d &v)
{
    Vector4d temp = Vector4d(v.getX(), v.getY(), v.getZ(), 1.f);
    return Matrix4x4{Vector4d{1.f}, Vector4d{0.f, 1.f}, Vector4d{0.f, 0.f, 1.f}, temp};
}
void Matrix4x4::frustum(float left, float right, float bottom, float top, float near, float far)
{
    // Forutsetter a_ij initielt 0
    matrix[0][0] = 2 * near / (right - left);
    matrix[1][1] = 2 * near / (top - bottom);
    matrix[0][2] = (right + left) / (right - left);
    matrix[1][2] = (top + bottom) / (top - bottom);
    matrix[2][2] = -(far + near) / (far - near);
    matrix[2][3] = -2 * far * near / (far - near);
    matrix[3][2] = -1.0f;
    matrix[3][3] = 0.0f;
}

Matrix4x4 &Matrix4x4::perspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane)
{
    float b, t, l, r;
    const float PI = 3.1415927;
    // Calculate screen coordinates
    float scale = std::tan(verticalAngle * 0.5f * PI / 180.f) * nearPlane;
    r = aspectRatio * scale;
    l = -r;
    t = scale;
    b = -t;

    Matrix4x4 projection{
        {2.f * nearPlane / (r - l), 0.f, 0.f, 0.f},
        {0.f, 2.f * nearPlane / (t - b), 0.f, 0.f},
        {(r + l) / (r - l), (t + b) / (t - b), -(farPlane + nearPlane) / (farPlane - nearPlane), -1.f},
        {0.f, 0.f, -2.f * farPlane * nearPlane / (farPlane - nearPlane), 0.f}};

    return *this = *this * projection;
}

Matrix4x4 &Matrix4x4::operator=(const Matrix4x4 &v) // Assignment
{
    for (unsigned int col{0}; col < MATRIX_COLUMNS; col++)
    {
        for (unsigned int row{0}; row < MATRIX_ROWS; row++)
        {
            matrix[col][row] = v.matrix[col][row];
        }
    }
    return *this;
}

Matrix4x4 Matrix4x4::operator*(float c) const
{
    float xyzw[4][4];
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            xyzw[i][j] = matrix[i][j] * c;
        }
    }
    Matrix4x4 m(xyzw);
    return m;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &mat)
{
    Matrix4x4 m{*this};
    for (unsigned int col{0}; col < MATRIX_COLUMNS; ++col)
    {
        for (unsigned int row{0}; row < MATRIX_ROWS; ++row)
        {
            matrix[col][row] += mat.matrix[col][row];
        }
    }
    return m;
}

Vector4d Matrix4x4::operator*(const Vector4d &v) const
{
    std::vector<float> tempVec;
    tempVec.push_back(v.getX());
    tempVec.push_back(v.getY());
    tempVec.push_back(v.getZ());
    tempVec.push_back(v.getW());
    float arr[4];
    for (size_t i = 0; i <= 3; i++)
    {
        arr[i] = tempVec.at(i) * matrix[i][0] + tempVec.at(i) * matrix[i][1] + tempVec.at(i) * matrix[i][2] + tempVec.at(i) * matrix[i][3];
    }
    Vector4d temp(arr[0], arr[1], arr[2], arr[3]);
    return temp;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &m) const
{
    std::array<float, MATRIX_SIZE> params;
    for (unsigned int col{0}; col < MATRIX_COLUMNS; col++)
    {
        for (unsigned int row{0}; row < MATRIX_ROWS; row++)
        {
            Vector4d a{matrix[0][row], matrix[1][row], matrix[2][row], matrix[3][row]};
            Vector4d b{m.matrix[col][0], m.matrix[col][1], m.matrix[col][2], m.matrix[col][3]};
            params.at(col * 4 + row) = a * b;
        }
    }
    return Matrix4x4{params};
}
std::istream &operator>>(std::istream &is, Matrix4x4 &point)
{
    // Trenger fire temporære variabler som kun skal lese inn parenteser og komma
    char dum, dum2;
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            is >> dum >> point.matrix[i][j];
            if (j == 3)
            {
                is >> dum2; // Get rid of the end parenthesis, not sure if I need this?
            }
        }
    }
    return is;
}

std::ostream &operator<<(std::ostream &out, const Matrix4x4 &c)
{
    // fixed and setprecision forces output to have one decimal.
    out << std::fixed << std::setprecision(3);
    for (int row = 0; row < 4; row++)
    {
        out << "(";
        for (int col = 0; col < 4; col++)
        {
            out << c.matrix[col][row];
            if (col < 3) // Commas after each number except the last
            {
                out << ", ";
            }
        }
        out << ")\n";
    }
    out << "\n";
    return out; // return std::ostream so we can chain calls to operator<<
}

} // namespace jl
