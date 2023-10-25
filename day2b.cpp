#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string dimensions;
    int totalfeet=0;
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
        totalfeet+=a*b*c;
        if(a>b){
            if(a>c){
                totalfeet+=2*(b+c);
            }
            else /*if(a<=c)*/{
                totalfeet+=2*(a+b);
            }
            
        }
        else/*if(a<=b)*/{
            if(b>c){
                totalfeet+=2*(a+c);
            }
            else/*if(b<=c)*/{
                totalfeet+=2*(a+b);
            }
        }
        
    }
    cout<<totalfeet;
    return 0;
}