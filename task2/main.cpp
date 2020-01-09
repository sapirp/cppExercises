#include "alg.h"
#include <vector>
#include <array>
#include <iterator>

using namespace std;

int main() {
    int ia[] = {1,2,3,10,8,6};
   // int* p = Median(begin(ia), end(ia), 1);
   // int* p = Transpose(begin(ia), end(ia));
    int* p = Transformations(begin(ia), end(ia),
        [](const int x, const int y) {return x + y;});

    for (auto i = ia; i != p;++i)
        cout << *i << ",";

    return 0;
}