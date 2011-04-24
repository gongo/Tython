#include <gtest/gtest.h>
#include "Vector.h"

class VectorTest : public testing::Test {
public:
    virtual void SetUp() {
        x = 100.0f;
        y = -12.0f;
        z = 0.0f;
        v00 = Vector(1.0f, 0.0f, 0.0f);
        v30 = Vector(1.73205081f, 1, 0.0f); 
        v60 = Vector(1, 1.73205081f, 0.0f); 
        v90 = Vector(0.0f, 1.0f, 0.0f);
        v120 = Vector(-1, 1.73205081f, 0.0f); 
        v150 = Vector(-1.73205081f, 1, 0.0f); 
        v180 = Vector(-1.0f, 0.0f, 0.0f);
    }

    float x, y, z;
    Vector v00;
    Vector v30;
    Vector v60;
    Vector v90;
    Vector v120;
    Vector v150;
    Vector v180;
};

TEST_F(VectorTest, TestConstructor) {
    Vector vec;

    ASSERT_EQ(0.0f, vec.X);
    ASSERT_EQ(0.0f, vec.Y);
    ASSERT_EQ(0.0f, vec.Z);
}

TEST_F(VectorTest, TestConstructorWithXnVector3D) {
    XnVector3D v  = {x, y, z};
    Vector vec(v);

    ASSERT_EQ(v.X, vec.X);
    ASSERT_EQ(v.Y, vec.Y);
    ASSERT_EQ(v.Z, vec.Z);
}

TEST_F(VectorTest, TestConstructorWithFloat) {
    Vector vec(x, y, z);

    ASSERT_EQ(x, vec.X);
    ASSERT_EQ(y, vec.Y);
    ASSERT_EQ(z, vec.Z);
}

TEST_F(VectorTest, TestAssignOperatorPlus) {
    Vector vec1(x, y, z);
    Vector vec2(x, y, z);

    vec1 += vec2;
    
    ASSERT_EQ(x + x, vec1.X);
    ASSERT_EQ(y + y, vec1.Y);
    ASSERT_EQ(z + z, vec1.Z);
}

TEST_F(VectorTest, TestAssignOperatorMinus) {
    Vector vec1(x, y, z);
    Vector vec2(x, y, z);

    vec1 -= vec2;
    
    ASSERT_EQ(x - x, vec1.X);
    ASSERT_EQ(y - y, vec1.Y);
    ASSERT_EQ(z - z, vec1.Z);
}

TEST_F(VectorTest, TestAssignOperatorMulti) {
    Vector vec(x, y, z);
    float f = 3.0f;

    vec *= f;
    
    ASSERT_EQ(x * f, vec.X);
    ASSERT_EQ(y * f, vec.Y);
    ASSERT_EQ(z * f, vec.Z);
}

TEST_F(VectorTest, TestAssignOperatorDiv) {
    Vector vec(x, y, z);
    float f = 3.0f;

    vec /= f;
    
    ASSERT_EQ(x / f, vec.X);
    ASSERT_EQ(y / f, vec.Y);
    ASSERT_EQ(z / f, vec.Z);
}

TEST_F(VectorTest, TestOperatorPlus) {
    Vector vec1(x, y, z);
    Vector vec2(x, y, z);

    Vector vec3 = vec1 + vec2;
    
    ASSERT_EQ(x + x, vec3.X);
    ASSERT_EQ(y + y, vec3.Y);
    ASSERT_EQ(z + z, vec3.Z);
}

TEST_F(VectorTest, TestOperatorMinus) {
    Vector vec1(x, y, z);
    Vector vec2(x, y, z);

    Vector vec3 = vec1 - vec2;
    
    ASSERT_EQ(x - x, vec3.X);
    ASSERT_EQ(y - y, vec3.Y);
    ASSERT_EQ(z - z, vec3.Z);
}

TEST_F(VectorTest, TestOperatorMulti) {
    Vector vec1(x, y, z);
    float f = 3.0f;

    Vector vec2 = vec1 * f;
    
    ASSERT_EQ(x * f, vec2.X);
    ASSERT_EQ(y * f, vec2.Y);
    ASSERT_EQ(z * f, vec2.Z);
}

