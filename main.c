#include <stdio.h>
#include <windows.h>

#define DELAY 1

void clickMouse() {
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(1);
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    printf("Auto Clicker\n");
    printf("Press '-' to start/stop clicking\n");
    printf("Press '=' to exit\n");

    int clicking = 0;

    while (1) {
        if (GetAsyncKeyState(VK_OEM_MINUS) & 0x8000) {
            clicking = !clicking;

            if (clicking) {
                printf("Clicking started...\n");
            } else {
                printf("Clicking stopped.\n");
            }

            while (GetAsyncKeyState(VK_OEM_MINUS) & 0x8000) {
                Sleep(1);
            }
        }

        if (GetAsyncKeyState(VK_OEM_PLUS) & 0x8000) {
            printf("Exiting program.\n");
            break;
        }

        if (clicking) {
            clickMouse();
            Sleep(DELAY);
        }
    }

    return 0;
}
