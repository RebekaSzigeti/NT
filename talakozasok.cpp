#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct vendeg{

    int erkezes, tavozas;
    int talalkozott;
};

int main()
{
    ifstream in("input.txt");
    int n;
    in >> n;
    vendeg vendegek[n];
    for(int i=0;i<n;i++){

        in >> vendegek[i].erkezes;
        in >> vendegek[i].tavozas;
    }

    for(int i=0;i<n;i++){

        int cnt = 0;
        for(int j=0;j<n;j++){

            if(i!=j){

                if( vendegek[i].erkezes <= vendegek[j].erkezes && vendegek[j].erkezes <= vendegek[i].tavozas ){
                    cnt++;
                } else if( vendegek[i].erkezes >= vendegek[j].erkezes && vendegek[i].erkezes <= vendegek[j].tavozas ){

                    cnt++;
                }


            }


        }

        vendegek[i].talalkozott = cnt;


    }


    int mx =0, sorszam;

    for( int i=0;i<n;i++ ){

        if(vendegek[i].talalkozott > mx){
            mx = vendegek[i].talalkozott;
            sorszam = i+1;
        }

    }

    cout << sorszam << '\n' << mx;




    return 0;
}
