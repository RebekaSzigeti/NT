#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 4294967296;
    vector<int> x;

    while(n>0){
        x.push_back(n%2);
        n=n/2;
    }


    vector<int> y;
    for(int i=0;i<x.size();i++){
        y.push_back(x[i]);
    }

    int j=0;
    while(y[j]!=0 && y[j+1]!=1){
        j++;
    }

    int aux = y[j];
    y[j] = y[j+1];
    y[j+1] = aux;

    int hatv=1, nr =0;

    for(int i=0;i<y.size();i++){
        nr = nr + hatv*y[i];
        hatv = hatv*2;
    }

    cout << nr;

    return 0;
}
