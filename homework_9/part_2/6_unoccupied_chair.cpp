using namespace std;

#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>


class Solution {
public:
    int smallestChair (vector<vector<int>>& times, int targetFriend) {
        // arrival, departure, friend
        // pair of pair so that we don't need to traverse 2d array
        vector<pair<int,pair<int, int>>> mv;
        int n = times.size();

        // store arrival time, departure time with friend number
        for (int i=0; i<n;i++)
        {
            pair<int,pair<int, int>> p = {times[i][0],{times[i][1],i}};
            mv.push_back(p);
        }

        // sort so that the friend who arrives first will be at first place
        sort(mv.begin(),mv.end());

        // initialize vector of chair of n size, all chairs currently have -1
        // as chairs are empty
        // this vector will contain the departure time
        vector<int>chair (n, -1);

        for (int i=0;i<n;i++)
        {
            int arrival = mv[i].first;
            int departure = mv[i].second.first;
            int friendNumber = mv[i].second.second;

            // traverse through chairs
            for(int j=0; j < n; j++)
            {
                // if departure < arrival; it means chair is not occupied
                if(chair[j] <= arrival) 
                {
                    // assign that chair to new friend by storing its departure time
                    chair[j] = departure;
                    // if current friend is the target friend return chair number
                    if(friendNumber == targetFriend)
                        return j;
                    // break because we found an empty chair and filled it
                    break;
                }
            }
        }
        return 0;
    }
};