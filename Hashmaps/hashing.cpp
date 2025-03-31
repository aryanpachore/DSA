#include <iostream>
using namespace std;

const int CHAR_SIZE = 256; // For all ASCII characters

void characterHashing(const string& str) {
    int hash[CHAR_SIZE] = {0};

    // Calculate frequency of each character
    for (char ch : str) {
        hash[ch]++;
    }

    // Display the hash values
    cout << "Character Frequency:" << endl;
    for (int i = 0; i < CHAR_SIZE; i++) {
        if (hash[i] > 0) {
            cout << (char)i << ": " << hash[i] << endl;
        }
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str; // Using cin instead of getline

    characterHashing(str);

    return 0;
}