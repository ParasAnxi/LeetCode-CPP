class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.size();
        int count = 0;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++){
            if (k + i <= n){
                count = 0;
                for (int j = i; j < k + i; j++){
                    if (blocks[j] == 'W'){
                        count++;
                    }
                }
            }
            mini = min(mini, count);
        }
        return mini;
    }
};