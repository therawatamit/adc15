#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string dimensions;
    int totalarea=0;
    ifstream ReadInput("input");

    while (getline(ReadInput,dimensions)){
        istringstream splitstring(dimensions);
        string dim[3];
        int i=0;
        while (getline(splitstring,dim[i],'x'))
        {
            i++;
        }
        int a = stoi(dim[0]);
        int b = stoi(dim[1]);
        int c = stoi(dim[2]);
        totalarea+=2*(a*b+b*c+c*a);
        if(a>b){
            if(a>c){
                totalarea+=b*c;
            }
            else /*if(a<=c)*/{
                totalarea+=a*b;
            }
            
        }
        else/*if(a<=b)*/{
            if(b>c){
                totalarea+=a*c;
            }
            else/*if(b<=c)*/{
                totalarea+=a*b;
            }
        }
        
    }
    cout<<totalarea;
    return 0;
}