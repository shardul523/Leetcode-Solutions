#include <vector>
#include <map>
using namespace std;


bool canCatchUp(pair<int, int> c1, pair<int, int> c2, int target) {

    if (c1.second >= c2.second) return false;

    float t1 = (target - c1.first) / (float)c1.second;
    float t2 = (target - c2.first)/ (float)c2.second;


    return t1 >= t2;
}


int carFleet(int target, vector<int>& position, vector<int>& speed) {

    map<int, int, greater<>> cars;
    pair<int, int> fleetHead = {0, 0};
    int fleets = 0;
    int n = position.size();

    for (int i = 0; i < n; i++) {
        cars.insert({position[i], speed[i]});
    }


    for (auto car: cars) {

        if (fleetHead == make_pair(0,0)) {
            fleetHead = car;
            fleets = 1;
            continue;
        }

        if (!canCatchUp(fleetHead, car, target)) {
            fleetHead = car;
            fleets++;
        }
    }

    return fleets;
}
