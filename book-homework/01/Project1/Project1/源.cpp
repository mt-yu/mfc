#include<stdio.h>

int main(void)
{
	char     ch = 'h',
		*string = "computer";
	wchar_t  wch = L'w',
		*wstring = L"Unicode";
	int      count = -9234;
	double   fp = 251.7366;

	// Display integers
	printf("Integer formats:\n"
		"   Decimal: %d  Justified: %.6d  "
		"Unsigned: %u\n",
		count, count, count, count);

	// Display decimals
	printf("Decimal %d as:\n   Hex: %Xh  "
		"C hex: 0x%x  Octal: %o\n",
		count, count, count, count);

	// Display in different radixes
	printf("Digits 10 equal:\n   Hex: %i  "
		"Octal: %i  Decimal: %i\n",
		0x10, 010, 10);

	// Display characters
	printf("Characters in field (1):\n"
		"%10c%5hc%5C%5lc\n",
		ch, ch, wch, wch);
	wprintf(L"Characters in field (2):\n"
		L"%10C%5hc%5c%5lc\n",
		ch, ch, wch, wch);

	// Display strings
	printf("Strings in field (1):\n%25s\n"
		"%25.4hs\n   %S%25.3ls\n",
		string, string, wstring, wstring);
	wprintf(L"Strings in field (2):\n%25S\n"
		L"%25.4hs\n   %s%25.3ls\n",
		string, string, wstring, wstring);

	// Display real numbers
	printf("Real numbers:\n   %f %.2f %e %E\n",
		fp, fp, fp, fp);

	// Display pointer
	printf("\nAddress as:   %p\n", &count);
	getchar();

	return 0;
}