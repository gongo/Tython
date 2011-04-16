#include <gtest/gtest.h>
#include "Vector.h"

class VectorTest : public testing::Test {
protected:
    virtual void SetUp() {
        x = 100.0f;
        y = -12.0f;
        z = 0.0f;
    }

    float x, y, z;
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

TEST_F(VectorTest, TestWithinAngle) {
    Vector v1(1.0f, 0.0f, 0.0f);
    Vector v2(0.1f, 1.0f, 0.0f);
    Vector v3(-1.0f, 0.2f, 0.0f);

    ASSERT_TRUE(v1.withinAngle(v2, 90.0f));
    ASSERT_TRUE(v2.withinAngle(v3, 120.0f));
    ASSERT_TRUE(v1.withinAngle(v3, 180.0f));
}

TEST_F(VectorTest, TestWithoutAngle) {
    Vector v1(1.0f, 0.0f, 0.0f); // 0 
    Vector v2(1.0f, 1.0f, 0.0f); // 45
    Vector v3(0.0f, 1.0f, 0.0f); // 90
    Vector v4(-1.0f, 0.0f, 0.0f); // 180

    ASSERT_TRUE(v1.withoutAngle(v2, 40.0f));
    ASSERT_TRUE(v2.withoutAngle(v3, 40.0f));
    ASSERT_TRUE(v1.withoutAngle(v3, 88.0f));
    ASSERT_TRUE(v1.withoutAngle(v4, 175.0f));
    ASSERT_TRUE(v2.withoutAngle(v4, 130.0f));
    ASSERT_TRUE(v3.withoutAngle(v4, 88.0f));
}
