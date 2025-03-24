class Solution
{
public:
    //MLE
    int countDays(int days, vector<vector<int>> &meetings)
    {
        vector<int> diff(n + 2, 0);

        for (auto &m : meetings)
        {
            diff[m[0]] += 1;
            diff[m[1] + 1] -= 1;
        }

        int meetCount = 0, freeDays = 0;

        for (int day = 1; day <= days; ++day)
        {
            meetCount += diff[day];
            if (meetCount == 0){
                freeDays++;
            }
        }
        return freeDays;
    }
};
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        if (meetings.empty()) return n;
        sort(meetings.begin(), meetings.end());
        long long occDays = 0;
        int start = meetings[0][0], end = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++){
            if (meetings[i][0] <= end){
                end = max(end, meetings[i][1]);
            }
            else{
                occDays += (end - start + 1);
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        occDays += (end - start + 1);

        return days - occDays;
    }
};