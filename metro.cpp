#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>

using namespace std;


int mindist(bool spt[], int dist[], int m){

    int mn = INT_MAX, min_index;

    for(int i=0;i<m;i++){

        if(!spt[i] && dist[i] < mn){
            mn = dis[i];
            min_index = i;
        }
    }

    return min_index;

}

int main()
{
    ifstream in("input.txt");
    int n, m, ind, erk;
    in >> n >> m >> ind >> erk;
    vector<vector<int>> vect(m, vector<int> (m, 0));
    int x,y ;

    for(int i=0;i<n;i++){
        in >> x;
        int k[x];
        for(int j=0;j<x;j++){
            in >> k[j];
        }

        for(int j=0;j<x;j++){
            for(int l=0;l<x;l++){
                vect[k[j]-1][k[l]-1]=i+1;
            }
        }

    }

    /*for(int i=0;i<m;i++){
        vect[i][i] = 0;
    }*/

    int dist[m];
    bool spt[m];
    set<int> indexek;

    for(int i=0;i<m;i++){
        dist[i] = INT_MAX;
        spt[i] = false;
    }

    spt[ind-1] = true;

    for(int i=0;i<m-1;i++){

        int u = mindist(spt, dist, m);
        spt[u] = true;

        for(int v=0;v<m;v++){

            if(!spt[v] && vect[u][v]>0 && dist[u] != INT_MAX && 1+dist[u] < dist[v]){
                dist[v] = 1+dist[u];
                indexek.insert(vect[u][v]);

            }

        }

    }

    cout << dist[erk];

    cout << '\n';
    for(int i=0;i<indexek.size();i++){
        cout << indexek[i];
    }




    return 0;
}
