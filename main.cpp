#include <iostream>
#include <string>

bool InputStrings (std::string* s, int size, int& x, int& o) {

    std::cout << "Enter " << size << " strings:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> s[i];
        if (s[i].length() != 3) {
            std::cout << "Incorrect input! Wrong size of string!" << std::endl;
            return false;
        } else {
            for (char j : s[i]) {
                if (j == 'X') {
                    x++;
                } else if (j == 'O') {
                    o++;
                } else if (j != '.') {
                    return false;
                }
            }
        }
    }
    return true;
}

bool CheckHorizLines(std::string* s, int size, bool &match, char& win) {
    for (int i = 0; i < size; ++i) {
        if (s[i] == "XXX" && !match) {
            match = true;
            win = 'X';
        } else if (s[i] == "OOO" && !match) {
            match = true;
            win = 'O';
        } else if (s[i] == "XXX" || s[i] == "OOO") {
            return false;
        }
    }
    return true;
}

bool CheckVertLines(std::string* s, int size, bool& match, char& win) {
    for (int i = 0; i < size; ++i) {
        if (s[0][i] == s[1][i] && s[1][i] == s[2][i]) {
            if (!match && (s[0][i] == 'X')) {
                match = true;
                win = 'X';
            } else if (!match && (s[0][i] == 'O')) {
                match = true;
                win = 'O';
            } else if (s[0][i] != '.') {
                return false;
            }
        }
    }
    return true;
}

bool CheckDiagLines(std::string* s, bool& match, char& win) {
    if (s[0][0] == s[1][1] && s[1][1] == s[2][2] ||
        s[0][2] == s[1][1] && s[1][1] == s[2][0]) {
        if (s[1][1] == 'X') {
            match = true;
            win = 'X';
        } else if (s[1][1] == 'O') {
            match = true;
            win = 'O';
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int command = 1;
    const int sizeOfField = 3;
    std::string field[sizeOfField];
    while (command == 1) {
        int xCount = 0;
        int oCount = 0;

        if (InputStrings(field, sizeOfField, xCount, oCount)) {
            bool match = false;
            char winner = 'N';
            int diff = std::abs(xCount - oCount);

            if (CheckHorizLines(field, sizeOfField, match, winner) &&
                CheckVertLines(field, sizeOfField, match, winner) &&
                CheckDiagLines(field, match, winner)) {
                if (winner == 'X' && xCount >= oCount && diff < 2) {
                    std::cout << "Petya won!" <<std::endl;
                } else if (winner == 'O' && oCount >= xCount && diff < 2) {
                    std::cout << "Vanya won!" <<std::endl;
                } else if (winner == 'N' && diff < 2) {
                    std::cout << "Nobody!" << std::endl;
                } else {
                    std::cout << "Incorrect input! Invalid combination!" << std::endl;
                }
            } else {
                std::cout << "Incorrect input! Matches in two or more rows!" << std::endl;
            }
        } else {
            std::cout << "Incorrect input! Invalid characters!" << std::endl;
        }
        std::cout << "Enter 1 to continue or any symbol to exit: ";
        std::cin >> command;
    }
    return 0;
}
