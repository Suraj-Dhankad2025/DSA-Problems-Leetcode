class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int i=0,j=0;
        int ind2=n/2;
        int ind1=ind2 -1;
        int a=-1,b=-1;
        int ind=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(ind==ind1){
                    a = nums1[i];
                }
                if(ind==ind2){
                    b = nums1[i];
                }
                i++;
                ind++;
            }
            else{
                if(ind==ind1){
                    a = nums2[j];
                }
                if(ind==ind2){
                    b = nums2[j];
                }
                j++;
                ind++;
            }
        }
        while(i<n1){
            if(ind==ind1){
                a = nums1[i];
            }
            if(ind==ind2){
                b = nums1[i];
            }
            i++;
            ind++;
        }
        while(j<n2){
            if(ind==ind1){
                a = nums2[j];
            }
            if(ind==ind2){
                b = nums2[j];
            }
            j++;
            ind++;
        }
        if(n%2==1){
            return b;
        }
        else{
            return (double)(double)(a+b)/2.0;
        }
    }
};