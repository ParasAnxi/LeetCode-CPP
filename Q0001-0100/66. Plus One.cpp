class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      vector<int>ans;
      int carry = 0;
      int sum = 0;
      if(digits.size() == 1){
        sum = digits[0] + 1 + carry;
        ans.push_back(sum%10);
        carry = sum/10;
        if(carry != 0){
          ans.push_back(carry);
        }
      }else{
        for(int i = digits.size()-1;i>=0;i--){
          sum = (i == digits.size()-1) ? digits[i] + 1 + carry : digits[i] + carry;
          ans.push_back(sum % 10);
          carry = sum / 10;
        }
        if(carry!=0){
          ans.push_back(carry);
        }
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};

//easy Solution
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size();
      for(int i = n - 1;i>=0;i--){
        if(digits[i] < 9){
          digits[i]++;
          return digits;
        }else{
          digits[i] = 0;
        }
      }
      digits.insert(digits.begin(),1);
      return digits;
    }
};