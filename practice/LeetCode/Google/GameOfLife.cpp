class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
		if (board.empty()) return;
		int n = board.size();
		int m = board[0].size();

		// 0->1: 2
		// 1->0: 3
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				int c = 0;
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++) {
						if (k == 0 && l == 0) continue;
						if (0 <= i + k && i + k <= n - 1 && 0 <= j + l && j + l <= m - 1) {
							if (board[i + k][j + l] == 1 || board[i + k][j + l] == 3) c ++;
						}
					}
				}
				if (board[i][j] == 1 && c < 2) board[i][j] = 3;
				if (board[i][j] == 0 && 3 == c) board[i][j] = 2;
				if (board[i][j] == 1 && 3 < c) board[i][j] = 3;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 2) board[i][j] = 1;
				if (board[i][j] == 3) board[i][j] = 0;
			}
		}
    }
};
