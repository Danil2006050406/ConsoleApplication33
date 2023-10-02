#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

template <typename T, typename U, typename V>
vector<vector<T>> createAndFillTable(int size, const U& aboveDiagonalValue, const V& belowDiagonalValue) {
    vector<vector<T>> table(size, vector<T>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i < j) {
                table[i][j] = aboveDiagonalValue;
            }
            else if (i == j) {
                table[i][j] = belowDiagonalValue;
            }
            else {
                table[i][j] = belowDiagonalValue;
            }
        }
    }

    return table;
}

template <typename T>
vector<vector<T>> transposeTable(const vector<vector<T>>& table) {
    int size = table.size();
    vector<vector<T>> transposedTable(size, vector<T>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transposedTable[i][j] = table[j][i];
        }
    }

    return transposedTable;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 5;
    char diagonalValue = 'X';
    int aboveDiagonalValue = 1;
    int belowDiagonalValue = 2;

    vector<vector<int>> table = createAndFillTable<int, char, int>(size, aboveDiagonalValue, belowDiagonalValue);

    cout << "Завдання 1: Створена та заповнена квадратна таблиця:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> transposed = transposeTable(table);

    cout << "Завдання 2: Транспонована таблиця:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
