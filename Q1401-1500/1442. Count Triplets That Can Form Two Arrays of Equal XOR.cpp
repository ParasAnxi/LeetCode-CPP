class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> v(arr.size(), 0);
        for(int i=0; i<arr.size(); i++){
            v[i] = (i>0 ? v[i-1] : 0)^arr[i];
        }

        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                int a = v[j];
                int b = (i>0 ? v[i-1] : 0);
                if((a^b) == 0){
                    ans += j-i;
                }
            }
        }
        return ans;
    }
};