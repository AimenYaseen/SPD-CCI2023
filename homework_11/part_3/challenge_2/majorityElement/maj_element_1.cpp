
// O(NlogN)
using namespace std;

#include <vector>
#include <iostream>

class Solution {
public:
    bool equalImages(int m1, int m2)
    {
        return m1 == m2;
    }

    int findMajorityImageRecursive(vector<int>& images, int start, int end) 
    {
        if (start == end)
            return images[start];

        int mid = (start + end) / 2;

        int leftMajority = findMajorityImageRecursive(images, start, mid);
        int rightMajority = findMajorityImageRecursive(images, mid + 1, end);

        if (equalImages(leftMajority, rightMajority))
            return leftMajority;

        int leftCount = countOccurrences(images, leftMajority, start, end);
        int rightCount = countOccurrences(images, rightMajority, start, end);

        if (leftCount > rightCount)
            return leftMajority;
        else
            return rightMajority;
    }

    int countOccurrences(vector<int>& images, int image, int start, int end) 
    {
        int count = 0;
        for (int i = start; i <= end; ++i) 
        {
            if (equalImages(images[i], image))
                count++;
        }
        return count;
    }

    int majorityElement(vector<int>& images) 
    {
        int majorityImage = findMajorityImageRecursive(images, 0, images.size() - 1);
        int count = countOccurrences(images, majorityImage, 0, images.size() - 1);
        if (count > images.size() / 2)
            return majorityImage;
        return -1;
    }
};