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