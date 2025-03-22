class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s=0;
        int e=letters.size()-1;
        if(letters[0] > target)
          return letters[0];
        else if(target >= letters[letters.size()-1])
        return letters[0];
        char ans;  
        while( s <= e){
            int mid=s+(e-s)/2;
             if(letters[mid] > target){
                 ans = letters[mid];
                 e = mid-1;
             }
             else
             s = mid+1;
        }
        return ans;
        
    }
};