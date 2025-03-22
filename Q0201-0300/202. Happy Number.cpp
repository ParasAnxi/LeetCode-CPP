class Solution {
private:
    int nextNumber(int n){
        int ans = 0;
        while(n!=0){
            int rem = n%10;
            ans += rem*rem;
            n = n/10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = nextNumber(n);
        while(fast != 1 && fast != slow){
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        }
        return fast==1;
    }
};