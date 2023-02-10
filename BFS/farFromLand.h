#include <vector>
#include <queue>
#include <iostream>


class Solution {

    public:

    int maxDistance(std::vector<std::vector<int>>& grid) {

        std::queue<std::pair<int, int>> q;
        int n = grid.size();
        int maxDist = 0;

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    if (i - 1 >= 0) q.push({i -1, j});
                    if (i + 1 < n) q.push({i + 1, j});
                    if (j - 1 >= 0) q.push({i, j - 1});
                    if (j + 1 < n) q.push({i, j + 1});
                }
        
        int curr_dist = 1;

        while (!q.empty()) {

            
            int curr_size = q.size();

            for (int i = 0; i < curr_size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (grid[x][y]) continue;

                grid[x][y] = curr_dist;
                maxDist = std::max(curr_dist, maxDist);

                if (x + 1 < n) q.push({x + 1, y});
                if (x - 1 >= 0) q.push({x - 1, y});
                if (y + 1 < n) q.push({x, y + 1});
                if (y - 1 >= 0) q.push({x, y - 1});
            }

            curr_dist++;
        }

        return maxDist;
    }

};


