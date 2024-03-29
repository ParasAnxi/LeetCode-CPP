class Solution {
private:
    vector<int> tripTimes;
    int numTrips;
public:
    long minimumTime(vector<int>& time, int totalTrips) {
        this->tripTimes = time;
        this->numTrips = totalTrips;
        long left = 1;
        long right = 0;
        for (int t : tripTimes) {
            right = max(right, (long)t);
        }
        right = right * numTrips;
        long ans = right;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (check(mid)) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    
    bool check(long givenTime) {
        long actualTrips = 0;
        for (int t : tripTimes) 
            actualTrips += givenTime / t;
        if(actualTrips >= numTrips)
            return true;
        return false;
    }
};