#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> lehetosegek;



void szam(int v[], int n){

    int aux;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j]){
                aux = v[i];
                v[i]= v[j];
                v[j] = aux;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(v[i]<0){
            v[i]= abs(v[i]);
        }
    }

    int k=1, us =0;
    for(int i=0;i<n;i++){
        us = us*k+v[i];
        k=k*10;
    }

    int l=true;


    for(int j=0;j<lehetosegek.size();j++){
            if(lehetosegek[j] == us){
                l = false;
                break;
            }
        }

        if(l){
            lehetosegek.push_back(us);
            cout << us << " ";
        }

    return ;
}


void backtrack(int v[], int n, int start){
    if(start == n){
        return;
    }

    for(int i=start;i<n;i++){
        int tempv[n];
        for(int j=0;j<n;j++){
            tempv[j]=v[j];
        }
        tempv[i]=tempv[i]*(-1);
        int tempstart = start+1;
        szam(tempv,n);


        backtrack(tempv,n,tempstart);

    }

    return;

}

int main()
{
    ifstream in("input.txt");
    int n;
    in >> n;
    int v[n];
    for(int i=0;i<n;i++){
        in >> v[i];
    }

    int aux;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j]){
                aux = v[i];
                v[i]= v[j];
                v[j] = aux;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(v[i]<0){
            v[i]= abs(v[i]);
        }
    }

    int k=1, us =0;
    for(int i=0;i<n;i++){
        us = us*k+v[i];
        k=k*10;
    }

    lehetosegek.push_back(us);


    backtrack(v,n,0);
    cout << lehetosegek.size();

    return 0;
}
