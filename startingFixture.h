    #include <iostream>
    #include <vector>
    using namespace std;


    //berechnet a(k,l) in der Polygon Method
    int polyA(int k, int l, int n) {
        if (k + l < n) {
            return(k + l);
        } else {
            return(k + l + 1 - n);
        }
    }


    //berechnet b(k,l) in der Polygon Method
    int polyB(int k, int l, int n) {
        if (k - l > 0) {
            return(k - l);
        } else {
            return(k - l - 1 + n);
        }
    }


    //Erstellen einer Starting Fixture nach der Polygon Method
    vector<vector<int>> polygonMethod(int n) {
        
        //Matrix der richtigen Größe wird initialisiert
        vector<vector<int>> schedule(n-1,vector<int>(n));

        //Variablen um Werte a(k,l) und b(k,l) zu speichern
        int a = 0;
        int b = 0;

        //Matrix wird ausgefüllt
        for (int k = 0; k < n-1; k++) {
            
            schedule[k][k] = n - 1;
            schedule[k][n - 1] = k;
            
            for (int l = 0; l < (n/2 - 1); l++) {
                a = polyA(k + 1,l + 1,n) - 1;
                b = polyB(k + 1,l + 1,n) - 1;
                schedule[k][a] = b;
                schedule[k][b] = a;
                }
        }
        return(schedule);
    }


    // Berechnet c(k,l) in der Methode von de Werra
    int deWerraC(int k, int l, int n) {
        return((k + l - 2) % (n / 2) + (n / 2) + 1);
    }


    // Erstellen einer Starting Fixture nach der Methode von de Werra
    vector<vector<int>> deWerraMethod(int n) {

        //Matrix der richtigen Größe wird initialisiert
        vector<vector<int>> schedule(n-1,vector<int>(n));

        // Zum speichern von c(k,l)
        int c = 0;

        // Die ersten n/2 Runden werden ausgefüllt
        for (int k = 0; k < (n / 2); k++) {
            for (int l = 0; l < (n / 2); l++) {
                c = deWerraC(k + 1, l + 1, n) - 1;
                schedule[k][l] = c;
                schedule[k][c] = l;
            }
        }

        vector<vector<int>> factorization = polygonMethod(n/2);

        //Die hinteren n/2 Runden werden ausgefüllt
        for (int i = 0; i < (n / 2) - 1; i++) {
            for (int j = 0; j < (n / 2); j++) {
                schedule[i + (n / 2)][j] = factorization[i][j];
                schedule[i + (n / 2)][j + (n / 2)] = factorization[i][j] + (n/2);
            }
        }
        return(schedule);
    }

    //Erstellt eine Starting Fixture. n ist Anzahl der Teams, auswahl = 0 für Polygon Methode, auswahl = 1 für deWerra Methode
    vector<vector<int>> startingFixture(int n, int a) {

        //return(polygonMethod(n));

        if (a == 0) {
            return(polygonMethod(n));
        } else if (a == 1) {
            return(deWerraMethod(n));
        } 
        vector<vector<int>> leer(n-1, vector<int>(n, 0));
        return leer;
    }