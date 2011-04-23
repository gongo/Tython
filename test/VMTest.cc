#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>

#include "VM.h"
#include "Compiler.h"

class VMTest : public testing::Test {
public:
    VM *object;
protected:
    virtual void SetUp() {
        object = VM::instance();
        object->clear();
    }
};

TEST_F(VMTest, TestGetInstance) {
    VM *object2 = VM::instance();

    ASSERT_TRUE(NULL != object);
    ASSERT_TRUE(object == object2);
}

TEST_F(VMTest, TestRun) {
    Compiler *compiler = Compiler::instance();
    vector<Instruction*> insns;

    // 2 + 7 = 9 を stdout
    insns = compiler->compile("aaaaagaa@a@g@aaa@ a@");
    testing::internal::CaptureStdout();
    object->run(insns);
    ASSERT_STREQ("9", testing::internal::GetCapturedStdout().c_str());

    // 11 * 23 = 253 を stdout
    insns = compiler->compile("aaa@aagaaa@aaag@aa @ a@");
    testing::internal::CaptureStdout();
    object->run(insns);
    ASSERT_STREQ("253", testing::internal::GetCapturedStdout().c_str());
}

TEST_F(VMTest, TestPush) {
    object->push(10);
    ASSERT_EQ(10, object->top());
}

TEST_F(VMTest, TestDup) {
    int p = 10;

    object->push(p);
    object->dup(NULL);

    ASSERT_EQ(p, object->top());
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
    int size = object->size();
    
    object->push(10);
    object->push(20);
    object->add(NULL);

    ASSERT_EQ(30, object->top());
    ASSERT_EQ(size + 1, object->size());
}

TEST_F(VMTest, TestSub) {
    int size = object->size();

    object->push(10);
    object->push(20);
    object->sub(NULL);

    ASSERT_EQ(10, object->top());
    ASSERT_EQ(size + 1, object->size());
}

TEST_F(VMTest, TestMul) {
    int size = object->size();

    object->push(10);
    object->push(20);
    object->mul(NULL);

    ASSERT_EQ(200, object->top());
    ASSERT_EQ(size + 1, object->size());
}

TEST_F(VMTest, TestDiv) {
    int size = object->size();

    object->push(10);
    object->push(20);
    object->div(NULL);

    ASSERT_EQ(2, object->top());
    ASSERT_EQ(size + 1, object->size());
}

TEST_F(VMTest, TestDiscard) {
    int p1 = 3;
    int p2 = 4;

    object->push(p1);
    object->push(p2);
    object->discard(NULL);

    ASSERT_NE(p2, object->top());
    ASSERT_EQ(p1, object->top());
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


TEST_F(VMTest, TestClear) {
    object->push(10);
    object->push(10);
    object->push(10);
    object->clear();

    ASSERT_EQ(0, object->size());
 }

TEST_F(VMTest, TestNum_Out) {
    object->push(20);

    testing::internal::CaptureStdout();
    object->num_out(NULL);
    ASSERT_STREQ("20", testing::internal::GetCapturedStdout().c_str());
}

TEST_F(VMTest, TestSlide) {
    int p1 = 1;
    int p2 = 2;
    int p3 = 3;
    int p4 = 4;
    int size;
    int slide = 3;

    object->push(p1);
    object->push(p2);
    object->push(p3);
    object->push(p4);
    size = object->size();

    object->slide(slide);

    ASSERT_EQ(p4, object->top());
    ASSERT_EQ(size - slide, object->size()); 
}
