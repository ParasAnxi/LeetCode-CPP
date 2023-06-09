class Solution {
public:
    int bitwiseComplement(int n) {
        int x = n;
        int mask = 0;
        if(n==0){
            return 1;
        }
        while(x!=0){
            mask = (mask<<1) | 1;
            x=x>>1;
        }
        return (~n) & mask;
    }
};