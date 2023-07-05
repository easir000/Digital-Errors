
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

char chr(int i) {
    return 'a' + i;
}

string encodeString(const string& s) {
    unordered_map<char, int> lastOccurrence;
    string encoded;

    for (char c : s) {
        int count = lastOccurrence.count(c);
        lastOccurrence[c] = count;

        int mapping = lastOccurrence.size() - count - 1;
        encoded.push_back(chr(mapping));
    }

    return encoded;
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string encodedString = encodeString(s);
    cout << encodedString << endl;

    return 0;
}
