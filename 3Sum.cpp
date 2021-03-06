/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)


*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        sort(num.begin(),num.end());
        int len = num.size();
        vector<vector<int>> result;
        for(int i=0;i<len-2;i++)
        {
            if(num[i]>0)
            break;
            if(i>0 && num[i]==num[i-1]) // check the duplicates
            continue;
            int j =i+1;
            int k=len-1;
            while(j<k)
            {
                int sum = num[i]+num[j]+num[k];
                if(sum==0)
                {
                    vector<int> curr;
                    curr.push_back(num[i]);
                    curr.push_back(num[j]);
                    curr.push_back(num[k]);
                    result.push_back(curr);
                   j++;k--;
                   while(j<k && num[j]==num[j-1]) j++; //check the duplicates
                   while(j<k && num[k]==num[k+1]) k--; //check the duplicates
                }
                else if(sum>0)
                k--;
                else
                j++;
            }
        }
        return result;
    }
};
