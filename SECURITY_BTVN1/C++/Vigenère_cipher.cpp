#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Hàm chuẩn hóa key để dài bằng văn bản
string generateKey(string text, string key) {
    int n = text.size();
    string fullKey = "";
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (isalpha(text[i])) {
            fullKey += toupper(key[j % key.size()]);
            j++;
        } else {
            fullKey += text[i]; // giữ nguyên ký tự không phải chữ
        }
    }
    return fullKey;
}

// Mã hóa Vigenere
string encryptVigenere(string text, string key) {
    string fullKey = generateKey(text, key);
    string result = "";
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            char ch = toupper(text[i]);
            char k = fullKey[i];
            char c = ((ch - 'A') + (k - 'A')) % 26 + 'A';
            result += c;
        } else {
            result += text[i];
        }
    }
    return result;
}

// Giải mã Vigenere
string decryptVigenere(string cipher, string key) {
    string fullKey = generateKey(cipher, key);
    string result = "";
    for (int i = 0; i < cipher.size(); i++) {
        if (isalpha(cipher[i])) {
            char c = toupper(cipher[i]);
            char k = fullKey[i];
            char p = ((c - 'A') - (k - 'A') + 26) % 26 + 'A';
            result += p;
        } else {
            result += cipher[i];
        }
    }
    return result;
}

int main() {
    string text, key;
    int choice;

    cout << "===== MA HOA VIGENERE CIPHER =====\n";
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa (chuoi ky tu): ";
    cin >> key;

    cout << "Chon che do (1 = Ma hoa, 2 = Giai ma): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Ban ma: " << encryptVigenere(text, key) << endl;
    } else {
        cout << "Ban ro: " << decryptVigenere(text, key) << endl;
    }

    return 0;
}
