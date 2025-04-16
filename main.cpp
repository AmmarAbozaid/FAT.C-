#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readFAT(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error: Cannot open FAT file!" << endl;
        return;
    }

    vector<unsigned short> FAT;
    unsigned short entry;

    while (file.read(reinterpret_cast<char*>(&entry), sizeof(entry))) {
        FAT.push_back(entry);
    }

    file.close();

    cout << "FAT Table Content:" << endl;
    for (size_t i = 0; i < FAT.size(); ++i) {
        cout << "Entry " << i << ": " << FAT[i] << endl;
    }
}

int main() {
    string filename;
    cout << "Enter FAT table file name: ";
    cin >> filename;

    readFAT(filename);
    return 0;
}
