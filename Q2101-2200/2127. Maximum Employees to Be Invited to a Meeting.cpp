#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maximumInvitations(vector<int> &favorite)
    {
        int n = favorite.size();
        vector<int> inDeg(n, 0);
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++){
            int f = favorite[i];
            inDeg[f]++;
            graph[f].push_back(i);
        }
        queue<int> q;
        vector<int> longChain(n, 1);

        for (int i = 0; i < n; i++)
        {
            if (inDeg[i] == 0)
                q.push(i);
        }

        while (!q.empty()){
            int node = q.front();
            q.pop();
            int fav = favorite[node];
            longChain[fav] = max(longChain[fav], longChain[node] + 1);
            if (--inDeg[fav] == 0)
                q.push(fav);
        }
        vector<bool> visited(n, false);
        int maxiCycSize = 0;
        int chainSum = 0;

        for (int i = 0; i < n; i++)
        {
            if (inDeg[i] > 0){
                int cycle_length = 0, curr = i;
                while (!visited[curr])
                {
                    visited[curr] = true;
                    cycle_length++;
                    curr = favorite[curr];
                }
                if (cycle_length == 2){
                    chainSum += longChain[i] + longChain[favorite[i]];
                }
                else{
                    maxiCycSize = max(maxiCycSize, cycle_length);
                }
            }
        }

        return max(maxiCycSize, chainSum);
    }
};
