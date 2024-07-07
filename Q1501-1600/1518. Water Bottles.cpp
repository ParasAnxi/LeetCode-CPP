class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        ans += numBottles;
        while(numBottles !=0){
            int rem=numBottles % numExchange;
            numBottles = numBottles / numExchange;
            ans += numBottles;
            numBottles = rem + numBottles; 
            if(numBottles < numExchange)
            break;           
        }
        return ans;
    }
};