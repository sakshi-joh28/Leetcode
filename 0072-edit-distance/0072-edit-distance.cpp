class Solution {
public:
  /*  int solve(string word1,string word2,int i,int j)
    {
        int in=0,up=0,de=0;
        //BASE CASES
        if(i==word1.length())
            return word2.length()-j;
        if(j==word2.length())
            return word1.length()-i;
        if(word1[i]==word2[j]) //MATCH HOGAYA 
            return  solve(word1,word2,i+1,j+1);
        else  //IF NOT MATCHED
        {
            //insert
            in=1+solve(word1,word2,i,j+1);
            //update
            up=1+solve(word1,word2,i+1,j+1);
            //delete
            de=1+solve(word1,word2,i+1, j);
            //min
           int t=min(in,up);
            return min(t,de);
        }
    }
    int minDistance(string word1, string word2) {
      return solve(word1,word2,0,0);
    }
};*/
     int minDistance(string word1, string word2) {
    const int m = word1.length();//first word length
    const int n = word2.length();//second word length
    // dp[i][j] := min # of operations to convert word1[0..i) to word2[0..j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
      dp[i][0] = i;

    for (int j = 1; j <= n; ++j)
      dp[0][j] = j;

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (word1[i - 1] == word2[j - 1])//same characters
          dp[i][j] = dp[i - 1][j - 1];//no operation
        else
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                             //replace       //delete        //insert
    return dp[m][n];
  }
};