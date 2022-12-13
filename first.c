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

void myhandler(int code)		//
{
	printf("\n To terminate shell type 'exit' \n");
	return;
}

void current()				//funtion thaf finds path to current directory
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

int main(int argc, char *argv[])
{	
	printf("*******************************************************");
	printf("\n\t\t\tMY SHELL\n");
	printf("\t\t      2020CSM1021\n");
	printf("*******************************************************\n");
	
	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);

	current();
	
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
		
		system(buf);
	}
	
	
}





