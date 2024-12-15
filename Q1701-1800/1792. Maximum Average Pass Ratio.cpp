class Solution {
public:

    void pushInHeap(int passStudent,int totalStudent,int index,priority_queue<pair<double,int>>& pq)
    {
        double currentAverage=(double) passStudent/totalStudent;
        double newAverage= (double) (passStudent+1)/(totalStudent+1);
        double increment = (double)newAverage-currentAverage;
        pq.push({increment,index});

    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans=0;
        int n=classes.size();
        priority_queue<pair<double,int>> pq;

        for(int i=0;i<classes.size();i++)
        {
            pushInHeap(classes[i][0],classes[i][1],i,pq);
        }
        while(extraStudents)
        {
            auto node=pq.top();
            pq.pop();

            int index=node.second;
            classes[index][0]++;
            classes[index][1]++;
            pushInHeap(classes[index][0],classes[index][1],index,pq);
            extraStudents--;
        }

        for(int i=0;i<classes.size();i++)
        {
            ans+=(double)classes[i][0]/classes[i][1];
        }

        ans=(double)ans/n;
        return ans;

    }
};