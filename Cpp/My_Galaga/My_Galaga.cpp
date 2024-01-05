#include <iostream>
#include <My_ConsoleEngine/ConsoleScreen.h>

int main()
{
    LeakCheck;

    ConsoleScreen NewScreen = ConsoleScreen();

    NewScreen.CreateScreen(2, 2);




    NewScreen.ReleaseScreen();
}