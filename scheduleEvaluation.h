 #include <iostream>
 #include <vector> 

/*
*   Berechnet die Cross-Over Effect Matrix 
*   
*   @param vector<vector<int>> Spielplan
*   @param int Anzahl der Teams
*
*   @return Cross-Over Effect Matrix
*/
std::vector<std::vector<int>> coeMatrix(std::vector<std::vector<int>> schedule, int n) {
    using namespace std;
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
    return coeM;
}




/*
*   Berechnet den (gewichteten) Cross-Over Effect Wert eines Spieplans
*
*   @param vector<vector<int>> Spielplan
*   @param int Anzahl der Teams
*   @param vector<vector<int>> Gewichtungsmatrix (optional)
*
*   @return (Gewichteter) Cross-Over Effect Wert 
*/
int coeValue(std::vector<std::vector<int>> schedule, int n, std::vector<std::vector<int>> weightMatrix = {}) {
    
    using namespace std;

    vector<vector<int>> coeM = coeMatrix(schedule, n);

    int coeV = 0;
    int weight = 1;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            weight = (weightMatrix.empty()) ? 1 : weightMatrix[i][j];
            coeV += coeM[i][j] * coeM[i][j] * weight;
        }
    }
    return coeV;
} 

