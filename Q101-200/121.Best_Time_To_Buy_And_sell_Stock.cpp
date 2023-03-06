#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_pro = 0;
        for (int i = 1; i < prices.size(); i++) {
            max_pro = max(max_pro, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return max_pro;
    }
};