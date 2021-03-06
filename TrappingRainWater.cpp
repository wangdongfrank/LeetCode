/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute 
 how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain 
water (blue section) are being trapped. Thanks Marcos for contributing this image!

*/
class Solution {
public:
    int trap(int A[], int n) {
        int left[n];
        int right[n];
        int leftmin=0,rightmax=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>leftmin)
            {
                left[i] = A[i];
                leftmin = A[i];
            }
            else
            left[i] = leftmin;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(A[i]>rightmax)
            {
                right[i] = A[i];
                rightmax = A[i];
            }
            else
            right[i] = rightmax;
        }
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += min(left[i],right[i])-A[i]; 
        }
        return sum;
    }
};
