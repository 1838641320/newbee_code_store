#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#define LEN sizeof(struct addritem)
#define FORMAT "%-10s%-10s%-15s%-25s%-30s%\n"
#define DATA addrinfo[i].name,addrinfo[i].occu,addrinfo[i].tel,addrinfo[i].email,addrinfo[i].address
struct addritem				/*����ͨѶ¼�ṹ��*/
{ 
  char name[10];			/*����*/
  char occu[10];     			/*ְҵ*/
  char tel[15];  			/*�ֻ���*/
  char email[25];			/*�����ʼ�*/
  char address[30];			/*ͨѶ��ַ*/

};
struct addritem addrinfo[100];	/*����ṹ������*/
void input();					/*¼��ͨѶ¼��Ŀ*/
void search();					/*�����ֲ���ͨѶ¼��Ŀ*/
void update();					/*�޸�ͨѶ¼��Ŀ*/
void del();						/*ɾ��ͨѶ¼��Ŀ*/
void display();					/*��ʾͨѶ¼��Ϣ*/
void sort();					/*����������*/
void menu();					/*���˵�*/

int main()						/*������*/
{ int n;
  menu();
  scanf("%d",&n);				/*����ѡ���ܵı��*/
  while(n)
  { 
	  switch(n)
	  { 
		case 1: input();  break;	
	    case 2: search(); break;
		case 3: update(); break;
		case 4: del();	  break;
		case 5: sort();   break;
		case 6: display();break;
		default:break;
     }
    getch();
    menu();						/*ִ���깦�ܺ��ٴ���ʾ�˵�����*/
    scanf("%d",&n);
  }
}

/*¼��ͨѶ¼��Ŀ*/
void input()					
{ int i,count=0;				/*count�Ǽ�¼������*/
  char ch[2];  
  FILE *fp;						/*�����ļ�ָ��*/
  if((fp=fopen("data.txt","a+"))==NULL)		/*��ָ���ļ�*/
  { 
	  printf("can not open\n");
	  return;
  }
  while(!feof(fp))
  {
	  if(fread(&addrinfo[count],LEN,1,fp)==1)
		  count++;				/*ͳ�Ƶ�ǰ��¼����*/
  }
  fclose(fp);
  if(count==0)
	  printf("No contact record!\n");
  else
  {
	  system("cls");
          display();			/*����display��������ʾԭ����Ϣ*/
  }

  if((fp=fopen("data.txt","wb"))==NULL)
  {
	  printf("can not open address list!\n");
	  return;
  }
  for(i=0;i<count;i++)
  {
	fwrite(&addrinfo[i] ,LEN,1,fp);			/*��ָ���Ĵ����ļ�д����Ϣ*/
  }

  printf("please input(y/n):");
  scanf("%s",ch);
  while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ¼������Ϣ*/
  {
    printf("name:");
	scanf("%s",&addrinfo[count].name);		 /*��������*/
    for(i=0;i<count;i++)
	    if(strcmp(addrinfo[i].name,addrinfo[count].name)==0)
	    {
			printf("The name already exists,press any key to continue!");
			getch();
			fclose(fp);
			return;
	    }
     printf("occupation:");
     scanf("%s",&addrinfo[count].occu);		/*������ϵ��ְҵ*/
     printf("telephone:");
	 scanf("%s",&addrinfo[count].tel);		/*������ϵ���ֻ���*/
	 printf("email:");
	 scanf("%s",&addrinfo[count].email);	/*������ϵ�˵����ʼ�*/
     printf("address:");
	 scanf("%s",&addrinfo[count].address);	/*������ϵ�˵�ַ*/
   
     if(fwrite(&addrinfo[count],LEN,1,fp)!=1)/*����¼�����ϵ����Ϣд��ָ���Ĵ����ļ�*/
     {
		 printf("Can not save the record!");
		 getch();
	 }
     else
	 {
		 printf("%s saved!\n",addrinfo[count].name);
		 count++;
	 }
     printf("continue?(y/n):");				/*ѯ���Ƿ��������*/
     scanf("%s",ch);
  }
  fclose(fp);
  printf("OK!\n");
}

/*��ʾ��ϵ����Ϣ*/
void display()
 { FILE *fp;
   int i,count=0;
   fp=fopen("data.txt","rb");
   while(!feof(fp))
   {
   if(fread(&addrinfo[count] ,LEN,1,fp)==1) 
   count++;
   }  
   fclose(fp);
   printf("name    occupation  telephone      email                      address\t\n");
   for(i=0;i<count;i++)
   { 
	   printf(FORMAT,DATA);					/*����Ϣ��ָ����ʽ��ӡ*/
   }
}
 
void menu()									/*�Զ��庯��ʵ�ֲ˵�����*/
{
  system("cls");
  printf("\n\n\n\n\n");
  printf("\t\t|---------------------CONTACT-------------------|\n");
  printf("\t\t|\t 0. exit                                |\n");
  printf("\t\t|\t 1. input record                        |\n");
  printf("\t\t|\t 2. search record                       |\n");
  printf("\t\t|\t 3. update record                       |\n");
  printf("\t\t|\t 4. delete record                       |\n");
  printf("\t\t|\t 5. sort                                |\n");
  printf("\t\t|\t 6. display                             |\n");
  printf("\t\t|-----------------------------------------------|\n\n");
  printf("\t\t\tchoose(0-6):");
}

