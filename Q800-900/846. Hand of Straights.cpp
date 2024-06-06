class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize){
        map<int, int> mp;
        for (auto x : hand)
            mp[x]++;
        if (hand.size() % groupSize)
            return 0;
        for (int i = 0; i < hand.size() / groupSize; i++){
            auto it = mp.begin();
            int temp = it->first;
            for (int j = 0; j < groupSize; j++){
                if (mp.find(temp) == mp.end())
                    return 0;
                mp[temp]--;
                if (mp[temp] == 0)
                    mp.erase(temp);
                temp++;
            }
        }
        return 1;
    }
};