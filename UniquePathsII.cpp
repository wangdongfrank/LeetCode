/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.

*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int row = obstacleGrid.size();
        if(row<=0 || obstacleGrid[0][0]==1)
        return 0;
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));  
        dp[0][0] = 1;
        for(int i=1;i<col;i++)
        {
            if(obstacleGrid[0][i]==0)
            dp[0][i] = dp[0][i-1];
            else break;
        }
        for(int i=1;i<row;i++)
        {
            if(obstacleGrid[i][0]==0)
            dp[i][0] = dp[i-1][0];
            else break;
        }
    
        for(int i=1;i<row;i++)
        for(int j=1;j<col;j++)
        {
            if(obstacleGrid[i][j]==1)
            dp[i][j] = 0;
            else 
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
        return dp[row-1][col-1];
    }
};
