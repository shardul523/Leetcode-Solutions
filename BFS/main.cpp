#include <iostream>
#include <vector>
#include <string>
#include "1162. As Far from Land as Possible/farFromLand.h"


int main() {

    Solution obj;
    std::vector<std::vector<int>> grid{{1,0,1},{0,0,0},{1,0,1}};
    std::cout<<"Max dist to nearest land: "<<obj.maxDistance(grid);
    getchar();
}