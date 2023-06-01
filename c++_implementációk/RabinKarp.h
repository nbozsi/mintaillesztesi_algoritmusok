#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

long long int myhash(string minta, int alap, int val)
{
    const int M = 1000000007;
    long long int ertek = 0;
    for (int i = 0; i < minta.length(); i++)
    {
        ertek = (ertek * alap + minta[i] - val) % M; // minta hashének kiszámítása
    }
    return ertek;
}
void val(string abc, int *min, int *max)
{
    *min = abc[0];
    *max = abc[0];
    for (int i = 0; i < abc.length() - 1; i += 2)
    {
        if (abc[i] < *min)
        {
            *min = abc[i];
        }

        if (abc[i] > *max)
        {
            *max = abc[i];
        }
    }
    int alap = 1;
    while (alap < min - max + 1)
    {
        alap = alap * 2;
    }
    *max = alap;
}
vector<int> RabinKarp(string minta, string szoveg, int alap, int val, long long int mintahash)
{
    vector<int> talalatok;
    // int alap = E.size() + 1; // szamrendszer alapszama
    const int M = 1000000007; // ez egy nagyon nagy prímszám
    int maxh = 1;
    long long int vizsgalthash = 0;
    for (int i = 0; i < minta.length(); i++)
    {
        vizsgalthash = (vizsgalthash * alap + szoveg[i] - val) % M; // szoveg első substringének kiszámítása
    }
    for (int i = 0; i < minta.length() - 1; i++)
    {
        maxh = (maxh * alap) % M; // legnagyobb helyiérték kiszámítása
    }
    if (mintahash == vizsgalthash)
    {
        talalatok.push_back(0); // azaz a szoveg a mintával kezdődik
    }
    for (int i = 1; i <= szoveg.length() - minta.length(); i++)
    {
        vizsgalthash = (vizsgalthash - (szoveg[i - 1] - val) * maxh) % M; // betű eltávolítása az elejéről
        if (vizsgalthash < 0)                                             // negatív maraékot pozitívra hozzuk
        {
            vizsgalthash = vizsgalthash + M;
        }
        vizsgalthash = (vizsgalthash * alap + (szoveg[i + minta.length() - 1] - val)) % M; // betű hozzáadása a végéhez
        if (vizsgalthash == mintahash)
        {
            talalatok.push_back(i);
        }
    }
    return talalatok;
}