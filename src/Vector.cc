#include <math.h>
#include "Vector.h"

inline static float deg2rad(float degree)
{
    return degree * M_PI / 180.0f;
}

inline static float rad2deg(float radian)
{
    return radian * 180.0f / M_PI;
}

const float Vector::THRESHOLD_ORTHOGONAL = cos(deg2rad(80.0f));
const float Vector::THRESHOLD_STRAIGHT   = cos(deg2rad(170.0f));

Vector::Vector(void)
{
    X = 0.0f;
    Y = 0.0f;
    Z = 0.0f;
}

Vector::Vector(const XnVector3D& v)
{
    X = v.X;
    Y = v.Y;
    Z = v.Z;
}

Vector::Vector(float x, float y, float z)
{
    X = x;
    Y = y;
    Z = z;
}

Vector& Vector::operator+=(const Vector& v)
{
    X += v.X;
    Y += v.Y;
    Z += v.Z;
    return *this;
}

Vector& Vector::operator-=(const Vector& v)
{
    X -= v.X;
    Y -= v.Y;
    Z -= v.Z;
    return *this;
}

Vector& Vector::operator*=(float f)
{
    X *= f;
    Y *= f;
    Z *= f;
    return *this;
}

Vector& Vector::operator/=(float f)
{
    X /= f;
    Y /= f;
    Z /= f;
    return *this;
}

Vector Vector::operator+(const Vector& v) const
{
    return Vector(X + v.X, Y + v.Y, Z + v.Z);
}

Vector Vector::operator-(const Vector& v) const
{
    return Vector(X - v.X, Y - v.Y, Z - v.Z);
}

Vector Vector::operator*(float f) const
{
    return Vector(X * f, Y * f, Z * f);
}

Vector Vector::operator/(float f) const
{
    return Vector(X / f, Y / f, Z / f);
}

float Vector::magnitude(void) const
{
    return sqrtf(X*X + Y*Y + Z*Z);
}

Vector Vector::normalize(void) const
{
    float m = magnitude();
    return Vector(X/m, Y/m, Z/m);
}

float Vector::dot(const Vector& v) const
{
    return (X*v.X + Y*v.Y + Z*v.Z) / magnitude() / v.magnitude();
}

float Vector::cross(const Vector& v) const
{
    Vector c(Y*v.Z - Z*v.Y, Z*v.X - X*v.Z, X*v.Y - Y*v.X);
    return c.magnitude() / magnitude() / v.magnitude();
}

float Vector::distance(const Vector& v) const
{
    return (*this - v).magnitude();
}

bool Vector::isOrthogonal(const Vector& v) const
{
    return fabs(dot(v)) < THRESHOLD_ORTHOGONAL;
}

bool Vector::isStraight(const Vector& v) const
{
    return dot(v) < THRESHOLD_STRAIGHT;
}
