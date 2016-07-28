#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rlimit lim;
    // print the following values using rlimit
    getrlimit(RLIMIT_STACK,&lim);
    printf("stack size: %llu\n",(unsigned long long)lim.rlim_max);
    getrlimit(RLIMIT_NPROC,&lim);
    printf("process limit: %d\n", (int)lim.rlim_max);
    getrlimit(RLIMIT_NOFILE,&lim);
    printf("max file descriptors: %d\n", (int)lim.rlim_max);
    return 0;
}
