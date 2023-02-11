#include <iostream>
#include <vector>
#include <string>
#include "utility.h"
#include "BFS/1129. Shortest Path with Alternating Colors/shortestPathWithAltColors.h"
using namespace std;


int main() {

    Solution obj;
    int n = 5;
    vector<vector<int>> redEdges{{0,1},{1, 2},{2,3},{3,4}};
    vector<vector<int>> blueEdges{{1,2},{2,3},{3,1}};
    vector<int> answer = obj.shortestAlternatingPaths(n, redEdges, blueEdges);
    printList(answer);
    getchar();

}