#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGSIZE 2000


void readUntilEOF(char str[]);
void putSpaceAfterPunctuations(char inputStr[]);
int isCharacterCapitalized(char character);
void capitalizeAfterPunctuation(char inputStr[]);
void copyArray(char copiedArray[], char targetArray[]);
void closeUnclosedBrackets(char inputStr[]);
void hyphenateString(char inputStr[]);
int isCharacterLetter(char character);
int isCharacterVowel(char character);
int isCharacterConsonant(char character);

int main()
{

    char userStr[STRINGSIZE],
         outputStr[STRINGSIZE];


    readUntilEOF(userStr);

    putSpaceAfterPunctuations(userStr);
    capitalizeAfterPunctuation(userStr);
    closeUnclosedBrackets(userStr);
    hyphenateString(userStr);

    copyArray(userStr,outputStr);
    fprintf(stdout, outputStr);
    return 0;
}

void readUntilEOF(char str[])
{
    char ch;
    int i = 0;
    ch = getchar();
    while(ch!=EOF)
    {

        if (i < STRINGSIZE -1)
        {
            str[i] = ch;
            i++;
        }
        ch = getchar();
    }
    str[i] = '\0';
}

void putSpaceAfterPunctuations(char inputStr[])
{
    char outputStr[STRINGSIZE];

    int inputCursor = 0;
    int outputCursor = 0;
    while(inputStr[inputCursor] != '\0')
    {

        outputStr[outputCursor] = inputStr[inputCursor];
        if((inputStr[inputCursor] == '.' ||
           inputStr[inputCursor] == ',' ||
           inputStr[inputCursor] == ':' ||
           inputStr[inputCursor] == ';' ||
           inputStr[inputCursor] == '?' ||
           inputStr[inputCursor] == '!') && inputStr[inputCursor+1] != ' ')
           {
               outputCursor++;
               outputStr[outputCursor] = ' ';
           }

           inputCursor++;
           outputCursor++;
    }
    outputStr[outputCursor] = '\0';
    copyArray(outputStr, inputStr);
}
int isCharacterCapitalized(char character)
{
    // returns 1 if input character is capitalized. If it's not, returns 0.
    char capitalizedAlphabet[26] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    for(int i = 0; i < 26; i++)
    {
        if(capitalizedAlphabet[i] == character){
            return 0;
        }
    }
    return 1;
}
void capitalizeAfterPunctuation(char inputStr[])
{
    char outputStr[STRINGSIZE];

    int cursor = 0;

    while(inputStr[cursor] != '\0')
    {
        outputStr[cursor] = inputStr[cursor];
        if(inputStr[cursor] == '.' && isCharacterCapitalized(inputStr[cursor + 2]) == 0)
           {
               outputStr[cursor+2] = inputStr[cursor+2] - 32;
               cursor += 2;
           }
           cursor++;
    }

    outputStr[cursor] = '\0';
    copyArray(outputStr,inputStr);
}
void copyArray(char copiedArray[], char targetArray[])
{
    int i = 0;
    while(copiedArray[i] != '\0')
        {
            targetArray[i] = copiedArray[i];
            i++;
        }
    targetArray[i] = '\0';
}
void closeUnclosedBrackets(char inputStr[])
{

    char bracketTypes[6] = {'(',')',
                            '{','}',
                            '[',']'};

//i increments by 2 at a time, so i + 1 means closing bracket for every bracket type.
//loop checks for 1 bracket type at a time.
    for(int i = 0; i < 6; i += 2)
    {
        char outputStr[STRINGSIZE];
        int inputCursor = 0;
        int outputCursor = 0;
        while(inputStr[inputCursor] != '\0')
        {
            outputStr[outputCursor] = inputStr[inputCursor];

//When program encounters with an opening bracket, it searches for a closing bracket until it encounters with '.' or '\0'.
//If there is no closing bracket until '.' or '\0', program inserts one.
            if(inputStr[inputCursor] == bracketTypes[i])
                {
                    while(inputStr[inputCursor] != '.' && inputStr[inputCursor] != '\0')
                    {
                        if(inputStr[inputCursor] == bracketTypes[i+1])
                        {
                            outputStr[outputCursor] = inputStr[inputCursor];

                            break;
                        }else if(inputStr[inputCursor + 1] == '.' || inputStr[inputCursor] == '\0' )
                        {
                            outputStr[outputCursor] = inputStr[inputCursor];
                            outputCursor++;
                            outputStr[outputCursor] = bracketTypes[i+1];



                            break;
                        }else
                        {
                            outputStr[outputCursor] = inputStr[inputCursor];
                        }
                        inputCursor++;
                        outputCursor++;
                    }
                }
            inputCursor++;
            outputCursor++;
        }
        outputStr[outputCursor] = '\0';
        copyArray(outputStr , inputStr);
    }


}
void hyphenateString(char inputStr[])
{


    char outputStr[STRINGSIZE];

    int outputCursor = 0;
    int inputCursor = 0;

    while(inputStr[inputCursor] != '\0')
    {

//Searches for first letter of a word.
        if(isCharacterLetter(inputStr[inputCursor]) == 1)
        {
//Analyzes the word to calculate the size of it's hyphenated form.
            int tempCursor = inputCursor;
            int tempCursor2;
            int lengthOfWord = 0;
            int quantityOfVowels = 0;
            while(isCharacterLetter(inputStr[tempCursor]) == 1)
            {
                lengthOfWord++;

                if(isCharacterVowel(inputStr[tempCursor]) == 1)
                {
                    quantityOfVowels++;
                }
                tempCursor++;
            }

            tempCursor = inputCursor;
            char hyphenatedWord[lengthOfWord + quantityOfVowels - 1];
            int hyphenatedWordCursor = 0;

//Loops over every syllable.
            while(hyphenatedWordCursor < lengthOfWord + quantityOfVowels - 1)
            {
                tempCursor2 = tempCursor;
                int isThereMoreVowel = 0;
                while(tempCursor2 - inputCursor < lengthOfWord)
                {
                    if(isCharacterVowel(inputStr[tempCursor2]))
                    {
                        isThereMoreVowel = 1;
                        break;
                    }
                    tempCursor2++;
                }

                if(hyphenatedWordCursor != 0 && isThereMoreVowel == 1)
                {
                    hyphenatedWord[hyphenatedWordCursor] = '-';
                    hyphenatedWordCursor++;
                }
                while(isCharacterVowel(inputStr[tempCursor]) == 0 && tempCursor - inputCursor < lengthOfWord)
            {
                hyphenatedWord[hyphenatedWordCursor] = inputStr[tempCursor];
                tempCursor++;
                hyphenatedWordCursor++;
            }

                hyphenatedWord[hyphenatedWordCursor] = inputStr[tempCursor];
                tempCursor++;
                hyphenatedWordCursor++;

                int consonantCounter = 0;
                tempCursor2 = tempCursor;
                while(isCharacterConsonant(inputStr[tempCursor2]) == 1)
                {
                    consonantCounter++;
                    tempCursor2++;
                }
                if(consonantCounter == 1)
                {


                }else if(consonantCounter == 2)
                {

                    hyphenatedWord[hyphenatedWordCursor] = inputStr[tempCursor];
                    hyphenatedWordCursor++;
                    tempCursor++;

                }else if(consonantCounter == 3)
                {
                     printf("%c", inputStr[tempCursor]);
                    hyphenatedWord[hyphenatedWordCursor] = inputStr[tempCursor];
                    hyphenatedWordCursor++;
                    tempCursor++;
                     printf("%c", inputStr[tempCursor]);
                    hyphenatedWord[hyphenatedWordCursor] = inputStr[tempCursor];
                    hyphenatedWordCursor++;
                    tempCursor++;

                }
            }

            for(int i = 0; i < lengthOfWord + quantityOfVowels - 1; i++)
            {
                outputStr[outputCursor] = hyphenatedWord[i];
                outputCursor++;
            }
            inputCursor += lengthOfWord;




        }else
        {
            outputStr[outputCursor] = inputStr[inputCursor];
            inputCursor++;
            outputCursor++;
        }
    }
    outputStr[outputCursor] = '\0';
    copyArray(outputStr , inputStr);

}
int isCharacterLetter(char character)
{
//returns 1 if given character is a letter. If it's not, returns 0.
     char alphabet[52] = {'q','w','e','r','t','y','u','o','p','a','s','d','f','g','h','j','k','l','i','z','x','c','v','b','n','m','Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
    for(int i = 0; i < 52; i++)
    {
        if(alphabet[i] == character)
        {
            return 1;
        }
    }
    return 0;
}
int isCharacterVowel(char character)
{
    char vowels[10] = {'e','o','i','a','u','E','O','I','A','U'};
    for(int i = 0; i < 10; i++)
    {
        if(vowels[i] == character)
        {
            return 1;
        }
    }
    return 0;
}
int isCharacterConsonant(char character)
{
    char consonants[42] = {'q','w','r','t','y','p','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','Q','W','R','T','Y','P','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
    for(int i = 0; i < 42 ; i++)
    {
        if(consonants[i] == character)
        {
            return 1;
        }
    }
    return 0;

}
