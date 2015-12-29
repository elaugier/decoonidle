// DecoOnIdle.cpp : Defines the entry point for the console application.
//
#define WINVER 0x0500
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <tchar.h>
#include "Winuser.h"
#include "Winbase.h "
#include "Wtsapi32.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FreeConsole();
	_TCHAR* tc = _T("-t");
	int count;
	int tempo = 300;
	wchar_t buffer[256];
	if (argc > 3) return 1;
	for (count = 0; count < argc; count++){
		if (*argv[count] == *tc){
			if (count + 1 <= argc)
			{
				tempo = _ttoi(argv[count + 1]);
			}
			else
			{
				return 1;
			}
		}
	}
	wsprintfW(buffer, L"%d", tempo);
	MessageBoxW(0, buffer, L"Message title", MB_OK);

	do
	{
		LASTINPUTINFO li;
		li.cbSize = sizeof(LASTINPUTINFO);
		GetLastInputInfo(&li);
		DWORD te = GetTickCount();
		int elapsed = (te - li.dwTime) / 1000;
		if (elapsed > (tempo))
		{
			WTSDisconnectSession(
				WTS_CURRENT_SERVER_HANDLE,
				WTS_CURRENT_SESSION,
				true
				);
			exit;
		}
		Sleep(5000);
	} while (true);

	return 0;
}
