#include <winuser.h>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <thread>
#include <unistd.h>

using namespace std;

using Time = std::chrono::steady_clock;
using ms = std::chrono::milliseconds;

using float_sec = std::chrono::duration<float>;
using float_time_point = std::chrono::time_point<Time, float_sec>;

float_time_point get_time() {
    return Time::now();
}

int rand(int upper){
	return rand() % upper;
}

void LeftClick ( )
{  
  INPUT    Input={0};
  // left down 
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
  ::SendInput(1,&Input,sizeof(INPUT));

  // left up
  ::ZeroMemory(&Input,sizeof(INPUT));
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
  ::SendInput(1,&Input,sizeof(INPUT));
}

int main(){
	auto width = GetSystemMetrics(SM_CXSCREEN);
	auto height = GetSystemMetrics(SM_CYSCREEN);

	auto sleep_time = chrono::milliseconds(15);
	auto start = get_time();

	while((get_time() - start).count() < 10){
		SetCursorPos(rand(width), rand(height));
		usleep(15000);
	}
}