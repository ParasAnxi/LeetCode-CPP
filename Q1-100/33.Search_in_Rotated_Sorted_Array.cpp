class Solution {
public:
    int bS(vector<int>& arr,int s,int e ,int key){
     int start=s;
    int end=e;
    int m=s+(e-s)/2;

    while(s<=e){
        if(arr[m]==key){
            return m;
        }
        else if(arr[m]<key){
            s=m+1;
        }
        else{
            e=m-1;
        }
        m=s+(e-s)/2;
    }
    return -1;
}
    int pivot(vector<int>& arr,int n){
    int s=0;
    int e=n-1;
    int m=s+(e-s)/2;
    while(s<e){
        if(arr[m]>=arr[0]){
            s=m+1;
        }
        else{
            e=m;
        }
        m=s+(e-s)/2;
    }
    return s;
}
    int search(vector<int>& nums, int target) {
        int n = nums.size();
         int z= pivot(nums,n);
   if(target>=nums[z] && target<=nums[n-1]){
        return bS(nums,z,n-1,target);
   }
   else{
       return bS(nums,0,z-1,target);
   }
    }
};