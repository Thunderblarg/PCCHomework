#include <iostream>
#include <fstream>

using namespace std;

// int sumCounter(int target){
//     int sum = 0;
    
//     for(int idx = 0; idx < target; idx++){
//         sum += idx;
//     }
//     return sum;
// }

// char htoc(int ch){
    
// }

int main(){
    // std::cout << "607: " << sumCounter(607) << std::endl;
    fstream fin;
    char* input = "pad.txt";
    fin.open(input);

    while(!fin.eof()){
        char h[3];
        fin.ignore(2);
        fin.getline(h, 3, ',');

        int c = stoi(h, nullptr, 16);
        cout << (char)c;
    }
    cout << endl;
}