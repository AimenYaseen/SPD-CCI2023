using namespace std;

#include<iostream>
#include<vector>


class Permutations {
public:

    void getPermutation(string& s, int i, vector<string>& V)
    {
        if( i == s.size())
        {
            cout << s << " ";
            V.push_back(s);
            return; 
        }

        for(int t=i; t < s.size(); t++)
        {
            swap(s[t], s[i]);
            getPermutation(s, i+1, V);
            swap(s[t], s[i]);
        }
    }

    string getPermutation(int n, int k) {
        string s = "";
        for(int i=1; i<=n; i++)
        {
            s+=to_string(i);
        }

        vector<string> V;

        getPermutation(s, 0, V);
        return V[k - 1];
    }
};


int main()
{
    Permutations p;
    string s = p.getPermutation(3, 4);
    cout << "\n4th permutation : " << s;
}