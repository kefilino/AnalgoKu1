/*
 * Nama     : Kefilino Khalifa Filardi
 * NPM      : 140810180028
 * Kelas    : B
 * Program  : Gale Shapley Stable Matching Problem Program
 * Tanggal  : 3 Maret 2020
 * Desc     : Program ini menggunakan algoritma Gale Shapley untuk memecahkan masalah Stable Matching Problem.
 */

#include <iostream>
using namespace std;

bool isFree(char match[5]) {
    for (int i = 0; i < 5; i++) {
        if (match[i] == '\0')
            return true;
    }
    return false;
}

bool hasProposed(int proposal[5]) {
    for (int i = 0; i < 5; i++) {
        if (proposal[i] != 5)
            return false;
    }
    return true;
}

void fungsiGS(int pref[][5], char match[5]) {
    int proposal[5] = {0}; // Jumlah wanita yang telah dilamar
    int taken[5] = {-1}; // Wanita ke-i taken oleh siapa

    while (isFree(match) && !hasProposed(proposal)) {
        for (int i = 0; i < 5; i++) {
            if (match[i] == '\0') {

            }
        }
    }
}

int main()
{
    //Profil preferensi pria
    const int mpp[5][5] = {
        {1, 0, 3, 4, 2},
        {3, 1, 0, 2, 4},
        {1, 4, 2, 3, 0},
        {0, 3, 2, 1, 4},
        {1, 3, 0, 4, 2}
    };
    char match[5] = {'\0'}; //Pasangan dari pria
    
}