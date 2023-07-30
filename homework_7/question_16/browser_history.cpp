using namespace std;

#include <iostream>
#include <list>
#include <string>

class BrowserHistory {
    list<string> history;
    list<string>::iterator current;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current = history.begin();
    }
    
    void visit(string url) {
        history.erase(next(current), history.end());
        history.push_back(url);
        current = prev(history.end());
    }
    
    string back(int steps) {
        while(steps>0 && current != history.begin())
        {
            steps--;
            current--;
        }
        return *current;
    }
    
    string forward(int steps) {
        auto end = prev(history.end());
        while(steps>0 && current != end)
        {
            steps--;
            current++;
        }
        return *current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */