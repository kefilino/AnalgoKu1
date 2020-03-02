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

bool isFree(int match[5]) {
    for (int i = 0; i < 5; i++) {
        if (match[i] == -1)
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

bool prefers(int wpref[][5], int w, int m1, int m2) {
    int m1idx = -1, m2idx = -1;
    for (int i = 0; i < 5; i++) {
        if (wpref[w][i] == m1)
            m1idx = i;
        else if (wpref[w][i] == m2)
            m2idx = i;
    }
    if (m1idx < m2idx)
        return true;
    else
        return false;
}

void fungsiGS(int mpref[][5], int wpref[][5], int match[5]) {
    int proposal[5] = {0}; // Jumlah wanita yang telah dilamar
    int taken[5] = {-1, -1, -1, -1, -1}; // Wanita ke-i taken oleh siapa

    while (isFree(match) && !hasProposed(proposal)) {
        for (int i = 0; i < 5; i++) {
            if (match[i] == -1) {
                int temp = mpref[i][proposal[i]]; // Preferensi wanita dari pria saat ini
                if (taken[temp] == -1) {
                    match[i] = temp;
                    taken[temp] = i;
                } else if (prefers(wpref, temp, i, taken[temp])) {
                    match[taken[temp]] = -1;
                    match[i] = temp;
                    taken[temp] = i;
                }
            }
            proposal[i]++;
        }
    }
}

void print(int match[], int size) {
    cout << "Hasil Dari Stable Matching : " << endl;
    for (int i = 0; i < size; i++) {
        cout << "(" << (char)(i + 86) << ", " << (char)(match[i] + 65) << ")" << endl;
    }
}

int main()
{
    //Profil preferensi pria
    int mpp[5][5] = {
        {1, 0, 3, 4, 2},
        {3, 1, 0, 2, 4},
        {1, 4, 2, 3, 0},
        {0, 3, 2, 1, 4},
        {1, 3, 0, 4, 2}
    };
    //Profil preferensi wanita
    int wpp[5][5] = {
        {4, 0, 1, 3, 2},
        {2, 1, 3, 0, 4},
        {1, 2, 3, 4, 0},
        {0, 4, 3, 2, 1},
        {3, 1, 4, 2, 0}
    };
    int match[5] = {-1, -1, -1, -1, -1}; //Pasangan dari pria
    fungsiGS(mpp, wpp, match);
    print(match, sizeof(match)/sizeof(match[0]));
}