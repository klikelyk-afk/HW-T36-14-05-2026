#include <iostream>
#include "MyList.h"

using std::cout;
using std::endl;

int main() {
    DList<int> list;

    list.push_back(4);
    list.push_front(6);
    list.push_back(2);
    list.insertBefore(2, 8);

    list.show();

    return 0;
}