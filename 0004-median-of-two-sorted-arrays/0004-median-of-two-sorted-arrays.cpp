class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int i = 0;
        int j = 0;

        int n = nums1.size();
        int m = nums2.size();
        vector<int>num(n+m , 0);
        int k =0;

        //merge and sorted num.
        while(i< n && j <m){
            if(nums1[i] <= nums2[j]){
                num[k] = nums1[i];
                k++;
                i++;
            }
            else{
                num[k] = nums2[j];
                k++;
                j++;
            }
        }
        while(i<n){
            num[k] = nums1[i];
            k++;
            i++;
        }
        while(j<m){
            num[k] = nums2[j];
            k++;
            j++;
        }

        //find if odd or even.
        int x = n + m;
        if (x % 2 == 0) return (num[x / 2 - 1] + num[x / 2]) / 2.0;
       return num[x / 2];
        
        
    }
};