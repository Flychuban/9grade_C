#include <stdio.h>

#define COMMAND(name, type) type ## _ ## name ## _command
#define DEFINE_COMMAND(name, type) void COMMAND(name, type)(void)
#define DEFINE_EXTERNAL_COMMAND(name) DEFINE_COMMAND(name, external)
#define DEFINE_INTERNAL_COMMAND(name) DEFINE_COMMAND(name, internal)
#define CALL_COMMAND(name, type) COMMAND(name, type)()
#define CALL_INTERNAL_COMMAND(name) CALL_COMMAND(name, internal)
#define CALL_EXTERNAL_COMMAND(name) CALL_COMMAND(name, external)

/* CALL_COMMAND(zzz, xxx) -> entry in DEFINE_COMMAND(zzz, xxx)
   CALL_INTERNAL_COMMAND(print) -> entry in DEFINE_INTERNAL_COMMAND(print)
   CALL_EXTERNAL_COMMAND(quit) -> entry in DEFINE_EXTERNAL_COMMAND(quit)

   If you want to call specific command you have to give similar parameters and arguments 
*/

int main()
{
    printf("HI! \n");
    CALL_COMMAND(zzz, xxx);
    return 0;
}

DEFINE_COMMAND(zzz, xxx)
{
    printf("I'm in DEFINE_COMMAND");
}

DEFINE_INTERNAL_COMMAND(print)
{
    printf("I'm in DEFINE_INTERNAL_COMMAND");
}

DEFINE_EXTERNAL_COMMAND(quit)
{
    printf("I'm in DEFINE_EXTERNAL_COMMAND");
}


// #include <stdio.h>

// #define COMMAND(NAME, TYPE) TYPE ## _ ## NAME ## _command(void);
// #define DEFINE_COMMAND(NAME, TYPE) void COMMAND(NAME, TYPE){ \
//     printf("\n I'm in a DEFINE_COMMAND"); \
// }
// #define DEFINE_EXTERNAL_COMMAND(NAME) DEFINE_COMMAND(NAME, external)
// #define DEFINE_INTERNAL_COMMAND(NAME) DEFINE_COMMAND(NAME, internal)
// #define CALL_COMMAND(NAME, TYPE) DEFINE_COMMAND(NAME, TYPE)
// #define CALL_INTERNAL_COMMAND(NAME) CALL_COMMAND(NAME, internal)
// #define CALL_EXTERNAL_COMMAND(NAME) CALL_COMMAND(NAME, external)

// int main(void)
// {

//     DEFINE_COMMAND(quit, external);
//     // DEFINE_INTERNAL_COMMAND(print);
//     // DEFINE_EXTERNAL_COMMAND(quit);
//     // CALL_COMMAND(quit, internal);
//     // CALL_INTERNAL_COMMAND(quit);
//     // CALL_EXTERNAL_COMMAND(delete);

//     return 0;
// }