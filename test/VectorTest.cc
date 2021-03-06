#include <gtest/gtest.h>
#include <math.h>
#include "Vector.h"
#include "MockVector.h"

class VectorTest : public testing::Test {
public:
    virtual void SetUp() {
        x = 100.0f;
        y = -12.0f;
        z = 0.0f;
    }

    float x, y, z;
};

TEST_F(VectorTest, TestConstructor) {
    ty::Vector vec;

    ASSERT_EQ(0.0f, vec.X);
    ASSERT_EQ(0.0f, vec.Y);
    ASSERT_EQ(0.0f, vec.Z);
}

TEST_F(VectorTest, TestConstructorWithXnVector3D) {
    XnVector3D v  = {x, y, z};
    ty::Vector vec(v);

    ASSERT_EQ(v.X, vec.X);
    ASSERT_EQ(v.Y, vec.Y);
    ASSERT_EQ(v.Z, vec.Z);
}

TEST_F(VectorTest, TestConstructorWithFloat) {
    ty::Vector vec(x, y, z);

    ASSERT_EQ(x, vec.X);
    ASSERT_EQ(y, vec.Y);
    ASSERT_EQ(z, vec.Z);
}

TEST_F(VectorTest, TestAssignOperatorPlus) {
    ty::Vector vec1(x, y, z);
    ty::Vector vec2(x, y, z);

    vec1 += vec2;
    
    ASSERT_EQ(x + x, vec1.X);
    ASSERT_EQ(y + y, vec1.Y);
    ASSERT_EQ(z + z, vec1.Z);
}

TEST_F(VectorTest, TestAssignOperatorMinus) {
    ty::Vector vec1(x, y, z);
    ty::Vector vec2(x, y, z);

    vec1 -= vec2;
    
    ASSERT_EQ(x - x, vec1.X);
    ASSERT_EQ(y - y, vec1.Y);
    ASSERT_EQ(z - z, vec1.Z);
}

TEST_F(VectorTest, TestAssignOperatorMulti) {
    ty::Vector vec(x, y, z);
    float f = 3.0f;

    vec *= f;
    
    ASSERT_EQ(x * f, vec.X);
    ASSERT_EQ(y * f, vec.Y);
    ASSERT_EQ(z * f, vec.Z);
}

TEST_F(VectorTest, TestAssignOperatorDiv) {
    ty::Vector vec(x, y, z);
    float f = 3.0f;

    vec /= f;
    
    ASSERT_EQ(x / f, vec.X);
    ASSERT_EQ(y / f, vec.Y);
    ASSERT_EQ(z / f, vec.Z);
}

TEST_F(VectorTest, TestOperatorPlus) {
    ty::Vector vec1(x, y, z);
    ty::Vector vec2(x, y, z);

    ty::Vector vec3 = vec1 + vec2;
    
    ASSERT_EQ(x + x, vec3.X);
    ASSERT_EQ(y + y, vec3.Y);
    ASSERT_EQ(z + z, vec3.Z);
}

TEST_F(VectorTest, TestOperatorMinus) {
    ty::Vector vec1(x, y, z);
    ty::Vector vec2(x, y, z);

    ty::Vector vec3 = vec1 - vec2;
    
    ASSERT_EQ(x - x, vec3.X);
    ASSERT_EQ(y - y, vec3.Y);
    ASSERT_EQ(z - z, vec3.Z);
}

TEST_F(VectorTest, TestOperatorMulti) {
    ty::Vector vec1(x, y, z);
    float f = 3.0f;

    ty::Vector vec2 = vec1 * f;
    
    ASSERT_EQ(x * f, vec2.X);
    ASSERT_EQ(y * f, vec2.Y);
    ASSERT_EQ(z * f, vec2.Z);
}

