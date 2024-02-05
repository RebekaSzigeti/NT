#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    string x;
    in >> x;
    bool a= false, c = false, g = false, t = false;

    int mx = 0;
    int cnt =0, index = 0;

    for(int i=0;i<x.size();i++){

        if( x[i]=='A' ){
            a= true;
        }

        if(x[i] == 'C'){

            c = true;
        }

        if(x[i] == 'G'){

            g = true;
        }

        if( x[i] == 'T' ){

            t = true;
        }


        if(a && c && g && t){
            cnt = i-index+1;
            if(cnt > mx){
                mx = cnt;
            }
            cnt = 0;
            a =false, c = false , g = false, t = false;

        }

    }

    a =false, c = false , g = false, t = false;

    for(int i= x.size()-1;i>=0;i--){

         if( x[i]=='A' ){
            a= true;
        }

        if(x[i] == 'C'){

            c = true;
        }

        if(x[i] == 'G'){

            g = true;
        }

        if( x[i] == 'T' ){

            t = true;
        }


        if(a && c && g && t){
            cnt = x.size() - i;
            if(cnt > mx){
                mx = cnt;
            }

        }
    }

    cout << mx;


    return 0;
}
