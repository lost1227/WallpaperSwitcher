#include "pch.h"
#include <Windows.h>

#include <iostream>
#include <csignal>

#include "SystemInterface.h"
#include "App.h"

using namespace std;
using namespace std::filesystem;

void signal_handler(int) {
    App::getInstance()->interrupt();
}

// TODO: https://www.dreamincode.net/forums/topic/258176-putting-a-program-icon-in-the-system-tray-with-c/

int main() {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    HANDLE mutex = CreateMutexA(NULL, true, "powers.wallpaperswitcher.singleinstance");
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        SystemInterface::messagebox("Instance already running!");
        return 1;
    }

    App::getInstance()->main();

    cout << "Goodbye!\n";

    return 0;
}

int WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR    lpCmdLine,
    int       cmdShow) {

    main();
}