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
     int length;
    int find(int low,int high,int target,MountainArray &mountainArr){
        if(low>high) return -1;
        int mid,currentEle;
        mid=low+(high-low)/2;
        currentEle=mountainArr.get(mid);
        if(currentEle < target){
            if(mid!=length && currentEle<mountainArr.get(mid+1)) return find(mid+1,high,target,mountainArr);
            else return find(low,mid-1,target,mountainArr);
        }
        else{
            int left=find(low,mid-1,target,mountainArr);
            return left != -1 ? left  : currentEle == target ? mid : find(mid+1,high,target,mountainArr);
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low=0,high=mountainArr.length()-1;
        length=high;
        return find(low,high,target,mountainArr);
    }
};