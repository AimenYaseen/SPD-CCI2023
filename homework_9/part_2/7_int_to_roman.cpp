using namespace std;

#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>


class Solution {
public:
    string intToRoman(int num) {
        map <int, string, greater<int>> m = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"},
        };

        string roman;
        for(const auto& pair: m)
        {
            if(num == 0)
                break;

            int count = num / pair.first;

            for (int i = 0; i < count; ++i) {
                roman += pair.second;
            }

            num = num % pair.first;
        }

        return roman;
    }
};