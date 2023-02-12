class Solution {
public:
    int removeDuplicates(vector<int>& x) {
        for(int i=0;i<x.size()-1;i++){
            for(int j=i+1;j<x.size();j++){
                if(x[i]==x[j]){
                    x.erase(x.begin()+j);
                    j--;
                }
            }
        }
        return x.size();
    }
};