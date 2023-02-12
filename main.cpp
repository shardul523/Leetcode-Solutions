#include <iostream>
#include <vector>
#include <string>
#include "utility.h"
#include "minFuelToCapital.h"
using namespace std;


int main() {

    Solution obj;
    int n = 5;
    vector<vector<int>> roads{{0,1},{0,2},{1,3},{1,4}};
    cout<<"Minimum Fuel Needed: "<<obj.minimumFuelCost(roads, n)<<'\n';
    getchar();
}