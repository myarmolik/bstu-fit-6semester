#include <windows.h>
#include <string>
#include "sddl.h"

SECURITY_ATTRIBUTES getSecurityAttributes();

int main()
{
	//SECURITY_ATTRIBUTES SA = getSecurityAttributes();

	//std::wstring closeEventName = L"Global\\"; closeEventName += L"D:/OS_HT/storage/HTspace.ht"; closeEventName += L"-stopEvent";

	//HANDLE hStopEvent = CreateEvent(
	//	&SA,
	//	TRUE, //FALSE - автоматический сброс; TRUE - ручной
	//	FALSE,
	//	closeEventName.c_str());
	//SetEvent(hStopEvent);

	HANDLE hStopEvent = CreateEvent(
		NULL,
		TRUE, //FALSE - автоматический сброс; TRUE - ручной
		FALSE,
		L"Stop");
	SetEvent(hStopEvent);
}

SECURITY_ATTRIBUTES getSecurityAttributes()
{
	const wchar_t* sdd = L"D:"
		L"(D;OICI;GA;;;BG)" //Deny guests
		L"(D;OICI;GA;;;AN)" //Deny anonymous
		L"(A;OICI;GA;;;AU)" //Allow read, write and execute for Users
		L"(A;OICI;GA;;;BA)"; //Allow all for Administrators
	SECURITY_ATTRIBUTES SA;
	ZeroMemory(&SA, sizeof(SA));
	SA.nLength = sizeof(SA);
	ConvertStringSecurityDescriptorToSecurityDescriptor(
		sdd,
		SDDL_REVISION_1,
		&SA.lpSecurityDescriptor,
		NULL);

	return SA;
}
