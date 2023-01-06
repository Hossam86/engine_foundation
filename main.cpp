#include <iostream>
#include "Vector3D.h"

int main() {
    Vector3D x{};
    std::cout << "vector components" << "(" << x.x << " ," << x.y << " ," << x.z << ")\n";
    std::cout << "vector components" << "(" << x[0] << " ," << x[1] << " ," << x[2] << ")\n";

    x[0] = 1;
    x[1] = 2;
    x[2] = 3;

    std::cout << "vector components" << "(" << x.x << " ," << x.y << " ," << x.z << ")\n";
    std::cout << "vector components" << "(" << x[0] << " ," << x[1] << " ," << x[2] << ")\n";

    auto r = x + x;
    std::cout << "vector addition" << "(" << r.x << " ," << r.y<< " ," << r.z << ")\n";

    r = x - x;
    std::cout << "vector subtraction" << "(" << r.x << " ," << r.y << " ," << r.z << ")\n";

    return 0;
}