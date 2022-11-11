#include <iostream>

using namespace std;

int brute_force(string minta, string szoveg)
{
    bool jo;
    for (int i = 0; i <= szoveg.length() - minta.length(); i++)
    {
        jo = true;
        for (int j = 0; j < minta.length(); j++)
        {
            if (minta[j] != szoveg[i + j])
            {
                jo = false;
                break;
            }
        }
        if (jo)
        {
            return i;
        }
    }
    return -1;
}