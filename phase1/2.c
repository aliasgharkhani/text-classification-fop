#include<stdio.h>
#include<string.h>
#include<curl/curl.h>

char title[300][200];
char date[300][300];
char description[300][600];
char categorized[300][300];
char categories[300][300];

int kt = 0 , kd = 0, kde = 0 , kc = 0,kca = 0;

void CategoryFinder(char *ata,int c_start,int c_end )
{
    int o , y = 0;
    char aux[1000];
    for (o = c_start;o <= c_end;o++)
    {
        if(ata[o] == '[')
        {
            o++;
            while(ata[o] != '[')
            {
                 o++;
            }
            o++;
            aux[y] = '"';
            y++;
            while(ata[o] != ']')
            {
                aux[y] = ata[o];
                y++;
                o++;
            }
            aux[y] = '"';
            y++;
            aux[y] = ',';
            y++;
        }
    }
    aux[y - 1] = '\0';
    strcpy(categories[kca],aux);
    kca++;
}


void DataFinder(char *ata,int s_start,int s_end ,char flag[50])
{
    int i , j = 0 , p = 0 , w= 0,q = 0, e = 0;
    char temp[3000] , temp1[100];
    for (i = s_start;i <= s_end;i++)
    {
        if(ata[i] == '<')
        {
            i++;
            while (ata[i] != '>')
                {
                    i++;
                }

        }
        else
        {
            temp[j] = ata[i];
            j++;
        }

    }
    temp[j] = '\0';
    if (strcmp(flag,"title") == 0)
    {

        strcat(title[kt] , temp);
        kt++;
    }
    if (strcmp(flag,"date") == 0)
    {

        for (q = 0;q < 24;q++)
        {
            if(temp[q] == ' ')
                w++;
            if (w >= 1 && w <= 3)
            {
                temp1[e] = temp[q];
                e++;
            }
        }
        temp1[e] = '\0';
        strcat(date[kd] , temp1);
        kd++;
    }
    if (strcmp(flag,"description") == 0)
    {
        strcat(description[kde] , temp);
        kde++;
    }
    if (strcmp(flag,"categorized") == 0)
    {
        strcpy(categorized[kc] , temp);
        kc++;
    }
}
void search(char *ata,int start , int end)
{
    char flag[100];
    int t_start,t_end,p_start,p_end,g_start,g_end,c_start,c_end,d_start,d_end;
    int i,j;
    i = start;
    while (ata[i] !='<' || ata[i + 1] !='t' ||  ata[i + 2] !='i' || ata[i + 3] !='t' || ata[i + 4] !='l' || ata[i + 5] !='e' || ata[i + 6] !='>')
    {
        i++;
    }
    t_start = i + 7;
    while (ata[i] !='<' || ata[i + 1] !='/' || ata[i + 2] !='t' ||  ata[i + 3] !='i' || ata[i + 4] !='t' || ata[i + 5] !='l' || ata[i + 6] !='e')
    {
        i++;
    }
    t_end = i - 1;
    strcpy(flag,"title");
    DataFinder(ata,t_start,t_end ,flag);
    while (ata[i - 1] != '<' || ata[i] != 'p'|| ata[i + 1] != 'u' || ata[i + 2] != 'b'|| ata[i + 3] != 'D')
    {
        i++;
    }
    p_start = i + 8;
    while (ata[i - 2] != '<' || ata[i - 1] != '/' || ata[i] != 'p'|| ata[i + 1] != 'u' || ata[i + 2] != 'b'|| ata[i + 3] != 'D')
    {
        i++;
    }
    p_end = i - 3;
    strcpy(flag,"date");
    DataFinder(ata,p_start,p_end ,flag);
    while (ata[i - 1] != '<' || ata[i] != 'g'|| ata[i + 1] != 'u' || ata[i + 2] != 'i'|| ata[i + 3] != 'd' || ata[i + 4] != ' ')
    {
        i++;
    }
    g_start = i + 18;
    g_end = g_start + 4;
    strcpy(flag,"categorized");
    DataFinder(ata,g_start,g_end ,flag);
        while (ata[i - 2] != '<' || ata[i - 1] != 'c' || ata[i] != 'a' || ata[i + 1] != 't' || ata[i + 2] != 'e' || ata[i + 3] !='g')
        {
            i++;
        }
        c_start = i + 9;
        while (ata[i - 2] != '<' || ata[i - 1] != 'd' || ata[i] != 'e' || ata[i + 1] != 's' || ata[i + 2] != 'c' || ata[i + 3] != 'r')
        {
            i++;
        }
        c_end = i - 16;
        strcpy(flag,"categories");
        CategoryFinder(ata,c_start,c_end);
    while (ata[i - 2] != '<' || ata[i - 1] != 'd' || ata[i] != 'e' || ata[i + 1] != 's' || ata[i + 2] != 'c' || ata[i + 3] != 'r')
    {
        i++;
    }
    d_start = i + 20;
    while (ata[i - 3] != '<' || ata[i - 2] != '/' || ata[i - 1] != 'd' || ata[i] != 'e' || ata[i + 1] != 's' || ata[i + 2] != 'c' || ata[i + 3] != 'r')
    {
        i++;
    }
    d_end = i - 7;
    strcpy(flag,"description");
    DataFinder(ata,d_start,d_end ,flag);
}