TEST_F(VectorTest, TestOperatorDiv) {
    Vector vec1(x, y, z);
    float f = 3.0f;

    Vector vec2 = vec1 / f;
    
    ASSERT_EQ(x / f, vec2.X);
    ASSERT_EQ(y / f, vec2.Y);
    ASSERT_EQ(z / f, vec2.Z);
}

TEST_F(VectorTest, TestMagnitude) {
    Vector vec(x, y, z);
    ASSERT_EQ(sqrtf(x*x + y*y + z*z), vec.magnitude());
}

TEST_F(VectorTest, TestNormalize) {
    Vector v(x, y, z);
    Vector nv = v.normalize();

    ASSERT_GE(1.0f,   nv.magnitude()); // 誤差範囲内をテスト
    ASSERT_LT(0.999f, nv.magnitude()); // 1.0 >= magnitude > 0.999
}

TEST_F(VectorTest, TestDot) {
    Vector vec1(3.0f, 0.0f, 0.0f);
    Vector vec2(0.0f, 1.0f, 0.0f);
    Vector vec3(1.0f, 1.0f, 1.0f);
    Vector vec4(-12.0f, 0.0f, 0.0f);

    ASSERT_EQ( 1.0f, vec1.dot(vec1)); // 平行(同方向)
    ASSERT_EQ( 0.0f, vec1.dot(vec2)); // 直行
    ASSERT_LT( 0.0f, vec1.dot(vec3)); // 鋭角
    ASSERT_EQ(-1.0f, vec1.dot(vec4)); // 平行(逆方向)
    ASSERT_GT( 0.0f, vec3.dot(vec4)); // 鈍角
}

TEST_F(VectorTest, TestCross) {
    Vector vec0;
    Vector vec1(3.0f, 0.0f, 0.0f);
    Vector vec2(0.0f, 1.0f, 0.0f);
    Vector vec3(1.0f, 1.0f, 1.0f);
    Vector vec4(-12.0f, 0.0f, 0.0f);

    ASSERT_EQ(0.0f, vec1.cross(vec1)); // 平行(同方向)
    ASSERT_EQ(1.0f, vec1.cross(vec2)); // 直行
    ASSERT_LT(0.0f, vec1.cross(vec3)); // 鋭角
    ASSERT_EQ(0.0f, vec1.cross(vec4)); // 平行(逆方向)
    ASSERT_LT(0.0f, vec3.cross(vec4)); // 鈍角
}

TEST_F(VectorTest, TestDistance) {
    Vector v1(1.0f, 0.0f, 3.0f);
    Vector v2(3.0f, 0.0f, 0.0f);
    Vector v3(-3.0f, 0.0f, 0.0f);

    ASSERT_EQ(0.0f, v1.distance(v1));
    ASSERT_EQ(6.0f, v2.distance(v3));
}

TEST_F(VectorTest, TestReverse) {
    Vector vec(x, y, z);
    Vector rev = vec.reverse();
    
    ASSERT_EQ(-x, rev.X);
    ASSERT_EQ(-y, rev.Y);
    ASSERT_EQ(-z, rev.Z);
}

