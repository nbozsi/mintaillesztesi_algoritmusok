#include <iostream>
#include <chrono>
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
    auto t1 = high_resolution_clock::now();
    int x = KMP(minta, szoveg, P);
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    cout << x << '\t' << ms_double.count() << endl;
    t1 = high_resolution_clock::now();
    int y = brute_force(minta, szoveg);
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    cout << y << '\t' << ms_double.count() << endl;
    map tavok = tav(minta, szoveg);
    t1 = high_resolution_clock::now();
    int z = Horspool(minta, szoveg, tavok);
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    cout << z << '\t' << ms_double.count() << endl;
    return 0;
}
