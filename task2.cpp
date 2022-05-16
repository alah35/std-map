#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> queue;
    std::map<std::string, int>::iterator it;
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
            it->second--;
            if (it->second == 0)
                queue.erase(it);
            continue;
        }
        
        if (queue.contains(input))
            queue[input]++;
        else {
            queue.insert(std::make_pair(input, 1));
        }
    }

    return 0;
}
