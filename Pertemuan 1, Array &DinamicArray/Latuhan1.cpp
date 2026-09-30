#include <iostream>
using namespace std;

int main(){
        //Deklarasi
    int array[3][3][4];
        
    int angka = 2;

    //mengisi array dengan bil.ganjil
    for (int i =0; i < 3; i++ ){
        for (int j=0; j < 3; j++){
            for (int k=0; k < 4; k++){
                array[i][j][k] = angka;
                angka +=  2;
            }
        } 
    }

    //Menampilkan array
    for (int i = 0; i < 3; i++){
        cout << "Lapis " << i+1 << endl;

        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 4; k++){
                cout << array[i][j][k] << "\t"; 
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;

}