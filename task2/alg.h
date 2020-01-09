#ifndef _alg_h
#define _alg_h
#include <iostream>
#include <algorithm>
using namespace std;

template <class Iter, class Num>
Iter Median(Iter b, Iter e,  Num n) {
    Num midN = n / 2;
    if (e == b || n == 1 || (e - b) % n != 0) return e;
    for (auto i = b; i != e ; i = i + n) {
        sort(i, (i + n));
         if (n % 2 == 0)
            *b++ = (*(i + midN) + *(i + midN - 1)) / 2;
        else
            *b++ = *(i + midN);
        }
    return b;
}

template <class Iter>
Iter Transpose(Iter b, Iter e) {
    if ((e - b) % 2 != 0) e = e - 1;
    for (auto i = b; i != e; i = i + 2) {
        auto temp = *i;
        *i = *(i + 1);
        *(i + 1) = temp;
    }
    return e;
}

template <class Iter , class Fun>
Iter Transformations(Iter b, Iter e, Fun f) {
    if ((e - b) % 2 != 0) return e;
    for (auto i = b; i != e; i = i + 2) {
        *b++ = f(*i, *(i + 1));
    }
    return b;
}

#endif