/*�Զ��������� ����������ĸ����*/
void sort()						
{ FILE *fp;
  struct addritem t;
  int i=0,j=0,count=0;
  if((fp=fopen("data.txt","r+"))==NULL)
  { 
	printf("can not open!\n");
        return;
  }
  while(!feof(fp)) 
  if(fread(&addrinfo[count] ,LEN,1,fp)==1) 
	  count++;
  fclose(fp);
  if(count==0) 
  {
	  printf("no record!\n");
	  return;
  }
  for(i=0;i<count-1;i++)
      for(j=i+1;j<count;j++)		/*˫��ѭ��ʵ�������Ƚϲ�����*/
	  if(strcmp(addrinfo[i].name,addrinfo[j].name)>0)
          { 
			  t=addrinfo[i];
			  addrinfo[i]=addrinfo[j];
			  addrinfo[j]=t;
		  }
	  if((fp=fopen("data.txt","wb"))==NULL)
     { printf("can not open\n");return;}
  for(i=0;i<count;i++)				/*�������ź������������д��ָ���Ĵ����ļ���*/
      if(fwrite(&addrinfo[i] ,LEN,1,fp)!=1)
       { 
        printf("%s can not save!\n"); 
        getch();
      }
  fclose(fp);
  printf("save successfully\n");
}

/*�Զ���ɾ������*/
void del()
{
	FILE *fp;
	int i,j,count=0;
	char ch[2];
	char name[15];
	if((fp=fopen("data.txt","r+"))==NULL)
	{
		printf("can not open\n");return;}
		while( !feof(fp) )  
			if(fread(&addrinfo[count],LEN,1,fp)==1) count++;
			fclose(fp);
		if(count==0) 
		{
			printf("no record!\n");
			return;
		}
  		display();
		printf("please input the name:");
		scanf("%s",&name);
		for(i=0;i<count;i++)
		{
			if(strcmp(name,addrinfo[i].name)==0)
			{
				printf("find the contact,del?(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ����ɾ��*/
				for(j=i;j<count;j++)
				addrinfo[j]=addrinfo[j+1];/*����һ����¼�Ƶ�ǰһ����¼��λ��*/
				count--;/*��¼���ܸ�����1*/
				if((fp=fopen("data.txt","wb"))==NULL)
				{ printf("can not open\n");return;}
				for(j=0;j<count;j++)/*�����ĺ�ļ�¼����д��ָ���Ĵ����ļ���*/
				if(fwrite(&addrinfo[j] ,LEN,1,fp)!=1)
				{ printf("can not save!\n");
				getch();}
				fclose(fp);
				printf("del successfully!\n");
				return;
			}
		}
		printf("û���ҵ�Ҫɾ������ϵ�ˣ�\n");
}

/*�Զ�����Һ���*/
void search()
{ FILE *fp;
  int i,count=0;
  char ch[2],name[15];
  if((fp=fopen("data.txt","rb"))==NULL)
     { printf("can not open\n");
	   return;}
  while(!feof(fp))  if(fread(&addrinfo[count],LEN,1,fp)==1) count++;
  fclose(fp);
  if(count==0) {printf("no record!\n");return;}
	printf("please input the name:");
		scanf("%s",name);
		for(i=0;i<count;i++)
			if(strcmp(name,addrinfo[i].name)==0)
     { printf("find the contact,display?(y/n)");
		scanf("%s",ch);
      if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
        {
	  printf("name    occupation  telephone      email                      address\t\n");
          printf(FORMAT,DATA);/*�����ҳ��Ľ����ָ����ʽ���*/
	} 
	  break;
     }   
  if(i==count) printf("can not find the contact!\n");/*δ�ҵ�Ҫ���ҵ���Ϣ*/
}


/*�Զ����޸ĺ���*/
void update()
{ FILE *fp;
  int i,j,count=0;
  char name[30];
  if((fp=fopen("data.txt","r+"))==NULL)
     { printf("can not open\n");return;}
  while(!feof(fp))  
 if(fread(&addrinfo[count],LEN,1,fp)==1) count++;
  if(count==0) 
  {
	printf("no record!\n");
	fclose(fp);
	return;
  }
  display();
  printf("please input the name of the contact which you want to update!\n");
  printf("update name:");
  scanf("%s",&name);
  for(i=0;i<count;i++)
  {
	if(strcmp(name,addrinfo[i].name)==0)
	{
	  printf("find the contact!you can update!\n");
	  printf("name:");
	  scanf("%s",addrinfo[i].name);/*��������*/
      printf("occuption:");
	  scanf("%s",&addrinfo[i].occu);/*����ְҵ*/
      printf("telephone:");
	  scanf("%s",&addrinfo[i].tel);/*����绰����*/
      printf("email:");
	  scanf("%s",&addrinfo[i].email);/*�����������*/
	  printf("address:");
	  scanf("%s",&addrinfo[i].address);
	  printf("update successful!");
	  if((fp=fopen("data.txt","wb"))==NULL)
     { printf("can not open\n");return;}
	  for(j=0;j<count;j++)/*�����޸ĵ���Ϣд��ָ���Ĵ����ļ���*/
	  if(fwrite(&addrinfo[j] ,LEN,1,fp)!=1)
       { printf("can not save!"); getch(); }
	fclose(fp);
	return;
	}	 
  }
	printf("û���ҵ�ƥ����Ϣ��\n");
 }

