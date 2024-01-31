#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int mx=0;

int index_1, index_2;

void lcs( vector<int> vect, int x, int y, int cnt, int n){

    vector<int> v(y-x+1);
    copy(vect.begin()+x, vect.begin()+y, v.begin());

    for(int i=0;i<n-y+x-1;i++){

        int k=0;
        bool same = true;

        for(int j=i;j<y-x+1;j++){

            if(v[k]!=vect[j]){

                same = false;
                j=n;
            }
            k++;
        }

        if(same){
            cnt++;
        }
    }

    if(cnt <= mx){

        return;
    } else {

    index_1 = x;
    index_2 = y;
        lcs(vect, x, y+1,cnt, n);
    }


}

int main()
{

    ifstream in("input.txt");
    int n;
    in >> n;
    vector<int> vect(n);

    for(int i=0;i<n;i++){
        in >> vect[n];
    }

    for(int i=0;i <n;i++){

        lcs(vect, i, i, 1, n);
    }

    for(int i=index_1;i<=index_2;i++){
        cout << vect[i] << " ";
    }



    return 0;
}
