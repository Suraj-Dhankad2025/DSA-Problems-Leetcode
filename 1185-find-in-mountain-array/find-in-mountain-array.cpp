/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int ans = -1;
    int find(int target, MountainArray &a, int s, int e, bool increasingOrder) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int ele = a.get(mid);
            if (ele == target) {
                if (ans == -1) {
                    ans = mid;
                }
                ans = min(ans, mid);
            }

            if (increasingOrder) {
                if (ele < target) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            } else {
                if (ele > target) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return ans;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int s = 0, e = n - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        ans = find(target, mountainArr, 0, e, true);
        if (ans != -1) {
            return ans;
        }
        ans = find(target, mountainArr, e + 1, n - 1, false);
        return ans;
    }
};
