// O(N)
using namespace std;

#include <vector>
#include <iostream>


class Solution {
public:
    bool equalImages(int m1, int m2)
    {
        return m1 == m2;
    }

    int majorityElement(vector<int>& images) 
    {
        int candidate = -1;
        int count = 0;

        for (int image : images) 
        {
            if (count == 0) 
            {
                candidate = image;
                count = 1;
            } 
            else if (equalImages(candidate, image))
                count++;
            else
                count--;
        }

        count = 0;
        for (int image : images)
            if (equalImages(candidate, image))
                count++;
            

        if (count > images.size() / 2)
            return candidate;

        return -1; // No majority image
    }
};