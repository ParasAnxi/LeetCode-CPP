class BrowserHistory {
public:
    vector<string> res;
    int now=0;
    BrowserHistory(string homepage) {
        res.push_back(homepage);
    }
    
    void visit(string url) {
        vector<string> new_res;
        for(int i=0;i<=now;i++){
            new_res.push_back(res[i]);
        }
        new_res.push_back(url);
        now++;
        res.clear();
        res=new_res;
    }
    
    string back(int steps) {
        if(steps>now){
            now=0;
        }
        else{
            now-=steps;
        }
        return res[now];
    }
    
    string forward(int steps) {
        if(steps>=(int)res.size()-now){
            now=(int)res.size()-1;
        }
        else{
            now+=steps;
        }
        return res[now];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */