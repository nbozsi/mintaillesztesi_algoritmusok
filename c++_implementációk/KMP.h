#include <iostream>
#include <vector>

using namespace std;

vector<int> labfej(string minta)
{
    vector<int> P(minta.length() + 1, 0);
    int j;
    for (int i = 1; i < minta.length(); i++)
    {
        j = i;
        while (j > 0)
        {
            if (minta[P[j]] == minta[i])
            {
                P[i + 1] = P[j] + 1;
                break;
            }
            else
            {
                j = P[j];
            }
        }
    }
    return P;
}
vector<int> KMP(string minta, string szoveg, vector<int> P)
{
    vector<int> talalatok;
    int i = 0;
    int j = 0;
    while (i + j < szoveg.length())
    {
        if (j == minta.length())
        {
            talalatok.push_back(i);
        }
        if (szoveg[i + j] == minta[j])
        {
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                i = i + j - P[j];
                j = P[j];
            }
        }
    }
    if (j == minta.length())
    {
        talalatok.push_back(i);
    }
    return talalatok;
}