#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<vector<int>> reports;
    string report;
    ifstream reportsSource {"input.txt"};

    while (getline(reportsSource, report)) {
        vector<int> reportNums;
        int reportNum;
        istringstream reportLine {report};
        while (reportLine >> reportNum) {
            reportNums.emplace_back(reportNum);
        }
        reports.emplace_back(reportNums);
    }

    int safeReports = 0;

    for (vector<int> v : reports) {
        if (v.at(0) < v.at(v.size() - 1)) {
            for(unsigned int i = 1; i < v.size(); ++i) {
                int diffPrior = v.at(i) - v.at(i - 1);
                if ((diffPrior < 1) || (diffPrior > 3)) {
                    break;
                }
                if (i == v.size() - 1) ++safeReports;
            }
        }
        if (v.at(0) > v.at(v.size() - 1)) {
            for(unsigned int i = 1; i < v.size(); ++i) {
                int diffPrior = v.at(i) - v.at(i - 1);
                if ((diffPrior > -1) || (diffPrior < -3)) {
                    break;
                }
                if (i == v.size() - 1) ++safeReports;
            }
        }
    }

    cout << safeReports << endl;

    return 0;
}
