#include "pch.h"
#include "../TDD_StringSimilarityChecker/StringSimilarityChecker.cpp"
#include <string>

using namespace std;

class StringSmilarityCheckerFixture : public testing::Test
{
public:
    StringSmilarityChecker cChecker;
};

TEST_F(StringSmilarityCheckerFixture, GetTotalPoint_NoString1)
{
    EXPECT_THROW(cChecker.GetTotalPoint("", "qwer"), invalid_argument);
}

TEST_F(StringSmilarityCheckerFixture, GetTotalPoint_NoString2)
{
    EXPECT_THROW(cChecker.GetTotalPoint("asdf", ""), invalid_argument);
}

TEST_F(StringSmilarityCheckerFixture, GetTotalPoint_NoStrings)
{
    EXPECT_THROW(cChecker.GetTotalPoint("", ""), invalid_argument);
}

TEST_F(StringSmilarityCheckerFixture, GetLengthPoint_1)
{
    EXPECT_EQ(60, cChecker.GetLengthPoint("asdf", "qwer"));
}

TEST_F(StringSmilarityCheckerFixture, GetLengthPoint_2)
{
    EXPECT_EQ(45, cChecker.GetLengthPoint("asdfe", "qwer"));
}

TEST_F(StringSmilarityCheckerFixture, GetLengthPoint_3)
{
    EXPECT_EQ(45, cChecker.GetLengthPoint("asdf", "qwert"));
}

TEST_F(StringSmilarityCheckerFixture, GetLengthPoint_4)
{
    EXPECT_EQ(0, cChecker.GetLengthPoint("asdf", "qwertyqwerty"));
}
