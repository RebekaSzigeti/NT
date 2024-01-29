#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<vector<int>> utvonalak;


int mindist( int spt[], int dist[], int n){

    int min_index, mn = INT_MAX;

    for(i=0;i<n;i++){

        if(spt[i]==false && dist[i]!= INT_MAX && dist[i] < mn){

            mn = dist[i];
            mn_index = i;
        }

    }

    return min_index;

}

int legh;


int dijkstra( vector<vector<int>> vect, int n, int src){


    utvonalak.clear();
    int dist[n];
    bool spt[n];

    for(int i=0;i<n;i++){
        spt[i]=false;
        dist[i]= INT_MAX;
    }

    dist[0]= 0;

    for(int cnt =0;cnt<k-1;k++){

        int u = mindist( spt, dist, n  );

        spt[u] = true;

        for(int v=0;v<n;v++){

            if(spt[v] == false && vect[u][v] > 0 && dist[u] != INT_MAX && vect[u][v]+dist[u]<dist[v]  ){

                dist[v] = dist[u] + vect[u][v];
                utvonalak[v] = utvonalak[u];
                utvonalak[v].push_back(v);

            }


        }

    }

    int mx = 0, index;

    for(int i=1;i<n;i++){

        if( dist[i]>mx){

            mx = dist[i];
            index = i;
            legh = mx;
        }
    }

    return index;


}




int main()
{

    ifstream in("input.txt");
    int n, k;
    in >> n >> k;
    vector<vector<int>> vect(n, vector<int> (n,0));
    int x,y;
    for(int i=1;i<n;i++){

       in >> x >> y;
       vect[x-1][i]=y;
       vect[i][x-1]=y;

    }

    int index, index_1, index_2;
    int a , b;

    while(k!=0){


        index = dijkstra(vect, n, 0);
        int mx=0;

        for(int i=0;i<utvonalak[index].size()-1;i++){
            a = utvonalak[index][i];
            b= utvonalak[index][i+1];

            if( vect[a][b] > mx ){
                mx = vect[a][b];
                index_1 = a;
                index_2 = b;
            }



        }

        vect[index_1][index_2]= 0;
         k--;




    }


    cout << legh;

    return 0;
}
