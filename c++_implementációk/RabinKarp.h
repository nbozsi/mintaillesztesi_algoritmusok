#include <iostream>
#include <map>
using namespace std;

map<char, int> charvalue(string szoveg)
{
    map<char, int> E;
    int next = 1;
    pair<map<char, int>::iterator, bool> ret;
    for (int i = 0; i < szoveg.length(); i++)
    {
        ret = E.insert({szoveg[i], next});
        if (ret.second)
        {
            next++;
        }
    }
    return E;
}
vector<int> RabinKarp(string minta, string szoveg, map<char, int> E)
{
    vector<int> talalatok;
    int alap = E.size() + 1; // szamrendszer alapszama
    int M = 1000000007;      // ez egy nagyon nagy prímszám
    int maxh = 1;
    long long int mintahash = 0;
    long long int vizsgalthash = 0;
    for (int i = 0; i < minta.length(); i++)
    {
        mintahash = (mintahash * alap + E[minta[i]]) % M;        // minta hashének kiszámítása
        vizsgalthash = (vizsgalthash * alap + E[szoveg[i]]) % M; // szoveg első substringének kiszámítása
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
        vizsgalthash = (vizsgalthash - E[szoveg[i - 1]] * maxh) % M; // betű eltávolítása az elejéről (hozzáadunk M-t hogy pozitív maradék legyen)
        if (vizsgalthash < 0)                                        // negatív maraékot pozitívra hozzuk
        {
            vizsgalthash = vizsgalthash + M;
        }
        vizsgalthash = (vizsgalthash * alap + E[szoveg[i + minta.length() - 1]]) % M; // betű hozzáadása a végéhez
        if (vizsgalthash == mintahash)
        {
            talalatok.push_back(i);
        }
    }
    return talalatok;
}