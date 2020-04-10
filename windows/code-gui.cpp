#include <iostream>
#include <windows.h>

int main() {
    std::cout << "Hello World!!\n";
    MessageBoxA(NULL,"Hello World!!\n", "Hello world message",MB_OK);
    return 0;
}
