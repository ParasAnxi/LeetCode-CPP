class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0, rem , pro=1;
         while(n!=0){
            rem=n%10;
            sum+=rem;
            pro=pro*rem;
             n=n/10;
        }
        return pro-sum;
    }
};