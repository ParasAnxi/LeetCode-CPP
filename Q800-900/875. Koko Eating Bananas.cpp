class Solution {
    private:
    long long getHoursToEatAll(vector<int>&pile, int bPerHour){
        long long totalHours = 0;
        for (int i = 0; i < pile.size(); i++){
            int hoursToEatPile = ceil(pile[i] / (double)bPerHour);
            totalHours += hoursToEatPile;
        }
        return totalHours;
    }
    public:
    int minEatingSpeed(vector<int>& piles, int targetHours){
        int start = 1;
        int end = *(max_element(piles.begin(), piles.end()));
        int ans = -1;
        while(start<=end){
            int mid =start+ (end-start)/2;
            long long hoursToEatAll = getHoursToEatAll(piles, mid);
            
            if (hoursToEatAll <= targetHours)
            {
                ans = mid;
                end=mid - 1;
            }
            else start=mid+1;
        }
        return ans;
    }
};