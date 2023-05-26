#include <iostream>
#include <chrono>
#include "brute_force.h"
#include "Horspool.h"
#include "KMP.h"
#include "RabinKarp.h"

using namespace std;
using namespace std::chrono;

void timeit(vector<int> (*func)(string, string, vector<int>), string minta, string szoveg, vector<int> P, int); // function overloading, hogy mindre működjön
void timeit(vector<int> (*func)(string, string, unordered_map<char, int>), string minta, string szoveg, unordered_map<char, int> tavok, int);
void timeit(vector<int> (*func)(string, string), string minta, string szoveg, int);

int main(int argc, char *argv[])
{
    string minta(argv[1]); // beolvasás
    string szoveg(argv[2]);
    int probak = 10;

    vector<int> P = labfej(minta); // előfeldolgozás
    unordered_map tavok = tav(minta, szoveg);
    unordered_map betuertek = charvalue(szoveg);

    cout << "brute_force" << '\t';
    timeit(&brute_force, minta, szoveg, probak);
    cout << '\n';

    cout << "Horspool" << '\t';
    timeit(&Horspool, minta, szoveg, tavok, probak);
    cout << '\n';

    cout << "KMP" << '\t';
    timeit(&KMP, minta, szoveg, P, probak);
    cout << '\n';

    cout << "Rabin-Karp" << '\t';
    timeit(&RabinKarp, minta, szoveg, betuertek, probak);

    return 0;
}

void timeit(vector<int> (*func)(string, string, vector<int>), string minta, string szoveg, vector<int> P, int n)
{
    vector<int> pos;
    double sum = 0;
    for (int i = 0; i < n; i++) // n-szer futtatjuk és a futásidők átlagát vesszük
    {
        auto t1 = high_resolution_clock::now(); // kezdő időpont
        pos = func(minta, szoveg, P);
        auto t2 = high_resolution_clock::now(); // végző időpont
        duration<double, std::milli> ms_double = t2 - t1;
        sum = sum + ms_double.count();
    }
    int r = -1;
    if (!pos.empty()) // ellenőrizzük, hogy van- egyáltalán találat
    {
        r = pos.back();
    }
    cout << r << '\t' << sum / n;
}
void timeit(vector<int> (*func)(string, string, unordered_map<char, int>), string minta, string szoveg, unordered_map<char, int> tavok, int n)
{
    vector<int> pos;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(minta, szoveg, tavok);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        sum = sum + ms_double.count();
    }
    int r = -1;
    if (!pos.empty()) // ellenőrizzük, hogy van- egyáltalán találat
    {
        r = pos.back();
    }
    cout << r << '\t' << sum / n;
}
void timeit(vector<int> (*func)(string, string), string minta, string szoveg, int n)
{
    vector<int> pos;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(minta, szoveg);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        sum = sum + ms_double.count();
    }
    int r = -1;
    if (!pos.empty()) // ellenőrizzük, hogy van- egyáltalán találat
    {
        r = pos.back();
    }
    cout << r << '\t' << sum / n;
}