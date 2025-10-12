#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using namespace std;

struct pelajaran {
    string namamapel,kodemapel;
    
};

pelajaran create_pelajaran(string namamapel, string kodemapel);
void tampil_pelajaran(pelajaran pel);

#endif