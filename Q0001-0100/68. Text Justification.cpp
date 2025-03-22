class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;

        int i = 0;
        int width = 0;
        vector<string> curLine;

        while (i < words.size()){
            string curWord = words[i];
            if (width + curWord.length() <= maxWidth){
                curLine.push_back(curWord);
                width += curWord.length() + 1;
                i++;
            }
            else{
                int spaces = maxWidth - width + curLine.size();
                int added = 0;
                int j = 0;
                while (added < spaces){
                    if (j >= curLine.size() - 1){
                        j = 0;
                    }
                    curLine[j] += " ";
                    added++;
                    j++;
                }
                string line = "";
                for (const string &word : curLine){
                    line += word;
                }
                ans.push_back(line);
                curLine.clear();
                width = 0;
            }
        }
        for (int word = 0; word < curLine.size() - 1; word++){
            curLine[word] += " ";
        }
        curLine[curLine.size() - 1] += string(maxWidth - width + 1, ' ');

        string lastLine = "";
        for (const string &word : curLine){
            lastLine += word;
        }
        ans.push_back(lastLine);

        return ans;
    }
};