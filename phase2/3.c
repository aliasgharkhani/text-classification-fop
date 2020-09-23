#include<stdio.h>


struct news
{
    int num;
    char word[50];
    char category[250];
    struct news *upper;
    struct news *lower;
    struct news *next;
    //struct news *down;
};
typedef struct news news;

void isprint1(rss *ata , char *auxd ,char *auxt)
{
    long long int z = 0 , i;
    for (i = 0; (ata->title)[i] != '\0'; i++)
    {
        if (((ata->title)[i]) >= 97 &&  ((ata->title)[i]) <= 122)
        {
            auxt[z] = (ata->title)[i];
            z++;
        }
        else if (((ata->title)[i]) >= 65 &&  ((ata->title)[i]) <= 90)
        {
            auxt[z] = ((ata->title)[i] + 32);
            z++;
        }
        else if (((ata->title)[i]) == 32)
        {
            auxt[z] = (ata->title)[i];
            z++;
        }
        else
        {
            continue;
        }
    }
    auxt[z] ='\0';
    z = 0;
    for (i = 0; (ata->description)[i] != '\0'; i++)
    {
        if (((ata->description)[i]) >= 97 &&  ((ata->description)[i]) <= 122)
        {
            auxd[z] = (ata->description)[i];
            z++;
        }
        else if (((ata->description)[i]) >= 65 &&  ((ata->description)[i]) <= 90)
        {
            auxd[z] = ((ata->description)[i]) + 32;
            z++;
        }
        else if (((ata->description)[i]) == 32)
        {
            auxd[z] = (ata->description)[i];
            z++;
        }

    }
    auxd[z] ='\0';

}
void filler(news *input , news* root , FILE *f5)
{
    news *q;
    q = (news*)calloc(1,sizeof(news));
    if(root->upper == NULL)
    {
        root->upper = (news*)calloc(1, sizeof(news));
        q = root->upper;
        strcpy(q->word , input->word);
        q->num = input->num;
        fprintf(f5,"%s   %s   %d\n",root->category,q->word,q->num);
    }
    else
    {

        for(q = root->upper;q != NULL;)
        {
            if(strcmp((input->word) ,q->word) == 0)
                continue;
            if(strcmp((input->word) ,q->word) == 1)
            {
                if(q->upper == NULL)
                {
                    q->upper = (news*)calloc(1, sizeof(news));
                    q = q->upper;
                    strcpy(q->word ,input->word);
                    q->num = input->num;
                    fprintf(f5,"%s   %s   %d\n",root->category,q->word,q->num);
                    return;
                }
                else
                {
                    q = q->upper;
                }
            }

            if(strcmp((input->word) ,q->word) == -1)
            {
                if(q->lower == NULL)
                {
                    q->lower = (news*)calloc(1, sizeof(news));
                    q = q->lower;
                    strcpy(q->word ,input->word);
                    q->num = input->num;
                    fprintf(f5,"%s   %s   %d\n",root->category,q->word,q->num);
                    return;
                }
                else
                {
                    q = q->lower;
                    //goto qb;
                }
            }
        }

    }
}

void treeprint(news *p , news *root ,FILE *f5)
{
    if (p != NULL)
    {
        treeprint(p->lower , root , f5);

        treeprint(p->upper , root,f5);
        if((p->num) > 100 && (p->num) < 520)
        {
            filler(p ,root , f5);
        }
    }
}


void BSTfillerL(char* a, news *root)
{
    long long int  i, j = 0;
    char aux[100000];
    news *p;
    while(sscanf(a,"%s%n",aux,&i) == 1)
    {

    a += i;
        if((strlen(aux) == 1) || (strlen(aux) == 2) || (strlen(aux) == 3))
            continue;
        if(root->lower == NULL)
        {
            root->lower = (news*)calloc(1, sizeof(news));
            strcpy(((root->lower)->word) , aux);
            continue;
        }
        p = root->lower;
            line:
            if (strcmp(aux, p->word)==0 )
            {
                p->num += 1;
                continue;
            }

            if (strcmp(aux, p->word)== 1 )
            {
                if((p->upper ) == NULL )
                {
                    p->upper = (news*)calloc(1, sizeof(news));
                    p = p->upper;
                    strcpy(p->word, aux);
                    p->num = 1;
                    continue;
                }
                else
                {
                    p = p->upper;
                    goto line;
                }
            }

            if (strcmp(aux, p->word)== -1 )
            {
                 if((p->lower ) == NULL )
                {
                    p->lower = (news*)calloc(1, sizeof(news));
                    p = p->lower;
                    strcpy(p->word, aux);
                    p->num = 1;
                    continue;
                }
                else
                {
                    p = p->lower;
                    goto line;
                }
            }

    }
}

void c (news *p, rss *ata1 )
{
    char auxt[100000] , auxd[100000];
    news *temp;
    int i, z = 0;
    isprint1(ata1, auxd, auxt);
    BSTfillerL(auxt, p);
    BSTfillerL(auxd, p);
}

