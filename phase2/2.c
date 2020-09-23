#include<stdio.h>
#include<string.h>
#include<curl/curl.h>

struct rss
{
    char title[30000];
    char description[30000];
    char categories[30000];
};
typedef struct rss rss;

int kt = 0 , kd = 0, kde = 0 , kc = 0,kca = 0;

void CategoryFinder(char *ata,int c_start,int c_end, rss *n )
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

            while(ata[o] != ']')
            {
                aux[y] = ata[o];
                y++;
                o++;
            }

        }
    }
    aux[y] = '\0';
    strcpy(n ->categories,aux);
    //printf("%s\n",n ->categories);
}


void DataFinder(char *ata,int s_start,int s_end ,char flag[50], rss *f)
{
    int i , j = 0 , p = 0 , w= 0,q = 0, e = 0;
    char temp[30000] , temp1[10000];
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

        strcpy(f->title , temp);
    }

    if (strcmp(flag,"description") == 0)
    {
        strcpy(f->description , temp);
    }
}
void search(char *ata,int start , int end , rss *u)
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
    DataFinder(ata,t_start,t_end ,flag ,u);

        {
        while (ata[i - 2] != '<' || ata[i - 1] != 'c' || ata[i] != 'a' || ata[i + 1] != 't' || ata[i + 2] != 'e' || ata[i + 3] !='g')
            i++;
        }
        c_start = i + 9;
        while (ata[i - 2] != '<' || ata[i - 1] != 'd' || ata[i] != 'e' || ata[i + 1] != 's' || ata[i + 2] != 'c' || ata[i + 3] != 'r')
        {
            i++;
        }
        c_end = i - 16;
        strcpy(flag,"categories");
        CategoryFinder(ata,c_start,c_end, u);
    while (ata[i - 2] != '<' || ata[i - 1] != 'd' || ata[i] != 'e' || ata[i + 1] != 's' || ata[i + 2] != 'c' || ata[i + 3] != 'r')
    {
        i++;
    }
    d_start = i + 26;
    while (ata[i - 3] != '<' || ata[i - 2] != '/' || ata[i - 1] != 'd' || ata[i] != 'e' || ata[i + 1] != 's' || ata[i + 2] != 'c' || ata[i + 3] != 'r')
    {
        i++;
    }
    d_end = i - 12;
    strcpy(flag,"description");
    DataFinder(ata,d_start,d_end ,flag, u);
}

