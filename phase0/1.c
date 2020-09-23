#include <stdio.h>
#include <string.h>
#include <curl/curl.h>



void post(char input[] , char input1[])
{
    char df[100],fg[10] , fgh[10];
  //int b;
  //int *a;
  CURL *curl;
  CURLcode res;
    //scanf("%d",&b);
    //a = &b;

    curl_global_init(CURL_GLOBAL_ALL);
    strcpy(fgh,input1);
    strcpy(fg,input);

  curl = curl_easy_init();
  if(curl) {

    curl_easy_setopt(curl, CURLOPT_URL, "http://team41:ali1395ata@fop-project.ir/phase0");
    strcpy(df,"member=");
    strcat(df,fgh);
    strcat(df,"&answer=");
    strcat(df,input);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS,df);


    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));


    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
}








void function1(char ata1[][100] , int i)
{

	int  j , k , r = 0 , alamat = 0 , javab = 0 , m = 0 , max ,y = 0 , o ,w;
	char ata[100] , df[100] , fg[10];
	for(j = 0; j < i  ; j++)
	{
		for (k = j+1 ; k < i; k++)
		{
			if (ata1[j][0]==ata1[k][0] && ata1[j][0] != '0' && ata1[k][0] != '0' && strlen(ata1[j])==strlen(ata1[k]))
			{
				for (w = 0; w < strlen(ata1[j]) ; w++)
				{

					if ( ata1[j][w] != ata1[k][w] )
					{
						alamat ++;
						break;
					}

				}

				if ( alamat == 0 )
				{
					javab ++;

					strcpy(ata1[k],"0");

				}
				alamat = 0;

			}
		}
		k = 0;

		if (javab == max)
		{

			while ( ata1[m][y] == ata1[j][y] && ata1[m][y]!= '\0')
				{
					y++;

				}

				y =0;
			if (ata1[m][y] > ata1[j][y] && ata1[m][y] != '\0' )
				m = j;
		}
		if (javab > max)
		{

			max = javab;
			m = j;
		}
		javab = 0;

	}
	strcpy(df,"1");
    post(ata1[m] , df);
	printf("%s",ata1[m]);
}

void function2(char art[][100] , int i)
{

	int javab2 = 1, g , j = 0 ,o = 1 ,n =0, k = 0, max1 = 0, e = 0, t = 0,javab=1, s = 0,f = 0,test=0, h , y = 0, l = 0 ;
    char  aux[1000] , aux1[1000] , aux2[1000] , ata1[10] , ata2[2];

	for (h = 0; h < i; h++)
	{
		if (strlen(art[h]) > max1)
			max1 = strlen(art[h]);
	}
	for (h = 0; h < i; h++)
	{
		if (strlen(art[h]) == max1)
		{
			for (e = 0; e < max1 ; e++)
			{
				aux[e + n] = art[h][e];

			}
			n += max1 ;

		}
	}

	for (h = 0; h < n; h+= max1)
	{
		for(y = h; y < n; y+= max1)
		{
			if (aux[h] == aux[y] && y != h && aux[h] != '1' && aux[y] != '1')
			{

				for(o = 0 ; o < max1; o++)
				{
					if (aux[o + h] == aux[o + y])
					{
						l++;

					}

				}

				if (l == max1)
				{
					for(o = 0 ; o < max1; o++)
					{
						aux[o + y] = 0;
					}
				}
				l = 0;
			}
		}
	}
	strcpy(ata2,"2");
	sprintf(ata1,"%d",(strlen(aux)/ max1));
	post(ata1, ata2);
	//printf("%d", (strlen(aux)/ max1));
}

void get_page(const char* url, const char* file_name)
{
  CURL* easyhandle = curl_easy_init();

  curl_easy_setopt( easyhandle, CURLOPT_URL, url ) ;

  FILE* file = fopen( file_name, "w");

  curl_easy_setopt( easyhandle, CURLOPT_WRITEDATA, file) ;

  curl_easy_perform( easyhandle );

  curl_easy_cleanup( easyhandle );

  fclose(file);

}

int main()
{
	int q = 0 ,a ;
	char ata0[8000][100],ata[100];
	get_page( "http://team41:ali1395ata@fop-project.ir/phase0", "text.txt" ) ;
	FILE *f=fopen("text.txt","r");
	while(fscanf(f,"%s",ata)!=EOF)
    {
	   strcpy(ata0[q],ata);
	   q++;
	}
	printf("Please choose the function to get the answer:");
	scanf("%d",&a);

    if (a == 1)
        function1(ata0,q);
    if (a == 2)
        function2(ata0,q);

}

