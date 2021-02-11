#include <iostream>
#include <string>
#include <sstream>

bool validChar(char c) {
    return (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c == '-') || (c == '.') ||
            (c >= '0' && c <= '9');
}

bool validCharLogin(char c) {
    return (c == 33) ||
           (c >= 35 && c <= 39) ||
           (c >= 42 && c <= 43) ||
           (c == 45) ||
           (c == 47) ||
           (c == 61) ||
           (c == 63) ||
           (c >= 94 && c <= 96) ||
           (c >= 125 && c <= 126);
}

bool CheckValidChars(std::string& s, bool login = false) {
    if (login && (s.length() < 1 || s.length() > 64)) {
        return false;
    } else if (!login && (s.length() < 1 || s.length() > 63)) {
        return false;
    }
    for (int i = 0; i < s.length(); ++i) {
        if (validChar(s[i]) || (login && validCharLogin(s[i]))) {
            if (s[i] == '.') {
                if (s[i-1] == '.' || i == 0 || i == s.length()) {
                    return false;
                }
            }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str, login, domain;

    while (str != "0") {
        std::cout << "Enter @mail: " << std::endl;
        std::getline(std::cin, str);

        std::stringstream ss(str);

        std::getline(ss, login, '@');
        std::getline(ss, domain);

        std::cout << "login " << login << std::endl;
        std::cout << "domain " << domain << std::endl;

        if (!login.empty() && !domain.empty() &&
                CheckValidChars(login, true) &&
                CheckValidChars(domain)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}

