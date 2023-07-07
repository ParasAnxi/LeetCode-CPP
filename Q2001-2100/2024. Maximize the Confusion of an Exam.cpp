class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k){
        int arr[2] = {};
        int n = answerKey.length(), start = 0, ans = 0;
        for(int end = 0; end < n; end++){
            if(answerKey[end] == 'T') arr[1]++;
            else arr[0]++;
            while(end - start + 1 - *max_element(arr, arr+2) > k){
                if(answerKey[start] == 'T') arr[1]--;
                else arr[0]--;
                start++;
            }
            ans = max(ans, end - start + 1);
        }       
        return ans;
    }
};