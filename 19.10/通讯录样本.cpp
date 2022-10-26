#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#define LEN sizeof(struct addritem)
#define FORMAT "%-10s%-10s%-15s%-25s%-30s%\n"
#define DATA addrinfo[i].name,addrinfo[i].occu,addrinfo[i].tel,addrinfo[i].email,addrinfo[i].address
struct addritem				/*定义通讯录结构体*/
{ 
  char name[10];			/*姓名*/
  char occu[10];     			/*职业*/
  char tel[15];  			/*手机号*/
  char email[25];			/*电子邮件*/
  char address[30];			/*通讯地址*/

};
struct addritem addrinfo[100];	/*定义结构体数组*/
void input();					/*录入通讯录条目*/
void search();					/*按名字查找通讯录条目*/
void update();					/*修改通讯录条目*/
void del();						/*删除通讯录条目*/
void display();					/*显示通讯录信息*/
void sort();					/*按名字排序*/
void menu();					/*主菜单*/

int main()						/*主函数*/
{ int n;
  menu();
  scanf("%d",&n);				/*输入选择功能的编号*/
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
    menu();						/*执行完功能后再次显示菜单界面*/
    scanf("%d",&n);
  }
}

/*录入通讯录条目*/
void input()					
{ int i,count=0;				/*count是记录的条数*/
  char ch[2];  
  FILE *fp;						/*定义文件指针*/
  if((fp=fopen("data.txt","a+"))==NULL)		/*打开指定文件*/
  { 
	  printf("can not open\n");
	  return;
  }
  while(!feof(fp))
  {
	  if(fread(&addrinfo[count],LEN,1,fp)==1)
		  count++;				/*统计当前记录条数*/
  }
  fclose(fp);
  if(count==0)
	  printf("No contact record!\n");
  else
  {
	  system("cls");
          display();			/*调用display函数，显示原有信息*/
  }

  if((fp=fopen("data.txt","wb"))==NULL)
  {
	  printf("can not open address list!\n");
	  return;
  }
  for(i=0;i<count;i++)
  {
	fwrite(&addrinfo[i] ,LEN,1,fp);			/*向指定的磁盘文件写入信息*/
  }

  printf("please input(y/n):");
  scanf("%s",ch);
  while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要录入新信息*/
  {
    printf("name:");
	scanf("%s",&addrinfo[count].name);		 /*输入姓名*/
    for(i=0;i<count;i++)
	    if(strcmp(addrinfo[i].name,addrinfo[count].name)==0)
	    {
			printf("The name already exists,press any key to continue!");
			getch();
			fclose(fp);
			return;
	    }
     printf("occupation:");
     scanf("%s",&addrinfo[count].occu);		/*输入联系人职业*/
     printf("telephone:");
	 scanf("%s",&addrinfo[count].tel);		/*输入联系人手机号*/
	 printf("email:");
	 scanf("%s",&addrinfo[count].email);	/*输入联系人电子邮件*/
     printf("address:");
	 scanf("%s",&addrinfo[count].address);	/*输入联系人地址*/
   
     if(fwrite(&addrinfo[count],LEN,1,fp)!=1)/*将新录入的联系人信息写入指定的磁盘文件*/
     {
		 printf("Can not save the record!");
		 getch();
	 }
     else
	 {
		 printf("%s saved!\n",addrinfo[count].name);
		 count++;
	 }
     printf("continue?(y/n):");				/*询问是否继续输入*/
     scanf("%s",ch);
  }
  fclose(fp);
  printf("OK!\n");
}

/*显示联系人信息*/
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
	   printf(FORMAT,DATA);					/*将信息按指定格式打印*/
   }
}
 
void menu()									/*自定义函数实现菜单功能*/
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

/*自定义排序函数 按姓名首字母排序*/
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
      for(j=i+1;j<count;j++)		/*双重循环实现姓名比较并交换*/
	  if(strcmp(addrinfo[i].name,addrinfo[j].name)>0)
          { 
			  t=addrinfo[i];
			  addrinfo[i]=addrinfo[j];
			  addrinfo[j]=t;
		  }
	  if((fp=fopen("data.txt","wb"))==NULL)
     { printf("can not open\n");return;}
  for(i=0;i<count;i++)				/*将重新排好序的内容重新写入指定的磁盘文件中*/
      if(fwrite(&addrinfo[i] ,LEN,1,fp)!=1)
       { 
        printf("%s can not save!\n"); 
        getch();
      }
  fclose(fp);
  printf("save successfully\n");
}

/*自定义删除函数*/
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
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要进行删除*/
				for(j=i;j<count;j++)
				addrinfo[j]=addrinfo[j+1];/*将后一个记录移到前一个记录的位置*/
				count--;/*记录的总个数减1*/
				if((fp=fopen("data.txt","wb"))==NULL)
				{ printf("can not open\n");return;}
				for(j=0;j<count;j++)/*将更改后的记录重新写入指定的磁盘文件中*/
				if(fwrite(&addrinfo[j] ,LEN,1,fp)!=1)
				{ printf("can not save!\n");
				getch();}
				fclose(fp);
				printf("del successfully!\n");
				return;
			}
		}
		printf("没有找到要删除的联系人！\n");
}

/*自定义查找函数*/
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
          printf(FORMAT,DATA);/*将查找出的结果按指定格式输出*/
	} 
	  break;
     }   
  if(i==count) printf("can not find the contact!\n");/*未找到要查找的信息*/
}


/*自定义修改函数*/
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
	  scanf("%s",addrinfo[i].name);/*输入名字*/
      printf("occuption:");
	  scanf("%s",&addrinfo[i].occu);/*输入职业*/
      printf("telephone:");
	  scanf("%s",&addrinfo[i].tel);/*输入电话号码*/
      printf("email:");
	  scanf("%s",&addrinfo[i].email);/*输入电子邮箱*/
	  printf("address:");
	  scanf("%s",&addrinfo[i].address);
	  printf("update successful!");
	  if((fp=fopen("data.txt","wb"))==NULL)
     { printf("can not open\n");return;}
	  for(j=0;j<count;j++)/*将新修改的信息写入指定的磁盘文件中*/
	  if(fwrite(&addrinfo[j] ,LEN,1,fp)!=1)
       { printf("can not save!"); getch(); }
	fclose(fp);
	return;
	}	 
  }
	printf("没有找到匹配信息！\n");
 }

