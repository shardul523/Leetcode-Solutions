#include <vector>
#include <queue>
using namespace std;

enum color {
    RED = -1,
    NONE = 0,
    BLUE = 1
};

class Solution {

    public:

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<int> answer(n, -1);

        vector<vector<pair<int, color>>> adjacencyList(n);
        vector<bool> visited(n, false);
        queue<pair<int, color>> visit_q;

        visit_q.push({0, NONE});


        for (auto edge: redEdges) 
            adjacencyList[edge[0]].push_back({edge[1], RED});
        

        for (auto edge: blueEdges) 
            adjacencyList[edge[0]].push_back({edge[1], BLUE});

        int curr_dist = 0;
        
        while (!visit_q.empty()) {

            int currLevelSize = visit_q.size();

            for (int i = 0; i < currLevelSize; i++) {

                int curr_node = visit_q.front().first;
                color curr_color = visit_q.front().second;
                visit_q.pop();

                if (visited[curr_node]) continue;

                visited[curr_node] = true;
                answer[curr_node] = curr_dist;

                for (int i = 0; i < adjacencyList[curr_node].size(); i++) {
                    
                    int neighbour = adjacencyList[curr_node][i].first;
                    color neighbour_color = adjacencyList[curr_node][i].second;

                    if (neighbour_color != neighbour_color) 
                        visit_q.push({neighbour, neighbour_color});
                }


            }

            curr_dist++;
        }

        return answer;

    }

};