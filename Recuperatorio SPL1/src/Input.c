#include "Input.h"
static int Input_GetInt(int* number);
static int Input_GetFloat(float* number);

static int Input_GetInt(int* number)
{
    int gotInt = -2;

    if(number != NULL)
    {
        gotInt = 0;
        if(scanf("%d", number) == 0)
        {
            fflush(stdin);
            gotInt = -1;
        }
    }
    return gotInt;
}

static int Input_GetFloat(float* number)
{
    int gotInt = -2;

    if(number != NULL)
    {
        gotInt = 0;
        if(scanf("%f", number) == 0)
        {
            fflush(stdin);
            gotInt = -1;
        }
    }
    return gotInt;
}

int Input_Int(int* number, char* inputMsg, ...)
{
    int gotInt = -2;
    va_list arguments;

    if(number != NULL && inputMsg != NULL)
    {
        gotInt = -1;
        va_start(arguments, inputMsg);
        Text_PrintString_Internal(inputMsg, arguments);
        if(!Input_GetInt(number))
        {
            gotInt = 0;
        }
        va_end(arguments);
    }
    return gotInt;
}

int Input_IntOverValue(int* number, char inputMsg[], int minValue, char invalidInput[],...)
{
    int assignedValue = -2;
    va_list arguments;
    if(number != NULL)
    {
        va_start(arguments, invalidInput);
        Text_PrintString_Internal(inputMsg, arguments);
        if(!Input_GetInt(number))
        {
            assignedValue = 0;
            if(*number<minValue)
            {
                assignedValue = -1;
            }
        }
        va_end(arguments);
    }
    return assignedValue;
}

int Input_IntExcludingRange(int* number, char inputMsg[], int min, int max, char invalidInput[],...)
{
    int gotInt = -3;
    va_list arguments;

    if(number != NULL && min<max)
    {
        gotInt = -2;
        va_start(arguments, invalidInput);
        Text_PrintString_Internal(inputMsg, arguments);
        if(!Input_GetInt(number))
        {
            gotInt = -1;
            if(*number>=max && *number<=min)
            {
                gotInt = 0;;
            }
            else
            {
                Text_PrintString_Internal(invalidInput, arguments);
            }
        }
        va_end(arguments);
    }
    return gotInt;
}

int Input_IntInRange(int* number, char inputMsg[], int min, int max, char invalidInput[],...)
{
    int gotInt = -2;
    va_list arguments;

    if(number != NULL && inputMsg != NULL && invalidInput != NULL)
    {
        va_start(arguments, invalidInput);
        do
        {
            Text_PrintString_Internal(inputMsg, arguments);
            if(!Input_GetInt(number))
            {
                gotInt = 0;
                if(*number>max || *number<min)
                {
                    printf("\n%s", invalidInput);
                    gotInt = -1;
                }
            }
        }while(gotInt == -1);
        va_end(arguments);
    }
    return gotInt;
}

int Input_Float(float* number, char inputMsg[], ...)
{
    int gotFloat = -2;
    va_list arguments;

    if(number != NULL && inputMsg != NULL)
    {
        gotFloat = -1;
        va_start(arguments, inputMsg);
        Text_PrintString_Internal(inputMsg, arguments);
        if(!Input_GetFloat(number))
        {
            gotFloat = 0;
        }
        va_end(arguments);
    }
    return gotFloat;
}

int Input_FloatOverValue(float* number, char inputMsg[], int minValue, ...)
{
    int assignedValue = -3;
    va_list arguments;
    if(number != NULL)
    {
        assignedValue = -2;
        va_start(arguments, minValue);
        Text_PrintString_Internal(inputMsg, arguments);
        if(!Input_GetFloat(number))
        {
            assignedValue = 0;
            if(*number<minValue)
            {
                assignedValue = -1;
            }
        }
        va_end(arguments);
    }
    return assignedValue;
}


int Input_FloatExcludingRange(float* number, char inputMsg[], int min, int max, ...)
{
    int gotFloat = -3;
    va_list arguments;

    if(number != NULL)
    {
        gotFloat = -2;
        va_start(arguments, max);
        Text_PrintString_Internal(inputMsg, arguments);
        if(!Input_GetFloat(number))
        {
            gotFloat = -1;
            if(*number>=max && *number<=min)
            {
                gotFloat = 0;;
            }
        }
        va_end(arguments);
    }
    return gotFloat;
}

int Input_FloatInRange(float* number, char inputMsg[], int min, int max, ...)
{
    int gotFloat = -3;
    va_list arguments;

    if(number != NULL)
    {
        gotFloat = -2;
        va_start(arguments, max);
        Text_PrintString_Internal(inputMsg, arguments);
        if(!Input_GetFloat(number))
        {
            gotFloat = -1;
            if(*number<=max && *number>=min)
            {
                gotFloat = 0;;
            }
        }
        va_end(arguments);
    }
    return gotFloat;
}

int Input_GetChar(char* c, char inputMsg[], ...)
{
    int assignedChar = -2;
    va_list arguments;
    if(c!=NULL && inputMsg != NULL)
    {
        assignedChar = 0;
        va_start(arguments, inputMsg);
        Text_PrintString_Internal(inputMsg, arguments);
        va_end(arguments);
        if(scanf("%c", c) == 0)
        {
            assignedChar = -1;
        }
    }
    return assignedChar;
}

int Input_GetChar_WithArguments(char* c, char inputMsg[], va_list arguments)
{
    int assignedChar = -2;
    if(c!=NULL && inputMsg != NULL)
    {
        assignedChar = 0;
        Text_PrintString_Internal(inputMsg, arguments);
        if(scanf("%c", c) == 0)
        {
            assignedChar = -1;
        }
    }
    return assignedChar;
}

int Input_Confirmation(char inputMsg[], char invalidInput[], char confirmChar, char cancelChar, ...)
{
    char answer;
    int confirmation;
    int wrongAnswer;
    va_list arguments;

    va_start(arguments, cancelChar);
    do
    {
        fflush(stdin);
        Input_GetChar_WithArguments(&answer, inputMsg, arguments);
        answer = tolower(answer);
        if(answer != confirmChar && answer != cancelChar)
        {
            printf("\n%s", invalidInput);
            wrongAnswer = 1;
        }
        else
        {
            wrongAnswer = 0;
            if(answer == confirmChar)
            {
                confirmation = 1;
            }
            else
            {
                confirmation = 0;
            }

        }
    }while(wrongAnswer);
    return confirmation;
}


int Input_String(char myString[], int sizeOfString,char inputMsg[])
{
    int i;
    printf("\n%s", inputMsg);
    fflush(stdin);
    fgets(myString,sizeOfString, stdin);
    for(i=0;i<strlen(myString);i++)
    {
        if(myString[i] == '\n' && myString[i+1] == '\0')
        {
            myString[i] = '\0';
            break;
        }
    }
    return i;
}

int Input_String_Name(char name[],int sizeOfString, char inputMsg[], char numberFound[])
{
    int input;
    do
    {
        input = 0;
        Input_String(name, sizeOfString,inputMsg);
        Text_NormalizeName(name);
        if(Text_ContainsNumbers(name))
        {
            input = 1;
            printf("\n%s", numberFound);
        }
    }while(input);
    return input;
}
