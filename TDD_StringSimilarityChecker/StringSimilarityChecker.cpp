#include <string>
#include <stdexcept>

using namespace std;

class StringSmilarityChecker
{
public:
    int GetTotalPoint(string sString1, string sString2)
    {
        if (0 == sString1.size() || 0 == sString2.size())
            throw invalid_argument("���� �־�� �մϴ�.");
    }
};