using namespace std;

#include <vector>
#include <queue>


class Solution {
    typedef pair<int, pair<int, int>> pr;

    int euclideanDistance(int x2, int y2) 
    {
        int distance = (x2 * x2) + (y2 * y2);
        return distance;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pr> maxHeap;

        for(auto point: points)
        {
            int dist = euclideanDistance(point[0], point[1]);
            maxHeap.push({dist, {point[0], point[1]}});
            if(maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> pairs;

        while(!maxHeap.empty())
        {
            int num1 = maxHeap.top().second.first;
            int num2 = maxHeap.top().second.second;
            pairs.push_back({num1, num2});
            maxHeap.pop();
        }

        return pairs;

    }
};