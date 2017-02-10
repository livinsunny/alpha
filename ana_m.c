

#include<stdio.h>


int main()
{
    char str1[]="POST";
    char str2[]="SPOTF";

    int i=0;
    _Bool f=1;

    int counter1[26]={0};
    int counter2[26]={0};

    for (i=0;str1[i]!='\0';i++)
    {
        counter1[str1[i] - 'A']++;
    }

    for (i=0;str2[i]!='\0';i++)
    {
        counter2[str2[i] - 'A']++;
    }

    for (i=0;i<26;i++)
    {
        if(counter1[i]!= counter2[i])
        {
            f=0;
            break;
        }
    }

    if (f)
    {
        printf("Its Ana\n");
    }
    else
    {
        printf("Not Ana\n");
    }
}