TEST_F(VectorTest, TestOperatorDiv) {
    ty::Vector vec1(x, y, z);
    float f = 3.0f;

    ty::Vector vec2 = vec1 / f;
    
    ASSERT_EQ(x / f, vec2.X);
    ASSERT_EQ(y / f, vec2.Y);
    ASSERT_EQ(z / f, vec2.Z);
}

TEST_F(VectorTest, TestOperatorEqual) {
    ty::Vector vec1(x, y, z);
    ty::Vector vec2(x, y, z);
    ty::Vector vec3(x, y + 1, z + 1);

    ASSERT_TRUE(vec1 == vec2);
    ASSERT_FALSE(vec1 == vec3);
}

TEST_F(VectorTest, TestMagnitude) {
    ty::Vector vec(x, y, z);
    ASSERT_EQ(sqrtf(x*x + y*y + z*z), vec.magnitude());
}

TEST_F(VectorTest, TestNormalize) {
    ty::Vector v(x, y, z);
    ty::Vector nv = v.normalize();

    ASSERT_GE(1.0f,   nv.magnitude()); // 誤差範囲内をテスト
    ASSERT_LT(0.999f, nv.magnitude()); // 1.0 >= magnitude > 0.999
}

TEST_F(VectorTest, TestDot) {
    ty::Vector vec1(3.0f, 0.0f, 0.0f);
    ty::Vector vec2(0.0f, 1.0f, 0.0f);
    ty::Vector vec3(1.0f, 1.0f, 1.0f);
    ty::Vector vec4(-12.0f, 0.0f, 0.0f);

    ASSERT_EQ( 1.0f, vec1.dot(vec1)); // 平行(同方向)
    ASSERT_EQ( 0.0f, vec1.dot(vec2)); // 直行
    ASSERT_LT( 0.0f, vec1.dot(vec3)); // 鋭角
    ASSERT_EQ(-1.0f, vec1.dot(vec4)); // 平行(逆方向)
    ASSERT_GT( 0.0f, vec3.dot(vec4)); // 鈍角
}

TEST_F(VectorTest, TestCross) {
    ty::Vector vec0;
    ty::Vector vecX(1.0f, 0.0f, 0.0f);
    ty::Vector vecY(0.0f, 1.0f, 0.0f);
    ty::Vector vecZ(0.0f, 0.0f, 1.0f);

    ASSERT_TRUE(ty::Vector(0.0f, 0.0f,  1.0f) == vecX.cross(vecY));
    ASSERT_TRUE(ty::Vector(0.0f, 0.0f, -1.0f) == vecY.cross(vecX));
    ASSERT_TRUE(ty::Vector(0.0f, -1.0f, 0.0f) == vecX.cross(vecZ));
    ASSERT_TRUE(ty::Vector(0.0f,  1.0f, 0.0f) == vecZ.cross(vecX));
    ASSERT_TRUE(ty::Vector( 1.0f, 0.0f, 0.0f) == vecY.cross(vecZ));
    ASSERT_TRUE(ty::Vector(-1.0f, 0.0f, 0.0f) == vecZ.cross(vecY));
}

TEST_F(VectorTest, TestDistance) {
    ty::Vector v1(1.0f, 0.0f, 3.0f);
    ty::Vector v2(3.0f, 0.0f, 0.0f);
    ty::Vector v3(-3.0f, 0.0f, 0.0f);

    ASSERT_EQ(0.0f, v1.distance(v1));
    ASSERT_EQ(6.0f, v2.distance(v3));
}

TEST_F(VectorTest, TestReverse) {
    ty::Vector vec(x, y, z);
    ty::Vector rev = vec.reverse();
    
    ASSERT_EQ(-x, rev.X);
    ASSERT_EQ(-y, rev.Y);
    ASSERT_EQ(-z, rev.Z);
}

