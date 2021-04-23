#include <iostream>
#include "unorderedList.h"
#include "orderedList.h"

using namespace std;

int main()
{
    orderedLinkedList<int> mainList;

    mainList.insert(5);
    mainList.insert(9);
    mainList.insert(8);
    mainList.insert(3);
    mainList.insert(10);

    mainList.print();

    system("PAUSE");
    return 0;
}