#include <string>
#include <stdexcept>

using namespace std;

class StringSmilarityChecker
{
public:
    int GetTotalPoint(string sString1, string sString2)
    {
        if (IsInputEmpty(sString1, sString2))
            throw invalid_argument("���� �־�� �մϴ�.");

        if (IsNotAllCapital(sString1) || IsNotAllCapital(sString2))
            throw invalid_argument("�빮�ڸ� �Է� �����մϴ�.");

        return GetLengthPoint(sString1, sString2);
    }

    bool IsInputEmpty(string sString1, string sString2)
    {
        if (0 == sString1.size() || 0 == sString2.size())
            return true;

        return false;
    }

    bool IsNotAllCapital(string sString)
    {
        for (char cEach : sString)
        {
            if (cEach < 'A' || cEach > 'Z')
                return true;
        }

        return false;
    }

    int GetLengthPoint(string sString1, string sString2)
    {
        CompareLength(sString1, sString2);

        return CalculateLengthPoint();
    }


    void CompareLength(string sString1, string sString2)
    {
        if (sString1.size() > sString2.size())
        {
            nLongLength = sString1.size();
            nShortLength = sString2.size();
        }
        else
        {
            nLongLength = sString2.size();
            nShortLength = sString1.size();
        }

        nDiffLength = nLongLength - nShortLength;
    }

    int CalculateLengthPoint()
    {
        if (nLongLength >= 2 * nShortLength) return 0;
        return (nShortLength - nDiffLength) * MAX_LENGTH_POINT / nShortLength;
    }

private:
    const int MAX_LENGTH_POINT = 60;
    int nLongLength = 0;
    int nShortLength = 0;
    int nDiffLength = 0;
};