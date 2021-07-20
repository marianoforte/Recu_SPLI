#include "Text.h"

int Text_NormalizeName(char name[])
{
    int i;

    for(i=0;i<strlen(name);i++)
    {
        if(i==0 || (name[i] != ' ' && name[i-1] == ' '))
        {
            name[i] = toupper(name[i]);
        }
    }
    return i;
}

int Text_Initialize(char myString[])
{
    int i;
    for(i=0;i<strlen(myString);i++)
    {
        myString[i] = '\0';
    }
    return i;
}

int Text_ContainsNumbers(char myString[])
{
    int containsNumbers = 0;

    for(int i=0;i<strlen(myString);i++)
    {
        if(atoi(&myString[i]))
        {
            containsNumbers = 1;
            break;
        }
    }
    return containsNumbers;
}

int Text_PrintString_Internal(char myString[], va_list arguments)
{
    int printedString = -1;
    int format;

    if(myString != NULL)
    {
        printedString = 0;
        for(int i=0;i<=strlen(myString)-1;i++)
        {
            //printf("\n%c", *(myString+i));
            format = Text_ReadFormatMask((myString+i));
            if(format>0)
            {
                i++;
                switch(format)
                {
                    case 1:
                        printf("%c", va_arg(arguments, int));
                        break;
                    case 2:
                        printf("%d", va_arg(arguments, int));
                        break;
                    case 3:
                        printf("%.2f", va_arg(arguments, double));
                        i+=2;
                        break;
                }
            }
            else
            {
                printf("%c", *(myString+i));
            }
        }
    }
    return printedString;
}

int Text_PrintString(char myString[], ...)
{
    int printedString = -1;
    va_list arguments;
    int format;

    if(myString != NULL)
    {
        va_start(arguments, myString);
        printedString = 0;
        for(int i=0;i<=strlen(myString)-1;i++)
        {
            //printf("\n%c", *(myString+i));
            format = Text_ReadFormatMask((myString+i));
            if(format>0)
            {
                i++;
                switch(format)
                {
                    case 1:
                        printf("%c", va_arg(arguments, int));
                        break;
                    case 2:
                        printf("%d", va_arg(arguments, int));
                        break;
                    case 3:
                        printf("%.2f", va_arg(arguments, double));
                        i+=2;
                        break;
                }
            }
            else
            {
                printf("%c", *(myString+i));
            }
        }
        va_end(arguments);
    }
    return printedString;
}

int Text_ReadFormatMask(char* myChar)
{
    int readMask = -2;
    int tempInt;
    int i = 0;
    if(myChar != NULL)
    {
        readMask = -1;
        if(*myChar == '%')
        {
            switch(*(myChar+1))
            {
                case 'c':
                    readMask = 1;
                    break;
                case 'd':
                    readMask = 2;
                    break;
                case '.':
                    do
                    {
                        i++;
                        tempInt = atoi(myChar+i);
                    }while(tempInt!=0);
                    if(*(myChar+i) == 'f')
                    {
                        readMask = 3;
                    }
                default:
                readMask = 0;
            }
        }
    }
    return readMask;
}
