#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n,m,x,y,nr=0;
    in >> n >> m;
    int indul[n], vegez[n], sorrend[n];
    for(int i=0;i<n;i++){
        in >> x;
        indul[i] = x;
        in >> x;
        vegez[i]=x;
    }
    for(int i=0;i<n;i++){
        sorrend[i]=i+1;
    }
    int aux;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           if( vegez[i]<vegez[j]){
                aux = vegez[i];
                vegez[i]=vegez[j];
                vegez[j]=aux;

                aux = sorrend[i];
                sorrend[i]=sorrend[j];
                sorrend[j]=aux;

                aux = indul[i];
                indul[i]=indul[j];
                indul[j]=aux;


           }

        }
    }

    y=1;
    int prev_y;

    while(y!=m){
         prev_y=y;
        for(int i=0;i<n;i++){
            if(y>=indul[i]){
                y = vegez[i];
                v.push_back(sorrend[i]);
                nr++;
                break;
            }
        }
        if(prev_y==y){
            break;
        }
    }

    if(y==prev_y){
        cout << -1;
    } else {
        cout << nr-1 << endl;
        for(int i=0;i<v.size();i++){
            cout << v[i] << endl;
        }

    }







    return 0;
}
