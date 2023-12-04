#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    int n, m,x,y;
    in >> n >> m;
    int v[n+1][n+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            v[i][j]=0;
        }
    }

    for(int i=0;i<m;i++){
        in >> x >> y;
        v[x][y]=1;
        v[y][x]=1;
    }
    vector<int> zsakfalu;
    int nr =0;
    for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(v[i][j]==1){
                    nr++;
                }
            }
            if(nr==1){
                zsakfalu.push_back(i);
            }
            nr=0;

    }


    vector<int> faluk;
    int z,p;
    nr=0;
    for(int i=0;i<zsakfalu.size();i++){
        z = zsakfalu[i];
        for(int j=1;j<n+1;j++){
            if(v[z][j]==1){
                y=j;
                faluk.push_back(y);
                break;
            }
        }
        while(nr<2){
              nr =0;
            for(int j=1;j<n+1;j++){
                if(v[y][j]==1){
                    nr++;
                    p=j;
                }
            }

                y = p;
                faluk.push_back(y);


        }
    }

    cout << faluk.size() << endl;
    for(int i=0;i<faluk.size();i++){
        cout << faluk[i] << " ";
    }

    return 0;
}
