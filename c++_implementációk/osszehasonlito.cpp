#include <iostream>
#include <chrono>
#include "brute_force.h"
#include "Horspool.h"
#include "KMP.h"
using namespace std;
using namespace std::chrono;
// TODO valamilyen wrapper function az időméréshez
int main()
{
    string minta;
    string szoveg;
    cin >> minta;
    cin >> szoveg;

    vector<int> P = labfej(minta);
    auto t1 = high_resolution_clock::now(); // kezdő időpont
    int x = KMP(minta, szoveg, P);          //?Ha a KMP a Horspool után fut akkor valamiért mindig -1-t ad eredményül, pedig a stringek nem változnak
    auto t2 = high_resolution_clock::now(); // végző időpont
    duration<double, std::milli> ms_double = t2 - t1;
    cout << "KMP" << '\t' << x << '\t' << ms_double.count() << endl;

    t1 = high_resolution_clock::now(); //** időmérés ugyanúgy, mint az előbb
    int y = brute_force(minta, szoveg);
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    cout << "brute_force" << '\t' << y << '\t' << ms_double.count() << endl;

    map tavok = tav(minta, szoveg); //** időmérés ugyanúgy, mint az előbb
    t1 = high_resolution_clock::now();
    int z = Horspool(minta, szoveg, tavok); //! A KMP után kell futnia
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    cout << "Horspool" << '\t' << z << '\t' << ms_double.count() << endl;
    return 0;
}

template <typename Function>
void timeit(string title, Function func) //? hogy lehet különbőző argumentumokat adni a belső függvénynek
{
    func(title);
}