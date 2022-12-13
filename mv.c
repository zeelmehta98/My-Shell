#include "head.h"

/*
gedit test.txt
"Write something in file"

gcc mymv.c -o mymv

./mymv test.txt ./temp/mynewtestfile.txt
*/

int vflg=0,iflg=0,uflg=0,nflg=0;
char c,ichar;

long double us, ud;

void error(char *this, char *first, char *second)
{
	fprintf(stderr,"%s cannot move %s to %s\n%s\n", this, first, second, strerror(errno));
	exit(EXIT_FAILURE);
}

void syntax_error(char *this)
{
	fprintf(stderr, "SYNTAX ERROR:\nUsage %s [old_filename] [new_filename]\n", this);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	errno = 0;
	if(argc == 3)
	{
		
		if(rename(argv[1], argv[2]) == -1)
		{
			
			error(argv[0], argv[1], argv[2]);
		}
		
		if(strcmp(argv[1],argv[2])==0)
		{
			printf("\nERROR!!! Same File\n");
			exit(0);
		}
	}
	else
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
		
		if(vflg==0 && iflg==0 && nflg==1 && uflg==0)		//n flag only
		{
			if(access(argv[3], F_OK)==0)
 			{
 				printf("\nfile exists so....Cannot be overwritten\n");
 			}
 			else
 			{
        			
        			if(rename(argv[2], argv[3]) == -1)
				{
					error(argv[0], argv[2], argv[3]);
				}
        			
 			}
		}
		
		if(vflg==1 && iflg==1 && nflg==0 && uflg==0)		//v i flag
		{
			if(access(argv[3], F_OK)==0)
 			{
 				printf("Do you want to overwrite:(type y if yes)");
 				scanf("%c",&ichar);
 		
 				if(ichar=='y')
 				{
 					rename(argv[2], argv[3]);
 					printf("Renamed %s -> %s \n",argv[2],argv[3]);	
				
				}
				else
 				{
 					printf("\nPermission to ovewwrite not granted\n");
 					exit(0);
 				} 
 		
 			}
 			else
 			{
 				rename(argv[2], argv[3]);
 				printf("Renamed %s -> %s \n",argv[2],argv[3]);
 			}
		}
		
		if(vflg==1 && iflg==0 && nflg==1 && uflg==0)		//v n flag
		{
			if(access(argv[3], F_OK)==0)
 			{
 				printf("\nfile exists so....Cannot be overwritten\n");
 			}
 			else
 			{
        			
        			if(rename(argv[2], argv[3]) == -1)
				{
					error(argv[0], argv[2], argv[3]);
				}
				
				printf("Renamed %s -> %s \n",argv[2],argv[3]);
        			
 			}
		
		}
		
		
		
		if(vflg==0 && iflg==1 && nflg==0 && uflg==0)		//i flag only
		{
			if(access(argv[3], F_OK)==0)
 			{
 				printf("Do you want to overwrite:(type y if yes)");
 				scanf("%c",&ichar);
 		
 				if(ichar=='y')
 				{
 					rename(argv[2], argv[3]);
				
				}
				else
 				{
 					printf("\nPermission to ovewwrite not granted\n");
 					exit(0);
 				} 
 		
 			}
 			else
 			{
 				rename(argv[2], argv[3]);
 			}
 		
		}
		
		if(vflg==1 && iflg==0 && nflg==0 && uflg==0)		//v flag only
		{
			printf("\nv flag\n");
			
			if(rename(argv[2], argv[3]) == -1)
			{
				error(argv[0], argv[2], argv[3]);
			}
			
			printf("Renamed %s -> %s \n",argv[2],argv[3]);
		}
		
		
		if(vflg==0 && iflg==0 && nflg==0 && uflg==1)		//u flag only
		{
			struct dirent *de;
	
		
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
		
			us=my_stat1.st_ctime;
			ud=my_stat2.st_ctime;
		
		
			if(us>ud)	//source file is newer
			{
				rename(argv[2], argv[3]);
        		
        			 
			}
		
			else
			{
				printf("\nSource file is older than destination file! cannot br copied\n");
				exit(0);
			}	
		}
		
		if(vflg==1 && iflg==0 && nflg==0 && uflg==1)		//v u
		{
			struct dirent *de;
	
		
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
		
			us=my_stat1.st_ctime;
			ud=my_stat2.st_ctime;
		
		
			if(us>ud)	//source file is newer
			{
				rename(argv[2], argv[3]);
				
        			printf("\n");
        			printf(" '%s' -> '%s' ",argv[2], argv[3]);
        		
        			 
			}
		
			else
			{
				printf("\nSource file is older than destination file! cannot br copied\n");
				exit(0);
			}
 		}
		
		
		}
		}
	return 0;
}







