#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// M? h�a b?ng ho�n v? c?t
string encryptTransposition(string text, string key) {
    int col = key.length();
    int row = (text.length() + col - 1) / col;
    vector<vector<char>> table(row, vector<char>(col, 'X')); // padding = X

    // �i?n v�n b?n v�o b?ng theo h�ng
    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (k < text.length()) {
                table[i][j] = text[k++];
            }
        }
    }

    // T?o th? t? c?t theo key
    vector<pair<char,int>> order;
    for (int i = 0; i < col; i++) order.push_back({key[i], i});
    sort(order.begin(), order.end());

    // �?c theo c?t �? s?p x?p
    string cipher = "";
    for (auto p : order) {
        int j = p.second;
        for (int i = 0; i < row; i++) {
            cipher += table[i][j];
        }
    }
    return cipher;
}

// Gi?i m? b?ng ho�n v? c?t
string decryptTransposition(string cipher, string key) {
    int col = key.length();
    int row = (cipher.length() + col - 1) / col;

    // Th? t? c?t
    vector<pair<char,int>> order;
    for (int i = 0; i < col; i++) order.push_back({key[i], i});
    sort(order.begin(), order.end());

    // Chu?n b? b?ng r?ng
    vector<vector<char>> table(row, vector<char>(col, ' '));

    // �i?n theo c?t �? s?p x?p
    int k = 0;
    for (auto p : order) {
        int j = p.second;
        for (int i = 0; i < row; i++) {
            if (k < cipher.length())
                table[i][j] = cipher[k++];
        }
    }

    // �?c l?i theo h�ng
    string plain = "";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (table[i][j] != 'X') plain += table[i][j];
        }
    }
    return plain;
}

int main() {
    string text, key;
    int mode;

    cout << "===== MA HOA HOAN VI (COLUMNAR) =====\n";
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa (chuoi ky tu): ";
    cin >> key;

    cout << "Chon che do (1 = Ma hoa, 2 = Giai ma): ";
    cin >> mode;

    if (mode == 1) {
        cout << "Ban ma: " << encryptTransposition(text, key) << endl;
    } else {
        cout << "Ban ro: " << decryptTransposition(text, key) << endl;
    }

    return 0;
}
