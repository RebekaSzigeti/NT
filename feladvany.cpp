#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int sj_sz(int a){

    int cnt = 0;
    while(a>0){
        cnt++;
        a/=10;
    }

    return cnt;

}

int main()
{
    int a, b, k;
    ifstream in("input.txt");

    int x, y;


    for(int i=0;i<3;i++){

        in >> a >> b >> k;
        if(k<sj_sz(a) || k < sj_sz(b)){
            cout << "-1"<< '\n';
        }
         x= a;
         y = b;

         int lkkt;

         while(x!=y){

            if(x>y){
                x = x-y;
            } else {
                y = y -x;
            }

         }




    }


    return 0;
}
