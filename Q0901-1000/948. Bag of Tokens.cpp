class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int i = 0;
        int n = tokens.size() - 1;
        int score = 0;
        while (i <= n)
        {
            if (power >= tokens[i])
            {
                power -= tokens[i];
                score++;
                i++;
            }
            else if (score > 0 && i != n)
            {
                power += tokens[n];
                score--;
                n--;
            }
            else
            {
                break;
            }
        }
        return score;
    }
};