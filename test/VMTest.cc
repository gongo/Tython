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
    ASSERT_EQ(10, object->_stack.top());
}

TEST_F(VMTest, TestSwap) {
    object->_stack.push(10);
    object->_stack.push(20);

    object->swap(0);

    ASSERT_EQ(10, object->_stack.top());
    object->_stack.pop();
    ASSERT_EQ(20, object->_stack.top());
}

TEST_F(VMTest, TestAdd) {
    int size = object->_stack.size();

    object->push(10);
    object->push(20);
    object->add(NULL);

    ASSERT_EQ(30, object->_stack.top());
    ASSERT_EQ(size + 1, object->_stack.size());
}

TEST_F(VMTest, TestSub) {
    int size = object->_stack.size();

    object->push(10);
    object->push(20);
    object->sub(NULL);

    ASSERT_EQ(10, object->_stack.top());
    ASSERT_EQ(size + 1, object->_stack.size());
}

TEST_F(VMTest, TestMul) {
    int size = object->_stack.size();

    object->push(10);
    object->push(20);
    object->mul(NULL);

    ASSERT_EQ(200, object->_stack.top());
    ASSERT_EQ(size + 1, object->_stack.size());
}

TEST_F(VMTest, TestDiv) {
    int size = object->_stack.size();

    object->push(10);
    object->push(20);
    object->div(NULL);

    ASSERT_EQ(2, object->_stack.top());
    ASSERT_EQ(size + 1, object->_stack.size());
}
