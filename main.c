#include <stdio.h>
#define NOB_STRIP_PREFIX
#define NOB_IMPLEMENTATION
#include "nob.h"

#define BUFF_SIZE 512

void cls()
{
    printf("\e[1;1H\e[2J");
}


int main(int argc, char **argv)
{
    if(argc < 2) { 
        nob_log(ERROR,"output file expected but none provided");
        return 1;
    }

    char buff[BUFF_SIZE] = {0};
    char *line = NULL;

    cls();
    FILE* out = fopen(argv[1], "w");
    for(;;) {
	line = NULL;
        buff[0] = '\0';
        line = fgets(buff, BUFF_SIZE, stdin);
        if(buff[0]=='\n') cls();
        else if(buff[0] == EOF || line == NULL) break;
        else fputs(buff, out);
    }
    cls();

    printf("%s, written.\n", argv[1]);

    fclose(out);
}