TEST_F(VectorTest, TestWithinAngle) {
    ASSERT_FALSE(MockVector::v00.withinAngle(MockVector::v30, 29.0f));
    ASSERT_FALSE(MockVector::v00.withinAngle(MockVector::v60, 59.0f));
    ASSERT_FALSE(MockVector::v00.withinAngle(MockVector::v90, 89.0f));
    ASSERT_FALSE(MockVector::v00.withinAngle(MockVector::v120, 119.0f));
    ASSERT_FALSE(MockVector::v00.withinAngle(MockVector::v150, 149.0f));
    ASSERT_FALSE(MockVector::v00.withinAngle(MockVector::v180, 179.0f)); 
    ASSERT_FALSE(MockVector::v30.withinAngle(MockVector::v60, 29.0f));
    ASSERT_FALSE(MockVector::v30.withinAngle(MockVector::v90, 59.0f));
    ASSERT_FALSE(MockVector::v30.withinAngle(MockVector::v120, 89.0f));
    ASSERT_FALSE(MockVector::v30.withinAngle(MockVector::v150, 119.0f));
    ASSERT_FALSE(MockVector::v30.withinAngle(MockVector::v180, 149.0f));
    ASSERT_FALSE(MockVector::v60.withinAngle(MockVector::v90, 29.0f));
    ASSERT_FALSE(MockVector::v60.withinAngle(MockVector::v120, 59.0f));
    ASSERT_FALSE(MockVector::v60.withinAngle(MockVector::v150, 89.0f));
    ASSERT_FALSE(MockVector::v60.withinAngle(MockVector::v180, 119.0f));
    ASSERT_FALSE(MockVector::v90.withinAngle(MockVector::v120, 29.0f));
    ASSERT_FALSE(MockVector::v90.withinAngle(MockVector::v150, 59.0f));
    ASSERT_FALSE(MockVector::v90.withinAngle(MockVector::v180, 89.0f));
    ASSERT_FALSE(MockVector::v120.withinAngle(MockVector::v150, 29.0f));
    ASSERT_FALSE(MockVector::v120.withinAngle(MockVector::v180, 59.0f));
    ASSERT_FALSE(MockVector::v150.withinAngle(MockVector::v180, 29.0f));

    ASSERT_TRUE(MockVector::v00.withinAngle(MockVector::v30, 31.0f));
    ASSERT_TRUE(MockVector::v00.withinAngle(MockVector::v60, 61.0f));
    ASSERT_TRUE(MockVector::v00.withinAngle(MockVector::v90, 91.0f));
    ASSERT_TRUE(MockVector::v00.withinAngle(MockVector::v120, 121.0f));
    ASSERT_TRUE(MockVector::v00.withinAngle(MockVector::v150, 151.0f));
    ASSERT_TRUE(MockVector::v30.withinAngle(MockVector::v60, 31.0f));
    ASSERT_TRUE(MockVector::v30.withinAngle(MockVector::v90, 61.0f));
    ASSERT_TRUE(MockVector::v30.withinAngle(MockVector::v120, 91.0f));
    ASSERT_TRUE(MockVector::v30.withinAngle(MockVector::v150, 121.0f));
    ASSERT_TRUE(MockVector::v30.withinAngle(MockVector::v180, 151.0f));
    ASSERT_TRUE(MockVector::v60.withinAngle(MockVector::v90, 31.0f));
    ASSERT_TRUE(MockVector::v60.withinAngle(MockVector::v120, 61.0f));
    ASSERT_TRUE(MockVector::v60.withinAngle(MockVector::v150, 91.0f));
    ASSERT_TRUE(MockVector::v60.withinAngle(MockVector::v180, 121.0f));
    ASSERT_TRUE(MockVector::v90.withinAngle(MockVector::v120, 31.0f));
    ASSERT_TRUE(MockVector::v90.withinAngle(MockVector::v150, 61.0f));
    ASSERT_TRUE(MockVector::v90.withinAngle(MockVector::v180, 91.0f));
    ASSERT_TRUE(MockVector::v120.withinAngle(MockVector::v150, 31.0f));
    ASSERT_TRUE(MockVector::v120.withinAngle(MockVector::v180, 61.0f));
    ASSERT_TRUE(MockVector::v150.withinAngle(MockVector::v180, 31.0f));
}

