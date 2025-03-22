class Solution {
public:

    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int carry = 0;
        int i = num.size() - 1;

        while(i >= 0)
        {

         int sum = num[i] + (k % 10) + carry;
         k /= 10;

         num[i--] = sum % 10;
         carry = sum/10;

        }

        while(k > 0)
        {

         int sum = (k % 10) + carry;
         k /= 10;
    
         num.insert(num.begin(), sum%10);
         carry = sum/10;
       
        }

        if(carry > 0) num.insert(num.begin(), carry);
        
        return num;
    }
};