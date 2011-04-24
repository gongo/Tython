// -*- C++ -*-

#ifndef _TYTHON_VECTOR_H_
#define _TYTHON_VECTOR_H_

#include <XnOpenNI.h>

class Vector : public XnVector3D {
public:
    Vector(void);
    Vector(const XnVector3D& v);
    Vector(float x, float y, float z);

    /**
     * 直交を判断するしきい値
     */
    static const float THRESHOLD_ORTHOGONAL;

    /**
     * 平行を判断するしきい値
     */
    static const float THRESHOLD_STRAIGHT;

    /**
     * 各しきい値に対する誤差許容範囲値
     */
    static const float THRESHOLD_TOLERANCE;

    Vector& operator+=(const Vector& v);
    Vector& operator-=(const Vector& v);
    Vector& operator*=(float f);
    Vector& operator/=(float f);
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector operator*(float f) const;
    Vector operator/(float f) const;

    /**
     * ベクトルの大きさ
     *
     * @return  大きさ |v|
     */
    float magnitude(void) const;

    /**
     * ベクトルの内積を返す
     *
     * @param   v  対象のベクトル
     * @return     内積 |v1 ・ v2|
     */
    float dot(const Vector& v) const;

    /**
     * ベクトルの外積を返す
     *
     * @param   v  対象のベクトル
     * @return     外積 |v1 × v2|
     */
    float cross(const Vector& v) const;

    /**
     * ベクトルの正規化
     *
     * @return  正規化されたベクトル
     */
    Vector normalize(void) const;

    /**
     * ベクトルの距離を測る
     *
     * @param   v  対象のベクトル
     * @return     2ベクトルの距離
     */
    float distance(const Vector& v) const;

    /**
     * 逆ベクトルを返す
     *
     * @return  自身の逆ベクトル
     */
    Vector reverse(void) const;

    /**
     * 二つのベクトルが指定した角度より鋭角かチェックする
     *
     * @param    v    角度をチェックするベクトル
     * @param  angle  鋭角と判定基準とする角度
     * @return        鋭角と判断されれば true
     */
    bool withinAngle(const Vector& v, float angle) const;

    /**
     * 二つのベクトルが指定した角度より鈍角かチェックする
     *
     * @see Vector::THRESHOLD_ORTHOGONAL
     *
     * @param    v    角度をチェックするベクトル
     * @param  angle  鈍角の判定基準とする角度
     * @return        鈍角と判断されれば true
     */
    bool withoutAngle(const Vector& v, float angle) const;

    /**
     * 二つのベクトルが直交しているかチェックする
     *
     * @see Vector::THRESHOLD_ORTHOGONAL
     *
     * @param   v  this と直行しているか確認するベクトル
     * @return     直交していれば true
     */
    bool isOrthogonal(const Vector& v) const;

    /**
     * 二つのベクトルが平行かチェックする
     *
     * @see Vector::THRESHOLD_STRAIGHT
     *
     * @param   v  this と平行か確認するベクトル
     * @return     平行であれば true 
     */
    bool isStraight(const Vector& v) const;
};

#endif // _TYTHON_VECTOR_H_
