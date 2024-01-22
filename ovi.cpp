#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


struct gyerek{

    int szerep_szam, siras, sorszam;

};

int main()
{

    int n, k;
    ifstream in("input.txt");
    in >> n >> k;
    int szerepek[k];
    for(int i=0;i<k;i++){
        in >> szerepek[i];
    }

    gyerek gyerekek[n];
    for(int i=0;i<n;i++){
        in >> gyerekek[i].szerep_szam;
        gyerekek[i].sorszam = i+1;

    }

    for(int i=0;i<n;i++){
        in >> gyerekek[i].siras;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(gyerek[i].siras < gyerek[j].siras){
                swap(gyerekek[i],gyerekek[j]);
            }
        }
    }


    int cnt=0;

    for(int i=0;i<n;i++){
        if( szerepek[gyerekek[i].szerep_szam-1]>0 ){
            szerepek[gyerekek[i].szerep_szam-1]--;
            gyerekek[i].siras = 0;

        }
    }

    for(int i=0;i<n;i++){
        cnt+= gyerekek[i].siras;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(gyerek[i].sorszam > gyerek[j].sorszam){
                swap(gyerekek[i],gyerekek[j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        if( gyerekek[i].siras>0)
{
        for(int i=0;i<k;i++){
            if(szerepek[i]>0){
                gyerekek[i].szerep_szam = i+1;
                szerepek[i]--;
            }
        }
}
    }

    //kiiratod gyerek_szerep






    return 0;
}
