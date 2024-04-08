class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        queue<int> q;
        for (auto it : students)
        {
            q.push(it);
        }
        int i = 0;
        int j = 0;
        while (!q.empty() && j != q.size())
        {
            if (q.front() == sandwiches[i])
            {
                q.pop();
                j = 0;
                i++;
            }
            else
            {
                int temp = q.front();
                q.pop();
                q.push(temp);
                j++;
            }
        }
        return q.size();
    }
};