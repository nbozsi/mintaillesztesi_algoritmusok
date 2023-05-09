#include <iostream>
#include <chrono>
#include "brute_force.h"
#include "Horspool.h"
#include "KMP.h"
#include "RabinKarp.h"

using namespace std;
using namespace std::chrono;

void timeit(int (*func)(string, string, vector<int>), string minta, string szoveg, vector<int> P, int); // function overloading, hogy mindre működjön
void timeit(int (*func)(string, string, map<char, int>), string minta, string szoveg, map<char, int> tavok, int);
void timeit(int (*func)(string, string), string minta, string szoveg, int);

int main()
{
    string minta; // beolvasás
    string szoveg;
    cin >> minta;
    cin >> szoveg;
    int probak = 20;

    vector<int> P = labfej(minta); // előfeldolgozás
    map tavok = tav(minta, szoveg);
    map betuertek = charvalue(szoveg);

    cout << "brute_force" << '\t';
    timeit(&brute_force, minta, szoveg, probak);

    cout << "Horspool" << '\t';
    timeit(&Horspool, minta, szoveg, tavok, probak);

    cout << "KMP\t\t";
    timeit(&KMP, minta, szoveg, P, probak);

    cout << "Rabin-Karp\t";
    timeit(&RabinKarp, minta, szoveg, betuertek, probak);

    return 0;
}

void timeit(int (*func)(string, string, vector<int>), string minta, string szoveg, vector<int> P, int n)
{
    int pos;
    double sum = 0;
    for (int i = 0; i < n; i++) // n-szer futtatjuk és a futásidők átlagát vesszük
    {
        auto t1 = high_resolution_clock::now(); // kezdő időpont
        pos = func(minta, szoveg, P);
        auto t2 = high_resolution_clock::now(); // végző időpont
        duration<double, std::milli> ms_double = t2 - t1;
        sum = sum + ms_double.count();
    }
    cout << pos << '\t' << sum / n << endl;
}
void timeit(int (*func)(string, string, map<char, int>), string minta, string szoveg, map<char, int> tavok, int n)
{
    int pos;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(minta, szoveg, tavok);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        sum = sum + ms_double.count();
    }
    cout << pos << '\t' << sum / n << endl;
}
void timeit(int (*func)(string, string), string minta, string szoveg, int n)
{
    int pos;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(minta, szoveg);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        sum = sum + ms_double.count();
    }
    cout << pos << '\t' << sum / n << endl;
}