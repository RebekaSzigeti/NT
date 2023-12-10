#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");

    int n;
    in >> n;
    int cnt=0, m = n;
    while(m>1){
        if(m%2==1){
            cnt++;
        }
        m=m/2;
    }

   int mn=n-1, mx = n+1;
   int k = mn, nr=0;

   while(mn >=1){
    k=mn;
    nr =0;
        while(k>1){
            if(k%2==1){
            nr++;
        }
            k=k/2;
        }

    if(nr == cnt){
        break;
    }

    mn--;

   }

   bool t = true;

   while(t){
    k=mx;
    nr =0;
        while(k>1){
            if(k%2==1){
            nr++;
        }
        if(nr>cnt){
            k=0;
        }
            k=k/2;
        }

    if(nr == cnt){
        t = false;
    }
    mx++;

   }

   cout << mn << endl;
   cout << mx-1<<endl;


    return 0;
}
