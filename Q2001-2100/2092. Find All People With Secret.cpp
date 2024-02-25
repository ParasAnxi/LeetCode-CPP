class Solution{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson){
        vector<pair<int, int>> adj[n];
        for (auto i : meetings){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        queue<pair<int, int>> pq;
        pq.push({0, 0});
        pq.push({firstPerson, 0});
        vector<int> TimeTaken(n, INT_MAX);
        TimeTaken[0] = 0, TimeTaken[firstPerson] = 0;
        vector<int> ans;
        while (!pq.empty()){
            int to = pq.front().first;
            int time = pq.front().second;
            pq.pop();
            for (auto i : adj[to]){
                int adjNode = i.first;
                int instantTime = i.second;
                if (adjNode == to){
                    continue;
                }
                else if (instantTime >= time &&TimeTaken[adjNode] > instantTime){
                    TimeTaken[adjNode] = instantTime;
                    pq.push({adjNode, instantTime});
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (TimeTaken[i] != INT_MAX){
                ans.push_back(i);
            }
        }
        return ans;
    }
};