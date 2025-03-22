class Solution {
public:
    bool isPowerOfTwo(int n) {
       for(int i = 0; i<=30 ; i++){
           int ans = pow(2,i);
           if(n==ans)
           {
               return true;
           }
       }
        return false;
    }
};
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
};