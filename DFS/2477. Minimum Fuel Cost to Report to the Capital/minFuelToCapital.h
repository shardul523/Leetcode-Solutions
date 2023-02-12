#include <vector>
#include <functional>
using namespace std;

class Solution {

    vector<bool> visited;

    public:

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        vector<vector<int>> adjacencyList(roads.size() + 1);
        visited = vector<bool>(roads.size() + 1, false);
        long long fuelNeeded = 0;

        for (const auto& road: roads) {
            adjacencyList[road[0]].emplace_back(road[1]);
            adjacencyList[road[1]].emplace_back(road[0]);
        }

        function<int (int, int)> dfsTraversal = [&] (int n, int level) -> int {

            if (visited[n])
                return 0;
            
            int remainingSeats = 0;

            visited[n] = true;

            for (auto city: adjacencyList[n]) {
                int seatsNeeded = seats - dfsTraversal(city, level + 1);
                if (remainingSeats >= seatsNeeded) {
                    fuelNeeded -= level;
                    remainingSeats -= seatsNeeded;
                } else {
                    remainingSeats += seats - seatsNeeded;
                }
            }
            

            if (remainingSeats > 0)
                return remainingSeats - 1;
            else {
                fuelNeeded += level;
                return seats - 1;
            }
        };

        dfsTraversal(0, 0);
        
        return fuelNeeded;
    }

};
