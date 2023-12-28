#include "hospital.h"
#include "menu.cpp"

int main()
{
    hospital h;
    first(h) = NULL;

    cout << "\033c";
    mainMenu(h);
}