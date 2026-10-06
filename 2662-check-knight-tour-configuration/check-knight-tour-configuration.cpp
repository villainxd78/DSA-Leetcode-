class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        // Knight must start from (0,0)
        if (grid[0][0] != 0)
            return false;

        int x = 0;
        int y = 0;

        int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

        // Find 1, then 2, then 3, ...
        for (int move = 1; move < n * n; move++) {

            bool found = false;

            for (int k = 0; k < 8; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 &&
                    nx < n && ny < n &&
                    grid[nx][ny] == move) {

                    x = nx;
                    y = ny;
                    found = true;
                    break;
                }
            }

            if (!found)
                return false;
        }

        return true;
    }
};