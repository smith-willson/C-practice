#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Function to generate SQL INSERTs from a CSV
void csvToSQL(const string& csvFile, const string& tableName) {
    ifstream infile(csvFile);
    if (!infile.is_open()) {
        cerr << "Cannot open file: " << csvFile << endl;
        return;
    }

    string line, header;
    getline(infile, header); // Skip header line

    int recordCount = 0;
    while (getline(infile, line)) {
        stringstream ss(line);
        string value;
        string sql = "INSERT INTO " + tableName + " VALUES(";
        bool first = true;

        while (getline(ss, value, ',')) {
            if (!first) sql += ", ";
            // Add quotes if not a number
            bool isNumber = true;
            for (char c : value) if (!isdigit(c) && c != '.' && c != '-') { isNumber = false; break; }
            if (isNumber) sql += value;
            else sql += "'" + value + "'";
            first = false;
        }
        sql += ");";
        cout << sql << endl;
        recordCount++;
    }

    cout << "-- Total records processed: " << recordCount << endl;
}

int main() {
    // Example usage
    csvToSQL("users.csv", "Users");
    csvToSQL("students.csv", "Students");
    csvToSQL("teachers.csv", "Teachers");
    csvToSQL("resources.csv", "Resources");
    csvToSQL("borrow_records.csv", "BorrowRecords");

    return 0;
}