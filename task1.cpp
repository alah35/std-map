#include <iterator>
#include <iostream>
#include <string>
#include <map>
#include <vector>

bool is_request(const std::string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ')
            return false;
    }
    return true;
}

std::pair<std::string, std::string> parse(const std::string &s) {
    std::string number = "", name = "";
    int i = 0;
    while (s[i] != ' ') {
        number += s[i];
        i++;
    }
    i++;
    while (i < s.length()) {
        name += s[i];
        i++;
    }
    return std::make_pair(number, name);
}

void find_by_num(std::map<std::string, std::string>  &m, const std::string &s) {
    auto it = m.find(s);
    std::cout << it->first << ": " << it->second << std::endl;
}

void find_by_surname(std::map<std::string, std::vector<std::string>> &m, std::string &s) {
    auto it = m.find(s);
    std::cout << it->first << ":" << std::endl;
    std::copy(it->second.begin(), it->second.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}
int main() {
    std::map<std::string, std::string> numberToSurname;
    std::map<std::string, std::vector<std::string>> surnameToNumber;
    
    while (true) {
        std::string input;
        std::cout << "Waiting for input..." << std::endl;
        getline(std::cin, input);

        if (input == "q" || input == "quit")
            return 0;

        if (is_request(input)) {
            if (numberToSurname.empty() && surnameToNumber.empty()) {
                std::cout << "Handbook is empty" << std::endl;
                continue;
            }

            if (input[0] >= '0' && input[0] <= '9')
                find_by_num(numberToSurname, input);
            else 
                find_by_surname(surnameToNumber, input);
            continue;
        }
        
        auto current = parse(input);
        if (numberToSurname.contains(current.first))
            std::cout << "Number has already registred" << std::endl;
        else {
            numberToSurname[current.first] = current.second;
            surnameToNumber[current.second];
            surnameToNumber[current.second].push_back(current.first);
        }
    }
}
