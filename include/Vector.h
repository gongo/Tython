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

    /**
     * 二つのベクトルが指定した角度より鋭角かチェックする
     *
     * @param    v    角度をチェックするベクトル
     * @param  angle  鋭角と判定基準とする角度
     */
    bool withinAngle(const Vector& v, float angle) const;

    /**
     * 二つのベクトルが指定した角度より鈍角かチェックする
     *
     * @param    v    角度をチェックするベクトル
     * @param  angle  鈍角の判定基準とする角度
     */
    bool withoutAngle(const Vector& v, float angle) const;

    /**
     * 二つのベクトルが直交しているかチェックする
     *
     * @param   v  this と直行しているか確認するベクトル
     * @return  直交していれば true
     */
    bool isOrthogonal(const Vector& v) const;

    /**
     * 二つのベクトルが平行かチェックする
     *
     * @param   v  this と平行か確認するベクトル
     * @return  平行であれば true 
     */
    bool isStraight(const Vector& v) const;
};

#endif // _TYTHON_VECTOR_H_