TEST_F(VectorTest, TestWithoutAngle) {
    ASSERT_TRUE(MockVector::v00.withoutAngle(MockVector::v30, 29.0f));
    ASSERT_TRUE(MockVector::v00.withoutAngle(MockVector::v60, 59.0f));
    ASSERT_TRUE(MockVector::v00.withoutAngle(MockVector::v90, 89.0f));
    ASSERT_TRUE(MockVector::v00.withoutAngle(MockVector::v120, 119.0f));
    ASSERT_TRUE(MockVector::v00.withoutAngle(MockVector::v150, 149.0f));
    ASSERT_TRUE(MockVector::v00.withoutAngle(MockVector::v180, 179.0f)); 
    ASSERT_TRUE(MockVector::v30.withoutAngle(MockVector::v60, 29.0f));
    ASSERT_TRUE(MockVector::v30.withoutAngle(MockVector::v90, 59.0f));
    ASSERT_TRUE(MockVector::v30.withoutAngle(MockVector::v120, 89.0f));
    ASSERT_TRUE(MockVector::v30.withoutAngle(MockVector::v150, 119.0f));
    ASSERT_TRUE(MockVector::v30.withoutAngle(MockVector::v180, 149.0f));
    ASSERT_TRUE(MockVector::v60.withoutAngle(MockVector::v90, 29.0f));
    ASSERT_TRUE(MockVector::v60.withoutAngle(MockVector::v120, 59.0f));
    ASSERT_TRUE(MockVector::v60.withoutAngle(MockVector::v150, 89.0f));
    ASSERT_TRUE(MockVector::v60.withoutAngle(MockVector::v180, 119.0f));
    ASSERT_TRUE(MockVector::v90.withoutAngle(MockVector::v120, 29.0f));
    ASSERT_TRUE(MockVector::v90.withoutAngle(MockVector::v150, 59.0f));
    ASSERT_TRUE(MockVector::v90.withoutAngle(MockVector::v180, 89.0f));
    ASSERT_TRUE(MockVector::v120.withoutAngle(MockVector::v150, 29.0f));
    ASSERT_TRUE(MockVector::v120.withoutAngle(MockVector::v180, 59.0f));
    ASSERT_TRUE(MockVector::v150.withoutAngle(MockVector::v180, 29.0f));

    ASSERT_FALSE(MockVector::v00.withoutAngle(MockVector::v30, 31.0f));
    ASSERT_FALSE(MockVector::v00.withoutAngle(MockVector::v60, 61.0f));
    ASSERT_FALSE(MockVector::v00.withoutAngle(MockVector::v90, 91.0f));
    ASSERT_FALSE(MockVector::v00.withoutAngle(MockVector::v120, 121.0f));
    ASSERT_FALSE(MockVector::v00.withoutAngle(MockVector::v150, 151.0f));
    ASSERT_FALSE(MockVector::v30.withoutAngle(MockVector::v60, 31.0f));
    ASSERT_FALSE(MockVector::v30.withoutAngle(MockVector::v90, 61.0f));
    ASSERT_FALSE(MockVector::v30.withoutAngle(MockVector::v120, 91.0f));
    ASSERT_FALSE(MockVector::v30.withoutAngle(MockVector::v150, 121.0f));
    ASSERT_FALSE(MockVector::v30.withoutAngle(MockVector::v180, 151.0f));
    ASSERT_FALSE(MockVector::v60.withoutAngle(MockVector::v90, 31.0f));
    ASSERT_FALSE(MockVector::v60.withoutAngle(MockVector::v120, 61.0f));
    ASSERT_FALSE(MockVector::v60.withoutAngle(MockVector::v150, 91.0f));
    ASSERT_FALSE(MockVector::v60.withoutAngle(MockVector::v180, 121.0f));
    ASSERT_FALSE(MockVector::v90.withoutAngle(MockVector::v120, 31.0f));
    ASSERT_FALSE(MockVector::v90.withoutAngle(MockVector::v150, 61.0f));
    ASSERT_FALSE(MockVector::v90.withoutAngle(MockVector::v180, 91.0f));
    ASSERT_FALSE(MockVector::v120.withoutAngle(MockVector::v150, 31.0f));
    ASSERT_FALSE(MockVector::v120.withoutAngle(MockVector::v180, 61.0f));
    ASSERT_FALSE(MockVector::v150.withoutAngle(MockVector::v180, 31.0f));
}

