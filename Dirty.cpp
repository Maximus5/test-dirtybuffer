
#include <Windows.h>
#include <stdio.h>

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi = {};
	if (!GetConsoleScreenBufferInfo(h, &csbi))
	{
		printf("GetConsoleScreenBufferInfo failed, not a console?\n");
		return 1;
	}
	printf("Buffer size: {%ix%i}, Buffer bottom: %i, Cursor pos: {%i,%i}\n", csbi.dwSize.X, csbi.dwSize.Y, csbi.srWindow.Bottom, csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y);
	if (csbi.srWindow.Bottom >= (csbi.dwSize.Y - 2))
	{
		printf("The buffer bottom is already visible\n");
	}
	else
	{
		printf("Writing dirty line at %i\n\n", csbi.dwSize.Y-2);
		LPCSTR pszDirty = "**** This is dirty line ****";
		COORD cr = {0, csbi.dwSize.Y-2}; DWORD dwWritten = 0;
		WriteConsoleOutputCharacterA(h, pszDirty, strlen(pszDirty), cr, &dwWritten);
	}
    return 0;
}
