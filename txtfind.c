#include "stdio.h"
#define LINE 256
#define WORD 30
#define MAX_LINES 250
#include "stdlib.h"
//function that gets line from the txt and save it in s[]
int myGetline(char s[])
{
    char ch;
    int counter=0;
    for (int i = 0; i <LINE ; ++i)
    {
       if(scanf("%c", &ch)==1)
       {
           s[counter]=ch;
           counter++;
           //the options to end line
           if (ch =='\n')
               break;
           if (ch ==EOF)
               break;

       }
    }
    return counter;
}
//functon that gets word from the text and put it in w[]
int getword(char w[])
{
    int counter=0;
    char temp;
    for(int i=0;i<WORD;i++)
    {
        if(scanf("%c",&temp)==1){
            w[counter]=temp;
            counter++;
        }
        //all the options to end word
        if(temp=='\n'||temp=='\t'||temp==' '||temp==EOF||temp=='\0')
            return counter;
    }
    return counter;
}
//function that receive string and check its length
int strLegnth(char *str1)
{
    int counter=0;
    //while its not the end of the string
    while (str1[counter]!='\0'&&str1[counter]!= ' '&&str1[counter]!='\n'&&str1[counter]!='\t'&&str1[counter]!=EOF&&str1[counter]!='\r')
            counter++;
    return counter;
}
//function that receive line and check its length
int lineLength(char *str)
{
    int counter =0;
    while (str[counter]!='\n'&&str[counter]!=EOF)
        counter++;
    return counter;
}
int substring( char * str1, char * str2)
{
    int counter=0;
    int str1_length = lineLength(str1);
    int str2_length = strLegnth(str2);
    if(str2_length > str1_length)
        return 0;
    //for loop that runs from 0 to str1 length-str2 length and check if str2 is substring of str 1
    for (int i = 0; i <=str1_length-str2_length ; ++i)
        for (int j = 0; j <str2_length ; ++j)
            //if the equal then counter get +1
          if(str2[j]==str1[i+j])
          {
              counter++;
              //its mean that str1 contain str 2
              if(counter==str2_length)
                  return 1;
          }
          else//they not equal so set counter to zero
          {
              counter=0;
              break;
          }

    return 0;
}
int similar (char *s, char *t)
{
    //the length is equal checks that the words are the same
    if(strLegnth(s) == strLegnth(t))
    {
        for (int i = 0; i <strLegnth(t) ; ++i)
            if (s[i]!=t[i])
                return 0;
        return 1;

    }
    //if the difference is lengths is bigger then 1 so they cant be similar
    if(strLegnth(s)-1 != strLegnth(t))
        return 0;
    int counterRemove=0;
    int indexT=0;
    for(int i=0;i<strLegnth(s);i++)
    {
        //if they equal so both get +1
        if(s[i] == t[indexT])
            indexT++;
        //they not equal so makes counterRemove +1 indexT stay as is
        else{
            counterRemove++;
        }
        //need to remove more then one char so they not equal
        if(counterRemove>1)
            return 0;
    }
    return 1;
}
void print_lines(char * str)
{
    char line[LINE];
    int x = 0;
    //runs on the Max lines of the text
    for (int i = 0; i < MAX_LINES; ++i)
    {
        x = myGetline(line);//copy line from the text into line
        //if str is sub string in the line then print it
        if (substring(line, str))
        {
            for (int j = 0; j < x; ++j)
                printf("%c", line[j]);

        }
    }
    printf("\n");
}

void print_similar_words(char *str) {
    int x = 0;
    char word[WORD];
    //runs on the Max lines of the text
    for (int i = 0; i < MAX_LINES; i++)
        //runs on the maximum words a line can hold (size of line/size of word)
        for (int j = 0; j < (double)LINE/WORD; ++j)
        {
            x = getword(word);//copy the word from the line into word
            //if it similar with str then print it
            if (similar(word, str))
            {
                for (int k = 0; k < x; ++k)
                    printf("%c", word[k]);
                if(word[x-1]!='\n'&&x>0)//checks if the word didnt contain \n
                    printf("\n");
            }
        }

}

    int main() {
        char str[WORD];//to hold the str from the txt
        int x = getword(str);//copy the string that we use in function to str from the txt
        char *temp = (char *) malloc(x);//to hold str with no empty space after x (size of str)
        if (temp == NULL) {
            printf("Error");
            return -1;
        }
        //copy str into temp
        for (int i = 0; i <x; i++)
            temp[i] = str[i];
        char c1[1];//to hold a or b
        getword(c1);
        if (c1[0] == 'a')
        {
            print_lines(temp);
        }
        else print_similar_words(temp);
        free(temp);
        return 0;
    }