TEST_F(VectorTest, TestIsOrthogonal) {
    ASSERT_FALSE(MockVector::v00.isOrthogonal(MockVector::v30));
    ASSERT_FALSE(MockVector::v00.isOrthogonal(MockVector::v60));
    ASSERT_TRUE(MockVector::v00.isOrthogonal(MockVector::v90));
    ASSERT_FALSE(MockVector::v00.isOrthogonal(MockVector::v120));
    ASSERT_FALSE(MockVector::v00.isOrthogonal(MockVector::v150));
    ASSERT_FALSE(MockVector::v00.isOrthogonal(MockVector::v180));
    
    ASSERT_FALSE(MockVector::v30.isOrthogonal(MockVector::v60));
    ASSERT_FALSE(MockVector::v30.isOrthogonal(MockVector::v90));
    ASSERT_TRUE(MockVector::v30.isOrthogonal(MockVector::v120));
    ASSERT_FALSE(MockVector::v30.isOrthogonal(MockVector::v150));
    ASSERT_FALSE(MockVector::v30.isOrthogonal(MockVector::v180));

    ASSERT_FALSE(MockVector::v60.isOrthogonal(MockVector::v90));
    ASSERT_FALSE(MockVector::v60.isOrthogonal(MockVector::v120));
    ASSERT_TRUE(MockVector::v60.isOrthogonal(MockVector::v150));
    ASSERT_FALSE(MockVector::v60.isOrthogonal(MockVector::v180));

    ASSERT_FALSE(MockVector::v90.isOrthogonal(MockVector::v120));
    ASSERT_FALSE(MockVector::v90.isOrthogonal(MockVector::v150));
    ASSERT_TRUE(MockVector::v90.isOrthogonal(MockVector::v180));

    ASSERT_FALSE(MockVector::v120.isOrthogonal(MockVector::v150));
    ASSERT_FALSE(MockVector::v120.isOrthogonal(MockVector::v180));

    ASSERT_FALSE(MockVector::v150.isOrthogonal(MockVector::v180));
}

