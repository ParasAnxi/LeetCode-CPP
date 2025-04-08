class Solution {
public:
  string addStrings(string num1, string num2) {
    string ans;
    int carry = 0;
    while (num1.length() < num2.length()){
        num1 = '0' + num1;
    }
    while (num2.length() < num1.length()){
        num2 = '0' + num2;
    }
    for (int i = num1.length() - 1; i >= 0; i--) {
      int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
      ans += sum % 10 + '0';
      carry = sum / 10;
    }
    if (carry) {
      ans += carry + '0';
    }
    reverse(ans.begin(), ans.end());

    return ans;
  }
};