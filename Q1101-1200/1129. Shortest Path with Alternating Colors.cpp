class Solution {

public:
    struct Node {
        int number;
        vector<int> blueCities;
        vector<int> redCitites;

        Node(int number) {
            this->number = number;
        }
    };

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, Node> hashMap;
        for (int i = 0; i < n; i++) {
            hashMap.insert({i,Node(i)});
        }
        for (auto redEdge : redEdges) {
            hashMap.at(redEdge[0]).redCitites.push_back(redEdge[1]);
        }
        for (auto blueEdge : blueEdges) {
            hashMap.at(blueEdge[0]).blueCities.push_back(blueEdge[1]);
        }
        vector<int> ans(n, -1);
        vector<vector<bool>> visit(n, vector<bool>(2, false));
        queue<vector<int>> q;
        q.push({0, 0, -1});
        ans[0] = 0;
        visit[0][0] = visit[0][1] = true;

        while (!q.empty()) {
            auto element = q.front();
            q.pop();
            int nodeNumber = element[0], steps = element[1], prevColor = element[2];

            for (auto neighbor : hashMap.at(nodeNumber).redCitites) {
                if (!visit[neighbor][0] && prevColor != 0) {
                    if (ans[neighbor] == -1) ans[neighbor] = 1 + steps;
                    visit[neighbor][0] = true;
                    q.push({neighbor, 1 + steps, 0});
                }
            }
            for (auto neighbor : hashMap.at(nodeNumber).blueCities) {
                if (!visit[neighbor][1] && prevColor != 1) {
                    if (ans[neighbor] == -1) ans[neighbor] = 1 + steps;
                    visit[neighbor][1] = true;
                    q.push({neighbor, 1 + steps, 1});
                }
            }

        }
        return ans;
    }
};