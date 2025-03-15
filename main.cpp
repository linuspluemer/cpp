#include <iostream>
#include <vector>
#include "startingFixture.h"
using namespace std;


//Gibt die Schedule aus
void printSchedule(vector<vector<int>> schedule) {
    for (int i = 0; i < schedule.size(); i++) {
        for (int j = 0; j < schedule[i].size(); j++) {
            cout << schedule[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

int n = 8;

vector<vector<int>> schedule = startingFixture(n, 0);



printSchedule(schedule);



return 0;

}







