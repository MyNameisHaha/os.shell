//xirui  shell��ʵ�� add/sub/smile/exit ���� 
//���� add 100 200  sub 100 50 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void myinfo_main()
{
	printf("����xirui �汾0.1 shell��ʵ�� add/sub/smile/exit ����\n");
	
}

void draw_SMface_main()
{
	printf("\1\n");
	
}


int sub_main(int argc,char *argv[])
{
	int a,b;
	
	if(argc < 3)
	{
		printf("argc = %d, ����ȱ��\n",argc);
		return 0;
	}
	
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	printf("sub result: %s - %s = %d\n",argv[1],argv[2],a - b);
	
	return 0;
}

int add_main(int argc,char *argv[])
{
	int a,b;
	
	if(argc < 3)
	{
		printf("argc = %d, ����ȱ��\n",argc);
		return 0;
	}
	
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	printf("add result: %s + %s = %d\n",argv[1],argv[2],a + b);
	
	return 0;
}


int command_do(int argc,char *argv[])
{
	if (strcmp(argv[0],"add")  == 0)
			add_main(argc,argv);

	if (strcmp(argv[0],"sub")  == 0)
			sub_main(argc,argv);
			
	if (strcmp(argv[0],"smile")  == 0)
			draw_SMface_main();
			
	if (strcmp(argv[0],"myinfo")  == 0)
			myinfo_main();
	 	
 	if (strcmp(argv[0],"exit")  == 0)
			exit(0);

			
	return 0;
}


void shell_parse(char *buf)
{
	int argc;
	char *argv[64];
	int state = 0;
	int i = 0;
	
	argc = 0;
	while(*buf)
	{
		char c = *buf;
		if(c == ' ' && state == 0)
				state = 0;
				
		else if(c != ' ' && state == 0)
		{
				argv[argc++] = buf;
				state = 1;
		}
				
		else if(c == ' ' && state == 1)
		{
			*buf = '\0';
			 state = 0;
		}
				
		else if(c != ' ' && state == 0)
		{
			state = 1;
		}
		buf++;
		if (*buf == '\n')
				*buf = '\0';
	}
	argv[argc] = NULL;
#if 0
	printf("argc = %d\n",argc);
	for (i = 0;i <= argc; i++)
			printf("argv[%d] : %s\n",i, argv[i]);
#endif	
	command_do(argc,argv);//������� 
}

int main(int argc,char *argv[])
{
	char buf[64];
	
 	while(1)
 	{	
 	printf("xirui_shell# ");
 	
 	fgets(buf,64,stdin);//��ȡ�ַ� 

 	
#if 0	
	printf("%s",buf); //���� 
#endif		

 	
	shell_parse(buf);//������� 
 	}

}