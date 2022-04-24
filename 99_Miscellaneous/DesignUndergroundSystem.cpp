#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/design-underground-system/
 * 
 */

class UndergroundSystem {
public:
    UndergroundSystem() {
        db.clear();
        checkedIn.clear();
    }
    
    void checkIn(int id, string startStation, int t) {
        checkedIn[id] = {startStation, t};
    }
    
    void checkOut(int id, string endStation, int t) {
        pair<string, int> checkIn = checkedIn[id];
        string key = checkIn.first + "," + endStation;
        db[key].first += (t - checkIn.second);
        db[key].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "," + endStation;
        return (db[key].first / double(db[key].second));
    }
private:
    unordered_map<string, pair<int, int>> db;   // stores route -> totaltime, no. of trips;
    unordered_map<int, pair<string, int>> checkedIn;    // stores checkin details of a customer; id -> startStation, t1
};