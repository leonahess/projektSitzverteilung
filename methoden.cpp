#include <iostream>
#include <string>
#include "klassen.h"
#include <iomanip>


using namespace std;

void quickSort(int arr[][2], int left, int right) {
    int i = left, j = right;
    int tmp = 0,tmp2 = 0;
    int pivot = arr[(left + right) / 2][0];

    /* partition */
    while (i <= j) {
        while (arr[i][0] > pivot)
            i++;
        while (arr[j][0] < pivot)
            j--;
        if (i <= j) {
            tmp = arr[i][0];
            tmp2 = arr[i][1];
            arr[i][0] = arr[j][0];
            arr[i][1] = arr[j][1];
            arr[j][0] = tmp;
            arr[j][1] = tmp2;

            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

wahl::wahl() {

}

wahl::~wahl() {

}

int wahl::eingabeAnzahlSitze() {
    int anzahlSitze;
    do {
        cout << "Wie viele Sitze sind zu vergeben: \n";

        if(cin >> anzahlSitze){
            //hat geklappt => raus aus der schleife
            break;
        }else if(!cin.bad() && !cin.eof()){
            cerr << "Bitte nur Zahlen eingeben! \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while(cin);
    return anzahlSitze;
}

string wahl::eingabeNamePartei() {
    string namePartei;
    cout << "Bitte gib den Namen der Partei ein: ";
    cin >> namePartei;
    return namePartei;
}

int wahl::eingabeAnzahlStimmen(string namePartei) {
    int anzahlStimmen;
    do {
        cout << "Wie viele Stimmen hat die Partei mit dem Namen " << namePartei << ": \n";

        if(cin >> anzahlStimmen){
            //hat geklappt => raus aus der schleife
            break;
        }else if(!cin.bad() && !cin.eof()){
            cerr << "Bitte nur Zahlen eingeben! \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while(cin);
    return anzahlStimmen;
}

int wahl::eingabeAnzahlParteien() {
    int anzahlParteien;
    do {
        cout << "Wie Parteien haben Stimmen erhalten: \n";

        if(cin >> anzahlParteien){
            //hat geklappt => raus aus der schleife
            break;
        }else if(!cin.bad() && !cin.eof()){
            cerr << "Bitte nur Zahlen eingeben! \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while(cin);
    return anzahlParteien;
}

string wahl::berechnungSitze(string partArray[][3], int anzahlSitze, int anzahlParteien) {

    //array der länge der Anzahl der Sitze * der anzahl der parteien erzeugen, mit zwei zeilen
    int table[anzahlParteien * anzahlSitze][2];

    //divisor und zähler initialisieren
    int divisor = 1;
    int z = 0;

    //table array mit höchstzahlen und parteinummer befüllen
    for(int i = 0; i < anzahlSitze; i++) {
       for(int l = 0; l < anzahlParteien; l++){
           table[z+l][0] = atoi(partArray[l][1].c_str())/ divisor;
           table[z+l][1] = l + 1;
       }

        //divisor und zähler erhöhen
        z = z + anzahlParteien;
        divisor++;
    }

    /***DEBUG***
    //array ausgeben für debug
    cout << endl;
    for(int o = 0; o < anzahlSitze * anzahlParteien; o++){
        cout << table[o][0] << " | ";
        cout << table[o][1] << endl;
    }cout << endl << endl;
    ***DEBUG***/


    //array absteigend sortieren (nimmt die parteinummern mit)
    quickSort(table, 0, anzahlParteien * anzahlSitze-1);


    /***DEBUG***
    //sortiertes array ausgeben für debug
    for(int o = 0; o < anzahlSitze; o++){
        cout << table[o][0] << " | ";
        cout << table[o][1] << endl;
    }cout << endl << endl;
    ***DEBUG***/


    //anzahl der sitze für jede partei aus dem sortierten array abzählen und in partArrays dritte Zeile schreiben
    int p = 1;
    for(int k = 0; k < anzahlParteien; k++){
        for(int t = 0; t < anzahlSitze; t++){
            if(table[t][1] == p)
                partArray[k][2] = to_string(atoi(partArray[k][2].c_str()) + 1);
        }
        p++;
    }

    // volles partArray wieder an die main function übergeben
    return partArray[anzahlParteien][3];
}

void wahl::ausgabeAnzahlSitze(string partArray[][3], int anzahlParteien) {

    //Gibt das array partArray als Tabelle aus
    cout << setw(20) << "Name der Partei:" << setw(20) << "Anzahl der Stimmen:" << setw(20) << "Anzahl der Sitze:" << endl;
    for(int i = 0; i < anzahlParteien; i++){
        cout << setw(20) << partArray[i][0] << setw(20) << partArray[i][1] << setw(20) << partArray[i][2] << endl;
    }

    return;
}