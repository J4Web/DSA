class Solution {
public:
	int helper(vector<vector<int>>& grid , int i , int j , int m , int n , vector<vector<bool>> &vis) {

		vis[i][j] = true;

		int cs = 1;

		int dx[] = {1, -1, 0, 0};
		int dy[] = {0, 0, 1, -1};

		for (int k = 0 ; k < 4 ; k++) {

			int x = i + dx[k];
			int y = j + dy[k];
			if (x >= 0 and x < m  and y >= 0 and y < n and grid[x][y] and !vis[x][y]) {
				int sub = helper(grid, x, y, m, n, vis);
				cs += sub;
			}
		}
		return cs;
	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int ans = 0;
		vector<vector<bool>> vis(m, vector<bool>(n, false));
		for (int i = 0 ; i < m ; i++) {
			for (int j = 0 ; j < n ; j++) {
				if (grid[i][j] and !vis[i][j])
					ans = max(ans, helper(grid, i, j, m, n, vis));
			}
		}
		return ans;

	}
};