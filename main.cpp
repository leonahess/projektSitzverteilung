#include <iostream>
#include <string>
#include "klassen.h"
#include <unistd.h>

using namespace std;

int main() {
    //Objekt der Klasse 'wahl'
    wahl partei;

    //initialisierung der Variablen
    int     anzahlParteien;
    int     anzahlSitze;

    //Eingabe der Variablen über objekt partei
    anzahlSitze = partei.eingabeAnzahlSitze();
    anzahlParteien = partei.eingabeAnzahlParteien();

    //Exceptions
    if(anzahlParteien == 0) {
        cerr << "!FATAL ERROR!" << endl;
        sleep(1);
        cerr << "!SHUTTING DOWN!" << endl;
        sleep(1);
        cerr << "3" << endl;
        sleep(1);
        cerr << "2" << endl;
        sleep(1);
        cerr << "1" << endl;
        sleep(1);
        cerr << "0" << endl;
        exit(EXIT_FAILURE);
    }
    if(anzahlParteien == 1) {
        cout << "Diktator much? Die eine Partei erhält natürlich alle Sitze!";
        exit(EXIT_SUCCESS);
    }

    //initialisierung eines ausreichend großem arrays
    /*                      0   1   2   3 ...
     * namePartei         0
     * stimmenPartei      1
     * sitzePartei        2
     */
    string partArray[anzahlParteien][3];

    cout << endl;

    //befüllung der ersten zeile des arrays mit den parteinamen
    for(int i = 0; i < anzahlParteien; i++){
        partArray[i][0] = partei.eingabeNamePartei();
    }

    cout << endl;

    //befüllung der der zweiten zeile des arrays mit den stimmen die die parteien erhalten haben
    for(int i = 0; i < anzahlParteien; i++){
        partArray[i][1] = to_string(partei.eingabeAnzahlStimmen(partArray[i][0].c_str()));
    }

    //berechnung der Sitze pro partei
    partei.berechnungSitze(partArray, anzahlSitze, anzahlParteien);

    /***DEBUG***
    //PartArray ausgeben für debug
    for(int o = 0; o < anzahlParteien; o++){
        cout << partArray[o][0] << " | ";
        cout << partArray[o][1] << " | ";
        cout << partArray[o][2] << endl;
    }cout << endl << endl;
    ***DEBUG***/

    //ausgabe der ergebnisse über objekt partei
    partei.ausgabeAnzahlSitze(partArray, anzahlParteien);

    return 0;
}