#include <iostream>
#include <string>
#include <sstream>

bool NumbIsNotValid(const std::string& str) {

    if (str.empty() || (str.length() > 1 && str[0] == '0')) {
        return true;
    } else {
        for (char i : str) {
            if (i < '0' || i > '9') {
                return true;
            }
        }

        int a = std::stoi(str);

        if (a > 255) {
            return true;
        } else {
            return false;
        }
    }
}

bool CheckIP(const std::string& str) {

    std::string ip[4], temp;
    std::stringstream ss(str);
    if (str.back() == '.') {
        return false;
    }
    for (int i = 0; i < 4; ++i) {
        std::getline(ss, ip[i], '.');
        if (NumbIsNotValid(ip[i])) {
            return false;
        }
    }
    // Если в потоке остались символы размер адреса IP неверный
    if (ss >> temp) {
        return false;
    } else {
        return true;
    };
}

void AnswerYes() {
    std::cout << "Yes" << std::endl;
}

void AnswerNo() {
    std::cout << "No" << std::endl;
}

int main() {
    std::string ip;

    while (ip != "0") {
        const int size = 4;

        std::cout << "Enter IP-address (enter 0 to exit): " << std::endl;
        std::getline(std::cin, ip);

        CheckIP(ip) ? AnswerYes() : AnswerNo();
    }
    return 0;
}

