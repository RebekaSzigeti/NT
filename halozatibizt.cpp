#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int mx = 0;
vector<int> csomopontok;


void halmaz(vector<vector<int>>& vect, int n, int jelen, vector<int> jelen_halmaz, int k){

    if( jelen_halmaz.size()==n){
        csomopontok = jelen_halmaz;
        mx = n;

    }

    if(jelen_halmaz.size()>mx){
        mx = jelen_halmaz.size();
        csomopontok = jelen_halmaz;

    }

    int cnt = 0;

    for(int i=0;i<n;i++){

        if(vect[jelen][i]==1){
            cnt++;
        }

    }

    bool megfelel;

    if(cnt >=k){

        for(int i=0;i<n;i++){
            megfelel = true;
            for(int j=0;j<jelen_halmaz.size();j++){
                if(i== jelen_halmaz[j]){
                    megfelel = false;
                }

            }

            if(megfelel){
            vector<int> temphalmaz = jelen_halmaz;
            temphalmaz.push_back(i);
            halmaz(vect,n,i,temphalmaz, k);

            }


        }

    }



}

int main()
{

    ifstream in("input.txt");
    int n ,m,k;
    in >> n >> m >> k;
    vector<vector<int>> vect(n, vector<int> (n,0));
    int x,y;

    for(int i=0;i<m;i++){

        in >> x >> y;
        vect[x-1][y-1] = 1;
        vect[y-1][x-1] = 1;


    }

    vector<int> pontok;

    for(int i=0;i<n;i++){

        int cnt = 0;
        for(int j=0;j<n;j++){
            cnt+= vect[i][j];
        }

        if(cnt >=k){
            pontok.push_back(i);
        }

    }


    for(int i=0;i<pontok.size();i++){

        if(pontok[i] != -1){
        vector<int> temp;
        temp.push_back(pontok[i]);

        halmaz(vect, n, pontok[i], temp, k);

        for(int j=0;j<csomopontok.size();j++){

            for(int t=0;t<pontok.size();t++){
                if( pontok[t]==csomopontok[j]){

                    pontok[t] = -1;
                }
            }
        }
        }


    }

    cout << mx << '\n';
    for(int i=0;i<csomopontok.size();i++){
        cout << csomopontok[i] << " ";

    }



    return 0;
}
