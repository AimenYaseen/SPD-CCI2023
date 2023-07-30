using namespace std;

#include <vector>

class FrontMiddleBackQueue {
    vector<int> v;
public:
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        v.insert(v.begin(), val);
    }
    
    void pushMiddle(int val) {
        int mid = v.size()/2;
        v.insert(v.begin()+mid, val);
    }
    
    void pushBack(int val) {
        v.push_back(val);
    }
    
    int popFront() {
        if(v.size() == 0) return -1;

        int ans = v[0];
        v.erase(v.begin());
        return ans;
    }
    
    int popMiddle() {
        if(v.size() == 0) return -1;
        int mid = (v.size()-1)/2;
        int ans = v[mid];
        v.erase(v.begin()+mid);
        return ans;
    }
    
    int popBack() {
        if(v.size() == 0) return -1;

        int ans = v[v.size()-1];
        v.pop_back();
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */