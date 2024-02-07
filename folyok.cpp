#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int mx = 0;
vector<int> utvonalak;


bool bennevan( vector<int> ut, int index){

    for(int i=0;i< ut.size();i++){

        if(ut[i]== index){
            return true;
        }

    }

    return false;
}


void max_lenght(vector<vector<int>> vect, vector<int> ut, int sum, int index, int n ){

    bool van = false;
    for(int i=0;i <n;i++){
        if( vect[index][i] >0 && !bennevan(ut, i)  ){
            van = true;
            vector<int> temput;
            temput = ut;
            temput.push_back(i);
            max_lenght(vect, temput, sum+vect[index][i], i, n);

        }


    }

    if(!van){
        return;
    }


}

int main()
{

    int n, x, y, t
    ifstream in("input.txt");
    in >> n;
    vector<vector<int>> vect( n, vector<int> (n,0));
    for(int i=0;i<n-1;i++){
        in >> x >> y >> t;

        vect[x-1][y-1] = t;
        vect[y-1][x-1] = t;
    }

    vector<int> indexek;

    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(vect[i][j]>0){
                cnt++;
            }

        }

        if(cnt==1){
            indexek.push_back(i);
        }


    }

    for(int i=0;i<indexek.size();i++){
        vector<int>temp;


    }





    return 0;
}
