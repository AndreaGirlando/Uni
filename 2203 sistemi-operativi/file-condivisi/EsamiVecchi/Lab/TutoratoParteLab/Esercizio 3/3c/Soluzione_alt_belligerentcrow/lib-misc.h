#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//error-handling 

#define exit_with_sys_err(s)                                                   \
    do {                                                                       \
        perror((s));                                                           \
        exit(EXIT_FAILURE);                                                    \
    } while (0)


#define exit_with_err(s, e)                                                    \
    do {                                                                       \
        fprintf(stderr, "%s: %s\n", (s), strerror((e)));                       \
        exit(EXIT_FAILURE);                                                    \
    } while (0)

#define exit_with_err_msg(...)                                                 \
do {                                                                       \
    fprintf(stderr, __VA_ARGS__);                                          \
    exit(EXIT_FAILURE);                                                    \
} while (0)
