 #include <iostream>
 #include <vector> 

using namespace std;



//Berechnet die coe Matrix zu einem Spielplan, Eintrag i,j sind die Nummer der coe die Team i an Team j gibt
vector<vector<int>> coeMatrix(vector<vector<int>> schedule, int n) {
    
    vector<vector<int>> coeM(n, vector<int>(n, 0));
    
    //Iteration über Teams i,j
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {

            //Iteration über Runden k
            for (int k = 0; k < (n-1); k++) {

                if (schedule[k][i] == schedule[(k+1)%(n-1)][j]) {
                    coeM[i][j]++;
                }
            }
        }
    }
    cout << "Größe von coeM vor Rückgabe von coeM " << coeM.size() << " * " << coeM[0].size() << '\n';
    return coeM;
}




//Berechnet den weighted carry-over effect value eines gegebenen Spielplan
int coeValue(vector<vector<int>> schedule, int n, vector<vector<int>> weightMatrix = {}) {
    
    vector<vector<int>> coeM = coeMatrix(schedule, n);

    cout << "Größe von coeM nach zuweisung in coeValue " << coeM.size() << " * " << coeM[0].size() << '\n';
    cout << "Größe von n in coeValue " << n << '\n';

    int coeTest = 0;
    int coeV = 0;
    int weight = 1;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            weight = (weightMatrix.empty()) ? 1 : weightMatrix[i][j];
            coeV += coeM[i][j] * coeM[i][j] * weight;
            coeTest += coeM[i][j];
        }
        cout << "Zeile " << i << " fertig. coeV ist: " << coeV << '\n';
    }
    cout << coeTest << '\n';
    cout << coeV << '\n';

    return coeV;

} 

