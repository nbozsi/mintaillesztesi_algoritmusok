#include <iostream>
#include <map>

using namespace std;

map<char, int> tav(string minta, string szoveg)
{
    map<char, int> E;
    for (int i = 0; i < szoveg.length(); i++)
    {
        E[szoveg[i]] = minta.length();
    }
    for (int i = 0; i < minta.length() - 1; i++)
    {
        E[minta[i]] = minta.length() - i - 1;
    }
    return E;
}
int Horspool(string minta, string szoveg, map<char, int> E)
{
    int j = minta.length() - 1;
    bool jo;
    while (j < szoveg.length())
    {
        if (szoveg[j] == minta.back())
        {
            jo = true;
            for (int i = 0; i < minta.length(); i++)
            {
                if (szoveg[j - minta.length() + 1 + i] != minta[i])
                {
                    jo = false;
                    break;
                }
            }
            if (jo)
            {
                return j - minta.length() + 1;
            }
        }
        j = E[szoveg[j]] + j;
    }
    return -1;
}