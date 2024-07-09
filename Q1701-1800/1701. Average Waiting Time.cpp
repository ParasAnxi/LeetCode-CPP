class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double time = 0,wait = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i][0] >= time)
            {
                wait += customers[i][1];
                time = customers[i][0] + customers[i][1];
            }
            else{
                wait += (time - customers[i][0]) + customers[i][1];
                time += customers[i][1];
            }
        }
        return wait / customers.size();
    }
};