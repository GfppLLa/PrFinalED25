/*aqui sera o entry point*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#ifdef _WIN32 || _WIN64
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

int main(int argc, char *argv[])
{

printf("Hello, World!\n");
sleep(500);
printf("funcionou\n");
return 0;
}