#include <iostream>
#include <chrono>
#include "brute_force.h"
#include "Horspool.h"
#include "KMP.h"

using namespace std;
using namespace std::chrono;

void timeit(int (*func)(string, string, vector<int>), string minta, string szoveg, vector<int> P); // function overloading, hogy mindre működjön
void timeit(int (*func)(string, string, map<char, int>), string minta, string szoveg, map<char, int> tavok);
void timeit(int (*func)(string, string), string minta, string szoveg);

int main()
{
    string minta; // beolvasás
    string szoveg;
    cin >> minta;
    cin >> szoveg;

    vector<int> P = labfej(minta); // előfeldolgozás
    map tavok = tav(minta, szoveg);

    cout << "brute_force" << '\t';
    timeit(&brute_force, minta, szoveg);

    cout << "Horspool" << '\t';
    timeit(&Horspool, minta, szoveg, tavok);

    cout << "KMP\t\t";
    timeit(&KMP, minta, szoveg, P);
    return 0;
}

void timeit(int (*func)(string, string, vector<int>), string minta, string szoveg, vector<int> P)
{
    int pos;
    auto t1 = high_resolution_clock::now(); // kezdő időpont
    pos = func(minta, szoveg, P);
    auto t2 = high_resolution_clock::now(); // végző időpont
    duration<double, std::milli> ms_double = t2 - t1;
    cout << pos << '\t' << ms_double.count() << endl;
}
void timeit(int (*func)(string, string, map<char, int>), string minta, string szoveg, map<char, int> tavok)
{
    int pos;
    auto t1 = high_resolution_clock::now();
    pos = func(minta, szoveg, tavok);
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    cout << pos << '\t' << ms_double.count() << endl;
}
void timeit(int (*func)(string, string), string minta, string szoveg)
{
    int pos;
    auto t1 = high_resolution_clock::now();
    pos = func(minta, szoveg);
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    cout << pos << '\t' << ms_double.count() << endl;
}