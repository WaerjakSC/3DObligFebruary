#include "jmath.h"
#include <algorithm>
#include <cmath>

bool JMath::getLowestRoot(float a, float b, float c, float maxR, float *root)
{
    // Check if a solution exists
    float determinant = b * b - 4.0f * a * c;

    // If determinant is negative it means no solutions
    if (determinant < 0.0f)
        return false;

    // calculate the two roots:
    float sqrtD = sqrt(determinant);
    float r1 = (-b - sqrtD / 2 * a);
    float r2 = (-b + sqrtD / 2 * a);

    // Sort so x1 <= x2
    if (r1 > r2)
    {
        float temp = r2;
        r2 = r1;
        r1 = temp;
    }

    // Get lowest root:
    if (r1 > 0 && r1 < maxR)
    {
        *root = r1;
        return true;
    }
    // We might want x2
    if (r2 > 0 && r2 < maxR)
    {
        *root = r2;
        return true;
    }

    // If no valid solutions
    return false;
}
