class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr){
        const int mod = 1e9 + 7;
        stack<int> s;
        int ans = 0;

        for (int right = 0; right <= arr.size(); ++right){
            while (!s.empty() && (right == arr.size() || arr[s.top()] >= arr[right])){
                int mid = s.top();
                s.pop();
                int left = s.empty() ? -1 : s.top();
                ans = (ans + (long long)(right - mid) * (mid - left) * arr[mid]) % mod;
            }
            s.push(right);
        }

        return ans;
    }
};