#include <winuser.h>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <thread>
#include <unistd.h>

using namespace std;

class key {
public:
	INPUT ip;
	int keycode;
	key(int keycode) {
		this->keycode = keycode;
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
	}
	void press(){
		ip.ki.wVk = keycode; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	}
	void release(){
		ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
	}
	void depress(){
		press();
		Sleep(50);
		release();
	}
};

int main(){
	Sleep(1000);

	key win(VK_LWIN);
	key x(0x58);
	key up(VK_UP);
	key down(VK_DOWN);
	key right(VK_RIGHT);
	key enter(VK_RETURN);
	key shift(VK_SHIFT);
	key space(VK_SPACE);

	for(int i = 0; i < 250; i++){
	  	for(int j = 0; j < 5; j++){
	  		x.press();
	  		x.release();
	  	}
	  	space.press();
	  	Sleep(65);
	  	space.release();
	}

	shift.press();
	enter.press();
	Sleep(1);
	shift.release();
	enter.release();

	  /*win.press();
	  x.press();

	  Sleep(50);

	  x.release();
	  win.release();

	  up.depress();
	  up.depress();

	  right.depress();

	  down.depress();
	  down.depress();

	  enter.depress();*/
}