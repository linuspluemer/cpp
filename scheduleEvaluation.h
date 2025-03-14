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
            for (int k = 0, k < (n-1); k++) {

                if (schedule[k][i] == schedule[(k+1)%(n-1)][j]) {
                    coeM[i][j]++;
                }
            }
        }
    }
    return coeM;
}




//Berechnet den weighted carry-over effect value eines gegebenen Spielplan
int coeValue(vector<vector<int>> coeM, int n, vector<vector<int>> weightMatrix) {
    
    int coeV = 0;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            coeV += coeM[i][j] * coeM[i][j] * weightMatrix[i][j];
        }
    }

    return coeV;

}


//Berechnet den ungewichteten carry-over effect value eines gegebenen Spielplan
int coeValue(vector<vector<int>> coeM, int n) {
    
    int coeV = 0;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            coeV += coeM[i][j] * coeM[i][j];
        }
    }

    return coeV;

}