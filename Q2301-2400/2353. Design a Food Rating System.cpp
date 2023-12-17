class FoodRatings{
public:
    map<string, set<pair<int, string>>> mp;
    unordered_map<string, pair<string, set<pair<int, string>>::iterator>> food_cuisine;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; ++i)
        {
            mp[cuisines[i]].insert({ratings[i], foods[i]});
            food_cuisine[foods[i]] = {cuisines[i], mp[cuisines[i]].find({ratings[i], foods[i]})};
        }
    }
    void changeRating(string food, int newRating)
    {
        string cuisine = food_cuisine[food].first;

        auto info = food_cuisine[food].second;
        mp[cuisine].erase(info);

        mp[cuisine].insert({newRating, food});
        food_cuisine[food] = {cuisine, mp[cuisine].find({newRating, food})};
    }

    string highestRated(string cuisine)
    {
        auto itr = mp[cuisine].rbegin();
        int highest_rate = itr->first;
        string result = itr->second;

        for (; itr != mp[cuisine].rend(); ++itr)
        {
            if (itr->first == highest_rate)
            {
                result = itr->second;
            }
            else
            {
                break;
            }
        }

        return result;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */