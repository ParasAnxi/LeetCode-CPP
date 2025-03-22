class Solution{
public:
    string countOfAtoms(string formula){
        stack<unordered_map<string, int>> s;
        s.push({});
        int i = 0, n = formula.size();
        while (i < n){
            if (formula[i] == '('){
                s.push({});
                i++;
            }
            else if (formula[i] == ')'){
                auto top = s.top();
                s.pop();
                i++;
                int start = i;
                while (i < n && isdigit(formula[i]))
                    i++;
                int mul = (i == start) ? 1 : stoi(formula.substr(start, i - start));
                for (auto &[str, count] : top){
                    s.top()[str] += count * mul;
                }
            }
            else{
                int start = i;
                i++;
                while (i < n && islower(formula[i]))
                    i++;
                string str = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i]))
                    i++;
                int count = (i == start) ? 1 : stoi(formula.substr(start, i - start));
                s.top()[str] += count;
            }
        }

        auto &counts = s.top();
        map<string, int> mp(counts.begin(), counts.end());
        string ans;
        for (auto &[str, count] : mp)
        {
            ans += str;
            if (count > 1)
                ans += to_string(count);
        }

        return ans;
    }
};