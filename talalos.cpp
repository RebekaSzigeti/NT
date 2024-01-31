#include <iostream>
#include <fstream>
#include <vector>
#include<limits.h>

using namespace std;

int main()
{

    ifstream in("input.txt");
    int n;
    in >> n;
    vector<vector<int>> vect(2*n+1, vector<int>(2*n+1, INT_MAX) );
    int x, y;
    for(int i=0;i<n;i++){

        in >> x >> y;
        vect[i][x-1]  =1;
        vect[x-1][i] = 1;
        vect[i][y-1] = -1;
        vect[y-1][i] = -1;
    }

    for(int i=0;i<2*n+1;i++){

        vect[i][i] = 0;
    }

    for(int k=0;k<2*n+1;k++){
        for(int i=0;i<2*n+1;i++){
            for(int j=0;j<2*n+1;j++){

                if(vect[i][k]!= INT_MAX && vect[k][j] != INT_MAX && vect[i][k] + vect[k][j] < vect[i][j]  ){
                    vect[i][j] = vect[i][k] + vect[k][j];
                }

            }

        }
    }


    vector<int> osszegek, elofordulas;


    for(int i=0;i<2*n+1;i++){

        int index;
        bool elofordul = false;
        for(int j=0;j<osszegek.size();j++){

            if(vect[0][i]==osszegek[j]){
                elofordul = true;
                index = j;
                j = osszegek.size() + 1;
            }
        }

        if(elofordul){
            elofordulas[index]++;
        } else {

            osszegek.push_back(vect[0][i]);
            elofordulas.push_back(1);
        }


    }


    int mx =0 ertek;

    for(int i=0; i<elofordulas.size();i++){
        if(elofordulas[i]>mx){
            mx = elofordulas[i];
            ertek = osszegek[i];
        }
    }

    cout << ertek << " "<< mx << '\n';




    return 0;
}
