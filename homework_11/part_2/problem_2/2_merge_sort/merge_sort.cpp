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


list<int> mergeSort(list<int> inputList)
{
    if(inputList.size() <= 1)
        return inputList;

    auto midIt = inputList.begin();
    advance(midIt, inputList.size() / 2);

    list<int> leftList(inputList.begin(), midIt);
    list<int> rightList(midIt, inputList.end());

    leftList = mergeSort(leftList);
    rightList = mergeSort(rightList);

    return mergeSortedLists(leftList, rightList);
}


int main() {
    list<int> linkedList = {5, 2, 8, 1, 3, 7};

    list<int> sortedList = mergeSort(linkedList);

    for (int num : sortedList)
        cout << num << " ";
        
    cout << endl;
}