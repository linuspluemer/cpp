#include <iostream>
#include <vector>
#include <random>
#include <numeric>

/*
*   Gibt die Gewichtungsmatrix zu einem Vector mit Gewichten zurück. Dabei können zwei unterschiedliche Teams 
*   nicht den Unterschied 0 haben.
*
*   @param std::vector<int> Vector mit den Gewichten der Teams
*   @param int Anzahl der Teams
*
*   @return Gewichtungsmatrix
*/
std::vector<std::vector<int>> fillOutWeightM(std::vector<int> weights, int n) {
    using namespace std;

    vector<vector<int>> weightM(n, vector<int>(n));

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
        
            // Damit in der Gewichtungsmatrix keine Werte = 0 sind (außer auf der Diagonalen)
            if (weights[i] == weights[j] && i != j) {
                weightM[i][j] = 1;
            } else {
                weightM[i][j] = abs(weights[i] - weights[j]);
            }

        }
    }
    return weightM;
}


/*
*   Erstellt eine zufällige Gewichtungsmatrix mit Gewichten zwischen 1 und 2n
*
*   @param int Anzahl der Teams
*
*   @return Gewichtungsmatrix
*/
std::vector<std::vector<int>> randomInstance(int n) {
    using namespace std;

    vector<vector<int>> weightM(n, vector<int>(n));

    //Wir benutzen diesen Seed, da mit random_device immer die selben Matrizen erstellt wurden
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 generator(seed);

    int min = 1;
    int max = 2*n;

    uniform_int_distribution<int> distribution(min,max);

    vector<int> weights(n);

    for (int i = 0; i<n; i++) {
        weights[i] = distribution(generator);
    }

    weightM = fillOutWeightM(weights, n);

    return weightM;
}


/*
*   Gibt eine Gewichtungsmatrix mit festgelegten Gewichten 1 bis n zurück
*
*   @param int Anzahl der Teams
*
*   @return Gewichtungsmatrix
*/
std::vector<std::vector<int>> linearInstance(int n) {
    using namespace std;

    vector<vector<int>> weightM(n, vector<int>(n));
    vector<int> weights(n);
    iota(weights.begin(), weights.end(), 1);

    weightM = fillOutWeightM(weights, n);

    return weightM;
}


/*
*   Gibt eine Gewichtungsmatrix mit linearen Gewichten die zufällig um einen Wert zwischen -n/2 und n/2 verändert
*   wurden zurück
*
*   @param int Anzahl der Teams
*
*   @return Gewichtungsmatrix
*/
std::vector<std::vector<int>> perturbedLinearInstance(int n) {
    using namespace std;

    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 generator(seed);

    int min = -(n/2);
    int max = (n/2);

    uniform_int_distribution<int> distribution(min,max);

    vector<vector<int>> weightM(n, vector<int>(n));
    vector<int> weights(n);
    iota(weights.begin(), weights.end(), 1);

    for (int i = 0; i<n; i++) {
        weights[i] = abs(weights[i] + distribution(generator));
        cout << weights[i];
    }
    cout << '\n';

    weightM = fillOutWeightM(weights, n);

    return weightM;
}