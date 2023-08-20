using namespace std;

#include <list>
#include <iostream>

list<int> mergeSortedLists(const list<int> list1, const list<int> list2)
{
    list<int> mergeList;

    auto l1 = list1.begin();
    auto l2 = list2.begin();

    while(l1 != list1.end() && l2 != list2.end())
    {
        if(*l1 <= *l2)
        {
            mergeList.push_back(*l1);
            ++l1;
        }
        else
        {
            mergeList.push_back(*l2);
            ++l2;
        }
    }

    while(l1 != list1.end())
    {
        mergeList.push_back(*l1);
        ++l1;
    }

    while(l2 != list2.end())
    {
        mergeList.push_back(*l2);
        ++l2;
    }

    return mergeList;
}


int main() 
{
    list<int> list1 = {1, 3, 5, 7};
    list<int> list2 = {2, 4, 6, 8};

    list<int> mergedList = mergeSortedLists(list1, list2);

    for (int num : mergedList) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}