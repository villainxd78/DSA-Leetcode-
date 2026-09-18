class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int size = m+n;
        int index1 = size/2;
        int element1 = -1;
        int index2 = size/2 - 1;
        int element2 = -1;
        int i = 0;
        int j = 0;
        int k = 0;

        while(i<n&&j<m){
            if(nums1[i]<nums2[j]){
                if(k ==  index1){
                    element1 = nums1[i];
                }
                 if(k==index2){
               element2 = nums1[i];
                }
                i++;
            }
                   
            else{
                if(k==index1){
                    element1 = nums2[j];

                }
                if(k==index2){
                    element2 = nums2[j];
                }
                j++;
            }
            k++;
        }
        while(i<n){
            if(k==index1){
                element1 = nums1[i];
            }
            if(k==index2){
                element2 = nums1[i];
            }
            i++;
            k++;
        }
        while(j<m){
            if(k==index1){
                element1 = nums2[j];

            }
            if(k==index2){
                element2 = nums2[j];

            }
            j++;
            k++;
        }
        if(size % 2 == 1)
            return element1;

        return (element1 + element2) / 2.0;



    }
};