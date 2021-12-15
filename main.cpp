#include <iostream>
#include <string>
#include <cmath>

std::string chek (std::string a) {
    int count = 0;
    bool good = true;

    for (int i = 0; i < a.length();) {
        char n = a[i];

        if (a[i] == '.') {
            count++;
            if (count > 1) {
                good = false;
            }
        }
        if ((a[0] == '-' && a[1] == '.' && i == a.length() - 1 && (n < 48 || n > 57)) || (i > 0 && a[i] == '-') ||
            ((n < 48 || n > 57) && n != 45 && n != 46)) {
            good = false;
        }
        i++;
    }
    if (good) {
        return "Yes!";
    }
    else {
        return "No!";
    }
}
std::string recycling (std::string a) {
    std::string b, c, u, u_1, a_1;
    bool good = true, good_sec = true, good_third = true;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '.') {
            int y= 0;
            for (;a[y] != '.'; y++){
                b += a[y];
            }
            for (int t = y; t < a.length(); t++) {
                c += a[t];
            }
            for (int q = 0; q < b.length(); q++) {
                if (b[q] > '0' || (b[q] >= '0' && q == b.length() - 1)) {
                    good = false;
                }
                if (b[q] == '0' && good) {
                    b[q] = ' ';
                }
                if (b[q] != ' ') {
                    u += b[q];
                }
            }
            for (int f = c.length() - 1; f >= 0; f--) {
                if (c[f] > '0') {
                    good_sec = false;
                }
                if ((c[f] == '0' || c[f] == '.') && good_sec) {
                    c[f] = ' ';
                }
                if ( c[f] != ' ') {
                    u_1 += c[f];
                }
            }
            for (int g = u_1.length() - 1; g >= 0; g--) {
                u += u_1[g];
            }
            return u;
        }
    }
    for (int i = 0; i < a.length(); i++){
        if (a[i] > '0') {
            good_third = false;
        }
        if (a[0] != '-' && a[i] == '0' && good_third && a.length() > 1) {
            a[i] = ' ';
        }
        if (a[0] == '-' && good_third && a.length() > 2) {
            if (a[i] != '-') {
                a[i] = ' ';
            }
        }
        if (a[i] != ' ') {
            a_1 += a[i];
        }
    }
    return a_1;
}

std::string str_processing (std::string a, std::string b) {
    int length = fmax(a.length(), b.length()), count_f = 0, count_s = 0;
    if (a[0] == '-' && a[1] > '0' && b[0] != '-') {
        return "Less!";
    }
    if (a[0] != '-' && b[0] == '-' && b[1] > '0') {
        return "More!";
    }
    if ((a[0] == '-' && a[1] && b[0] == '0') || (b[0] == '-' && b[1] && a[0] == '0')
            || (a[0] && b[0] == '-' && a[1] && b[1] == '0')) {
        return "Equal!";
    }
    if (a[0] != '-' && b[0] != '-') {
        for (int t = 0; a[t] != '.' && t < a.length(); t++) {
            count_f++;
        }
        for (int j = 0; b[j] != '.' && j < b.length(); j++) {
            count_s++;
        }
        if (count_f < count_s) {
            return "Less!";
        }
        if (count_f > count_s) {
            return "More!";
        }
        if (count_f == count_s) {
            for (int l = 0; l < length; l++) {
                if (a[l] > b[l]) {
                    return "More!";
                }
                if (a[l] < b[l]) {
                    return "Less!";
                }
                if (a[l] == b[l] && l == length - 1) {
                    if (a.length() > b.length()) {
                        return "More!";
                    }
                    if (a.length() < b.length()) {
                        return "Less!";
                    }
                    if (a.length() == b.length()) {
                        return "Equal!";
                    }
                }
            }
        }
    }
    if (a[0] == '-' && b[0] == '-') {
        for (int t = 0; a[t] != '.' && t < a.length(); t++) {
            count_f++;
        }
        for (int j = 0; b[j] != '.' && j < b.length(); j++) {
            count_s++;
        }
        if (count_f < count_s) {
            return "More!";
        }
        if (count_f > count_s) {
            return "Less!";
        }
        if (count_f == count_s) {
            for (int l = 0; l < length; l++) {
                if (a[l] > b[l]) {
                    return "Less!";
                }
                if (a[l] < b[l]) {
                    return "More!";
                }
                if (a[l] == b[l] && l == length - 1) {
                    if (a.length() > b.length()) {
                        return "Less!";
                    }
                    if (a.length() < b.length()) {
                        return "More!";
                    }
                    if (a.length() == b.length()) {
                        return "Equal!";
                    }
                }
            }
        }
    }
    return {};
}
int main() {
    std::string first_number, second_number, n_1, n_2;
    do {

        std::cout << "Enter two number:\n";
        std::cout << "First number:";
        std::cin >> first_number;
        std::cout << "Second number:";
        std::cin >> second_number;
    } while (chek(first_number) == "No!" || chek(second_number) == "No!");
    std::cout << str_processing(recycling(first_number), recycling(second_number));
}