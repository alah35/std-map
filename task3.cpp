#include <iostream>
#include <map>
#include <string>

std::string prepare_to_comp(std::string s) {
    std::string _s = ""; 
    for (int i = 0; i < s.size(); i++)
        _s += std::tolower(s[i]);
    return _s;
}

bool is_anagram(std::string s1, std::string s2) {
    std::map<char, int> _s1, _s2; 

    for (char ch: s1)
        _s1[ch]++;
    for (char ch: s2)
        _s2[ch]++;

    return _s1 == _s2;
}

int main() {
    std::string str1, str2;
    std::cout << "enter the first word:" << std::endl;
    std::cin >> str1;
    std::cout << "enter the second word:" << std::endl;
    std::cin >> str2;
    std::cout << (is_anagram(prepare_to_comp(str1), prepare_to_comp(str2)) ? "anagram" : "not anagram") << std::endl;
    return 0;
}
