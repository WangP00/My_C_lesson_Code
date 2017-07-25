#include <string.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int i;
	char text[80];
	// for (i = 0; i < argc; i++) {
	// 	printf("%d - %s\n", i, argv[i]);
	// }
    while (fgets(text, 80, stdin) != NULL) {
    	printf("I have read: %s", text);
    }
	return 0;
}