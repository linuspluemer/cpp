#include <iostream>
#include <vector>
#include <chrono>
#include "startingFixture.h"
#include "scheduleEvaluation.h"


//Gibt die Schedule aus
void printSchedule(std::vector<std::vector<int>> schedule) {
    for (int i = 0; i < schedule.size(); i++) {
        for (int j = 0; j < schedule[i].size(); j++) {
            std::cout << schedule[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {

    int n = 8;
    int a = 0;

    const auto start{std::chrono::steady_clock::now()};
    std::vector<std::vector<int>> schedule = startingFixture(n, a);
    const auto finish{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{finish - start};

    //vector<vector<int>> coeM = coeMatrix(schedule, n);

    int coeV = coeValue(schedule, n);

    std::cout << "Der Algorithmus lief " << elapsed_seconds.count() << "s\n";
    std::cout << "Der Cross-Over Wert des erstellten Spielplans ist: " << coeV << '\n';

    return 0;

}