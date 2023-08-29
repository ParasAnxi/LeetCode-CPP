class Solution{
public:
    int bestClosingTime(string customers){
        int count = 0;

        for (int i = 0; i < customers.length(); i++){
            if (customers[i] == 'Y')
                count++;
        }
        int n = customers.length();
        vector<int> v(n + 1, 0);
        int mn = INT_MAX;
        int preN = 0;
        for (int i = 0; i < n; i++){
            v[i] = preN + count;
            if (customers[i] == 'Y'){
                count--;
            }
            else{
                preN++;
            }
        }
        v[n] = preN;

        for (int i = 0; i <= n; i++){
            mn = min(mn, v[i]);
        }
        for (int i = 0; i <= n; i++){
            if (v[i] == mn)
                return i;
        }
        return 0;
    }
};