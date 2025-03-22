class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
     int dx = abs(sx-fx);
        int dy = abs(sy-fy);
        
        if( t == 1 && max(dx,dy) == 0) return false;
            
        return max(dx,dy) <= t;
    }
};