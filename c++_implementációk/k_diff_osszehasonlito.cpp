#include <iostream>
#include "Levenshtein_tav.h"
#include "brute_force.h"
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

void timeit(vector<int> (*func)(string, string, int), string minta, string szoveg, int, int);
void timeit(vector<int> (*func)(string, string), string minta, string szoveg, int);

int main(int argc, char *argv[])
{
    string minta; // beolvasás
    string szoveg;
    int k;
    if (argc > 1)
    {
        minta = argv[1]; // beolvasás
        szoveg = argv[2];
        k = stoi(argv[3]);
    }
    else
    {
        return 1;
    }
    int probak = 5;
    cout << "brute_force" << '\t';
    timeit(&brute_force, minta, szoveg, probak);
    cout << '\n';

    cout << "Dinamikus" << '\t';
    timeit(&Levenshtein_tavolsag, minta, szoveg, k, probak);
    cout << '\n';

    return 0;
}
void timeit(vector<int> (*func)(string, string, int), string minta, string szoveg, int k, int n)
{
    vector<int> pos;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(minta, szoveg, k);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        sum = sum + ms_double.count();
    }
    cout << pos.size() << '\t' << sum / n;
}
void timeit(vector<int> (*func)(string, string), string minta, string szoveg, int n)
{
    vector<int> pos;
    double min = 1000;
    for (int i = 0; i < n; i++)
    {
        auto t1 = high_resolution_clock::now();
        pos = func(minta, szoveg);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        if (min > ms_double.count())
        {
            min = ms_double.count();
        }
    }
    cout << pos.size() << '\t' << min;
}