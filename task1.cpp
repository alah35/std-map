#include <iostream>
#include <string>
#include <map>


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

void show_handbook(std::map<std::string, std::string> &hb) {
    for (std::map<std::string, std::string>::iterator it = hb.begin();
            it != hb.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
}

void find_by_num(std::map<std::string, std::string> &hb, const std::string &number){
    std::map<std::string, std::string>::iterator it = hb.find(number);
    std::cout << it->first << ": " << it->second << std::endl;
}

void find_by_name(std::map<std::string, std::string> &hb, std::string &name) {
    for (std::map<std::string, std::string>::iterator it = hb.begin();
            it != hb.end(); it++) {
        if (it->second == name)
            std::cout << it->second << ": " << it->first << std::endl;
    }
}

int main() {
    std::map<std::string, std::string> handbook;
    
    while(true) {
        std::string input;
        std::cout << "Waiting for input..." << std::endl;
        getline(std::cin, input);

        if (input == "show") {
            show_handbook(handbook);
            continue;
        }

        if (input == "q" || input == "quit")
            break;

       if (is_request(input)) {
           if (input[0] >= '0' && input[0] <= '9')
               find_by_num(handbook, input);
           else 
               find_by_name(handbook, input);
           continue;
        }

        handbook.insert(parse(input));
    }
    return 0;
}
