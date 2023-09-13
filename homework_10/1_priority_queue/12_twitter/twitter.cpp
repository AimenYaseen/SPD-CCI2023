using namespace std;

#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>


class Twitter {
    // user_id -> time, tweet_id
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    // follower, followee
    unordered_map<int, unordered_set<int>> followMap;
    // tweet count
    int tc;
public:
    Twitter() {
        tc = 0;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        // most recent one have less count
        // least recent has greater count
        tweetMap[userId].push_back({--tc, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        // tweet ids
        vector<int> tweets;
        // tc, tweet_id
        priority_queue<pair<int, int>> maxHeap;

        // most recent tweets should also contain user tweets as well
        follow(userId, userId);

        // get user followee
        for(const auto& followee: followMap[userId])
        {
            // get followee tweets
            for(const auto& tweet: tweetMap[followee])
            {
                // push followee tweets in heap
                maxHeap.push(tweet);
                // pop the least recent if heap size got bigger
                if(maxHeap.size() > 10)
                    maxHeap.pop();
            }
        }

        // push heap value in the heap
        // it will be arranged from least to most recent
        while (!maxHeap.empty()) {
            tweets.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        // reverse the tweets
        reverse(tweets.begin(), tweets.end());
        return tweets;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */