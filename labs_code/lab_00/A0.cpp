#include <iostream>
#define separator 0
#define word 1

unsigned int words_num(char* str)
{
    unsigned num = 0;
    bool cur_place = separator;

    while ( *str )
    {
        if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
            cur_place = separator;
        else if (cur_place == separator)
        {
            cur_place = word;
            num++;
        }
        str++;
    }
    return num;
}

int main(int argc, char* argv[]) 
{
    char* str;
    
    if ( argc == 1 )
    {
        printf("TEST MODE\n");
        str = (char*)("Hello World\tand\n\n\nothers!");
    }
    else if ( argc == 2 )
        str = argv[1];
    else
    {
        printf("Wrong number of parameters. Must be 1.");
        return 1;
    }
    printf(str);
    printf("\nWords in input: %d\n", words_num(str));
    return 0;
}
