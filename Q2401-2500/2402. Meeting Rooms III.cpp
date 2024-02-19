class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings){
        sort(meetings.begin(), meetings.end());
        long long int time = 0;
        vector<long long int> free(n, 0);
        map<int, int> mp;
        for (int i = 0; i < meetings.size(); i++){
            if (time < meetings[i][0]){
                time = meetings[i][0];
            }
            int key = -1;
            long long int mini = 1e18;
            int index = -1;
            for (int j = 0; j < n; j++){
                if (time >= free[j]){
                    free[j] = 0;
                }
                if (free[j] == 0 and key == -1)
                    key = j;
                if (free[j] != 0){
                    if (mini > free[j]){
                        mini = free[j];
                        index = j;
                    }
                }
            }
            if (key == -1)
            {
                time = max(mini, time);
                mp[index]++;
                free[index] = time + (long long int)(meetings[i][1] - meetings[i][0]);
            }
            else
            {
                mp[key]++;
                free[key] = time + (long long int)(meetings[i][1] - meetings[i][0]);
            }
        }
        int ans = -1;
        int cnt = 0;
        for (auto i : mp){
            if (i.second > cnt){
                ans = i.first;
                cnt = i.second;
            }
        }
        return ans;
    }
};