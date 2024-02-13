#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;


vector<int> vegso_tagok;
int mx = 0;


void   kor(int tagok_szerint[], int n, vector<int> tagok, int index){

    if( tagok_szerint[index] == tagok[0]  ){

        if(mx < tagok.size()){
            mx = tagok.size();
            vegso_tagok = tagok;
        }

        return;
    }


    for(int i=1;i<tagok.size();i++){

        if( tagok_szerint[index] == tagok[i] ){
            return;
        }

    }


    tagok.push_back(tagok_szerint[index]);
    index = tagok_szerint[index];
    kor(tagok_szerint, n, tagok, index);


}

int main()
{
    ifstream in("input.txt");
    int n;
    in >> n;
    int tagok_szerint[n];
    int x;
    for(int i=0;i<n;i++){
        in >> x;
        x--;
        tagok_szerint[i] = x;

    }

    vector<int> temp;


    for(int i=0;i<n;i++){
        kor(tagok_szerint, n, temp, i);

    }

    cout << mx << '\n';

    for(int i=0;i<vegso_tagok.size();i++){

        cout << vegso_tagok[i] << " ";
    }



    return 0;
}
