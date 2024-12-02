class Solution
{
public:
    int isPrefixOfWord(string sentence,string searchWord)
    {
        int index = 1;
        int i = 0;
        while (i < sentence.size())
        {
            int start = i;
            while (i < sentence.size() && sentence[i] != ' ')
            {
                i++;
            }
            string curr = sentence.substr(start, i - start);
            if (curr.find(searchWord) == 0)
            {
                return index;
            }
            index++;
            i++;
        }
        return -1;
    }
};