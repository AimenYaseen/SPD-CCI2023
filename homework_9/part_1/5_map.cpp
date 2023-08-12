#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int queries;
    cin >> queries;
    
    int type, marks;
    string student;
    map<string, int> m;
    
    while(queries)
    {
        cin >> type;
        
        switch(type)
        {
            case 1:
               cin >> student >> marks;
               m[student] = marks + m[student];
               break;
            case 2:
               cin >> student;
               m.erase(student);
               break;
            case 3:
                cin >> student;
                cout << m[student] << endl;
                break;
            default:
                cout << "Invalid query type" << endl;
                break;
        }
        
        queries--;
    }
    return 0;
}



