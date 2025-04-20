using vi = vector<int>;
#define pb push_back
class Solution {
public:
  int maxLength(vector<int> &nums) {
    
    vi keys = {0, 0, 2, 4, 2, 16, 6, 64, 2, 4, 18};
    int s = 0, e = 0;
    int n = nums.size();
    int curr = 0;
    int ans = 2;

    while (e < n) {
      int key = keys[nums[e++]];
      while ((curr & key) > 0) {    
        curr -= keys[nums[s++]]; 
      }
      curr |= key;                  
      ans = max(ans, e - s); 
    }
    return ans;
  }
};