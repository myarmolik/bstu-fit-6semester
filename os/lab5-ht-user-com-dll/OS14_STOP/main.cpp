#include <windows.h>
#include <string>
#include "sddl.h"

int main()
{
	HANDLE hStopEvent = CreateEvent(
		NULL,
		TRUE, //FALSE - автоматический сброс; TRUE - ручной
		FALSE,
		L"Stop");
	SetEvent(hStopEvent);
}
	