#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;


struct rod{

    int hossz, value;
    double ertek_1m;
    int sorszam;


};


int sum =0;
vector<int> sorszamok;
vector<int> mennyisegek;


void  minvalue( rod rods[], int n, int m, int index, int lenght  ){


    if( lenght == m ){

        return;
    }

    if( index == n ){

        sorszamok.clear();
    }

    int hozzad;

    if( rods[index].hossz <= m-lenght ){

        hozzaad = (m-lenght)/rods[index].hossz;
        sorszamok.push_back( rods[index].sorszam );
        mennyisegek.push_back( hozzaad);
        sum+= hozzaad*rods[index].value;

        lenght+= hozzaad*rods[index].hossz;


        minvalue(rods, n, m, index+1, lenght);

    }



}



int main()
{

   ifstream in("input.txt");
   int n, m;
   in >> n >> m;

   rod rods[n];


   for(int i=0;i<n;i++){

        in >> rods[i].hossz >> rods[i].value;
        rods[i].ertek_1m = rods[i].hossz/rods[i].value;
        rods[i].sorszam = i+1;

   }

   for(int i=0;i<n;i++){

    for(int j=i+1;j<n;j++){

        if(rods[i].ertek_1m > rods[j].ertek_1m ){
            swap(rods[i], rods[j] );

        }

    }

   }


   minvalue( rods[], n, m, 0 ,0  );


   if(sorszamok.size() == 0){

        cout << "-1";

   } else {

       cout << sum << '\n';

        cout << sorszamok.size() << '\n';

        for(int i=0;i<sorszamok.size();i++){

            cout << sorszam[i] << " " << mennnyisegek[i] << '\n';
        }


   }






    return 0;
}
