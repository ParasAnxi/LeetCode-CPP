class Solution {
public:
    void sortColors(vector<int>& arr) {
        for(int i = 0 ; i< arr.size();i++){
            for(int j = i+1;j<arr.size();j++){
                if(arr[i]>arr[j]){
                    int temp = arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }      
            }
        }
    }
};