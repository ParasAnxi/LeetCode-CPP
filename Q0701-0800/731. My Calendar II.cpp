class MyCalendarTwo
{
public:
    set<pair<int, int>> booking;
    set<pair<int, int>> st;

    MyCalendarTwo()
    {
    }
    bool checkOverlap(int start1, int end1, int start2, int end2)
    {
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> solve(int start1, int end1, int start2, int end2)
    {
        return {max(start1, start2), min(end1, end2)};
    }

    bool book(int start, int end)
    {
        for (auto it : st)
        {
            if (checkOverlap(it.first, it.second, start, end))
            {
                return false;
            }
        }

        for (auto it : booking)
        {
            if (checkOverlap(it.first, it.second, start, end))
            {
                st.insert(solve(it.first, it.second, start, end));
            }
        }

        booking.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */