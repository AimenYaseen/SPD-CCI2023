using namespace std;

#include<vector>
#include<string>
#include<map>
#include<set>


class StockPrice {
public:
    // time_to_p-> (time stamp, price)
    // price_to_t -> (price, timestamp)
    map<int, int> time_to_p;
    set<pair<int, int>> _price;

    StockPrice () {}
    void update(int timestamp, int price) {
        // if we already have this record
        if(time_to_p.find(timestamp) != time_to_p.end()) {
            // value of price at timestamp
            int prevPrice = time_to_p[timestamp];
            //reduce the frequency of that price.
            _price.erase(make_pair(prevPrice, timestamp));
        }
        
        time_to_p[timestamp] = price;
        _price.insert(make_pair(price, timestamp));
    }

    int current() {
        return time_to_p.rbegin()->second;
    }

    int maximum(){
        return _price.rbegin() -> first;;
    }

    int minimum(){
        return _price.begin() -> first;
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