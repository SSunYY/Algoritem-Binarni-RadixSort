#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream input("vhod.txt");
    vector<unsigned char> A;
    int temp;
    while(input >> temp){
        if(temp >= 0 || temp <= 255){
            A.push_back(static_cast<unsigned char>(temp));
        }
    }
    input.close();

    ofstream output("izhod.txt");
    for(unsigned char i = 0; i < A.size(); i++){
        output << static_cast<int>(i) << " ";
    }
    output.close();
    
    return 0;
}