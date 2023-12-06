#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    int n, k;
    in >> n >>k;
    int v[n];
    for(int i=0;i<n;i++){
        in >> v[i];
    }

    int s =0,y=0, mn,mx, cnt = 0;
    int p[k];


    for(int i=0;i<n-k+1;i++){
        s=0;
        y=0;
        cnt = 0;
         for(int j=0;j<k;j++){
        p[j]=0;
    }
        for(int j=i;j<i+k;j++){
            p[y] = v[j];
            y++;

        }

        mx = 0;
        for(int j=1;j<k;j++){
            if( p[j] > p[0]-j){
                if(mx == 0){
                    mx = p[j]+j;
                } else {
                    if(p[j]+j> mx){
                        mx = p[j]+j;
                    }
                }
            }
        }
        if(mx == 0){

            for(int j=1;j<k;j++){
                cnt = cnt + p[0]-j-p[j];

            }


        } else {
            cnt = cnt + mx - p[0];
            p[0] = mx;

            for(int j=1;j<k;j++){
                cnt = cnt + p[0]-j-p[j];


            }


        }
        if(i==0){
            mn = cnt;
        } else {
            if(cnt < mn){
                mn = cnt;
            }
        }



    }

    cout << mn;


    return 0;
}
