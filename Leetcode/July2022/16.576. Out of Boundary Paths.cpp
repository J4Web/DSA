int dx[] = {0, 0, -1, 1};
int dy[] = { -1, 1, 0, 0};
int mod = 1e9 + 7;
class Solution {
public:
    vector<vector<vector<int>>> dp;
    int helper(int sR , int sC , int mM , int m , int n) {
        if (sR<0 or sR >= m or sC<0 or sC >= n) return 1;
        else if (mM == 0) return 0;
        if (dp[sR][sC][mM] != -1) return dp[sR][sC][mM];
        int subp = 0;
        for (int k = 0 ; k < 4 ; k++) {
            int xx = sR + dx[k];
            int yy = sC + dy[k];
            subp = (subp % mod + helper(xx, yy, mM - 1, m, n) % mod) % mod;
        }
        return dp[sR][sC][mM] = subp;
    }
    int findPaths(int m, int n, int mM, int sR, int sC) {
        dp.resize(m, vector<vector<int>>(n, vector<int>(mM + 1, -1)));
        int ans = helper(sR, sC, mM, m, n);
        return ans;
    }
};