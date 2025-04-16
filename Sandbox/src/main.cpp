#include <iostream>

__declspec(dllimport) int sum(int i, int b);

int main()
{
    std::cout << sum(5, 1);
    return 0;
}