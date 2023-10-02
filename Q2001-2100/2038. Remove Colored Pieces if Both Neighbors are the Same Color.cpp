class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int alice = 0, bob = 0;
        stack<char> s;
        for (int i = 0; i < colors.size() - 1; ++i)
        {
            if (i == 0)
                s.push(colors[i]);
            else if (s.top() == colors[i] && colors[i + 1] == 'A' && colors[i] == 'A')
                alice++;
            else if (s.top() == colors[i] && colors[i + 1] == 'B' && colors[i] == 'B')
                bob++;
            else
                s.push(colors[i]);
        }
        return alice > bob;
    }
};