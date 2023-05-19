class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> arr(n,vector<int>(n));
        int curr=1, i=0, j=0, left= 0, right= n-1,top=0,bottom= n-1;
        
        while(curr<= (n*n)){
            
            while(curr<= (n*n) && j<= right) arr[i][j++]= curr++;
            j--;
            i++;
            top++;
            
            while(curr<= (n*n) && i<= bottom) arr[i++][j]= curr++;
            i--;
            j--; 
            right--;
            
            while(curr<= (n*n) && j>= left) arr[i][j--]= curr++;
            j++;
            i--;
            bottom--;
            
            while(curr<= (n*n) && i>= top) arr[i--][j]= curr++;
            i++, j++, left++;
        }
        
        return arr;
    }
};