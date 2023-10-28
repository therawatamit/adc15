#include <iostream>
#include <string>
#include "md5.h"
#include <cstring>

using namespace std;

int main(){
string inp_str = "yzbqklnj";
string test;
int i =0;
while (1){
    cout<<"current integer:"<<i<<endl;
    test=inp_str + to_string(i);
    if(GetMD5String(test).substr(0,5) == "00000"){
        break;
    }
    i++;
}

cout<<test;

return 0;
}