#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// H�m gcd
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// H�m t?m ngh?ch �?o modulo
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1; // kh�ng t?n t?i
}

// H�m m? h�a Affine: E(x) = (a*x + b) mod 26
string affineEncrypt(const string &plaintext, int a, int b) {
    string result = "";
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char up = toupper(ch);
            int x = up - 'A';
            int y = (a * x + b) % 26;
            result += char(y + 'A');
        }
    }
    return result;
}

// H�m gi?i m? Affine: D(y) = a?�*(y - b) mod 26
string affineDecrypt(const string &ciphertext, int a, int b) {
    string result = "";
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        return "L?i: a kh�ng c� ngh?ch �?o modulo 26!";
    }
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char up = toupper(ch);
            int y = up - 'A';
            int x = (a_inv * (y - b + 26)) % 26;
            result += char(x + 'A');
        }
    }
    return result;
}

int main() {
    string text;
    int a, b;
    int choice;

    cout << "===== MA HOA AFFINE CIPHER =====\n";
    cout << "Nhap van ban (chu cai): ";
    getline(cin, text);

    cout << "Nhap khoa a (nguyen to cung nhau voi 26): ";
    cin >> a;
    cout << "Nhap khoa b: ";
    cin >> b;

    if (gcd(a, 26) != 1) {
        cout << "Loi: a phai nguyen to cung nhau voi 26!\n";
        return 0;
    }

    cout << "Chon che do (1 = Ma hoa, 2 = Giai ma): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Ban ma: " << affineEncrypt(text, a, b) << endl;
    } else {
        cout << "Ban ro: " << affineDecrypt(text, a, b) << endl;
    }

    return 0;
}
