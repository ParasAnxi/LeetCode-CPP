class Solution {
public:
int BinarySearch(vector<int> &num, int s, int e) {
    if(s == e) 
        return s;
    else{
        int mid1 = s+(e-s)/2;
        int mid2 = mid1+1;
        if(num[mid1] > num[mid2]) 
            return BinarySearch(num, s, mid1);
        else 
            return BinarySearch(num, mid2, e);
    }
}
int findPeakElement(vector<int> &num) {
    return BinarySearch(num, 0, num.size()-1);
}
};