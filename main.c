
#include <stdio.h>
#include "proxy.h"

FILE * fp;
    int value[5];
    char SERVER_ADDR[100];
    char configtmp[5][20];
    int m=0;
    if((fp=fopen("bedrock-proxy.conf","r"))!=NULL)
    {
    	fscanf(fp,"%s",configtmp[m]);
        while(m<5)
        {
        	fscanf(fp,"%d",&value[m]);
        	m++;
        	fscanf(fp,"%s",configtmp[m]);
		}
		fscanf(fp,"%s",SERVER_ADDR);
    }
    else
    {
    	printf("cannot find configure file.\n");
	}
    fclose(fp);
    int n;
    int MAX_CLIENTS,TIMEOUT,CLIENT_PORT,SERVER_PORT;
    for(n=0;n<5;n++)
    {
    	if(strcmp(configtmp[n],"MAX_CLIENTS")==0)
    	{
    		MAX_CLIENTS=value[n];
		}
		if(strcmp(configtmp[n],"TIMEOUT")==0)
		{
			TIMEOUT=value[n];
		}
		if(strcmp(configtmp[n],"CLIENT_PORT")==0)
		{
			CLIENT_PORT=value[n];
		}
		if(strcmp(configtmp[n],"SERVER_PORT")==0)
		{
			SERVER_PORT=value[n];
		}
	}

int main(int argc, char* argv[]) {
  int ret;

  ret = start_proxy(CLIENT_PORT, SERVER_PORT, SERVER_ADDR, TIMEOUT, MAX_CLIENTS, NULL, NULL);
  if(ret) {
    printf("Error! %i\n", ret);
  }
  return ret;
}
