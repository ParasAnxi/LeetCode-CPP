class Solution
{
public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int left = 1, right = position.back() - position[0];
        while (left < right)
        {
            int mid = (left + right) / 2 + ((left + right) % 2 != 0 ? 1 : 0);
            int c = 1;
            int prev = position[0];
            for (auto i : position)
            {
                if (i - prev >= mid)
                {
                    c++;
                    prev = i;
                }
            }
            if (c >= m)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};