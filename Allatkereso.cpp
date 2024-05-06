#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Allat {
    string faj;
    string nev;
    int kor;
    string szin;
};
istream &operator>>(istream &stream, Allat &a) {
    stream >> a.faj >> a.nev >> a.kor >> a.szin;
    return stream;
}
ostream& operator<<(ostream& stream, Allat& a) {
    stream << a.faj << " " << a.nev << " " << a.kor << " " << a.szin << endl;
    return stream;
}
int main() {
    fstream adatb;
    adatb.open("allatok.txt", ios::in); // Állatokat tartalmazó fájl
    if (!adatb) {
        cerr << "Hiba: a fajl megnyitasa allatok.txt" << endl;
        return 1;
    }
    vector<Allat> allatok;
    Allat allat;
    while (adatb >> allat) {
        allatok.push_back(allat);
    }
    allatok.shrink_to_fit();

    cout << "Milyen adat alapjan keressuk az allatot? \nValasszon eggyet: (faj/nev/kor/szin)\n";
    string filter;
    int korertek;
    string masertek;
    cin >> filter;
    transform(filter.begin(), filter.end(), filter.begin(), ::toupper);
    if (filter == "KOR") {
        cin >> korertek;
    } else {
        cin >> masertek;
    }
    transform(masertek.begin(), masertek.end(), masertek.begin(), ::toupper);
    bool finding = false; // Az új változó neve: finding
    switch (filter[0]) {
        case 'F':
            for (int i = 0; i < allatok.size(); i++) {
                transform(allatok[i].faj.begin(), allatok[i].faj.end(), allatok[i].faj.begin(), ::toupper);
                if (allatok[i].faj == masertek) {
                    cout << allatok[i];
                    finding = true;
                }
            }
            if (!finding) {
                cout << "Nincs ilyen allat a fajlban" << endl;
            }
            break;
        case 'N':
            for (int i = 0; i < allatok.size(); i++) {
                transform(allatok[i].nev.begin(), allatok[i].nev.end(), allatok[i].nev.begin(), ::toupper);
                if (allatok[i].nev == masertek) {
                    cout << allatok[i];
                    finding = true;
                }
            }
            if (!finding) {
                cout << "Nincs ilyen allat a fajlban" << endl;
            }
            break;
        case 'K':
            for (int i = 0; i < allatok.size(); i++) {
                if (allatok[i].kor == korertek) {
                    cout << allatok[i];
                    finding = true;
                }
            }
            if (!finding) {
                cout << "Nincs ilyen allat a fajlban" << endl;
            }
            break;
        case 'S':
            for (int i = 0; i < allatok.size(); i++) {
                transform(allatok[i].szin.begin(), allatok[i].szin.end(), allatok[i].szin.begin(), ::toupper);
                if (allatok[i].szin == masertek) {
                    cout << allatok[i];
                    finding = true;
                }
            }
            if (!finding) {
                cout << "Nincs ilyen allat a fajlban " << endl;
            }
            break;
    }
    adatb.close();
    return 0;
}