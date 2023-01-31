class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int i = 0;
        sort(arr.begin(),arr.end());
        vector<int> freq;
        while (i < arr.size()){
            int count = 1;
            for (int j = i+1; j< arr.size(); j++){
                if (arr[i] == arr[j])
                    count++;
            }
            freq.push_back(count);
            i = i + count;
        }
        sort(freq.begin(),freq.end());
        for (int i = 0; i < freq.size() - 1; i++){
            if (freq[i] == freq[i+1])
                return false;
        }
        return true;
    }
};