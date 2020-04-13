#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int tes;
    cin>>tes;
    for(int t=0;t<tes;t++)
    {
        int i,j,row,col;
        cin>>row;
        col=row;
        vector<vector<int>>array(row,vector<int>(col));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                cin>>array[i][j];
        vector<vector<int>>dp(row,vector<int>(col));
        row--;col--;
        if(row==0 or col ==0)
        {
            cout<<dp[0][0]<<endl;
            continue;
        }
        dp[row][col]=array[row][col];
        for(i=row,j=col-1;j>=0;j--) dp[i][j]=dp[i][j+1]+array[i][j];
        for(j=col,i=row-1;i>=0;i--) dp[i][j]=dp[i+1][j]+array[i][j];
        for(i=row-1;i>=0;i--)
            for(j=col-1;j>=0;j--)
                dp[i][j]=max(dp[i+1][j],dp[i][j+1])+array[i][j];
        cout<<dp[0][0]<<endl;
    }
    return 0;
}
