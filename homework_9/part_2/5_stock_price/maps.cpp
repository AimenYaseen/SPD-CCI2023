using namespace std;

#include<vector>
#include<string>
#include<map>
#include<set>


class StockPrice {
public:
    //mp-> (time stamp, price)
    //freq -> (price, how many times it occured)
    map<int, int> mp, freq;
    //track of latest time stamp we have
    int maxTimestamp=-1;
    
    StockPrice () {}
    void update(int timestamp, int price) {
        // if we already have this record
        //logn
        if(mp.find(timestamp) !=mp.end()) {
            //value of price at timestamp
            int prev=mp[timestamp];
            //reduce the frequency of that price.
            freq[prev] --;
            if(freq[prev]==0)
                freq.erase(prev);
        }
        //logn time
        mp[timestamp]=price;
        freq[price]++;
        //track of latest timestamp
        if(timestamp>maxTimestamp)
            maxTimestamp=timestamp;
    }
    int current() {
        return mp[maxTimestamp];
    }
    int maximum(){
        return freq.rbegin()->first;
    }
    int minimum(){
        return freq.begin()->first;
    }
};
/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */