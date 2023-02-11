#include <vector>
#include <queue>
#include <set>
#include <tuple>
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
        set<tuple<int,int,color>> edgesTraversed;
        vector<vector<pair<int,color>>> adjacencyList(n);
        queue<pair<int, color>> visit_queue;

        for (auto edge: redEdges) {
            int source = edge[0];
            int dest = edge[1];
            adjacencyList[source].push_back({dest, RED});
        }

        for (auto edge: blueEdges) {
            int source = edge[0];
            int dest = edge[1];
            adjacencyList[source].push_back({dest, BLUE});
        }

        visit_queue.push({0, NONE});

        int currDist = 0;

        while (!visit_queue.empty()) {

            int currSize = visit_queue.size();

            for (int i = 0; i < currSize; i++) {

                int currNode = visit_queue.front().first;
                int currColor = visit_queue.front().second;
                visit_queue.pop();

                answer[currNode] = answer[currNode] == -1 ? currDist : min(answer[currNode], currDist);

                for (auto neighbour: adjacencyList[currNode]) {

                    tuple<int, int, color> currEdge{currNode, neighbour.first, neighbour.second};

                    if (currColor != neighbour.second && edgesTraversed.find(currEdge) == edgesTraversed.end()) {
                        visit_queue.push(neighbour);
                        edgesTraversed.insert(currEdge);
                    }
                }
            }

            currDist++;
        }

        return answer;
    }

};