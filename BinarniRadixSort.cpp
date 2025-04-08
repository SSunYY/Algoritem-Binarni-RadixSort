
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream input("vhod.txt");
    if(!input.is_open()){
        cout << "Error: napaka pri pisanju podatkov.";
        return 1;
    }
    vector<unsigned char> A;
    int temp;
    while(input >> temp){
        if(temp >= 0 || temp <= 255){
            A.push_back(static_cast<unsigned char>(temp));
        }
    }
    input.close();
    

    for(int k = 0; k < 8; k++){
        vector<int> C(2, 0);
        vector<unsigned char> D(A.size());

        for(size_t i = 0; i < A.size(); i++){
            int bit = (A[i] >> k) & 1;
            C[bit++];
        }

        C[1] += C[0];
        for(int i = A.size() - 1; i >= 0; i--){
            int bit = (A[i] >> k) & 1;
            D[--C[bit]] = A[i];
        }

        swap(A, D);
    }

    ofstream output("izhod.txt");
    if(!output.is_open()){
        cerr << "Error: napaka pri branju v izhodno datoteko." << endl;
        return 1;
    }
    for(unsigned char i = 0; i < A.size(); i++){
        output << static_cast<int>(i) << " ";
    }
    output.close();

    return 0;
}