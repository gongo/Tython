#include <gtest/gtest.h>
#include "VM.h"

class VMTest : public testing::Test {
public:
    VM *object;
protected:
    virtual void SetUp() {
        object = VM::instance();
    }
};

TEST_F(VMTest, TestGetInstance) {
    VM *object2 = VM::instance();

    ASSERT_TRUE(NULL != object);
    ASSERT_TRUE(object == object2);
}

TEST_F(VMTest, TestPush) {
    object->push(10);
    ASSERT_EQ(10, object->top());
}

TEST_F(VMTest, TestSwap) {
    object->push(10);
    object->push(20);

    object->swap(0);

    ASSERT_EQ(10, object->top());
    object->pop();
    ASSERT_EQ(20, object->top());
}

TEST_F(VMTest, TestAdd) {
    object->push(10);
    object->push(20);
    object->add(NULL);

    ASSERT_EQ(30, object->top());
}

TEST_F(VMTest, TestSub) {
    object->push(10);
    object->push(20);
    object->sub(NULL);

    ASSERT_EQ(10, object->top());
}

TEST_F(VMTest, TestMul) {
    object->push(10);
    object->push(20);
    object->mul(NULL);

    ASSERT_EQ(200, object->top());
}

TEST_F(VMTest, TestDiv) {
    object->push(10);
    object->push(20);
    object->div(NULL);

    ASSERT_EQ(2, object->top());
}

TEST_F(VMTest, TestPop) {
    int p1 = 3;
    int p2 = 4;

    object->push(p1);
    object->push(p2);
    ASSERT_EQ(p2, object->pop());
    ASSERT_NE(p2, object->top());
    ASSERT_EQ(p1, object->pop());
}

TEST_F(VMTest, TestTop) {
    int p1 = 3;
    int p2 = 4;

    object->push(p1);
    object->push(p2);
    ASSERT_EQ(p2, object->top());
    ASSERT_EQ(p2, object->top());
    ASSERT_NE(p1, object->top());
}
