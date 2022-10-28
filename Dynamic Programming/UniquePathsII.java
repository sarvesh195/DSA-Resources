class Solution 
{
    public int uniquePathsWithObstacles(int[][] grid) 
    {
        int m = grid.length, n = grid[0].length;
        int[][] dp = new int[m][n];
        for(int j=0; j<n; j++)
        {
            if(grid[0][j] == 1)
                break;
            dp[0][j] = 1;
        }
        for(int i=0; i<m; i++)
        {
            if(grid[i][0] == 1)
                break;
            dp[i][0] = 1;
        }
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i][j] = (grid[i][j] == 0) ? dp[i-1][j] + dp[i][j-1] : 0;
        return dp[m-1][n-1];
    }
}
