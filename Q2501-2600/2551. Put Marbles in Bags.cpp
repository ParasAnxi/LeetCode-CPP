class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        priority_queue<int> pq1;
        priority_queue<int,vector<int>,greater<int>> pq2;
        for(int i=1;i<n;i++){
            pq1.push(weights[i-1]+weights[i]);
            pq2.push(weights[i-1]+weights[i]);
            if(pq1.size()>k-1)
            pq1.pop();
             if(pq2.size()>k-1)
            pq2.pop();
        }
        long long s1=0,s2=0;
        while(!pq1.empty()){
            s1+=pq1.top();
            s2+=pq2.top();
            pq1.pop();
            pq2.pop();
        }
        return abs(s1-s2);
    }
};