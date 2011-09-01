#include <math.h>
#include "Vector.h"

namespace ty {

static float deg2rad(float degree)
{
    return degree * M_PI / 180.0f;
}

static float rad2deg(float radian)
{
    return radian * 180.0f / M_PI;
}

const float Vector::THRESHOLD_ORTHOGONAL = 90.0f;
const float Vector::THRESHOLD_STRAIGHT   = 170.0f;
const float Vector::THRESHOLD_TOLERANCE  = 20.0f;

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

bool Vector::operator==(const Vector& v) const
{
    return X == v.X && Y == v.Y && Z == v.Z;
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

Vector Vector::reverse(void) const
{
    return Vector(-X, -Y, -Z);
}

bool Vector::withinAngle(const Vector& v, float angle) const
{
    return dot(v) >= cosf(deg2rad(angle));
}

bool Vector::withoutAngle(const Vector& v, float angle) const
{
    return !withinAngle(v, angle);
}

bool Vector::betweenAngle(const Vector& v, float angle) const
{
    return withoutAngle(v, angle - THRESHOLD_TOLERANCE)
        && withinAngle(v, angle + THRESHOLD_TOLERANCE);
}

bool Vector::isOrthogonal(const Vector& v) const
{
    return betweenAngle(v, THRESHOLD_ORTHOGONAL);
}

bool Vector::isStraight(const Vector& v) const
{
    return withoutAngle(v, THRESHOLD_STRAIGHT - THRESHOLD_TOLERANCE);
}

bool Vector::isParallel(const Vector& v) const
{
    return isStraight(v) || withinAngle(v, THRESHOLD_TOLERANCE);
}

} // namespace ty