TEST_F(VectorTest, TestWithinAngle) {
    ASSERT_FALSE(v00.withinAngle(v30, 29.0f));
    ASSERT_FALSE(v00.withinAngle(v60, 59.0f));
    ASSERT_FALSE(v00.withinAngle(v90, 89.0f));
    ASSERT_FALSE(v00.withinAngle(v120, 119.0f));
    ASSERT_FALSE(v00.withinAngle(v150, 149.0f));
    ASSERT_FALSE(v00.withinAngle(v180, 179.0f)); 
    ASSERT_FALSE(v30.withinAngle(v60, 29.0f));
    ASSERT_FALSE(v30.withinAngle(v90, 59.0f));
    ASSERT_FALSE(v30.withinAngle(v120, 89.0f));
    ASSERT_FALSE(v30.withinAngle(v150, 119.0f));
    ASSERT_FALSE(v30.withinAngle(v180, 149.0f));
    ASSERT_FALSE(v60.withinAngle(v90, 29.0f));
    ASSERT_FALSE(v60.withinAngle(v120, 59.0f));
    ASSERT_FALSE(v60.withinAngle(v150, 89.0f));
    ASSERT_FALSE(v60.withinAngle(v180, 119.0f));
    ASSERT_FALSE(v90.withinAngle(v120, 29.0f));
    ASSERT_FALSE(v90.withinAngle(v150, 59.0f));
    ASSERT_FALSE(v90.withinAngle(v180, 89.0f));
    ASSERT_FALSE(v120.withinAngle(v150, 29.0f));
    ASSERT_FALSE(v120.withinAngle(v180, 59.0f));
    ASSERT_FALSE(v150.withinAngle(v180, 29.0f));

    ASSERT_TRUE(v00.withinAngle(v30, 31.0f));
    ASSERT_TRUE(v00.withinAngle(v60, 61.0f));
    ASSERT_TRUE(v00.withinAngle(v90, 91.0f));
    ASSERT_TRUE(v00.withinAngle(v120, 121.0f));
    ASSERT_TRUE(v00.withinAngle(v150, 151.0f));
    ASSERT_TRUE(v30.withinAngle(v60, 31.0f));
    ASSERT_TRUE(v30.withinAngle(v90, 61.0f));
    ASSERT_TRUE(v30.withinAngle(v120, 91.0f));
    ASSERT_TRUE(v30.withinAngle(v150, 121.0f));
    ASSERT_TRUE(v30.withinAngle(v180, 151.0f));
    ASSERT_TRUE(v60.withinAngle(v90, 31.0f));
    ASSERT_TRUE(v60.withinAngle(v120, 61.0f));
    ASSERT_TRUE(v60.withinAngle(v150, 91.0f));
    ASSERT_TRUE(v60.withinAngle(v180, 121.0f));
    ASSERT_TRUE(v90.withinAngle(v120, 31.0f));
    ASSERT_TRUE(v90.withinAngle(v150, 61.0f));
    ASSERT_TRUE(v90.withinAngle(v180, 91.0f));
    ASSERT_TRUE(v120.withinAngle(v150, 31.0f));
    ASSERT_TRUE(v120.withinAngle(v180, 61.0f));
    ASSERT_TRUE(v150.withinAngle(v180, 31.0f));
}

TEST_F(VectorTest, TestWithoutAngle) {
    ASSERT_TRUE(v00.withoutAngle(v30, 29.0f));
    ASSERT_TRUE(v00.withoutAngle(v60, 59.0f));
    ASSERT_TRUE(v00.withoutAngle(v90, 89.0f));
    ASSERT_TRUE(v00.withoutAngle(v120, 119.0f));
    ASSERT_TRUE(v00.withoutAngle(v150, 149.0f));
    ASSERT_TRUE(v00.withoutAngle(v180, 179.0f)); 
    ASSERT_TRUE(v30.withoutAngle(v60, 29.0f));
    ASSERT_TRUE(v30.withoutAngle(v90, 59.0f));
    ASSERT_TRUE(v30.withoutAngle(v120, 89.0f));
    ASSERT_TRUE(v30.withoutAngle(v150, 119.0f));
    ASSERT_TRUE(v30.withoutAngle(v180, 149.0f));
    ASSERT_TRUE(v60.withoutAngle(v90, 29.0f));
    ASSERT_TRUE(v60.withoutAngle(v120, 59.0f));
    ASSERT_TRUE(v60.withoutAngle(v150, 89.0f));
    ASSERT_TRUE(v60.withoutAngle(v180, 119.0f));
    ASSERT_TRUE(v90.withoutAngle(v120, 29.0f));
    ASSERT_TRUE(v90.withoutAngle(v150, 59.0f));
    ASSERT_TRUE(v90.withoutAngle(v180, 89.0f));
    ASSERT_TRUE(v120.withoutAngle(v150, 29.0f));
    ASSERT_TRUE(v120.withoutAngle(v180, 59.0f));
    ASSERT_TRUE(v150.withoutAngle(v180, 29.0f));

    ASSERT_FALSE(v00.withoutAngle(v30, 31.0f));
    ASSERT_FALSE(v00.withoutAngle(v60, 61.0f));
    ASSERT_FALSE(v00.withoutAngle(v90, 91.0f));
    ASSERT_FALSE(v00.withoutAngle(v120, 121.0f));
    ASSERT_FALSE(v00.withoutAngle(v150, 151.0f));
    ASSERT_FALSE(v30.withoutAngle(v60, 31.0f));
    ASSERT_FALSE(v30.withoutAngle(v90, 61.0f));
    ASSERT_FALSE(v30.withoutAngle(v120, 91.0f));
    ASSERT_FALSE(v30.withoutAngle(v150, 121.0f));
    ASSERT_FALSE(v30.withoutAngle(v180, 151.0f));
    ASSERT_FALSE(v60.withoutAngle(v90, 31.0f));
    ASSERT_FALSE(v60.withoutAngle(v120, 61.0f));
    ASSERT_FALSE(v60.withoutAngle(v150, 91.0f));
    ASSERT_FALSE(v60.withoutAngle(v180, 121.0f));
    ASSERT_FALSE(v90.withoutAngle(v120, 31.0f));
    ASSERT_FALSE(v90.withoutAngle(v150, 61.0f));
    ASSERT_FALSE(v90.withoutAngle(v180, 91.0f));
    ASSERT_FALSE(v120.withoutAngle(v150, 31.0f));
    ASSERT_FALSE(v120.withoutAngle(v180, 61.0f));
    ASSERT_FALSE(v150.withoutAngle(v180, 31.0f));
}

