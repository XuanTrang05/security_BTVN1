#include <bits/stdc++.h>
using namespace std;

string toUpperLetters(const string &s) {
    string t;
    for(char ch: s) if(isalpha((unsigned char)ch)) t.push_back(toupper(ch));
    return t;
}

string caesar_encrypt(const string &pt, int k) {
    string s = toUpperLetters(pt);
    for(char &c: s) c = char('A' + (c - 'A' + k) % 26);
    return s;
}

string caesar_decrypt(const string &ct, int k) {
    return caesar_encrypt(ct, (26 - (k % 26)) % 26);
}

int main() {
    string text;
    int k, mode;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa k (0..25): ";
    cin >> k;
    cout << "1) Ma hoa  2) Giai ma: ";
    cin >> mode;

    if(mode==1) cout << "Ciphertext: " << caesar_encrypt(text, k) << "\n";
    else cout << "Plaintext: " << caesar_decrypt(text, k) << "\n";
    return 0;
}
