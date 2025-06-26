class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int ts=m+n;
        int index2=ts/2;
        int index1=index2-1;
        int cnt=0;
        int ind1el=-1,ind2el=-1;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
               if(cnt==index1)
               ind1el=nums1[i];
               if(cnt==index2)
               ind2el=nums1[i];
               cnt++;
               i++;}
               else{
                   if(cnt==index1)
                   ind1el=nums2[j];
                   if(cnt==index2)
                   ind2el=nums2[j];
                   cnt++;
                   j++;
               }
        }
               while(i<m){
                    if(cnt==index1)
               ind1el=nums1[i];
               if(cnt==index2)
               ind2el=nums1[i];
               cnt++;
               i++;
               }
               while(j<n)
               {
                if(cnt==index1)
                   ind1el=nums2[j];
                   if(cnt==index2)
                   ind2el=nums2[j];
                   cnt++;
                   j++;
               }
               if(ts%2==1)
               return ind2el;
               else
               return (double)((ind1el+ind2el)/2.0);
    }
};