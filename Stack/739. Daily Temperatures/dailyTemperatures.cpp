#include <deque>
#include <vector>
using namespace std;

class Solution {

public: 

    vector<int> dailyTemperatures(vector<int>& temperatures) {

        deque<int> greaterTemps;
        vector<int> waitDays(temperatures.size(), 0);

        greaterTemps.push_back(temperatures.size() - 1);

        for (int i = temperatures.size() - 2; i >= 0; i--) {

            while (!greaterTemps.empty() && temperatures[i] >= temperatures[greaterTemps.back()]) 
                greaterTemps.pop_back();
            
            if (greaterTemps.empty()) 
                waitDays[i] = 0;
            else 
                waitDays[i] = greaterTemps.back() - i;

            greaterTemps.push_back(i);

        }

        return waitDays;
    }

};