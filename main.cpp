#include <iostream>
#include <vector>
#include <string>
#include "utility.h"
#include "BFS/1129. Shortest Path with Alternating Colors/shortestPathWithAltColors.h"
using namespace std;


int main() {

    Solution obj;
    int n = 3;
    vector<vector<int>> redEdges{{0,1}, {1, 2}};
    vector<vector<int>> blueEdges;
    vector<int> answer = obj.shortestAlternatingPaths(n, redEdges, blueEdges);
    printList(answer);
    getchar();

}