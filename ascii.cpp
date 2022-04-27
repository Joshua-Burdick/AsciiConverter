#include <iostream>
#include <map>

using namespace std;

int main() {

    // The ASCII Table does NOT include the Extended ASCII Codes (128-255)

    string characters[33] = {"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "TAB", "LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US", "Space"};
    string symbolsA[15] = {"!", "\"", "#", "$", "%", "&", "\'", "(", ")", "*", "+", ",", "-", ".", "/"};
    string numbers[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    string symbolsB[7] = {":", ";", "<", "=", ">", "?", "@"};
    string uppercase[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    string symbolsC[6] = {"[", "\\", "]", "^", "_", "`"};
    string lowercase[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k"," l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    string symbolsD[5] = {"{", "|", "}", "~", "DEL"};

    // The ASCII Table
    map<std::string, int> m {};

    // Populate the ASCII Table
    for (int i = 0; i < 33; i++) {
        m[characters[i]] = i;
    }
    for (int i = 33; i < 48; i++) {
        m[symbolsA[i - 33]] = i;
    }
    for (int i = 48; i < 58; i++) {
        m[numbers[i - 48]] = i;
    }
    for (int i = 58; i < 65; i++) {
        m[symbolsB[i - 58]] = i;
    }
    for (int i = 65; i < 91; i++) {
        m[uppercase[i - 65]] = i;
    }
    for (int i = 91; i < 97; i++) {
        m[symbolsC[i - 91]] = i;
    }
    for (int i = 97; i < 123; i++) {
        m[lowercase[i - 97]] = i;
    }
    for (int i = 123; i < 128; i++) {
        m[symbolsD[i - 123]] = i;
    }

    string type;

    do {
        cout << "Search by Key or Value?: ";
        cin >> type;
        type = type;

        if (type == "k" || type == "K") {
            string key;
            cout << "Enter key: ";
            cin >> key;

            try {
                cout << key << ": " << m[key] << endl << endl;
            }
            catch (exception e) {
                cout << e.what() << endl << endl;
            }
        }
        else if (type == "v" || type == "V") {
            int val;
            cout << "Enter value: ";
            cin >> val;

            for (auto &it : m) {
                if (it.second == val) cout << val << ": " << it.first << endl << endl;
            }
        }
        else if (type == "quit" || type == "QUIT" || type == "Quit") break;
        else cout << "Error! Search type \'" << type << "\' is not a valid type!" << endl << endl;
    } while (type != "quit");

    return 0;
}