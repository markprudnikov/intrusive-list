#include <string>

#include "point_list.hpp"

int main() {
    std::string cmd;

    PointList lst;

    while (true) {
        std::cin >> cmd;

        if (cmd == "exit") {
            return 0;
        } else if (cmd == "add") {
            int x, y;
            std::cin >> x >> y;
            lst.add_point(x, y);
        } else if (cmd == "rm") {
            int x, y;
            std::cin >> x >> y;
            lst.remove_point(x, y);
        } else if (cmd == "rma") {
            lst.remove_all_points();
        } else if (cmd == "print") {
            lst.show_all_points();
        } else if (cmd == "len") {
            std::cout << lst.size() << "\n";
        } else {
            std::cout << "Unknown command\n";
        }
    }
}