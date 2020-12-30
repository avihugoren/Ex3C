#include "stdio.h"
#define LINE 256
#define WORD 30
#define MAX_LINES 250
#include "stdlib.h"
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
           if (ch =='\n')
               break;
           if (ch ==EOF)
               break;

       }
    }
    return counter;
}
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
        if(temp=='\n'||temp=='\t'||temp==' '||temp==EOF||temp=='\0')
            return counter;
    }
    return counter;
}
int strLegnth(char *str1)
{
    int counter=0;
    while (str1[counter]!='\0'&&str1[counter]!= ' '&&str1[counter]!='\n'&&str1[counter]!='\t'&&str1[counter]!=EOF&&str1[counter]!='\r')
            counter++;
    return counter;
}
int lineLengh(char *str)
{
    int counter =0;
    while (str[counter]!='\n'&&str[counter]!=EOF)
        counter++;
    return counter;
}
int substring( char * str1, char * str2)
{
    int counter=0;
    int str1_length = lineLengh(str1);
    int str2_length = strLegnth(str2);
//    printf("str 1 length is : %d\n",str1_length);
//    printf("str 2 length is : %d\n",str2_length);
//    for (int i = 0; i < str1_length; ++i) {
//        printf("%c",str1[i]);
//    }
//    printf("\n");
    if(str2_length > str1_length)
        return 0;
    for (int i = 0; i <=str1_length-str2_length ; ++i)
    {
        for (int j = 0; j <str2_length ; ++j)
        {
          if(str2[j]==str1[i+j])
          {
              counter++;
              if(counter==str2_length)
                  return 1;
          }
          else
          {
              counter=0;
              break;
          }
        }
    }
    return 0;
}
int similar (char *s, char *t)
{
    if(strLegnth(s) == strLegnth(t))
    {
        return substring(s,t);
    }
    if(strLegnth(s)-1 != strLegnth(t))
        return 0;
    int counterRemove=0;
    int indexT=0;
    for(int i=0;i<strLegnth(s);i++)
    {
        if(s[i] == t[indexT])
            indexT++;
        else{
            counterRemove++;
        }
        if(counterRemove>1)
            return 0;
    }
    return 1;
}
void print_lines(char * str) {
    char line[LINE];
    int x = 0;
    for (int i = 0; i < MAX_LINES; ++i) {
        x = myGetline(line);
//        for (int k = 0; k <x ; ++k)
//            printf("%c",line[k]);
        if (substring(line, str))
        {
//            printf("debug");
            for (int j = 0; j < x; ++j)
                printf("%c", line[j]);

        }
    }
    printf("\n");
}

void print_similar_words(char *str) {
    int x = 0;
    char word[WORD];
    for (int i = 0; i < MAX_LINES; i++)
        for (int j = 0; j < (double)LINE/WORD; ++j)
        {
            x = getword(word);
            if (similar(word, str))
            {
                for (int k = 0; k < x; ++k)
                    printf("%c", word[k]);
                if(word[x-1]!='\n'&&x>0)
                    printf("\n");
//                    printf("\n");
            }
        }

}

    int main() {
        char c[WORD];
        int x = getword(c);
        char *temp = (char *) malloc(x);
        if (temp == NULL) {
            printf("Error");
            return -1;
        }
        for (int i = 0; i <x; i++)
            temp[i] = c[i];
//        temp[x] = '\0';
        char c1[1];
        getword(c1);
        if (c1[0] == 'a') {
            print_lines(temp);
        } else print_similar_words(temp);
        free(temp);
        return 0;
    }





