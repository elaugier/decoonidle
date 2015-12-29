// DisconnectOnIdle.cpp : Defines the entry point for the console application.
//

//#define WINVER 0x0500
//#define _WIN32_WINNT 0x0500

#include "Winuser.h"
#include "Winbase.h "
#include "Wtsapi32.h"

typedef struct tagLASTINPUTINFO {
	UINT  cbSize;
	DWORD dwTime;
} LASTINPUTINFO, *PLASTINPUTINFO;

int _tmain()
{
	LASTINPUTINFO li;
	li.cbSize = sizeof(LASTINPUTINFO);
	GetLastInputInfo(&li);
	DWORD te = GetTickCount();
	int elapsed = (te - li.dwTime) / 1000;
	if (elapsed > 60)
	{
		WTSDisconnectSession(
			WTS_CURRENT_SERVER_HANDLE,
			WTS_CURRENT_SESSION,
			true
			);
	}
	return 0;
}

