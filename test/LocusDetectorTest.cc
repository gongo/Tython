#include <gtest/gtest.h>
#include "LocusDetector.h"

class LocusDetectorTest : public testing::Test {
protected:
    void SetUp(void)
    {
        object = new LocusDetector(NULL);
    }

    LocusDetector* object;
};

// TEST_F(LocusDetectorTest, TestIsTraceCondition) {
//     TyVector v1(0.0f, 0.0f, 0.0f);
//     TyVector v2(1.0f, 0.0f, 0.0f);

//     ASSERT_FALSE(object->isTraceCondition(v1, v1));
//     ASSERT_TRUE(object->isTraceCondition(v1, v2));
// }
