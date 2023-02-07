class Solution {
public:

    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> m;

        int i = 0, j = 0, ans = 0;
        
        while(j < fruits.size())
        {

            m[fruits[j]]++;
            
            if(m.size() <= 2) 
                ans = max(ans, j-i+1);
            
            else
            {
                m[fruits[i]]--;

                if(m[fruits[i]] == 0) 
                    m.erase(fruits[i]);

                i++;
            }

            j++;
        }

        return ans; 
    }
};