#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Vector.h"

using ::testing::DefaultValue;

void setMockDefaultValue(void)
{
    DefaultValue<Vector>::Set(Vector(0.0f, 0.0f, 0.0f));
    DefaultValue<XnUInt64>::Set(0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    ::testing::FLAGS_gmock_verbose = "error";

    setMockDefaultValue();

    return RUN_ALL_TESTS();
}
