#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int lt = 0;

int lepes_x[] = {0, -1, 1 };
int lepes_y[] = {1, 1, 1};


bool lehet( int jelen_x, int jelen_y, int n, int m, int index){

    if( jelen_x + lepes_x[index] <0 || jelen_x+lepes_x >= n ){
        return false;
    }

    return true;

}



void mx( vector<vector<int>> vect, int jelen_x, int jelen_y, int sum, int n, int m){

    if( jelen_y== m-1){

        if(lt < sum){
            sum = lt;
        }

        return;
    }


    for(int i=0; i< 3;i++){

        if( lehet(jelen_x, jelen_y, n, m, i) ){

            mx(vect, jelen_x+lepes_x[i], jelen_y+ lepes_y[i], sum+vect[jelen_x+lepes_x[i]][ jelen_y+ lepes_y[i]], n,m );
        }

    }

}


int main()
{

    ifstream in("input.txt");
    int n, m;
    in >> n >> m;
    vector<vector<int>> vect(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            in >> vect[i][j];
        }

    }


    for(int i=0;i <n;i++){

        mx( vect, i, 0, vect[i][0], n,m );

    }


    cout << lt;


    return 0;
}
