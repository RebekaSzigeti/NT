#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    int m, k, n, a, b,x;
    in >> m >> x;
    in >> a >> b >> n >> k;
    int v[n];
    int cnt=0, nr, szj, w;
    int h[4*m], hatv=1;


    while(cnt < n){
        nr = x*a+b;
        for(int i=0;i<4*m;i++){
            h[i]=0;
        }
        w=0;
        while(nr>0){
            szj = nr%10;
            h[w] = szj;
            w++;
            nr = nr/10;
        }

        x=0;
        hatv = 1;
        for(int i=m;i<3*m;i++){
            x=h[i]*hatv+x;
            hatv*=10;
        }

        v[cnt]=x;
        cnt++;

    }



    int min_tav= -1;

    for(int i=0; i<n;i++){

        for(int j=i+1; j<n;j++){
            if(v[i]==v[j]){
                if(min_tav == -1){
                    min_tav = j-i;
                } else {
                    if(min_tav > j-i){
                        min_tav = j-i;
                    }
                }

            }

        }
    }

    cout << min_tav << endl;
    int aux;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j]){
                aux = v[i];
                v[i]=v[j];
                v[j] = aux;
            }
        }
    }

    cout << v[k];

    return 0;
}
