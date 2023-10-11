class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> s, e;
        for (int i = 0; i < flowers.size(); i++)
        {
            s.push_back(flowers[i][0]);
            e.push_back(flowers[i][1]);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        for (int i = 0; i < people.size(); i++)
        {
            auto upper = upper_bound(s.begin(), s.end(), people[i]);
            int up = upper - s.begin();

            auto lower = lower_bound(e.begin(), e.end(), people[i]);
            int down = lower - e.begin();
            people[i] = (up - down);
        }
        return people;
    }
};