#include "head.h"

// n flag
/* SYNTAX: mycp -flag(optional====>v i n u) source detination*/

int vflg=0,iflg=0,nflg=0,uflg=0;
char ichar;
long double us,ud;

//struct timespec us,ud;

int main(int argc, char *argv[])
{
	FILE *source, *dest;
	char c;
	
	if(argc<3)
	{
		printf("\nSYNTAX ERROR\n");
		exit(0);
	}
	
	//printf("argc: %d ",argc);
	if(argc==3)
	{
		//printf("1:%s",argv[1]);
		source=fopen(argv[1],"r");
		dest=fopen(argv[2],"w");
	
		if(source==NULL || dest==NULL)
		{
			printf("\nFile cannot be opened\n");
			exit(0);
		}
	
		c = fgetc(source); 
    		while (c != EOF) 
    		{ 
        		fputc(c, dest); 
        		c = fgetc(source); 
        	}
        		
        	fclose(source);
		fclose(dest);	 
    	}
 	
 	else		//if argc>3 i.e. flgs are presnt!
 	{
 		
 	while((c = getopt(argc, argv, "vinu")) != -1)
	{
		switch(c)
		{
			case 'v':
				vflg = 1;
				break;
				
			case 'i':
				iflg=1;
				break;
			
			case 'n':
				nflg=1;
				break;
			
			case 'u':
				uflg=1;
				break;
				
			case '?':
				fprintf((stderr), "Unknown option -%c.\n",optopt);
				return 0;
				break;
			default:
				fprintf(stderr,"getopt");
		}
	}
 		/*printf("\nTOO MANY ARGUMENTS\n");
 		exit(0);*/
 	}
 	
 	if(vflg==1 && iflg==0 && nflg==0 && uflg==0)		//1000-->v flag
 	{
 		printf(" '%s' -> '%s' ",argv[2], argv[3]);
 		printf("\n");
 	}
 	
 	if(vflg==0 && iflg==1 && nflg==0 && uflg==0)		//0100--->i flag
 	{
 		//printf("1: %s\n 2: %s \n 3: %s \n 4: %s\n",argv[0],argv[1],argv[2],argv[3]);
 		
 		if(access(argv[3], F_OK)==0)
 		{
 			printf("Do you want to overwrite:(type y if yes)");
 			scanf("%c",&ichar);
 		
 			if(ichar=='y')
 			{
 				source=fopen(argv[2],"r");
				dest=fopen(argv[3],"w");
	
				if(source==NULL || dest==NULL)
				{
					printf("\nFile cannot be opened\n");
					exit(0);
				}
	
				c = fgetc(source); 
    				while (c != EOF) 
    				{ 
        				fputc(c, dest); 
        				c = fgetc(source); 
        			}
        		
        			fclose(source);
				fclose(dest);	 
 			}
 			else
 			{
 				printf("\nPermission to ovewwrite not granted\n");
 				exit(0);
 			}
 		}
 		else
 		{
 			source=fopen(argv[2],"r");
			dest=fopen(argv[3],"w");
	
			if(source==NULL || dest==NULL)
			{
				printf("\nFile cannot be opened\n");
				exit(0);
			}
	
			c = fgetc(source); 
    			while (c != EOF) 
    			{ 
        			fputc(c, dest); 
        			c = fgetc(source); 
        		}
        		
        		fclose(source);
			fclose(dest);		
 		}
 	}
 	
 	if(vflg==1 && iflg==1 &&nflg==0 && uflg==0)		//110---> v i flag
 	{
 		if(access(argv[3], F_OK)==0)
 		{
 			printf("Do you want to overwrite:(type y if yes)");
 			scanf("%c",&ichar);
 		
 			if(ichar=='y')
 			{
 				source=fopen(argv[2],"r");
				dest=fopen(argv[3],"w");
			
				//printf("1: %s\n 2: %s \n 3: %s \n 4: %s\n",argv[0],argv[1],argv[2],argv[3]);
	
				if(source==NULL || dest==NULL)
				{
					printf("\nFile cannot be opened\n");
					exit(0);
				}
	
				c = fgetc(source); 
    				while (c != EOF) 
    				{ 
        				fputc(c, dest); 
        				c = fgetc(source); 
        			}
        			printf("\n");
        			printf(" '%s' -> '%s' ",argv[2], argv[3]);
        			printf("\n");
        			
        			fclose(source);
				fclose(dest);	 
 			}
 			else
 			{
 				printf("\nPermission to ovewwrite not granted\n");
 				exit(0);
 			}
 			
 		}
 		
 		else
 		{
 				source=fopen(argv[2],"r");
				dest=fopen(argv[3],"w");
			
				//printf("1: %s\n 2: %s \n 3: %s \n 4: %s\n",argv[0],argv[1],argv[2],argv[3]);
	
				if(source==NULL || dest==NULL)
				{
					printf("\nFile cannot be opened\n");
					exit(0);
				}
	
				c = fgetc(source); 
    				while (c != EOF) 
    				{ 
        				fputc(c, dest); 
        				c = fgetc(source); 
        			}
        			printf("\n");
        			printf(" '%s' -> '%s' ",argv[2], argv[3]);
        			printf("\n");
        			
        			fclose(source);
				fclose(dest);	 	
 		}
 	}
 	
 	if(vflg==0 && iflg==0 &&nflg==1 && uflg==0)	//0010
 	{
 		//printf("\ni and n\n");
 		
 		if(access(argv[3], F_OK)==0)
 		{
 			printf("\nfile exits so....Cannot be overwritten\n");
 		}
 		else
 		{
 			source=fopen(argv[2],"r");
			dest=fopen(argv[3],"w");
			
			//printf("1: %s\n 2: %s \n 3: %s \n 4: %s\n",argv[0],argv[1],argv[2],argv[3]);
	
			if(source==NULL || dest==NULL)
			{
				printf("\nFile cannot be opened\n");
				exit(0);
			}
	
			c = fgetc(source); 
    			while (c != EOF) 
    			{ 
        			fputc(c, dest); 
        			c = fgetc(source); 
        		}
        		printf("\n");
        		
        		fclose(source);
			fclose(dest);
 		}
 	}
 	
 	if(vflg==0 && iflg==1 &&nflg==1 && uflg==0)	//011---> i occurs
 	{
 		if(access(argv[3], F_OK)==0)
 		{
 			printf("Do you wanr to overwrite:(type y if yes)");
 			scanf("%c",&ichar);
 		
 			if(ichar=='y')
 			{
 				source=fopen(argv[2],"r");
				dest=fopen(argv[3],"w");
	
				if(source==NULL || dest==NULL)
				{
					printf("\nFile cannot be opened\n");
					exit(0);
				}
	
				c = fgetc(source); 
    				while (c != EOF) 
    				{ 
        				fputc(c, dest); 
        				c = fgetc(source); 
        			}
        		
        			fclose(source);
				fclose(dest);	 
 			}
 			else
 			{
 				printf("\nPermission to ovewwrite not granted\n");
 				exit(0);
 			}
 		}
 		else
 		{
 				source=fopen(argv[2],"r");
				dest=fopen(argv[3],"w");
	
				if(source==NULL || dest==NULL)
				{
					printf("\nFile cannot be opened\n");
					exit(0);
				}
	
				c = fgetc(source); 
    				while (c != EOF) 
    				{ 
        				fputc(c, dest); 
        				c = fgetc(source); 
        			}
        		
        			fclose(source);
				fclose(dest);		
 		}
 	}
 	
 	if(vflg==1 && iflg==0 &&nflg==1 && uflg==0)	//101
 	{
 		//printf("\nOnly v and n\n");
 		
 		if(access(argv[3], F_OK)==0)
 		{
 			printf("\nfile exits so....Cannot be overwritten\n");
 		}
 		else
 		{
 			source=fopen(argv[2],"r");
			dest=fopen(argv[3],"w");
			
			//printf("1: %s\n 2: %s \n 3: %s \n 4: %s\n",argv[0],argv[1],argv[2],argv[3]);
	
			if(source==NULL || dest==NULL)
			{
				printf("\nFile cannot be opened\n");
				exit(0);
			}
	
			c = fgetc(source); 
    			while (c != EOF) 
    			{ 
        			fputc(c, dest); 
        			c = fgetc(source); 
        		}
        		printf("\n");
        		printf(" '%s' -> '%s' ",argv[2], argv[3]);
        		printf("\n");
        		
        		fclose(source);
			fclose(dest);
 		}
 	}
 	
 	if(vflg==1 && iflg==1 &&nflg==1 && uflg==0)	//111
 	{
 		if(access(argv[3], F_OK)==0)
 		{
 			printf("Do you wanr to overwrite:(type y if yes)");
 			scanf("%c",&ichar);
 		
 			if(ichar=='y')
 			{
 				source=fopen(argv[2],"r");
				dest=fopen(argv[3],"w");
			
				//printf("1: %s\n 2: %s \n 3: %s \n 4: %s\n",argv[0],argv[1],argv[2],argv[3]);
	
				if(source==NULL || dest==NULL)
				{
					printf("\nFile cannot be opened\n");
					exit(0);
				}
	
				c = fgetc(source); 
    				while (c != EOF) 
    				{ 
        				fputc(c, dest); 
        				c = fgetc(source); 
        			}
        			printf("\n");
        			printf(" '%s' -> '%s' ",argv[2], argv[3]);
        			printf("\n");
        			
        			fclose(source);
				fclose(dest);	 
 			}
 			else
 			{
 				printf("\nPermission to ovewwrite not granted\n");
 				exit(0);
 			}
 		}
 		else
 		{
 				source=fopen(argv[2],"r");
				dest=fopen(argv[3],"w");
			
				//printf("1: %s\n 2: %s \n 3: %s \n 4: %s\n",argv[0],argv[1],argv[2],argv[3]);
	
				if(source==NULL || dest==NULL)
				{
					printf("\nFile cannot be opened\n");
					exit(0);
				}
	
				c = fgetc(source); 
    				while (c != EOF) 
    				{ 
        				fputc(c, dest); 
        				c = fgetc(source); 
        			}
        			printf("\n");
        			printf(" '%s' -> '%s' ",argv[2], argv[3]);
        			printf("\n");
        		
        			fclose(source);
				fclose(dest);	 	
 		}
 	}
 	
 	if(vflg==0 && iflg==0 &&nflg==0 && uflg==1)	//only u
 	{
 		struct dirent *de;
	
		source=fopen(argv[2],"r");
		dest=fopen(argv[3],"w");
	
		if(source==NULL || dest==NULL)
		{
			printf("\nFile cannot be opened\n");
			exit(0);
		}
		
		struct stat my_stat1;
		
		if(stat(argv[2], &my_stat1)<0)
		{
			printf("\nerror s\n");
			exit(0);
		}
		
		struct stat my_stat2;
		if(stat(argv[3], &my_stat2)<0)
		{
			printf("\nerror d\n");
			exit(0);
		}
		
		us=my_stat1.st_atime;
		ud=my_stat2.st_atime;
			
		/*printf("\nsource: %ld\n",my_stat1.st_atime);
		printf("\ndest: %ld\n",my_stat2.st_atime);*/
		
		if(us>ud)	//source file is newer
		{
			c = fgetc(source); 
    			while (c != EOF) 
    			{ 
        			fputc(c, dest); 
        			c = fgetc(source); 
        		}
        		
        		/*printf("\n");
        		printf(" '%s' -> '%s' ",argv[2], argv[3]);*/
        		
        		fclose(source);
			fclose(dest);	 
		}
		
		else
		{
			printf("\nSource file is older than destination file! cannot br copied\n");
			exit(0);
		}
	
 	}
 	if(vflg==0 && iflg==0 &&nflg==1 && uflg==1)	//n and u flag
 	{
 		//printf("n u");===>priority given to n!
 		
 		if(access(argv[3], F_OK)==0)
 		{
 			printf("\nfile exits so....Cannot be overwritten\n");
 		}
 		else
 		{
 			source=fopen(argv[2],"r");
			dest=fopen(argv[3],"w");
			
			//printf("1: %s\n 2: %s \n 3: %s \n 4: %s\n",argv[0],argv[1],argv[2],argv[3]);
	
			if(source==NULL || dest==NULL)
			{
				printf("\nFile cannot be opened\n");
				exit(0);
			}
	
			c = fgetc(source); 
    			while (c != EOF) 
    			{ 
        			fputc(c, dest); 
        			c = fgetc(source); 
        		}
        		printf("\n");
        		
        		fclose(source);
			fclose(dest);
 		}
 			
 		
 	}
 	
 	if(vflg==0 && iflg==1 &&nflg==0 && uflg==1)
 	{
 		 //printf("i u");-->overwrite and update flag: source old:==> puchyu j nai priority given to u flag
 		 
 		struct dirent *de;
	
		source=fopen(argv[2],"r");
		dest=fopen(argv[3],"w");
	
		if(source==NULL || dest==NULL)
		{
			printf("\nFile cannot be opened\n");
			exit(0);
		}
		
		struct stat my_stat1;
		
		if(stat(argv[2], &my_stat1)<0)
		{
			printf("\nerror s\n");
			exit(0);
		}
		
		struct stat my_stat2;
		if(stat(argv[3], &my_stat2)<0)
		{
			printf("\nerror d\n");
			exit(0);
		}
		
		us=my_stat1.st_atime;
		ud=my_stat2.st_atime;
			
		/*printf("\nsource: %ld\n",my_stat1.st_atime);
		printf("\ndest: %ld\n",my_stat2.st_atime);*/
		
		if(us>ud)	//source file is newer
		{
			printf("Do you wanr to overwrite:(type y if yes)");
 			scanf("%c",&ichar);
 		
 		if(ichar=='y')
 		{
	
			if(source==NULL || dest==NULL)
			{
				printf("\nFile cannot be opened\n");
				exit(0);
			}
	
			c = fgetc(source); 
    			while (c != EOF) 
    			{ 
        			fputc(c, dest); 
        			c = fgetc(source); 
        		}
        		
        		/*printf("\n");
        		printf(" '%s' -> '%s' ",argv[2], argv[3]);*/
        		
        		fclose(source);
			fclose(dest);	 
 		}
 		else
 		{
 			printf("\nPermission to ovewwrite not granted\n");
 			exit(0);
 		} 
		}
		
		else
		{
			printf("\nSource file is older than destination file! cannot br copied\n");
			exit(0);
		}
	
 		 
 		 
 	}
 	
 	if(vflg==0 && iflg==1 &&nflg==1 && uflg==1)
 	{
 	 	//printf("i n u");====>u priority given! now if source is new then i will occur!
 	 	
 	 	struct dirent *de;
	
		source=fopen(argv[2],"r");
		dest=fopen(argv[3],"w");
	
		if(source==NULL || dest==NULL)
		{
			printf("\nFile cannot be opened\n");
			exit(0);
		}
		
		struct stat my_stat1;
		
		if(stat(argv[2], &my_stat1)<0)
		{
			printf("\nerror s\n");
			exit(0);
		}
		
		struct stat my_stat2;
		if(stat(argv[3], &my_stat2)<0)
		{
			printf("\nerror d\n");
			exit(0);
		}
		
		us=my_stat1.st_atime;
		ud=my_stat2.st_atime;
			
		
		if(us>ud)	//source file is newer
		{
		
			printf("Do you wanr to overwrite:(type y if yes)");
 			scanf("%c",&ichar);
 		
 			if(ichar=='y')
 			{
	
				c = fgetc(source); 
    				while (c != EOF) 
    				{ 
        				fputc(c, dest); 
        				c = fgetc(source); 
        			}
        		
        			fclose(source);
				fclose(dest);	 
 			}
 			else
 			{
 				printf("\nPermission to ovewwrite not granted\n");
 				exit(0);
 			}	 
		}
		
		else
		{
			printf("\nSource file is older than destination file! cannot br copied\n");
			exit(0);
		}	 	
 	}
 	
 	if(vflg==1 && iflg==0 &&nflg==0 && uflg==1)	//u v
 	{
 	 	//printf("\nv u\n");
 	 	
 	 	struct dirent *de;
	
		source=fopen(argv[2],"r");
		dest=fopen(argv[3],"w");
	
		if(source==NULL || dest==NULL)
		{
			printf("\nFile cannot be opened\n");
			exit(0);
		}
		
		struct stat my_stat1;
		
		if(stat(argv[2], &my_stat1)<0)
		{
			printf("\nerror s\n");
			exit(0);
		}
		
		struct stat my_stat2;
		if(stat(argv[3], &my_stat2)<0)
		{
			printf("\nerror d\n");
			exit(0);
		}
		
		us=my_stat1.st_atime;
		ud=my_stat2.st_atime;
			
		/*printf("\nsource: %ld\n",my_stat1.st_atime);
		printf("\ndest: %ld\n",my_stat2.st_atime);*/
		
		if(us>ud)	//source file is newer
		{
			c = fgetc(source); 
    			while (c != EOF) 
    			{ 
        			fputc(c, dest); 
        			c = fgetc(source); 
        		}
        		
        		printf("\n");
        		printf(" '%s' -> '%s' ",argv[2], argv[3]);
        		printf("\n");
        		
        		fclose(source);
			fclose(dest);	 
		}
		
		else
		{
			printf("\nSource file is older than destination file! cannot br copied\n");
			exit(0);
		}
 	}
 	
 	if(vflg==1 && iflg==0 &&nflg==1 && uflg==1)
 	{
  		//printf("v n u");
  		
  		if(access(argv[3], F_OK)==0)
 		{
 			printf("\nfile exits so....Cannot be overwritten\n");
 		}
 		else
 		{
 			source=fopen(argv[2],"r");
			dest=fopen(argv[3],"w");
			
			//printf("1: %s\n 2: %s \n 3: %s \n 4: %s\n",argv[0],argv[1],argv[2],argv[3]);
	
			if(source==NULL || dest==NULL)
			{
				printf("\nFile cannot be opened\n");
				exit(0);
			}
	
			c = fgetc(source); 
    			while (c != EOF) 
    			{ 
        			fputc(c, dest); 
        			c = fgetc(source); 
        		}
        		printf("\n");
        		
        		printf(" '%s' -> '%s' ",argv[2], argv[3]);
        		
        		fclose(source);
			fclose(dest);
 		}	
 	}
 	
 	if(vflg==1 && iflg==1 &&nflg==0 && uflg==1)
 	{
 		//printf("v i u"); 
 		
 		struct dirent *de;
	
		source=fopen(argv[2],"r");
		dest=fopen(argv[3],"w");
	
		if(source==NULL || dest==NULL)
		{
			printf("\nFile cannot be opened\n");
			exit(0);
		}
		
		struct stat my_stat1;
		
		if(stat(argv[2], &my_stat1)<0)
		{
			printf("\nerror s\n");
			exit(0);
		}
		
		struct stat my_stat2;
		if(stat(argv[3], &my_stat2)<0)
		{
			printf("\nerror d\n");
			exit(0);
		}
		
		us=my_stat1.st_atime;
		ud=my_stat2.st_atime;
			
		/*printf("\nsource: %ld\n",my_stat1.st_atime);
		printf("\ndest: %ld\n",my_stat2.st_atime);*/
		
		if(us>ud)	//source file is newer
		{
			printf("Do you wanr to overwrite:(type y if yes)");
 			scanf("%c",&ichar);
 		
 			if(ichar=='y')
 			{
	
			if(source==NULL || dest==NULL)
			{
				printf("\nFile cannot be opened\n");
				exit(0);
			}
	
			c = fgetc(source); 
    			while (c != EOF) 
    			{ 
        			fputc(c, dest); 
        			c = fgetc(source); 
        		}
        		
        		printf("\n");
        		printf(" '%s' -> '%s' ",argv[2], argv[3]);
        		printf("\n");
        		
        		fclose(source);
			fclose(dest);	 
 			}
 			else
 			{
 				printf("\nPermission to ovewwrite not granted\n");
 				exit(0);
 			} 
		}
		
		else
		{
			printf("\nSource file is older than destination file! cannot br copied\n");
			exit(0);
		}
	
 		 	
 	}
 	if(vflg==1 && iflg==1 &&nflg==1 && uflg==1)
 	{
 		//printf("n v i u"); 
 		
 		struct dirent *de;
	
		source=fopen(argv[2],"r");
		dest=fopen(argv[3],"w");
	
		if(source==NULL || dest==NULL)
		{
			printf("\nFile cannot be opened\n");
			exit(0);
		}
		
		struct stat my_stat1;
		
		if(stat(argv[2], &my_stat1)<0)
		{
			printf("\nerror s\n");
			exit(0);
		}
		
		struct stat my_stat2;
		if(stat(argv[3], &my_stat2)<0)
		{
			printf("\nerror d\n");
			exit(0);
		}
		
		us=my_stat1.st_atime;
		ud=my_stat2.st_atime;
			
		
		if(us>ud)	//source file is newer
		{
		
			printf("Do you wanr to overwrite:(type y if yes)");
 			scanf("%c",&ichar);
 		
 			if(ichar=='y')
 			{
	
				c = fgetc(source); 
    				while (c != EOF) 
    				{ 
        				fputc(c, dest); 
        				c = fgetc(source); 
        			}
        			
        			printf("\n");
        			printf(" '%s' -> '%s' ",argv[2], argv[3]);
        			printf("\n");
        			
        			fclose(source);
				fclose(dest);	 
 			}
 			else
 			{
 				printf("\nPermission to ovewwrite not granted\n");
 				exit(0);
 			}	 
		}
		
		else
		{
			printf("\nSource file is older than destination file! cannot br copied\n");
			exit(0);
		}	 		
 	}
    	
	return 0;	
}

