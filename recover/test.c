#include <stdio.h>


// int fourByte(int byte)
// {
//     int rest = 0;
//     do
//     {
//         rest = byte % 16;
//         byte /= 16;
//     }
//     while(byte != 0);

//     if (rest == 14)
//     {
//         return 0;
//     }
//     return 1;
// }

int fourByte(int byte)
{
    if (byte >= 0xe0 && byte <= 0xef)
    {
        return 1;
    }
    return 0;
}

int main ()
{

    printf("%i", fourByte(0xf0));
}
