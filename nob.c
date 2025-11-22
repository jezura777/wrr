
#define NOB_STRIP_PREFIX
#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    Cmd cmd = {0};

    cmd_append(&cmd, "cc");
    cmd_append(&cmd, "-Wall");
    cmd_append(&cmd, "-o");
    cmd_append(&cmd, "wrr");
    cmd_append(&cmd, "main.c");

    if(!cmd_run(&cmd)) return 1;
    return 0;
}

	

