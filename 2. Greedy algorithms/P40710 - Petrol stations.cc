#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using VI = vector<int>;

int n;
VI fuel_stations;

int calc_stops(int x, int D) {
    int P, i, stops;
    P = i = stops = 0;
    while (P + x < D) {
        while (i < n-1 and fuel_stations[i + 1] <= P + x) ++i;
        P = fuel_stations[i];
        ++stops;
    }
    return stops;
}

int main() {
    int x, D;
    while (cin >> x >> D >> n) {
        fuel_stations = VI (n);
        for (int& fs : fuel_stations) cin >> fs;
        sort(fuel_stations.begin(), fuel_stations.end());
        
        int stops = calc_stops(x, D);
        cout << stops << endl;
    }
}
