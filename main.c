#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>
#include <stdio.h>

#define check_goto(A) if(!(A)) { goto error; }
#define check_function(A, F) !(A) ? F() : -2

int test_check_goto()
{
    void* null = NULL;
    check_goto(null);

    return 1;
error:
    return -1;
}

int check_funct()
{
    return -1;
}

int test_check_function()
{
    void* null = NULL;
    return check_function(null, check_funct);
}

int main(int argc, char* argv[])
{
    long i = 0l;
    long reps = 100000000L;
    clock_t c0, c1;

    c0 = clock();
    for(; i < reps; i++) {
        test_check_goto();
    }
    c1 = clock();
    printf("\telapsed wall clock time for goto: %ld\n", (long) (c1 - c0));

    i = 0;
    c0 = clock();
    for(; i < reps; i++) {
        test_check_function();
    }
    c1 = clock();
    printf("\telapsed wall clock time for function: %ld\n", (long) (c1 - c0));
}
