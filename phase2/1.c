#include<stdio.h>
#include<string.h>
#include<curl/curl.h>
#include"ATA2.c"
#include"ctype2.c"
#include<stdlib.h>

void Post(char *answer, char *url){
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *chunk = NULL;
        chunk = curl_slist_append(chunk,"X-Requested-With: XMLHttpRequest");
        chunk = curl_slist_append(chunk, "Content-Type: application/json");
        chunk = curl_slist_append(chunk, "Authoriation: application/json");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(answer));
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, answer);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
        curl_slist_free_all(chunk);
    }
    curl_global_cleanup();
}

char *RSS;

size_t Write(void *ptr1, size_t size, size_t number)
{
    size_t new_len = strlen(RSS) + size * number;
    RSS = realloc(RSS, new_len+1);
    if (RSS == NULL) {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(RSS + strlen(RSS), ptr1, size * number);
    RSS[new_len] = '\0';

    return size * number;
}


char *GetFromUrl(char *url){
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        RSS = malloc(1);
        RSS[0] = '\0';

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Write);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

    }
    return RSS;
}

int main()
{
    rss  *ptr;
    news *p1 , o1, *q1;
    o1.next=p1;
    p1 = (news*)calloc(1, sizeof(news));
    int q = 0 , i ,u = 0 ,start = 0,end = 0 ,a =0 ,s = 0,s1 = 0 , x = 0,w,yt = 0, flag = 0, num = 0 , url1 = 0 ,er = 0;
    char ali[20000] , ata0[3000][500] , ata[100000] ;
    ptr =(rss*)calloc(1, sizeof(rss));
    GetFromUrl( "http://team41:ali1395ata@fop-project.ir/news/get-urls/?phase=2") ;
    FILE *f10=fopen("tet10.txt","w");
    FILE *f11=fopen("tet11.txt","a");
    fprintf(f10,"%s",RSS);
    fclose(f10);
    FILE *f5 = fopen("words.txt" , "a");
    f10=fopen("tet10.txt","r");
    while(fscanf(f10,"%s\n",ali)!=EOF)
    {
        strcpy(ata0[q],ali);

        if (ata0[q][4] == 's')
        {
            for (i = 4;ata0[q][i] != '\0';i++)
                ata0[q][i] = ata0[q][i+1];
        }
        q++;

    }
    q1 = (news*)calloc(1,sizeof(news));
    FILE *f2=fopen("tet3.txt","w");
    printf("%d",q);
    for (w = 0;w < q;w++)
    {
        printf("%d",w);
        GetFromUrl( ata0[w]);
        fprintf(f2,"%s ",RSS);
        FILE *f1=fopen("tet2.txt","w");
        fprintf(f1,"%s ",RSS);
        fclose(f1);
        f1=fopen("tet2.txt","r");
        if(f1)
        {
            int er = 0;
            while((ata[er] = getc(f1)) != EOF)
                {
                    er++;
                }
                ata[er] = '\0';
        }



        i = 0;
        while( ata[i] != '\0')
        {
            i++;
            if (ata[i] == '<' && ata[i + 1] == 'i' && ata[i + 2] == 't' && ata[i + 3] == 'e' && ata[i + 4] == 'm' )
            {
                start = i - 1;
                s = 1;

            }
            if (ata[i - 1] == '<' && ata[i] == '/' && ata[i + 1] == 'i' && ata[i + 2] == 't' && ata[i + 3] == 'e' && ata[i + 4] == 'm' )
            {
                end = i + 5;
                s1 = 1;

            }
            if (s == 1 && s1 == 1)
            {
                s = 0;
                s1 = 0;
                ptr =(rss*)calloc(1 , sizeof(rss));
                search(ata,start,end, ptr);
                num++;
                for (q1 = p1; q1->next != NULL; q1 = q1->next)
                {
                   printf("A");
                    yt++;
                    if (strcmp(q1->category, ptr->categories) == 0)
                    {
                        printf("S");
                        c(q1,ptr );
                        printf("E");
                        printf("H");
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    q1->next = (news*)calloc(1,sizeof(news));
                    strcpy(q1->category, ptr->categories);
                    c(q1 ,ptr );
                }
                flag = 0;
            }

        free(ptr);
        }
        fclose(f1);
        printf("ahar");
    }
    printf("tehran");
    fclose(f2);
    for (q1 = p1; q1 != NULL; q1 = q1->next)
    {

        printf("%s\n",q1->category);
        treeprint(q1->lower,q1, f5);
    }
    printf("tabriz");
    fclose(f5);
    fclose(f11);
    return 0;
}

