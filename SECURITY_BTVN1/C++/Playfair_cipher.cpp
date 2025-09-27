#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

char matrix[5][5];

// Tạo ma trận khóa 5x5 từ keyword
void generateMatrix(string key) {
    bool used[26] = {false};
    key += "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // gộp chữ cái (J = I)
    int row = 0, col = 0;

    for (char &c : key) {
        c = toupper(c);
        if (c == 'J') c = 'I'; 
        if (!used[c - 'A']) {
            matrix[row][col] = c;
            used[c - 'A'] = true;
            col++;
            if (col == 5) {
                col = 0;
                row++;
            }
            if (row == 5) break;
        }
    }
}

// Tìm vị trí ký tự trong ma trận
pair<int,int> findPos(char c) {
    if (c == 'J') c = 'I';
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            if (matrix[i][j] == c) return {i,j};
        }
    }
    return {-1,-1};
}

// Chuẩn hóa văn bản thành cặp
string prepareText(string text, bool forEncrypt=true) {
    string result="";
    for (char c: text) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            result += c;
        }
    }
    if (forEncrypt) {
        string fixed="";
        for (size_t i=0;i<result.size();i++) {
            fixed += result[i];
            if (i+1<result.size() && result[i]==result[i+1]) fixed+='X';
        }
        if (fixed.size()%2!=0) fixed+='X';
        return fixed;
    }
    return result;
}

// Mã hóa Playfair
string encryptPlayfair(string text) {
    text = prepareText(text, true);
    string cipher="";
    for (size_t i=0;i<text.size();i+=2) {
        auto p1=findPos(text[i]);
        auto p2=findPos(text[i+1]);
        if (p1.first==p2.first) { // cùng hàng
            cipher += matrix[p1.first][(p1.second+1)%5];
            cipher += matrix[p2.first][(p2.second+1)%5];
        } else if (p1.second==p2.second) { // cùng cột
            cipher += matrix[(p1.first+1)%5][p1.second];
            cipher += matrix[(p2.first+1)%5][p2.second];
        } else { // hình chữ nhật
            cipher += matrix[p1.first][p2.second];
            cipher += matrix[p2.first][p1.second];
        }
    }
    return cipher;
}

// Giải mã Playfair
string decryptPlayfair(string cipher) {
    cipher = prepareText(cipher, false);
    string plain="";
    for (size_t i=0;i<cipher.size();i+=2) {
        auto p1=findPos(cipher[i]);
        auto p2=findPos(cipher[i+1]);
        if (p1.first==p2.first) { 
            plain += matrix[p1.first][(p1.second+4)%5];
            plain += matrix[p2.first][(p2.second+4)%5];
        } else if (p1.second==p2.second) {
            plain += matrix[(p1.first+4)%5][p1.second];
            plain += matrix[(p2.first+4)%5][p2.second];
        } else {
            plain += matrix[p1.first][p2.second];
            plain += matrix[p2.first][p1.second];
        }
    }
    return plain;
}

int main() {
    string key,text;
    int mode;

    cout<<"===== PLAYFAIR CIPHER =====\n";
    cout<<"Nhap khoa: ";
    getline(cin,key);
    generateMatrix(key);

    cout<<"Nhap van ban: ";
    getline(cin,text);

    cout<<"Chon che do (1=Ma hoa, 2=Giai ma): ";
    cin>>mode;

    if (mode==1) {
        cout<<"Ban ma: "<<encryptPlayfair(text)<<endl;
    } else {
        cout<<"Ban ro: "<<decryptPlayfair(text)<<endl;
    }
    return 0;
}
