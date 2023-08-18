using namespace std;

#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>


class Solution {
public:
    string getKey(int r, int c)
    {
        return to_string(r) + ", " + to_string(c);
    }

    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<string, unordered_set<char>> sub_boxes;

        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                char val = board[r][c];

                // if box has no value continue
                if(val == '.') continue;
                // store sub_boxes with indexes 0, 1, 2.
                string subKey = getKey(r/3, c/3);

                // if value already exists in set return false
                if(
                    rows[r].count(val) ||
                    cols[c].count(val) ||
                    sub_boxes[subKey].count(val)
                  )
                  return false;

                rows[r].insert(val);
                cols[c].insert(val);
                sub_boxes[subKey].insert(val);
            }
        }

        return true;
    }
};