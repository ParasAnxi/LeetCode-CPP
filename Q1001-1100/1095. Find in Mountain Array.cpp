/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();

        int l2 = 1;
        int h2 = n - 2;
        int peak = 0;

        while (l2 <= h2)
        {
            int mid = (l2 + h2) / 2;
            int x = mountainArr.get(mid);
            if (mountainArr.get(mid - 1) < x && x > mountainArr.get(mid + 1))
            {
                peak = mid;
                break;
            }
            else if (x < mountainArr.get(mid + 1))
                l2 = mid + 1;
            else
                h2 = mid - 1;
        }
        int l = 0;
        int h = peak;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int x = mountainArr.get(mid);
            if (x == target)
                return mid;
            else if (target < x)
                h = mid - 1;
            else if (target > x)
                l = mid + 1;
        }
        int l1 = peak;
        int h1 = n - 1;

        while (l1 <= h1)
        {
            int mid = (l1 + h1) / 2;
            int x = mountainArr.get(mid);
            if (x == target)
                return mid;
            else if (target < x)
                l1 = mid + 1;
            else if (target > x)
                h1 = mid - 1;
        }

        return -1;
    }
};