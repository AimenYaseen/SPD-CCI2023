#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int calculate_binary(int n)
{
    stack<int> s;
    while(n)
    {
        s.push(n%2);
        n = n / 2;
    }
    int ans = 0;

    while(!s.empty())
    {
        int m = s.top();
        s.pop();
        ans = (ans * 10) + m;
    }
    return ans;
}


void generate_binary(int n)
{

    for(int i=1; i<=n; i++)
    {
        int bin = calculate_binary(i);
        cout<< bin;
        if(i != n) cout<< ", ";
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    generate_binary(2);
    generate_binary(5);
    return 0;
}