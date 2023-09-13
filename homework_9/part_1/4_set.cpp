#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int queries;
    cin >> queries;
    
    int type, num;
    set<int> s;
    
    while(queries)
    {
        cin >> type >> num;
        
        switch(type)
        {
            case 1:
               s.insert(num); 
               break;
            case 2:
               s.erase(num);
               break;
            case 3:
                if(s.find(num) != s.end()) cout << "Yes" << endl;
                else cout << "No" << endl;
                break;
            default:
                cout << "Invalid query type" << endl;
                break;
        }
        
        queries--;
    }
      
    return 0;
}



