#include <iostream>
#include <string>


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
int count (std::string a) {
    int count = 0;

    for (int i = 0; i < a.length(); i++) {
        char op = a[i];
        if (a[i] == '.') {
            break;
        }
        if (op > 47 && op < 58) {
            count++;
        }
    }
    return count;
}
std::string str_big_small(std::string c, std::string d) {
    for ( int i = 0; i < c.length() || i < d.length(); i++) {
        if (c[i] == '.' && i == d.length()) {
            std::cout << "Yahoooo!";
            for (int j = i + 1; j < c.length(); j++){
                if (c[j] == '0' && j == c.length() - 1) {
                    return "Equal";
                }else {
                    return "More";
                }
            }
        }
        if (c[i] > d[i]) {
            std::cout << i;
            return "More";
        }if (c[i] < d[i]) {
            return "Less";
        }
    }
    return std::string();
}
std::string big_small (int a, int b, std::string x, std::string y) {
    if (a > b) {
        std::cout << "Hoooya";
        return "More";
    }else if (a < b) {
        return "less";
    }else if (a == b) {
       return str_big_small(x, y);
    }
    return std::string();
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


    std::cout << "\n" << big_small(count(first_number), count(second_number), first_number, second_number);
}
