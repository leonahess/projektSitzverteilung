#include <string>
using namespace std;

#ifndef BUNDESTAGSWAHL_KLASSEN_H
#define BUNDESTAGSWAHL_KLASSEN_H
class wahl{
private:

public:
    wahl();
    ~wahl();
    string berechnungSitze(string partArray[][3], int anzahlSitze, int anzahlParteien);
    int eingabeAnzahlSitze();
    string eingabeNamePartei();
    int eingabeAnzahlStimmen(string namePartei);
    int eingabeAnzahlParteien();
    void ausgabeAnzahlSitze(string partArray[][3], int anzahlParteien);
};
#endif //BUNDESTAGSWAHL_KLASSEN_H
