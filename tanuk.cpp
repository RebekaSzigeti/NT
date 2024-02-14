#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> min_tanuk;
vector<int> erintett_max_gyanus;


void tanu (int erkezesek[], int tavozasok[], int gyanus_pillanatok[], int n, int m, vector<int> tanuk, vector<int> erinett_gyanus_esetek, int index){

    if(index == n){


        if(erinett_gyanus_esetek.size() > erintett_max_gyanus.size()){
            erintett_max_gyanus = erinett_gyanus_esetek;
            min_tanuk = tanuk;

        }

        if(erintett_max_gyanus.size() == erinett_gyanus_esetek.size() && min_tanuk.size() > tanuk.size()){
            min_tanuk = tanuk;
            erintett_max_gyanus = erinett_gyanus_esetek;

        }

        return;


    }



    tanu(erkezesek, tavozasok, gyanus_pillanatok, n, m, tanuk, erinett_gyanus_esetek, index+1);


    int volt = false;

    for(int i=0;i<m;i++){

        if(erkezesek[index] <= gyanus_pillanatok[i] && tavozasok[index] >=  gyanus_pillanatok[i]){

            if(!volt){

                tanuk.push_back(index);
                volt = true;


            }

            auto it = find(erinett_gyanus_esetek.begin(), erinett_gyanus_esetek.end(), i);

            if(it==erinett_gyanus_esetek.end()){

                erinett_gyanus_esetek.push_back(i);

            }


        }



    }


    tanu(erkezesek, tavozasok, gyanus_pillanatok, n, m, tanuk, erinett_gyanus_esetek, index+1);



}



int main()
{

    ifstream in("input.txt");
    int n, m;
    in >> n >> m;
    int erkezes[n], tavozas[n];
    for(int i=0;i<n;i++){

        in >> erkezes[i] >> tavozas[i];
    }

    int gyanus_pillanatok[m];
    for(int i=0;i<m;i++){
        in >> gyanus_pillanatok[i];
    }

    vector<int> temp1, temp2;

    tanu(erkezes, tavozas, gyanus_pillanatok, n, m, temp1, temp2, 0 );

    cout << erintett_max_gyanus.size() << '\n';
    cout << min_tanuk.size() << '\n';

    for(int i=0;i<min_tanuk.size();i++){

        cout << min_tanuk[i] << " ";
    }







    return 0;
}
