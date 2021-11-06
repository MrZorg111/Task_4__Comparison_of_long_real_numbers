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



int main() {
    std::string first_number, second_number;
    do {

        std::cout << "Enter two number:\n";
        std::cout << "First number:";
        std::cin >> first_number;
        std::cout << "Second number:";
        std::cin >> second_number;
    } while (chek(first_number) == "No!" || chek(second_number) == "No!");

    std::cout << "Number good!";
}
