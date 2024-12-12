class Solution
{
public:
    long long int pickGifts(vector<int> &gifts, int k)
    {
        auto heap{priority_queue{less(), move(gifts)}};
        while (k-- > 0)
        {
            heap.push(floor(sqrt(heap.top())));
            heap.pop();
        }
        auto sum{0LL};
        while (!heap.empty())
        {
            sum += heap.top();
            heap.pop();
        }
        return sum;
    }
};