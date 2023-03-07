#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

string text_input1, text_input2, text_error, text_hsl, text5, text_ulang, ulang, bilangan[2], prosedur;
float nilai1, nilai2, hasil;

void text(){
    // text mengambil dari file .txt
    // link file saya upload di github https://github.com/RibyImanuel/tugas-alpro
    ifstream myfile;
    myfile.open("text_1.txt");
    getline(myfile,text_input1);
    getline(myfile,text_input2);
    getline(myfile,text_error);
    getline(myfile,text_hsl);
    getline(myfile,text_ulang);
}

void kalkulator(){
    atas:
    text();
    //user input bilangan 1
    cout << text_input1;
    cin >> bilangan[0];
    //user input prosedur
    cout << text_input2;
    cin >> prosedur;
    //user input bilangan 2
    cout << text_input1;
    cin >> bilangan[1];

    cout << endl;

    //Mengubah string ke float
    stringstream(bilangan[0]) >> nilai1;
    stringstream(bilangan[1]) >> nilai2;

    //perhitungan dan output
    if (bilangan[0]!="0" && nilai1==0 || bilangan[1]!="0" && nilai2==0 ) {
        system ("cls");
        cout << text_error << endl;
        goto atas;
    }else if (prosedur=="x") {
        hasil = nilai1 * nilai2;
        system ("cls");
        cout << text_hsl << nilai1 << " " << prosedur << " " << nilai2 << " = " << hasil; 
    } else if (prosedur=="/") {
        hasil = nilai1 / nilai2;
        system ("cls");
        cout << text_hsl << nilai1 << " " << prosedur << " " << nilai2 << " = " << hasil; 
    } else if (prosedur=="+") {
        hasil = nilai1 + nilai2;
        system ("cls");
        cout << text_hsl << nilai1 << " " << prosedur << " " << nilai2 << " = " << hasil; 
    } else if (prosedur=="-") {
        hasil = nilai1 - nilai2;
        system ("cls");
        cout << text_hsl << nilai1 << " " << prosedur << " " << nilai2 << " = " << hasil;
    } else {
        system ("cls");
        cout << text_error << endl;
        goto atas;
    }

    cout << endl << text_ulang;
    cin >> ulang;

    //untuk kembali mengulang kalkulator
    if (ulang=="ya") {
        system ("cls");
        goto atas;
    } else {
        system ("cls");
    }
}

main(){
    //menampilkan hasil output
    kalkulator();
    return 0;
}