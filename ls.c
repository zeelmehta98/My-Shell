#include "head.h"

int ifl = 0, r = 0, one = 0, m = 0;

static int comp(const void* x, const void* y)
{
    return strcmp(*(const char**)x, *(const char**)y); 
}

 
void sort(const char* arr[], int n) 
{ 
    qsort(arr, n, sizeof(const char*), comp); 
}

 
void print_usage(char *this)
{
	fprintf(stderr, "SYNTAX ERROR:\n SYNTAX: myls <flags>\n To know about this type man myls or help myls");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	DIR *dir, *d;
	int j=0;
	
	struct dirent *sub_dir, *sub_d, *de;
	
	const char *arr[500];
	
	int c, n, size = 0;
	
	while((c = getopt(argc, argv, "ir1m")) != -1)
	{
		switch(c)
		{
			case 'i':
				ifl = 1;
				break;
			
			case 'r':
				r = 1;
				break;
				
			case '1':
				one = 1;
				break;
				
			case 'm':
				m = 1;
				break;
				
			case '?':
				fprintf((stderr), "Unknown option -%c.\n",optopt);
				return 0;
				break;
			default:
				fprintf(stderr,"getopt");
		}
	}
	
	dir = opendir(".");
	d = opendir(".");
	
	if(dir == NULL)
	{
		printf("Error! Unable to open directory");
		exit(1);
	}
	
	while((sub_dir = readdir(dir)	) != NULL)
	{
		if(strcmp(sub_dir->d_name,"bad_dir")==0)
		{
			continue;
		}
		
 		if(strcmp(sub_dir->d_name,".") == 0)
 		{
 			continue;
 		}
 		
 		if(strcmp(sub_dir->d_name,"..") == 0)
 		{
 			continue;
 		}
 		
		arr[size] = sub_dir->d_name;
		size++;
	}
	
	sort(arr, size);
	
	if(ifl==0 && r==0 && m==0 && one==0)		//0000
	{
		for(j=0; j<size; j++)
		{
			printf("%s ",arr[j]);
		}
	}
	
	if(ifl==0 && r==0 && m==0 && one==1)		//0001
	{
		printf("\nIN FLAG 1\n");
		
		for(j=0; j<size; j++)
		{
			printf("%s \n",arr[j]);
		}
	}
	
	if(ifl==0 && r==0 && m==1 && one==0)         //0010
	{
		printf("\nIN FLAG M\n");
		for(j=0; j<size; j++)
		{
			printf("%s, ",arr[j]);
		}
	}
	
	if(ifl==0 && r==0 && m==1 && one==1)		//0011
	{
		printf("\nIN FLAG M 1\n");
		for(j=0; j<size; j++)
		{
			printf("%s, \n",arr[j]);
		}
	}
	
	if(ifl==0 && r==1 && m==0 && one==0)		//0100
	{
		printf("\nIN FLAG R\n");
		
		for(j = size-1;j >= 0; j--)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%s ",sub->d_name);
				}
			}
		}
	}
	
	if(ifl==0 && r==1 && m==0 && one==1)		//0101
	{
		printf("\nIN FLAG R 1\n");
		
		for(j = size-1;j >= 0; j--)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%s\n",sub->d_name);
				}
			}
		}
	}
	
	if(ifl==0 && r==1 && m==1 && one==0)		//0110
	{
		printf("\nIN FLAG R M\n");
		
		for(j = size-1;j >= 0; j--)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%s, ",sub->d_name);
				}
			}
		}
		
	}
	
	if(ifl==0 && r==1 && m==1 && one==1)		//0111
	{
		printf("\nIN FLAG R M 1\n");
		
		for(j = size-1;j >= 0; j--)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%s, \n",sub->d_name);
				}
			}
		}
	}
	
	if(ifl==1 && r==0 && m==0 && one==0)		//1000
	{
		printf("\nIN FLAG I \n");
		
		for(j = 0;j < size; j++)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%ld %s",sub->d_ino, sub->d_name);
				}
			}
		}
	}
	
	if(ifl==1 && r==0 && m==0 && one==1)		//1001
	{
		printf("\nIN FLAG I 1\n");
		
		for(j = 0;j < size; j++)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%ld %s \n",sub->d_ino, sub->d_name);
				}
			}
		}
	}
	
	if(ifl==1 && r==0 && m==1 && one==0)		//1010
	{
		printf("\nIN FLAG I 1\n");
		
		for(j = 0;j < size; j++)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%ld %s, ",sub->d_ino, sub->d_name);
				}
			}
		}
	}
	
	if(ifl==1 && r==0 && m==1 && one==1)		//1011
	{
		printf("\nIN FLAG I M 1\n");
		
		for(j = 0;j < size; j++)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%ld %s, \n",sub->d_ino, sub->d_name);
				}
			}
		}
	}
	
	if(ifl==1 && r==1 && m==0 && one==0)		//1100
	{
		printf("\nIN FLAG I R \n");
		
		for(j = size-1; j>=0; j--)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%ld %s ",sub->d_ino, sub->d_name);
				}
			}
		}
	}
	
	if(ifl==1 && r==1 && m==0 && one==1)		//1101
	{
		printf("\nIN FLAG I R 1\n");
		
		for(j = size-1; j>=0; j--)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%ld %s \n",sub->d_ino, sub->d_name);
				}
			}
		}
	}
	
	if(ifl==1 && r==1 && m==1 && one==0)		//1110
	{
		printf("\nIN FLAG I R M\n");
		
		for(j = size-1; j>=0; j--)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%ld %s, ",sub->d_ino, sub->d_name);
				}
			}
		}
	}
	
	if(ifl==1 && r==1 && m==1 && one==1)		//1111
	{
		printf("\nIN FLAG I R M 1\n");
		
		for(j = size-1; j>=0; j--)
		{
			struct dirent *sub;
			DIR *ind;
			ind = opendir(".");
			while((	sub = readdir(ind)	) != NULL	)
			{
				if(!strcmp(sub->d_name,arr[j]))
				{
					printf("%ld %s, \n",sub->d_ino, sub->d_name);
				}
			}
		}
	}	
}















