class Solution {
public:
    char solve(int n,int k,int rev){
        if(n==1) return rev & 1 ? '1' : '0';

        int sum = pow(2,n)-1;
        int div = sum/2;
        
        if(k == div + 1) return rev & 1 ? '0' : '1';
        
        if(k > div+1){
            rev++;
            k=div-(k-(div+1))+1;
        }
        return solve(n-1,k,rev);
    }
    char findKthBit(int n, int k) {
        return solve(n,k,0);
    }
};