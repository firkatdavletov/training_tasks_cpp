#include <iostream>
#include <string>
#include <sstream>

bool IsInvalid(const std::string& str) {
    bool pointIsPresence = false;
    if (str[0] != '.' && str.back() != '.') {
        for (int i = 0; i < str.length(); ++i) {
             if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == '-' || str[i] == '+') {
                 if (str[i] == '.') {
                     if (pointIsPresence) {
                         std::cout << "Invalid number!" << std::endl;
                         return true;
                     } else {
                         pointIsPresence = true;
                     }
                 } else if ((str[i] == '-' || str[i] == '+') && i != 0) {
                     std::cout << "Invalid number!" << std::endl;
                     return true;
                 }
             } else {
                 std::cout << "Invalid number!" << std::endl;
                 return true;
             }
        }
        return false;
    } else {
        std::cout << "Invalid number!" << std::endl;
        return true;
    }
}

bool CompareInteger(std::string& s1, std::string& s2, int size) {
    for (int i = 0; i < size; ++i) {
        if (s1[i] > s2[i]) {
            std::cout << "More" << std::endl;
            return true;
        } else if (s1[i] < s2[i]) {
            std::cout << "Less" << std::endl;
            return true;
        }
    }
    return false;
}

void CompareReal(std::string& s1, std::string& s2) {
    std::stringstream ss1(s1), ss2(s2);
    std::string integer1, decimal1, integer2, decimal2;

    std::getline(ss1, integer1, '.');
    ss1 >> decimal1;

    std::getline(ss2, integer2, '.');
    ss2 >> decimal2;

    if(!CompareInteger(integer1, integer2, integer1.length())) {
        int lowerSize = decimal1.length();
        if (lowerSize > decimal2.length()) {
            lowerSize = decimal2.length();
        }

        if (!CompareInteger(decimal1, decimal2, lowerSize)) {
            if (decimal1.length() < decimal2.length()) {
                std::cout << "Less" << std::endl;
            } else if (decimal1.length() > decimal2.length()) {
                std::cout << "More" << std::endl;
            } else {
                std::cout << "Equal" << std::endl;
            }
        }
    }
}

int main() {
    std::string command;
    while (command != "0") {
        std::string numb1, numb2;
        do {
            std::cout << "Enter first number:" << std::endl;
            std::getline(std::cin, numb1);
        } while (IsInvalid(numb1));

        do {
            std::cout << "Enter second number:" << std::endl;
            std::getline(std::cin, numb2);
        } while (IsInvalid(numb2));

        if (numb1[0] != '-' && numb2[0] != '-') {
            numb1.erase(0, numb1.find_first_not_of('0'));
            numb2.erase(0, numb2.find_first_not_of('0'));
            CompareReal(numb1, numb2);
        } else if (numb1[0] == '-' && numb2[0] == '-') {
            numb1.erase(0,1);
            numb1.erase(0, numb1.find_first_not_of('0'));
            numb2.erase(0,1);
            numb2.erase(0, numb2.find_first_not_of('0'));
            CompareReal(numb2, numb1);
        } else if (numb1[0] != '-' && numb2[0] == '-') {
            std::cout << "More" << std::endl;
        } else {
            std::cout << "Less" << std::endl;
        }

        std::cout << "Enter 0 to exit, any symbol to continue: ";
        std::getline(std::cin, command);
    }
    return 0;
}
