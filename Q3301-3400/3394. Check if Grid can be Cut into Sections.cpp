class Solution
{
public:
    bool check(vector<vector<int>> &arr)
    {
        int prev = arr[0][1];
        int count = 0;
        for (int i = 1; i < arr.size(); i++){
            if (prev <= arr[i][0]){
                count++;
            }
            prev = max(prev, arr[i][1]);
        }
        return count >= 2;
    }
    bool checkValidCuts(int n, vector<vector<int>> &rectangles){
        vector<vector<int>> hori, vert;
        for (auto &i : rectangles){
            hori.push_back({i[0], i[2]});
            vert.push_back({i[1], i[3]});
        }
        sort(hori.begin(), hori.end());
        sort(vert.begin(), vert.end());
        return check(hori) or check(vert);
    }
};