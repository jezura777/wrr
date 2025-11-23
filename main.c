#include <stdio.h>

#define CR "20"
#define CC "30"

#include "config.h"

#define BUFF_SIZE 512

void cls()
{
    printf("\e[1;1H\e[2J");
    if (center) printf("\e[%s;%sH", CR, CC);
}


int main(int argc, char **argv)
{
    if(argc < 2) { 
        printf("output file expected but none provided\n");
        return 1;
    }

    if(argc > 2 && argv[2][0]=='-' ){
	if(argv[2][1]=='n') center=!center;
	if(argv[2][1]=='a') append=!append;
    }

    char buff[BUFF_SIZE] = {0};
    char *line = NULL;

    cls();
    FILE* out = {0};
    if(!append) out = fopen(argv[1], "w");
    else out = fopen(argv[1], "a");

    for(;;) {
	printf("\e[%sG", CC);
	line = NULL;
        buff[0] = '\0';
        line = fgets(buff, BUFF_SIZE, stdin);
        if(buff[0]=='\n') cls();
        else if(buff[0] == EOF || line == NULL) break;
        else fputs(buff, out);
    }
    cls();
    printf("\e[H");

    printf("%s, written.\n", argv[1]);

    fclose(out);
}

