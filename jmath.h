#ifndef JMATH_H
#define JMATH_H

class JMath
{
public:
    static bool getLowestRoot(float a, float b, float c, float maxR, float *root);

private:
    // Disallow creating an instance of this object
    JMath() {}
};

#endif // JMATH_H
