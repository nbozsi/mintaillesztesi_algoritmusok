#include <iostream>
#include <chrono>
#include <map>
#include <vector>
#include "brute_force.h"
#include "Horspool.h"
#include "KMP.h"
using namespace std;
using namespace std::chrono;

int main()
{
    string minta;
    string szoveg;
    cin >> minta;
    cin >> szoveg;
    vector<int> P = labfej(minta);
    int x = KMP(minta, szoveg, P);
    cout << x << '\t' << endl;
    int y = brute_force(minta, szoveg);
    cout << y << endl;
    map tavok = tav(minta, szoveg);
    int pos = Horspool(minta, szoveg, tavok);
    return 0;
}
