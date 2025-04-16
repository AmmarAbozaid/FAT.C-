
#include <iostream>
 #include <fstream>
 #include <vector>
 using namespace std;
 vector<int> readFAT(const string&
filename)
 {
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "Error opening a file FAT!" <<
endl;
        exit(1);
    }
    vector<int> fatTable;
 int entry;
    while
(file.read(reinterpret_cast<char*>(&entry),
sizeof(entry)))
    {
    }
        fatTable.push_back(entry);
    file.close();
    return fatTable;
 }
 void analyzeFAT(const vector<int>&
fatTable)
 {
    cout << "table analysis FAT:\n";
 vector<bool> visited(fatTable.size(),
false);
    for (size_t i = 0; i < fatTable.size(); ++i)
    {
        if
        {
(!visited[i] && fatTable[i] != -1)
            cout << " File starts in the block: "
<< i << " -> ";
            size_t next = i;
            while (next != -1 && !visited[next])
            {
                cout << next << " ";
 visited[next] = true;
                next = fatTable[next];
            }
            cout << "[EOF]\n";
        }
    }
 }
 int main()
 {
    string filename = "fat_table.bin";
    vector<int> fatTable =
readFAT(filename);
 analyzeFAT(fatTable);
    return 0;
