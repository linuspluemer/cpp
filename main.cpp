#include <iostream>
#include <vector>
#include "startingFixture.h"
#include "scheduleEvaluation.h"
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
int a = 1;


vector<vector<int>> schedule = startingFixture(n, a);
vector<vector<int>> coeM = coeMatrix(schedule, n);


printSchedule(schedule);
cout << '\n';
printSchedule(coeM);


int coeV = coeValue(schedule, n);


return 0;

}







