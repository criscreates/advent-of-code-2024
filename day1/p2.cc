#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>

using namespace std;

int similarityScore(vector<int> l1, vector<int> l2) {
    if (l1.size() != l2.size()) throw logic_error("The lists are not the same size.");
    vector<int> l2_copy = l2;
    int similarityScore = 0;
    for (unsigned int i = 0; i < l1.size(); ++i) {
        for (vector<int>::iterator it = l2_copy.begin(); it != l2_copy.end(); ++it) {
            if (*it < l1.at(i)) {
                l2_copy.erase(it);
            }
            if (*it == l1.at(i)) {
                similarityScore += *it;
            }
            if (*it > l1.at(i)) break;
        }
    }
    return similarityScore;
}

int main() {
    vector<int> l1;
    vector<int> l2;
    int i1;
    int i2;
    ifstream file {"day1input.txt"};
    while (file >> i1 >> i2) {
        l1.emplace_back(i1);
        l2.emplace_back(i2);
    }
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());

    try {
        cout << similarityScore(l1, l2) << endl;
    } catch (const logic_error& e) {
        cout << "Logic error occurred: " << e.what() << endl;
    }

    return 0;
}
