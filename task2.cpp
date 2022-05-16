#include <iostream>
#include <map>
#include <string>

//Возможно, я неверно понял задание, но на мой взгляд здесь был бы уместней multiset

int main() {
    std::multimap<std::string, int> queue;
    std::multimap<std::string, int>::iterator it;
    int counter = 1;
    std::string input;

    while (true) {
        std::cout << "Waiting for input..." << std::endl;
        std::cin >> input;

        if (input == "q" || input == "quit")
            break;

        if (input == "Next" || input == "next") {
            if (queue.empty()) {
                std::cout << "Queue is empty" << std::endl;
                continue;
            }
            it = queue.begin();
            std::cout << it->first << std::endl;
            queue.erase(it);
            continue;
        }

        queue.insert(std::make_pair(input, counter));
        counter++;
    }

    return 0;
}
