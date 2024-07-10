class Solution {
public:
    int minOperations(vector<string>& logs) {
        int j = 0;
        int n = logs.size();
        for(int i=0; i<n; i++){
            if(logs[i] == "./")
            continue;
            else if(logs[i] == "../"){
                if(j < 0)
                j++;
            }
            else j--;
        }
        return abs(j);
    }
};