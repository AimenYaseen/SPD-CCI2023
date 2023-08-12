using namespace std;

#include<vector>
#include<string>
#include<unordered_map>
#include<set>


class FoodRatings {
    class Compare
    {
        public:
        bool operator()(const pair<string, int>& a, const pair<string, int>& b) const
        {
            // if sec/rating is equal then return lexicographical string
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        }
    };

    // food to <cuisine, rating> map
    unordered_map<string, pair<string, int>> f_t_c;
    // cuisine to set<food, rating> map 
    unordered_map<string, set<pair<string, int>, Compare>> c_t_f;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int size = foods.size();

        for(int i=0; i<size; i++)
        {
            f_t_c[foods[i]] = make_pair(cuisines[i], ratings[i]);
            c_t_f[cuisines[i]].insert(make_pair(foods[i], ratings[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        // let's find cuisine
        auto _food = f_t_c[food];
        auto cuisine = _food.first;
        auto raiting = _food.second;

        // remove last cuisine pair from c_t_f
        c_t_f[cuisine].erase(make_pair(food, raiting));
        // insert new raiting
        c_t_f[cuisine].insert(make_pair(food, newRating));

        // update food to cuisine
        f_t_c[food] = make_pair(cuisine, newRating);
    }
    
    string highestRated(string cuisine) {
        return (c_t_f[cuisine].begin()) -> first;
    }

};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */