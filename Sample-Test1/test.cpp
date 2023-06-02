#include "pch.h"
#include "../TDD_StringSimilarityChecker/StringSimilarityChecker.cpp"
#include <string>

using namespace std;

class StringSimilarityCheckerFixture : public testing::Test
{
public:
    StringSmilarityChecker cChecker;
};

TEST_F(StringSimilarityCheckerFixture, GetTotalPoint_NoString1)
{
    EXPECT_THROW(cChecker.GetTotalPoint("", "qwer"), invalid_argument);
}

TEST_F(StringSimilarityCheckerFixture, GetTotalPoint_NoString2)
{
    EXPECT_THROW(cChecker.GetTotalPoint("asdf", ""), invalid_argument);
}

TEST_F(StringSimilarityCheckerFixture, GetTotalPoint_NoStrings)
{
    EXPECT_THROW(cChecker.GetTotalPoint("", ""), invalid_argument);
}

TEST_F(StringSimilarityCheckerFixture, GetLengthPoint_1)
{
    EXPECT_EQ(60, cChecker.GetTotalPoint("asdf", "qwer"));
}

TEST_F(StringSimilarityCheckerFixture, GetLengthPoint_2)
{
    EXPECT_EQ(45, cChecker.GetTotalPoint("asdfe", "qwer"));
}

TEST_F(StringSimilarityCheckerFixture, GetLengthPoint_3)
{
    EXPECT_EQ(45, cChecker.GetTotalPoint("asdf", "qwert"));
}

TEST_F(StringSimilarityCheckerFixture, GetLengthPoint_4)
{
    EXPECT_EQ(0, cChecker.GetTotalPoint("asdf", "qwertyqwerty"));
}
