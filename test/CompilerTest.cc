#include <gtest/gtest.h>
#include "Compiler.h"

class CompilerTest : public testing::Test {
public:
    Compiler *object;
protected:
    virtual void SetUp() {
        object = Compiler::instance();
    }
};

TEST_F(CompilerTest, TestGetInstance) {
    Compiler *object2 = Compiler::instance();

    ASSERT_TRUE(NULL != object);
    ASSERT_TRUE(object == object2);
}

TEST_F(CompilerTest, TestCompile) {
    ASSERT_FALSE(object->compile("aa"));
    ASSERT_FALSE(object->compile("a@@aaa"));
}

TEST_F(CompilerTest, TestCompileErrorOfUnableToTreat) {
    ASSERT_FALSE(object->compile("a@a! "));
}

TEST_F(CompilerTest, TestScan) {
    string str  = "Thanks!!";
    string key1 = "T";
    string key2 = "Tha";
    string key3 = "Thanks!!";
    string key4 = "Thanks!!!";
    string key5 = "ank";

    ASSERT_EQ(1, object->scan(str, key1, 0));
    ASSERT_EQ(1, object->scan(str, key1, 1));

    ASSERT_EQ(3, object->scan(str, key2, 0));
    ASSERT_EQ(1, object->scan(str, key2, 1));

    ASSERT_EQ(8, object->scan(str, key3, 0));
    ASSERT_EQ(1, object->scan(str, key3, 1));

    ASSERT_EQ(0, object->scan(str, key4, 0));

    ASSERT_EQ(0, object->scan(str, key5, 0));
    ASSERT_EQ(5, object->scan(str, key5, 2));
    ASSERT_EQ(3, object->scan(str, key5, 3));
}
