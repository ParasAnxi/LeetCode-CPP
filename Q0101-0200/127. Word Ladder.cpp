class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    if (st.find(endWord) == st.end())
      return 0;
    queue<string> q;
    q.push(beginWord);
    int count = 1;
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        string front = q.front();
        q.pop();
        if (front == endWord)
          return count;
        for (int j = 0; j < front.size(); j++) {
          string str = front;
          for (char c = 'a'; c <= 'z'; c++) {
            str[j] = c;
            if (st.count(str)) {
              q.push(str);
              st.erase(str);
            }
          }
        }
      }
      count++;
    }
    return 0;
  }
};