TEST_F(VectorTest, TestIsOrthogonal) {
    ASSERT_FALSE(v00.isOrthogonal(v30));
    ASSERT_FALSE(v00.isOrthogonal(v60));
    ASSERT_TRUE(v00.isOrthogonal(v90));
    ASSERT_FALSE(v00.isOrthogonal(v120));
    ASSERT_FALSE(v00.isOrthogonal(v150));
    ASSERT_FALSE(v00.isOrthogonal(v180));
    
    ASSERT_FALSE(v30.isOrthogonal(v60));
    ASSERT_FALSE(v30.isOrthogonal(v90));
    ASSERT_TRUE(v30.isOrthogonal(v120));
    ASSERT_FALSE(v30.isOrthogonal(v150));
    ASSERT_FALSE(v30.isOrthogonal(v180));

    ASSERT_FALSE(v60.isOrthogonal(v90));
    ASSERT_FALSE(v60.isOrthogonal(v120));
    ASSERT_TRUE(v60.isOrthogonal(v150));
    ASSERT_FALSE(v60.isOrthogonal(v180));

    ASSERT_FALSE(v90.isOrthogonal(v120));
    ASSERT_FALSE(v90.isOrthogonal(v150));
    ASSERT_TRUE(v90.isOrthogonal(v180));

    ASSERT_FALSE(v120.isOrthogonal(v150));
    ASSERT_FALSE(v120.isOrthogonal(v180));

    ASSERT_FALSE(v150.isOrthogonal(v180));
}

TEST_F(VectorTest, TestIsStraight) {
    ASSERT_FALSE(v00.isStraight(v30));
    ASSERT_FALSE(v00.isStraight(v60));
    ASSERT_FALSE(v00.isStraight(v90));
    ASSERT_FALSE(v00.isStraight(v120));
    ASSERT_FALSE(v00.isStraight(v150));
    ASSERT_TRUE(v00.isStraight(v180));
    
    ASSERT_FALSE(v30.isStraight(v60));
    ASSERT_FALSE(v30.isStraight(v90));
    ASSERT_FALSE(v30.isStraight(v120));
    ASSERT_FALSE(v30.isStraight(v150));
    ASSERT_FALSE(v30.isStraight(v180));

    ASSERT_FALSE(v60.isStraight(v90));
    ASSERT_FALSE(v60.isStraight(v120));
    ASSERT_FALSE(v60.isStraight(v150));
    ASSERT_FALSE(v60.isStraight(v180));

    ASSERT_FALSE(v90.isStraight(v120));
    ASSERT_FALSE(v90.isStraight(v150));
    ASSERT_FALSE(v90.isStraight(v180));

    ASSERT_FALSE(v120.isStraight(v150));
    ASSERT_FALSE(v120.isStraight(v180));

    ASSERT_FALSE(v150.isStraight(v180));
}
