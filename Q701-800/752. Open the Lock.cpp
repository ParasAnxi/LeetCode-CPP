class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> visited{deadends.begin(), deadends.end()};
        if (visited.count("0000"))
            return -1;
        if (target == "0000")
            return 0;
        while (!q.empty()){
            string str = q.front().first;
            int steps = q.front().second;
            q.pop();
            steps++;
            for (int i = 0; i < 4; i++){
                char c = str[i];
                str[i] = str[i] == '9' ? '0' : str[i] + 1;
                if (str == target)
                    return steps;
                if (!visited.count(str)){
                    q.push({str, steps});
                    visited.insert(str);
                }
                str[i] = c;
                str[i] = str[i] == '0' ? '9' : str[i] - 1;
                if (str == target)
                    return steps;
                if (!visited.count(str)){
                    q.push({str, steps});
                    visited.insert(str);
                }
                str[i] = c;
            }
        }
        return -1;
    }
};