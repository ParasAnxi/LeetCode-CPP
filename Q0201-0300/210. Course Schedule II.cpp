class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (auto i : prerequisites)
      adj[i[1]].push_back(i[0]);

    vector<int> inDegree(numCourses, 0);

    for (auto i : adj) {
      for (auto j : i)
        inDegree[j]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
      if (inDegree[i] == 0)
        q.push(i);

    vector<int> ans;
    while (!q.empty()) {
      int front = q.front();
      q.pop();
      ans.push_back(front);

      for (auto i : adj[front]) {
        inDegree[i]--;
        if (inDegree[i] == 0)
          q.push(i);
      }
    }

    if (ans.size() != numCourses)
      return {};
    return ans;
  }
};