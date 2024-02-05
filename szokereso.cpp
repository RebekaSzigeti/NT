#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

vector<char> l;

int index_1, index_2;


int x_lepes = {1, 0, -1, 0 }
int y_lepes = { 0, -1, 0, 1 }


bool lehet( int x, int y, int n, int index){


    if( x+ x_lepes[index]<0 || x+x_lepes[index] >=n ){

        return false;
    }

    if(y + y_lepes[index] <0 || y + y_lepes[index] >=n){
        return false;
    }

    return true;

}


void szo(vector<string> vect, int x, int y, int k, vector<char> ut , int t , int n, string keresett, int index1, index2){


    if(ut.size() == t){

        l = ut;
        index_1 = index1;
        index_2 = index2;


        return;
    }


    for(int i=0;i<4;i++){

        if(lehet(x,y, n,i ) && vect[x+x_lepes[i] ][ y+y_lepes[i] ] == keresett[k]){

            vector<char> temput;
            temput = ut;

            if(i==0){
                temput.push_back('F');
            }

            if(i==1){
                temput.push_back('B');
            }

            if(i==2){
                temput.push_back('L');
            }

            if(i==3){
                temput.push_back('J');
            }

            szo(vect, x+x_lepes[i], y+y_lepes[i], k+1, temput, t, n, keresett);


        }
    }


}


int main()
{


    int n;
    ifstream in("input.txt");
    in >> n;
    vector<string> vect;

    for(int i=0;i<n;i++){
        string temp;
        in >> temp;
        vect[i] = temp;

    }


    string keresett;
    in >> keresett;
    int t= keresett.size();

    if(l.size() == 0){

        cout << 0 << " " << 0 << '\n';
        for(int i=0;i<l.size();i++){
            cout << l[i] << " ";
        }

    }



}
