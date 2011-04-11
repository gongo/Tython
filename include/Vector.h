// -*- C++ -*-

#ifndef _TYTHON_VECTOR_H_
#define _TYTHON_VECTOR_H_

#include <XnOpenNI.h>

class Vector : public XnVector3D {
public:
    Vector(void);
    Vector(const XnVector3D& v);
    Vector(float x, float y, float z);

    static const float THRESHOLD_ORTHOGONAL;
    static const float THRESHOLD_STRAIGHT;

    Vector& operator+=(const Vector& v);
    Vector& operator-=(const Vector& v);
    Vector& operator*=(float f);
    Vector& operator/=(float f);
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector operator*(float f) const;
    Vector operator/(float f) const;

    float magnitude(void) const;
    float dot(const Vector& v) const;
    float cross(const Vector& v) const;
    Vector normalize(void) const;
    float distance(const Vector& v) const;
    bool isOrthogonal(const Vector& v) const;
    bool isStraight(const Vector& v) const;
};

#endif // _TYTHON_VECTOR_H_
