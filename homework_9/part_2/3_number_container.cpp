using namespace std;

#include<vector>
#include<map>
#include<set>


class NumberContainers {
    // index, number
    map<int, int> m1;
    // number, set of indexes
    map<int, set<int>> m2;
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        // if index already exists
        if(m1.count(index) != 0)
        {
            int temp = m1[index];
            m2[temp].erase(index); // erase the index from set which are going to change
        }
        m1[index] = number;
        m2[number].insert(index);
    }
    
    int find(int number) {
        if(m2.count(number) == 0 || m2[number].empty())
            return -1;
        return *(m2[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */