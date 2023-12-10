#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    int x=0, y=0, k, a;
    in >> k;
    for(int i=0;i<k;i++){
        in >> a;
        if(a==0){
            y++;
            x = x*2;
        }
        if(a==1){
            y++;
            x = x*2+1;
        }
        if(a==2){
            y--;
            x = x/2;

        }
        if(a==3){
            x--;
        }
        if(a==4){
            x++;
        }
    }

    cout << y << endl;

    int ht=1, nr=0;
    while(x>0){
        nr = (x%2)*ht+nr;
        ht*=10;
        x/=2;
    }
    cout << nr;

    return 0;
}
