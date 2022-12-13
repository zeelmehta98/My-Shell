/*author : zeel mehta*/
/*enroll: 2020csm1021*/

#include "head.h"

#define skyblue "\x1B[92m"
#define cyan "\x1B[36m"
#define reset "\x1B[0m"

/*
EXACT COLORS ARE: 

*/

char hostname[HOST_NAME_MAX];
char username[LOGIN_NAME_MAX];
char name[LOGIN_NAME_MAX];
char *buf;
char cwd[4096];
int temp=0;


void myhandler(int code)		//
{
	printf("\n To terminate shell type 'exit' \n");
	return;
}

void currentdir()				//funtion thaf finds path to current directory
{
	
	getcwd(cwd, sizeof(cwd));
	
}
	
void printuser()			//function prints username and name
{

	printf(skyblue "%s",username);
	printf(cyan ":~%s",name);
}

void str()				//concatenate the names!
{
	strcat(username, "@");
	strcat(username, hostname);
	strcat(name, cwd);
}

void welcomemessage()
{
	printf("*******************************************************");
	printf("\n\t\t\tMY SHELL\n");
	printf("\t\t      2020CSM1021\n");
	printf("*******************************************************\n");
}

void execute_function()
{
	int len = strlen(buf);
	char *input[10];
	
	int n,k=0,i;
	char *token = strtok(buf, " ");
	
	while(token)
	{
		input[k]=token;
		k++;
		token = strtok(NULL, " ");
	}

	input[k] = NULL;
    	pid_t pid = fork();
    	
    	switch(temp)
    	{
    		case 1:
    		{
			if (pid == 0)
			{	  	
    				execv("./ls",input);				
			}
		
			else
			{
				waitpid(-1, NULL, 0);
			}
		}
		
		case 2:
		{
			if (pid == 0)
			{	  	
    				execv("./cp",input);				
			}
		
			else
			{
				waitpid(-1, NULL, 0);
			}
		}
		
		case 3:
		{
			if (pid == 0)
			{	  	
    				execv("./myps",input);				
			}
		
			else
			{
				waitpid(-1, NULL, 0);
			}
		}
		
		case 4:
		{
			if (pid == 0)
			{	  	
    				execv("./mv",input);				
			}
		
			else
			{
				waitpid(-1, NULL, 0);
			}
		}
		
		case 5:
		{
			if (pid == 0)
			{	  	
    				execv("./mygrep",input);				
			}
		
			else
			{
				waitpid(-1, NULL, 0);
			}
		}
	}	
}


int main(int argc, char *argv[])
{	
	welcomemessage();
	
	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);

	currentdir();
	
	str();
	
	while(1)
	{
		signal(SIGINT, myhandler);
		signal(SIGSEGV, myhandler);
		
		printuser();
		
		printf(reset"");		
		buf = readline("$ ");
	
		if(strlen(buf)>0)
		{
			add_history(buf);
		}
		
		if(strcmp(buf, "exit")==0)
		{
			break;
		}
		
		else if(strstr(buf, "myls"))
		{
			if(strstr(buf, "help") || strstr(buf, "man"))
			{
				system("cat myls.txt");
			}
			
			else
			{
				temp=1;		//myls command
				execute_function();
			}
		}
		
		else if(strstr(buf, "mycp"))
		{
			if(strstr(buf, "help") || strstr(buf, "man"))
			{
				system("cat mycp.txt");
			}
			
			else
			{
				temp=2;		//mycp command
				execute_function();
			}
		}
		
		else if(strstr(buf, "myps"))
		{
			if(strstr(buf, "help") || strstr(buf, "man"))
			{
				system("cat myps.txt");
			}
			
			else
			{
				temp=3;		//myps command
				execute_function();
			}
		}
		
		else if(strstr(buf, "mymv"))
		{
			if(strstr(buf, "help") || strstr(buf, "man"))
			{
				system("cat mymv.txt");
			}
			
			else
			{
				temp=4;		//mymv command
				execute_function();
			}
		}
		
		else if(strstr(buf, "mygrep"))
		{
			if(strstr(buf, "help") || strstr(buf, "man"))
			{
				system("cat mygrep.txt");
			}
			
			else
			{
				temp=5;		//mygrep command
				execute_function();
			}
		}
		
		
		else
		{
			system(buf);
		}
	}	
}




