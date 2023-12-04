#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{

    ifstream in("input.txt");
    ofstream of("output.txt");
    vector <int> v;
    int n,x, mx=0, nr=0;
    in >> n;
    for(int i=1;i<n+1;i++){
        in >> x;
        if(x==mx){
            nr++;
            v.push_back(i);
        } else if(x > mx){
            mx = x;
            nr = 1;
            v.clear();
            v.push_back(i);
        }
    }

    of<< mx << endl << nr << endl;
    for(int i=0;i<v.size();i++){
        of << v[i] << endl;
    }




    return 0;
}
