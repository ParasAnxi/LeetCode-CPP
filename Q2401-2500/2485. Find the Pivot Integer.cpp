class Solution
{
public:
    int pivotInteger(int n){
        int sum = (n * (n + 1)) / 2;

        int start = 1;
        int end = n;

        while (start <= end){
            int mid = start + (end - start) / 2;
            int left = (mid * (mid + 1)) / 2;
            int right = (sum - left) + mid;
            if (left == right)
                return mid;
            else if (left < right)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};