TEST_F(VectorTest, TestIsStraight) {
    ASSERT_TRUE(MockVector::v00.isStraight(MockVector::v00));
    ASSERT_FALSE(MockVector::v00.isStraight(MockVector::v30));
    ASSERT_FALSE(MockVector::v00.isStraight(MockVector::v60));
    ASSERT_FALSE(MockVector::v00.isStraight(MockVector::v90));
    ASSERT_FALSE(MockVector::v00.isStraight(MockVector::v120));
    ASSERT_FALSE(MockVector::v00.isStraight(MockVector::v150));
    ASSERT_FALSE(MockVector::v00.isStraight(MockVector::v180));
    
    ASSERT_TRUE(MockVector::v30.isStraight(MockVector::v30));
    ASSERT_FALSE(MockVector::v30.isStraight(MockVector::v60));
    ASSERT_FALSE(MockVector::v30.isStraight(MockVector::v90));
    ASSERT_FALSE(MockVector::v30.isStraight(MockVector::v120));
    ASSERT_FALSE(MockVector::v30.isStraight(MockVector::v150));
    ASSERT_FALSE(MockVector::v30.isStraight(MockVector::v180));

    ASSERT_TRUE(MockVector::v60.isStraight(MockVector::v60));
    ASSERT_FALSE(MockVector::v60.isStraight(MockVector::v90));
    ASSERT_FALSE(MockVector::v60.isStraight(MockVector::v120));
    ASSERT_FALSE(MockVector::v60.isStraight(MockVector::v150));
    ASSERT_FALSE(MockVector::v60.isStraight(MockVector::v180));

    ASSERT_TRUE(MockVector::v90.isStraight(MockVector::v90));
    ASSERT_FALSE(MockVector::v90.isStraight(MockVector::v120));
    ASSERT_FALSE(MockVector::v90.isStraight(MockVector::v150));
    ASSERT_FALSE(MockVector::v90.isStraight(MockVector::v180));
    
    ASSERT_TRUE(MockVector::v120.isStraight(MockVector::v120));
    ASSERT_FALSE(MockVector::v120.isStraight(MockVector::v150));
    ASSERT_FALSE(MockVector::v120.isStraight(MockVector::v180));

    ASSERT_TRUE(MockVector::v150.isStraight(MockVector::v150));
    ASSERT_FALSE(MockVector::v150.isStraight(MockVector::v180));

    ASSERT_TRUE(MockVector::v180.isStraight(MockVector::v180));
}

TEST_F(VectorTest, TestIsParallel) {
    ASSERT_TRUE(MockVector::v00.isParallel(MockVector::v00));
    ASSERT_FALSE(MockVector::v00.isParallel(MockVector::v30));
    ASSERT_FALSE(MockVector::v00.isParallel(MockVector::v60));
    ASSERT_FALSE(MockVector::v00.isParallel(MockVector::v90));
    ASSERT_FALSE(MockVector::v00.isParallel(MockVector::v120));
    ASSERT_FALSE(MockVector::v00.isParallel(MockVector::v150));
    ASSERT_TRUE(MockVector::v00.isParallel(MockVector::v180));
    
    ASSERT_TRUE(MockVector::v30.isParallel(MockVector::v30));
    ASSERT_FALSE(MockVector::v30.isParallel(MockVector::v60));
    ASSERT_FALSE(MockVector::v30.isParallel(MockVector::v90));
    ASSERT_FALSE(MockVector::v30.isParallel(MockVector::v120));
    ASSERT_FALSE(MockVector::v30.isParallel(MockVector::v150));
    ASSERT_FALSE(MockVector::v30.isParallel(MockVector::v180));

    ASSERT_TRUE(MockVector::v60.isParallel(MockVector::v60));
    ASSERT_FALSE(MockVector::v60.isParallel(MockVector::v90));
    ASSERT_FALSE(MockVector::v60.isParallel(MockVector::v120));
    ASSERT_FALSE(MockVector::v60.isParallel(MockVector::v150));
    ASSERT_FALSE(MockVector::v60.isParallel(MockVector::v180));

    ASSERT_TRUE(MockVector::v90.isParallel(MockVector::v90));
    ASSERT_FALSE(MockVector::v90.isParallel(MockVector::v120));
    ASSERT_FALSE(MockVector::v90.isParallel(MockVector::v150));
    ASSERT_FALSE(MockVector::v90.isParallel(MockVector::v180));

    ASSERT_TRUE(MockVector::v120.isParallel(MockVector::v120));
    ASSERT_FALSE(MockVector::v120.isParallel(MockVector::v150));
    ASSERT_FALSE(MockVector::v120.isParallel(MockVector::v180));

    ASSERT_TRUE(MockVector::v150.isParallel(MockVector::v150));
    ASSERT_FALSE(MockVector::v150.isParallel(MockVector::v180));

    ASSERT_TRUE(MockVector::v180.isParallel(MockVector::v180));
}
