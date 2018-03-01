#include "stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h"
#define N 100
struct sell
{  
	char f[20];
   	int  i;
   	float j;
}amount[N]; 
struct bookstore_time/*销售时间*/
{  
	int year;
	int month;
    int day;
};
struct bookstore1
{	
	char book_number[10];/*图书编号*/
	char book_name[50];/*书名*/
 	char book_author[20];/*作者*/
 	float  book_money;/*价格*/
	char book_publisher[20];/*出版社*/
 	char book_variety[12];/*图书类别*/
	int book_amount;/*添加入库数量*/
	int book_reserves;/*总库数量*/
}store1[N],store11[N];
struct bookstore2
{	
	char sale_number[8];/*销售人员编号*/
 	char sale_name[8];/*销售人员姓名*/
 	char sale_sex[2];/*性别*/
 	char sale_passwords[10];/*登录密码*/
}store2[N];
struct bookstore3
{	
	char administrator_number[8];/*管理员编号*/
 	char administrator_name[8];/*管理员姓名*/
 	char administrator_sex[2];/*性别*/
 	char administrator_passwords[10];/*登录密码*/
}store3[N];
struct bookstore4
{	
	int  customer_number;/*顾客号*/
 	char customer_name[8];/*顾客姓名*/
	char customer_sex[2];/*性别*/
 	int  customer_vip;/*是否会员*/
 	char customer_bookid[10];/*购买图书编号*/
 	int  customer_buy;/*购买数量*/
 	float customer_price;
 	struct bookstore_time time;/*销售时间*/
}store4[N];
struct bookstore5
{
	char vip_number[8];/*会员号*/
 	char vip_name[8];/*会员姓名*/
 	char vip_sex[2];/*性别*/
 	char vip_level[5];/*会员级别*/
}store5[N];
void w1_fp(char ch[],struct bookstore1 store1[],int a,int flag)
{
	FILE *fp;
	if((fp=flag?fopen(ch,"ab"):fopen(ch,"wb"))==NULL)
	{	
		printf("cannot open this file\n");
		return;
	}
    fwrite(&store1[0],sizeof(struct bookstore1),a,fp);
    fclose(fp);
}
int r1_fp(char ch[],struct bookstore1 store1[])
{
	FILE *fp;
	int i=0;
	if((fp=fopen(ch,"rb"))==NULL)
	{
	    printf("\n\t\t还没有添加图书信息!!\n");
	    return i;
	}
	while(fread(&store1[i],sizeof(struct bookstore1),1,fp)==1)
	{
        i++;
    }
    fclose(fp);
    return(i);
}	
void w2_fp(char ch[],struct bookstore2 store2[],int a,int flag)
{
	FILE *fp;
	if((fp=flag?fopen(ch,"ab"):fopen(ch,"wb"))==NULL)
	{	
		printf("cannot open this file\n");
		return;
	}
    fwrite(&store2[0],sizeof(struct bookstore2),a,fp);
    fclose(fp);
}
int r2_fp(char ch[],struct bookstore2 store2[])
{
	FILE *fp;
	int i=0;
	if((fp=fopen(ch,"rb"))==NULL)
	{
	    printf("\n\t\t还没有添加销售人员信息!!\n");
	    return i;
	}
	while(fread(&store2[i],sizeof(struct bookstore2),1,fp)==1)
	{
        i++;
    }
    fclose(fp);
    return(i);
}	
void w3_fp(char ch[],struct bookstore3 store3[],int a,int flag)
{
	FILE *fp;
	if((fp=flag?fopen(ch,"ab"):fopen(ch,"wb"))==NULL)
	{	
		printf("cannot open this file\n");
		return;
	}
    fwrite(&store3[0],sizeof(struct bookstore3),a,fp);
    fclose(fp);
}
int r3_fp(char ch[],struct bookstore3 store3[])
{
	FILE *fp;
	int i=0;
	if((fp=fopen(ch,"rb"))==NULL)
	{
	    printf("\n\t\t还没有添加管理人员信息!!\n");
	    return i;
	}
	while(fread(&store3[i],sizeof(struct bookstore3),1,fp)==1)
	{
        i++;
    }
    fclose(fp);
    return(i);
}	
void w4_fp(char ch[],struct bookstore4 store4[],int a,int flag)
{
	FILE *fp;
	if((fp=flag?fopen(ch,"ab"):fopen(ch,"wb"))==NULL)
	{	
		printf("cannot open this file\n");
		return;
	}
    fwrite(&store4[0],sizeof(struct bookstore4),a,fp);
    fclose(fp);
}
int r4_fp(char ch[],struct bookstore4 store4[])
{
	FILE *fp;
	int i=0;
	if((fp=fopen(ch,"rb"))==NULL)
	{
		printf("\n\t\t还没有顾客信息!!\n");
		return i;
	}
  while(fread(&store4[i],sizeof(struct bookstore4),1,fp)==1)
	{
        i++;
    }
    fclose(fp);
    return(i);
}
void w5_fp(char ch[],struct bookstore5 store5[],int a,int flag)
{
	FILE *fp;
	int i=0;
    if((fp=flag?fopen(ch,"ab"):fopen(ch,"wb"))==NULL)
	{	
		printf("cannot open this file\n");
		return;
	}
    fwrite(&store5[0],sizeof(struct bookstore5),a,fp);
    fclose(fp);
}
int r5_fp(char ch[],struct bookstore5 store5[])
{
	FILE *fp;
	int i=0;
	if((fp=fopen(ch,"rb"))==NULL)
	{
	    printf("\n\t\t还没有会员信息!!\n");
	    return i;
	}
	while(fread(&store5[i],sizeof(struct bookstore5),1,fp)==1)
	{
        i++;
    }
    fclose(fp);
    return(i);
}
void book_information()
{
	char ch,a[30]="c:/book_information.txt";
	int flag=1,i,k,m,book_information_count=0;
	while(flag)
	{
		printf("是否添加图书信息(y/n):");
		ch=getchar();
		ch=getchar();
		if(ch=='y')
		{
			k=r1_fp(a,store11);
			m=k;
			printf("\t添加你要的图书信息:\n");
			while(flag)
			{
				printf("图书编号:");
				scanf("%s",store1[book_information_count].book_number);
				printf("书名:");
				scanf("%s",store1[book_information_count].book_name);
				printf("作者:");
				scanf("%s",store1[book_information_count].book_author);
				for(i=0;i<k;i++)
				{
					if(strcmp(store11[i].book_name,store1[book_information_count].book_name)==0)
					if(strcmp(store11[i].book_author,store1[book_information_count].book_author)==0)
					{
						printf("这本书的信息已经入库了,请添加要入库的数量:");
	    				scanf("%d",&store11[i].book_amount);
	    				store11[i].book_reserves+=store11[i].book_amount;
	    				w1_fp(a,store11,k,0);
	    				printf("你已成功添加本图书信息,是否继续添加?<0(否)/1(是)>:");
	   				 	scanf("%d",&flag);
	   				 	break;
	   				 }
				}
				if(i==k)
				{
					printf("价格:");
					scanf("%f",&store1[book_information_count].book_money);
					printf("出版社:");
					scanf("%s",store1[book_information_count].book_publisher);
					printf("图书类别:");
					scanf("%s",store1[book_information_count].book_variety);
					printf("添加入库数量:");
					scanf("%d",&store1[book_information_count].book_amount);
					store1[book_information_count].book_reserves=0;
					store1[book_information_count].book_reserves=store1[book_information_count].book_amount;
					printf("\n");
					printf("你已成功添加图书信息,是否继续添加?<0(否)/1(是)>:");
					book_information_count++;
					scanf("%d",&flag);
				}
			}
			if(m==0)
			{
				w1_fp(a,store1,book_information_count,0);
			}
			else
			w1_fp(a,store1,book_information_count,1);
			printf("\n\t\t共添加了%d本图书",k+book_information_count);
			printf("\n\n");
		}
		if(ch=='n')
		{
			return;
		}
    }
}
void customers()
{   
	char ch[20],file[30]="c:/book_information.txt",file1[30]="c:/customer_information.txt";
	char file2[30]="c:/vip_application.txt";
	int k,i,j,a,m,d,flag=1,c_count=0;
	system("cls");
    printf("\n\n");  
    printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|          书店销售管理系统(销售人员)        |\n");
	printf("\t\t|                  销售管理                  |\n");
	printf("\t\t|                  顾客购买                  |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************顾客购买信息!!!*************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|               -1---退出系统                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	d=r4_fp(file1,store4);
	while(flag)
	{	
		m=0;
	    printf("顾客号:");
	    scanf("%d",&store4[c_count].customer_number);
	    printf("顾客姓名:");
	    scanf("%s",store4[c_count].customer_name);
	    printf("顾客性别:");
	    scanf("%s",store4[c_count].customer_sex);
	    printf("是否会员<0(否)/1(是)>:");
        scanf("%d",&store4[c_count].customer_vip);
	    while(store4[c_count].customer_vip<0||store4[c_count].customer_vip>1)
        {
        	printf("请输入0或者1");
		    scanf("%d",&store4[c_count].customer_vip);
	    }
	    if(store4[c_count].customer_vip==1)
	    {
	    	printf("请输入会员号:");
	        scanf("%s",ch);
	        k=r5_fp(file2,store5);
            for(m=0,a=0;a<k;a++)
	        {
	        	if(strcmp(store5[a].vip_number,ch)==0)
	            {
	            	printf("会员号:%-10s会员姓名:%-10s会员性别:%-10s会员等级:%-10s",store5[a].vip_number,store5[a].vip_name,store5[a].vip_sex,store5[a].vip_level);
	                printf("\n");
	                m=1;
	                break;
	             }
	         } 
	         if(m==0)
	         {
	         	printf("并没有此用户的会员信息!!\n");
	            store4[c_count].customer_vip=0;	
	         }
	    }
	    m=0;
	    printf("购买图书编号:");
	    scanf("%s",store4[c_count].customer_bookid);
	    printf("购买数量:");
	    scanf("%d",&store4[c_count].customer_buy);
	    printf("购买时间(例如:2015 06 28):");
 	    scanf("%d%d%d",&store4[c_count].time.year,&store4[c_count].time.month,&store4[c_count].time.day);
        printf("图书单本价格:");
        k=r1_fp(file,store1);
        for(j=0;j<k;j++)
	    {
	        if(strcmp(store4[c_count].customer_bookid,store1[j].book_number)==0)
	        {
	           	printf("%-5.2f\n",store1[j].book_money);
	           	store4[c_count].customer_price=store1[j].book_money*store4[c_count].customer_buy;
	            printf("购买总价:%-5.2f\n",store4[c_count].customer_price);
	            store1[j].book_reserves=store1[j].book_reserves-store4[c_count].customer_buy;
	            printf("购买后剩余库存:%d\n",store1[j].book_reserves);
	            m=1;
	            w1_fp(file,store1,k,0);
	            break;
	         }
	     } 
	     if(m==0)
	     printf("这本图书信息还没有入库,价格不详!!\n");
	     c_count++;
         printf("是否还要继续输入?<0(否)/1(是)>:");
	     scanf("%d",&flag);    
	}
	if(d==0)
	w4_fp(file1,store4,c_count,0);
	else
	w4_fp(file1,store4,c_count,1);
	printf("\n\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void vip_application()
{
    char file[30]="c:/vip_application.txt";
	int i,j,k,flag=1,vip_application_count=0;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|          书店销售管理系统(销售人员)        |\n");
	printf("\t\t|                 会员申请                   |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************请输入会员信息!!!************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               0---返回上一级               |\n");
	printf("\t\t|               -1---退出系统                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n\n\n");
	printf("\t是否输入会员信息<0(否)/1(是)>:");
	scanf("%d",&j);
	while(j<0||j>1)
    {
    	printf("请重新输入(请选择菜单序号<0-1>");
    	scanf("%d",&j);
    }
    if(j==1)
	{	
		k=r5_fp(file,store5);
		while(flag)
	    {
	    	printf("\t添加新的会员信息:\n");
	        printf("会员号:");
	        scanf("%s",store5[vip_application_count].vip_number);
	        printf("会员姓名:");
	        scanf("%s",store5[vip_application_count].vip_name);
			printf("性别:");
			scanf("%s",store5[vip_application_count].vip_sex);
			printf("会员级别:");
			scanf("%s",store5[vip_application_count].vip_level);
			printf("\n");
			vip_application_count++;
			printf("你已成功添加新的会员信息,是否继续添加?<0(否)/1(是)>:");
			scanf("%d",&flag);
	    }
	    if(k==0)
	    {
			w5_fp(file,store5,vip_application_count,0);
	    }
	    else
	    w5_fp(file,store5,vip_application_count,1);
		k=r5_fp(file,store5);
		printf("共添加了%d个会员信息",k);
		printf("\n");
	}
	printf("\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void day()
{  
	int a,k,c,b,z,j,temp,i,m,flag=1,day,month,year;
	float money=0,tem;
    char ch[20], file[30]="c:/customer_information.txt";
    system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               书店销售管理系统             |\n");
	printf("\t\t|               销售统计管理系统             |\n");
	printf("\t\t|                   按天统计                 |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************销售列表(day)!!!************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|                -1---退出系统               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r4_fp(file,store4);
    while(flag)
    {	
    	money=0;
    	a=0;
    	printf("请输入你要查看的年月日(例如:2015 06 30):");
    	scanf("%d%d%d",&year,&month,&day);
    	printf("\t按单本销售量大到小排序!\n");
    	for(c=0,i=0;i<k;i++)
    	{	
    		if((store4[i].time.year==year)&&(store4[i].time.month==month)&&(store4[i].time.day==day))
			{	
				for(m=0,j=0;j<a;j++)	
				{
					if(strcmp(amount[j].f,store4[i].customer_bookid)==0)
					{	
						amount[j].i+=store4[i].customer_buy;
						amount[j].j+=store4[i].customer_price;
	 					m=1;
	 					c=1;
	 					break;
					}
				}
				if(m==0)
				{   
					strcpy(amount[a].f,store4[i].customer_bookid);
					amount[a].i=store4[i].customer_buy;
					amount[a].j=store4[i].customer_price;
					a++;
					c=1;
				}
			}
		}
   		for(i=0;i<a-1;i++)
		{   
			z=i;
			for(b=i+1;b<a;b++)
			{
				if(amount[z].i<amount[b].i)
	 			z=b;
	 		}
			if(z!=i)
			{
					temp=amount[i].i;
					strcpy(ch,amount[i].f);
					tem=amount[i].j;
	 				amount[i].i=amount[z].i;
	 				strcpy(amount[i].f,amount[z].f);
	 				amount[i].j=amount[z].j;
	 				amount[z].i=temp;
	 				strcpy(amount[z].f,ch);
					amount[z].j=tem;
			}
		}
		if(c==1)
		{   
			printf("\n\t图书编号\t每本销售总量(当日)\t每本销售总额(当日)\n");
    		for(i=0;i<a;i++)
    		{	
    			printf("\t%s\t\t%d\t\t\t%.2f\t",amount[i].f,amount[i].i,amount[i].j);
    			money+=amount[i].j;
    			printf("\n");
    		}
    		printf("\n\t\t\t\t\t\t总销售额:%-5.2f\n",money);
		}
		else
		printf("\n\t\t不好意思!当天没有销售记录!!!");
    	printf("\n\t\t\t是否继续查询销售量?<0(否)--1(是)>:");
    	scanf("%d",&flag);
    	while(flag<0||flag>1)
    	{
    		printf("\t\t请选择0或者1");
    		scanf("%d",&flag);
    	}
    }
    printf("\n\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void month()
{  
	int a,k,c,b,z,j,temp,i=0,m,flag=1,year,month;
	float money=0,tem;
    char ch[20], file[30]="c:/customer_information.txt";
    system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               书店销售管理系统             |\n");
	printf("\t\t|               销售统计管理系统             |\n");
	printf("\t\t|                   按月统计                 |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************销售列表(month)!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|                -1---退出系统               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r4_fp(file,store4);
    while(flag)
    {
    	money=0;
    	a=0;
    	printf("请输入你要查看的年月(例如:2015 06):");
    	scanf("%d%d",&year,&month);
    	printf("\t按单本销售量大到小排序!\n");
    	for(c=0,i=0;i<k;i++)
    	{
    		if((store4[i].time.year==year)&&(store4[i].time.month==month))
			{	
				for(m=0,j=0;j<a;j++)	
				{
					if(strcmp(amount[j].f,store4[i].customer_bookid)==0)
					{	
						amount[j].i+=store4[i].customer_buy;
						amount[j].j+=store4[i].customer_price;
	 					m=1;
	 					c=1;
	 					break;
					}
				}
				if(m==0)
				{
					strcpy(amount[a].f,store4[i].customer_bookid);
					amount[a].i=store4[i].customer_buy;
					amount[a].j=store4[i].customer_price;
					a++;
					c=1;
				}
			}
		}
   		for(i=0;i<a-1;i++)
		{
			z=i;
			for(b=i+1;b<a;b++)
			{
				if(amount[z].i<amount[b].i)
	 			z=b;
	 		}
			if(z!=i)
			{
					temp=amount[i].i;
					strcpy(ch,amount[i].f);
					tem=amount[i].j;
	 				amount[i].i=amount[z].i;
	 				strcpy(amount[i].f,amount[z].f);
	 				amount[i].j=amount[z].j;
	 				amount[z].i=temp;
	 				strcpy(amount[z].f,ch);
	 				amount[z].j=tem;
				
			}
		}
    	if(c==1)
		{
			printf("\n\t图书编号\t每本销售总量(当月)\t每本销售总额(当月)\n");
    		for(i=0;i<a;i++)
    		{	
    			printf("\t%s\t\t%d\t\t\t%.2f\t",amount[i].f,amount[i].i,amount[i].j);
    			money+=amount[i].j;
    			printf("\n");
    		}
    		printf("\n\t\t\t\t\t\t总销售额:%-5.2f\n",money);
		}
		else
		printf("\n\t\t不好意思!当天没有销售记录!!!");
    	printf("\n\t\t\t是否继续查询销售量?<0(否)--1(是)>:");
    	scanf("%d",&flag);
    	while(flag<0||flag>1)
    	{
    		printf("\t\t请选择0或者1");
    		scanf("%d",&flag);
    	}
    }
    printf("\n\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void season()
{  
	int a,k,c,b,z,j,temp,i=0,m,n,flag=1,season,year;
	float money=0,tem;
    char ch[20], file[30]="c:/customer_information.txt";
    system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               书店销售管理系统             |\n");
	printf("\t\t|               销售统计管理系统             |\n");
	printf("\t\t|                  按季度统计                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************销售列表(season)!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|                -1---退出系统               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r4_fp(file,store4);
    while(flag)
    {	
    	money=0;
    	a=0;
    	c=0;
    	printf("请输入你要查看的季度(例如:2015 1----表示2015年第一季度):");
    	scanf("%d%d",&year,&season);
    	printf("\t按单本销售量大到小排序!\n");
    	for(i=0;i<k;i++)
    	{	
    		switch(store4[i].time.month)
    		{	
    			case 1:	case 2:	case 3:n=1;break;
    			case 4:	case 5:	case 6:n=2;break;
    			case 7:	case 8:	case 9:n=3;break;
    			case 10: case 11: case 12:n=4;break;
    		}
    		if((store4[i].time.year==year)&&(season==n))
			{	
				for(m=0,j=0;j<a;j++)	
				{
					if(strcmp(amount[j].f,store4[i].customer_bookid)==0)
					{	
						amount[j].i+=store4[i].customer_buy;
						amount[j].j+=store4[i].customer_price;
	 					m=1;
	 					c=1;
	 					break;
					}
				}
				if(m==0)
				{
					strcpy(amount[a].f,store4[i].customer_bookid);
					amount[a].i=store4[i].customer_buy;
					amount[a].j=store4[i].customer_price;
					a++;
					c=1;
				}
			}
		}
   		for(i=0;i<a-1;i++)
		{
			z=i;
			for(b=i+1;b<a;b++)
			{
				if(amount[z].i<amount[b].i)
	 			z=b;
	 		}
			if(z!=i)
			{
					temp=amount[i].i;
					strcpy(ch,amount[i].f);
					tem=amount[i].j;
	 				amount[i].i=amount[z].i;
	 				strcpy(amount[i].f,amount[z].f);
	 				amount[i].j=amount[z].j;
	 				amount[z].i=temp;
	 				strcpy(amount[z].f,ch);
	 				amount[z].j=tem;
				
			}
		}
    	if(c==1)
		{	
			printf("\n\t图书编号\t每本销售总量(当季度)\t每本销售总额(当季度)\n");
    		for(i=0;i<a;i++)
    		{	
    			printf("\t%s\t\t%d\t\t\t%.2f\t",amount[i].f,amount[i].i,amount[i].j);
    			money+=amount[i].j;
    			printf("\n");
    		}
    		printf("\n\t\t\t\t\t\t总销售额:%-5.2f\n",money);
		}
		else
		printf("\n\t\t不好意思!当天没有销售记录!!!");
    	printf("\n\t\t\t是否继续查询销售量?<0(否)--1(是)>:");
    	scanf("%d",&flag);
    	while(flag<0||flag>1)
    	{
    		printf("\t\t请选择0或者1");
    		scanf("%d",&flag);
    	}
    }
    printf("\n\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void bookin()
{   
	int i;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               书店销售管理系统             |\n");
	printf("\t\t|                 图书入库管理               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************请输入图书信息!!!************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               0---返回上一级               |\n");
	printf("\t\t|               -1---退出系统                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n\n\n");
	book_information();/*book information图书信息*/
	printf("\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>:");
    	scanf("%d",&i);
    }
   
    switch(i)
     {
     	case 0:return;
     	case -1:exit(0);
     }
}	
void publisher()
{   
	char ch[20],file[30]="c:/book_information.txt";
	int k,i,j,flag=1,m;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|                 图书查询统计               |\n");
	printf("\t\t|                 按出版社询查               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************图书信息列表!!!*************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|                -1---退出系统               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r1_fp(file,store1);
	while(flag)
	{
		m=0;
		printf("输入出版社名称:");
		scanf("%s",ch);
		for(j=0;j<k;j++)
		{
			if(strcmp(ch,store1[j].book_publisher)==0)
	 		{
	 			printf("出版社:%-10s图书编号:%-10s书名:%-10s作者:%-10s",store1[j].book_publisher,store1[j].book_number,store1[j].book_name,store1[j].book_author);
	 			printf("\n价格:%-5.2f图书类别:%-10s总库数量:%-5d",store1[j].book_money,store1[j].book_variety,store1[j].book_reserves);
	 			printf("\n");
	 			m++;
	 		}
	 	}
	 	if(m==0)
	 	printf("对不起,没有此出版社的图书!!\n\n");
	 	printf("是否继续询查?<0(否)/1(是)>:");
		scanf("%d",&flag);
	}
	printf("\n\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void author()
{ 
	char ch[20],file[30]="c:/book_information.txt";
	int k,i,j,flag=1,m;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|                 图书查询统计               |\n");
	printf("\t\t|                 按作者询查                 |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************图书信息列表!!!*************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|                -1---退出系统               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r1_fp(file,store1);
	while(flag)
	{
		m=0;
		printf("输入作者名称:");
		scanf("%s",ch);
		for(j=0;j<k;j++)
		{
			if(strcmp(ch,store1[j].book_author)==0)
	 		{
	 			printf("作者:%-10s图书编号:%-10s书名:%-10s出版社:%-10s",store1[j].book_author,store1[j].book_number,store1[j].book_name,store1[j].book_publisher);
	 			printf("\n价格:%-5.2f图书类别:%-10s总库数量:%-5d",store1[j].book_money,store1[j].book_variety,store1[j].book_reserves);
	 			printf("\n");
	 			m++;
	 		}
	 	}
	 	if(m==0)
		printf("对不起,没有此作者的图书!!\n\n");
	 	printf("是否继续询查?<0(否)/1(是)>:");
		scanf("%d",&flag);
	}
	printf("\n\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void book()
{   
	char ch[20],file[30]="c:/book_information.txt";
	int k,i,j,flag=1,m;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|                 图书查询统计               |\n");
	printf("\t\t|                 按书名询查                 |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************图书信息列表!!!*************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|                -1---退出系统               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r1_fp(file,store1);
	while(flag)
	{
		m=0;
		printf("输入图书名称:");
		scanf("%s",ch);
		for(j=0;j<k;j++)
		{
			if(strcmp(ch,store1[j].book_name)==0)
	 		{
	 			printf("书名:%-10s图书编号:%-10s作者:%-10s出版社:%-10s",store1[j].book_name,store1[j].book_number,store1[j].book_author,store1[j].book_publisher);
	 			printf("\n价格:%-5.2f图书类别:%-10s总库数量:%-5d",store1[j].book_money,store1[j].book_variety,store1[j].book_reserves);
	 			printf("\n");
	 			m++;
	 		}
	 	}
	 	if(m==0)
	 	printf("对不起,没有此名称的图书!!\n\n");
	 	printf("是否继续询查?<0(否)/1(是)>:");
		scanf("%d",&flag);
	}
	printf("\n\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void books_categories()
{
	char ch[20],file[30]="c:/book_information.txt";
	int k,i,j,flag=1,m;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|                 图书查询统计               |\n");
	printf("\t\t|                按图书类别询查              |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************图书信息列表!!!*************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|                -1---退出系统               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r1_fp(file,store1);
	while(flag)
	{
		m=0;
		printf("输入图书类别:");
		scanf("%s",ch);
		for(j=0;j<k;j++)
		{
			if(strcmp(ch,store1[j].book_variety)==0)
	 		{
	 			printf("图书类别:%-10s图书编号:%-10s作者:%-10s出版社:%-10s",store1[j].book_variety,store1[j].book_number,store1[j].book_author,store1[j].book_publisher);
	 			printf("\n价格:%-5.2f书名:%-10s总库数量:%-5d",store1[j].book_money,store1[j].book_name,store1[j].book_reserves);
	 			printf("\n");
	 			m++;
	 		}
	 	}
	 	if(m==0)
	 	printf("对不起,没有此类别的图书!!\n\n");
	 	printf("是否继续询查?<0(否)/1(是)>:");
		scanf("%d",&flag);
	}
	printf("\n\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void vip_message()
{
	char file[30]="c:/vip_application.txt";
	int j,i,k,flag=1;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
    printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|                  会员管理                  |\n");
	printf("\t\t|                  会员信息                  |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************会员信息列表!!!**************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               0---返回上一级               |\n");
	printf("\t\t|               -1---退出系统                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n\n\n");
	k=r5_fp(file,store5);
	for(j=0;j<k;j++)
	{
	 	printf("会员号:%-10s会员姓名:%-10s会员性别:%-10s会员等级:%-10s",store5[j].vip_number,store5[j].vip_name,store5[j].vip_sex,store5[j].vip_level);
	 	printf("\n");
	}
	printf("\n\t\t共添加了%d个会员信息",k);
	printf("\n\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void sale_apply()
{	
	char file[30]="c:/sale_message.txt";
	int k,j,i,d,flag,sale_count=0;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|                   系统管理                 |\n");
	printf("\t\t|               申请成为销售人员             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************创建销售人员信息!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|                -1---退出系统               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	printf("\t是否输入销售人员信息<0(否)/1(是)>:");
	scanf("%d",&j);
	while(j<0||j>1)
    {
    	printf("请重新输入(请选择菜单序号<0-1>");
    	scanf("%d",&j);
    }
    if(j==1)
    {	
    	d=r2_fp(file,store2);
		while(flag)
	    {
	    	printf("\t添加新的销售人员信息:\n");
	        printf("销售人员编号:");
	        scanf("%s",store2[sale_count].sale_number);
	        printf("销售人员姓名:");
	        scanf("%s",store2[sale_count].sale_name);
			printf("性别:");
			scanf("%s",store2[sale_count].sale_sex);
			printf("登录密码:");
			scanf("%s",store2[sale_count].sale_passwords);
			printf("\n");
			sale_count++;
			printf("你已成功添加新的销售人员信息,是否继续添加?<0(否)/1(是)>:");
			scanf("%d",&flag);
	    }
	    if(d==0)
		w2_fp(file,store2,sale_count,0);
		else
		w2_fp(file,store2,sale_count,1);
		k=r2_fp(file,store2);
		printf("共添加了%d个销售人员信息",k);
		printf("\n");
	}	
	printf("\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void manage_apply()
{	
	char file[30]="c:/manage_message.txt";
	int k,j,d,i,flag,manage_count=0;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|                   系统管理                 |\n");
	printf("\t\t|               申请成为管理人员             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************创建管理人员信息!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|                -1---退出系统               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	printf("\t是否输入管理人员信息<0(否)/1(是)>:");
	scanf("%d",&j);
	while(j<0||j>1)
    {
    	printf("请重新输入(请选择菜单序号<0-1>");
    	scanf("%d",&j);
    }
    if(j==1)
    {
    	d=r3_fp(file,store3);
		while(flag)
	    {
	    	printf("\t添加新的管理人员信息:\n");
	        printf("管理人员编号:");
	        scanf("%s",store3[manage_count].administrator_number);
	        printf("管理人员姓名:");
	        scanf("%s",store3[manage_count].administrator_name);
			printf("性别:");
			scanf("%s",store3[manage_count].administrator_sex);
			printf("登录密码:");
			scanf("%s",store3[manage_count].administrator_passwords);
			printf("\n");
			manage_count++;
			printf("你已成功添加新的管理人员信息,是否继续添加?<0(否)/1(是)>:");
			scanf("%d",&flag);
	    }
	    if(d==0)
		w3_fp(file,store3,manage_count,0);
		else
		w3_fp(file,store3,manage_count,1);
		k=r3_fp(file,store3);
		printf("共添加了%d个管理人员信息",k);
		printf("\n");
	}	
	printf("\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void sale_change()
{	
	char ch[20],file[30]="c:/sale_message.txt";
	int k,j,i,m,flag;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|                   系统管理                 |\n");
	printf("\t\t|               更改销售人员密码             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************更改销售人员密码!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|                -1---退出系统               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	printf("\t是否更改销售人员密码<0(否)/1(是)>:");
	scanf("%d",&j);
	while(j<0||j>1)
    {
    	printf("请重新输入(请选择菜单序号<0-1>");
    	scanf("%d",&j);
    }
    if(j==1)
    {
		while(flag)
	    {	
	    	k=r2_fp(file,store2);	
	    	printf("\t输入想要更改的销售人员编号:");
	        scanf("%s",ch);
	        for(m=0,i=0;i<k;i++)
	        {	
	        	if(strcmp(store2[i].sale_number,ch)==0)
	            {
	            	printf("销售人员编号:%-10s销售人员姓名:%-10s性别:%-10s登录密码:%-10s",store2[i].sale_number,store2[i].sale_name,store2[i].sale_sex,store2[i].sale_passwords);
	                printf("\n");
	                printf("\n新的登录密码:");
			 		scanf("%s",store2[i].sale_passwords);
			 		w2_fp(file,store2,k,0);
	                m=1;
	                break;
	             }
	         } 
	         if(m==0)
	         {
	         	printf("并没有此销售人员信息!!\n");
	         }
			 printf("\n\t\t\t是否继续更改?<0(否)/1(是)>:");
			 scanf("%d",&flag);
	    }
	}	
	printf("\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void manage_change()
{	
	char ch[20],file[30]="c:/manage_message.txt";
	int k,j,i,m,flag;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|                   系统管理                 |\n");
	printf("\t\t|               更改管理人员密码             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************更改管理人员密码!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---返回上一级              |\n");
	printf("\t\t|                -1---退出系统               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	printf("\t是否更改管理人员密码<0(否)/1(是)>:");
	scanf("%d",&j);
	while(j<0||j>1)
    {
    	printf("请重新输入(请选择菜单序号<0-1>");
    	scanf("%d",&j);
    }
    if(j==1)
    {
		while(flag)
	    {	
	    	k=r3_fp(file,store3);	
	    	printf("\t输入想要更改的管理人员编号:");
	        scanf("%s",ch);
	        for(m=0,i=0;i<k;i++)
	        {	
	        	if(strcmp(store3[i].administrator_number,ch)==0)
	            {
	            	printf("管理人员编号:%-10s管理人员姓名:%-10s",store3[i].administrator_number,store3[i].administrator_name);
	                printf("性别:%-10s登录密码:%-10s",store3[i].administrator_sex,store3[i].administrator_passwords);
	                printf("\n");
	                printf("\n新的登录密码:");
			 		scanf("%s",store3[i].administrator_passwords);
			 		w3_fp(file,store3,k,0);
	                m=1;
	                break;
	             }
	         } 
	         if(m==0)
	         {
	         	printf("并没有此管理人员信息!!\n");
	         }
			 printf("\n\t\t\t是否继续更改?<0(否)/1(是)>:");
			 scanf("%d",&flag);
	    }
	}	
	printf("\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void sale_list()
{
	char file[30]="c:/sale_message.txt";
	int j,i,k,flag=1;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
    printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|                   系统管理                 |\n");
	printf("\t\t|               销售人员信息列表             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************销售人员信息列表!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               0---返回上一级               |\n");
	printf("\t\t|               -1---退出系统                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n\n\n");
	k=r2_fp(file,store2);
	for(j=0;j<k;j++)
	{
	 	printf("销售人员编号:%-10s销售人员姓名:%-10s性别:%-10s登录密码:%-10s",store2[j].sale_number,store2[j].sale_name,store2[j].sale_sex,store2[j].sale_passwords);
	 	printf("\n");
	}
	printf("\n\t\t共添加了%d个销售人员信息",k);
	printf("\n\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void manage_list()
{
	char file[30]="c:/manage_message.txt";
	int j,i,k,flag=1;
	system("cls");
	printf("\n\n");  
	printf("\t\t|--------------------------------------------|\n");
    printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|                   系统管理                 |\n");
	printf("\t\t|               管理人员信息列表             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************管理人员信息列表!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               0---返回上一级               |\n");
	printf("\t\t|               -1---退出系统                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n\n\n");
	k=r3_fp(file,store3);
	for(j=0;j<k;j++)
	{
	 	printf("管理人员编号:%-10s管理人员姓名:%-10s性别:%-10s登录密码:%-10s",store3[j].administrator_number,store3[j].administrator_name,store3[j].administrator_sex,store3[j].administrator_passwords);
	 	printf("\n");
	}
	printf("\n\t\t共添加了%d个管理人员信息",k);
	printf("\n\t\t\t请选择菜单序号<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("请重新输入(请选择菜单序号<-1-0>");
    	scanf("%d",&i);
    }
    if(i==-1)
    exit(0);
}
void sm()
{
	int i;
	while(1)
	{
		system("cls");
	    printf("\n\n");
	    printf("\t\t|--------------------------------------------|\n");
	    printf("\t\t|          书店销售管理系统(销售人员)        |\n");
	    printf("\t\t|                  销售管理                  |\n");
	    printf("\t\t|--------------------------------------------|\n");
	    printf("\t\t|               1---顾客购买                 |\n");
        printf("\t\t|               0---返回上一级               |\n");
        printf("\t\t|--------------------------------------------|\n");
        printf("\t\t\t请选择菜单序号<0-1>:");
        scanf("%d",&i);
        while(i<0||i>1)
        {
        	printf("请重新输入(请选择菜单序号<0-1>:");
    	    scanf("%d",&i);
        }
        switch(i)
        {
        	case 1:customers();break;/*customers顾客购买*/
	        case 0:return;
        } 
	}
}
void vip1()
{ 
    int i;
    while(1)
	{
		system("cls");
	 	printf("\n\n");  
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|          书店销售管理系统(销售人员)        |\n");
		printf("\t\t|                   会员管理                 |\n");
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|                 1---会员申请               |\n");
   		printf("\t\t|                 0---返回上一级             |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t请选择菜单序号<0-1>:");
    	scanf("%d",&i);
   	 	{
   	 		while(i<0||i>1)
    		{
    			printf("请重新输入(请选择菜单序号<0-1>:");
    			scanf("%d",&i);
    		}
    		switch(i)
    		{
    			case 1:vip_application();break;/*vip_application会员申请*/
	 			case 0:return;
    		}
   	 	}
	}
}

void ssm()
{   
	while(1)
	{
		int i; 
		system("cls");
		printf("\n\n");  
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|          书店销售管理系统(销售人员)        |\n");
		printf("\t\t|               销售统计管理                 |\n");
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|               1---按天统计                 |\n");
    	printf("\t\t|               2---按月统计                 |\n");
    	printf("\t\t|               3---按季度统计               |\n");
   		printf("\t\t|               0---返回上一级               |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t请选择菜单序号<0-3>:");
    	scanf("%d",&i);
    	while(i<0||i>3)
    	{
    		printf("请重新输入(请选择菜单序号<0-3>:");
    		scanf("%d",&i);
    	}
    	switch(i)
    	{	
    		case 1:day();break;/*day按天统计*/
	 		case 2:month();break;/*month按月统计*/
	 		case 3:season();break;/*season按季度统计*/
	 		case 0:return;
    	} 
    
	}
}
void bwm()
{ 
    int i;
    while(1)
	{
		system("cls");
	 	printf("\n\n");  
	 	printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|           书店销售管理系统(管理人员)       |\n");
		printf("\t\t|                图书入库管理                |\n");
	    printf("\t\t|--------------------------------------------|\n");
	    printf("\t\t|               1---图书入库信息             |\n");
   		printf("\t\t|               0---返回上一级               |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t请选择菜单序号<0-1>:");
    	scanf("%d",&i);
   	 	{
   	 		while(i<0||i>1)
    		{
    			printf("请重新输入(请选择菜单序号<0-1>:");
    			scanf("%d",&i);
    		}
    		switch(i)
    		{
    			case 1:bookin();break;
	 			case 0:return;
    		}
   	 	}
	}
}
void bqs()
{   
	int i;
	while(1)
	{
		system("cls");
		printf("\n\n");  
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|           书店销售管理系统(管理人员)       |\n");
		printf("\t\t|                 图书询查统计               |\n");
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|               1---按出版社询查             |\n");
    	printf("\t\t|               2---按作者询查               |\n");
    	printf("\t\t|               3---按书名询查               |\n");
    	printf("\t\t|               4---按图书类别询查           |\n");
    	printf("\t\t|               0---返回上一级               |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t请选择菜单序号<0-4>:");
    	scanf("%d",&i);
    	while(i<0||i>4)
    	{
    		printf("请重新输入(请选择菜单序号<0-4>:");
    		scanf("%d",&i);
    	}
    	switch(i)
    	{
    		case 1:publisher();break;/*publisher出版社询查*/
	 		case 2:author();break;/*author作者询查*/
			case 3:book();break;/*书名询查*/
	 		case 4:books_categories();break;/*图书类别询查*/
	 		case 0:return;
    	} 
	}
}
void vip2()
{ 
    int i;
    while(1)
	{
		system("cls");
	 	printf("\n\n");  
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|           书店销售管理系统(管理人员)       |\n");
		printf("\t\t|                   会员管理                 |\n");
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|                1---会员信息列表            |\n");
   		printf("\t\t|                0---返回上一级              |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t请选择菜单序号<0-1>:");
    	scanf("%d",&i);
   	 	{
   	 		while(i<0||i>1)
    		{
    			printf("请重新输入(请选择菜单序号<0-1>:");
    			scanf("%d",&i);
    		}
    		switch(i)
    		{
    			case 1:vip_message();break;/*vip_message会员信息列表*/
	 			case 0:return;
    		}
   	 	}
	}
}
void sys()
{
	int i;
	while(1)
	{
		system("cls");
		printf("\n\n");  
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|           书店销售管理系统(管理人员)       |\n");
		printf("\t\t|                   系统管理                 |\n");
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|             1---申请成为销售人员           |\n");
		printf("\t\t|             2---申请成为管理人员           |\n");
		printf("\t\t|             3---更改销售人员密码           |\n");
		printf("\t\t|             4---更改管理人员密码           |\n");
		printf("\t\t|             5---销售人员信息列表           |\n");
		printf("\t\t|             6---管理人员信息列表           |\n");
		printf("\t\t|             0---返回上一级                 |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t请选择菜单序号<0-6>:");
    	scanf("%d",&i);
    	while(i<0||i>6)
    	{
    		printf("请重新输入(请选择菜单序号<0-6>:");
    		scanf("%d",&i);
    	}
    	switch(i)
    	{
    		case 1:sale_apply();break;/*申请成为销售人员*/
	 		case 2:manage_apply();break;/*申请成为管理人员*/
			case 3:sale_change();break;/*更改销售人员信息*/
			case 4:manage_change();break;/*更改管理人员信息*/
	 		case 5:sale_list();break;/*销售人员信息列表 */
	 		case 6:manage_list();break;/*管理人员信息列表 */
	 		case 0:return;
    	} 
	}
}
int Menu1()
{
	int i; 
	system("cls");
	printf("\n\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|          书店销售管理系统(销售人员)        |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|              1---销售管理                  |\n");
	printf("\t\t|              2---会员申请                  |\n");
    printf("\t\t|              3---销售统计管理              |\n");
    printf("\t\t|              0---返回登陆界面              |\n");
    printf("\t\t|             -1---退出系统                  |\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t\t请选择主菜单序号<-1-3>:");
    scanf("%d",&i);
    while(i<-1||i>3)
    {
    	printf("请重新输入(请选择主菜单序号<-1-3>:");
    	scanf("%d",&i);
    }
    return(i);
}
int Menu2()
{
	int i; 
	system("cls");
	printf("\n\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|           书店销售管理系统(管理人员)       |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|              1---图书入库管理              |\n");
	printf("\t\t|              2---图书询查统计              |\n");
    printf("\t\t|              3---会员管理                  |\n");
    printf("\t\t|              4---系统管理                  |\n");
    printf("\t\t|              0---返回登陆界面              |\n");
    printf("\t\t|             -1---退出系统                  |\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t\t请选择主菜单序号<-1-4>:");
    scanf("%d",&i);
    while(i<-1||i>4)
    {
    	printf("请重新输入(请选择主菜单序号<-1-4>");
    	scanf("%d",&i);
    }
    return(i);
}
int PassWord1()
{
	char pwd1[8],pwd2[10],ch,h,file[30]="c:/sale_message.txt";
	int k,i,j,a,b=0;
	for(i=1;i<=3;i++)
	{   
		system("cls");
		printf("\n\n\n\n\t\t  |--------------------------------------------|\n");
		printf("\t\t  |          书店销售管理系统(销售人员)        |\n");
		printf("\t\t  |--------------------------------------------|\n");
		k=r2_fp(file,store2);
		if(k==0)
		{	
			printf("\n\t\t还没注册成为销售人员!!\n");
			printf("\t\t请找管理人员注册后才能登录系统!!");
			getchar();
			printf("\n\n\n\t\t\t按回车返回登陆界面!");
		    while((h=getchar())!='\n')
		   	{
		    	printf("\n\n\t\t\t按回车登陆界面!");
			   	getchar();
		   	}
			return k;
			
		}
		printf("\n\n\t\t\t      请输入销售人员编号:");
	    scanf("%s",pwd1);	
		printf("\n\t\t\t      请输入密码:");
		for(j=0;(ch=getch())!='\r';j++)
		{
			if(j>0&&ch=='\b')
			{	
				putchar('\b');
				putchar(' ');
				putchar('\b');
				j=j-2;
			}
			else
			{
				pwd2[j]=ch;
				putchar('*');
			}
		}
		getchar();
		pwd2[j]='\0';
		k=r2_fp(file,store2);
		for(a=0,b=0;b<k;b++)
		{
			if((strcmp(pwd1,store2[b].sale_number)==0)&&(strcmp(pwd2,store2[b].sale_passwords)==0))
			{	
				a=1;
				system("cls");
		    	printf("\n\n\n\n\n\t\t\t成功进入到书店销售系统\n");
		   	 	printf("\n\n\n\n\n\t\t\t按回车继续!");
		    	while((h=getchar())!='\n')
		   		{
		    		printf("\n\n\t\t\t按回车继续!");
			   	 	getchar();
		    	}
		    	break;
			}
		}
		if(a==1)
		break;
		if(a==0)
		{
			printf("\n\n\t\t\t      用户名或密码错误!\n");
			if(i==1||i==2)
			{
				printf("\n\n\t\t\t\t\t按回车重新输入!");
				while((h=getchar())!='\n')
		   		{
		    		printf("\n\n\t\t\t\t\t按回车重新输入!");
			    	getchar();
		    	}
			}
		}
	}
	if(i>3)
	{
		printf("\n\t\t密码输入已达3次,你无权使用该系统,请退出!\n");
		exit(0);
	}
	return k;
}
void PassWord2()
{
	char pwd1[8],pwd2[10],ch,h,file[30]="c:/manage_message.txt";
	int i,j,k,b,a;
	for(i=1;i<=3;i++)
	{   
		system("cls");
		printf("\n\n\n\n\t\t  |--------------------------------------------|\n");
		printf("\t\t  |          书店销售管理系统(管理人员)        |\n");
		printf("\t\t  |--------------------------------------------|\n");
		k=r3_fp(file,store3);
		if(k==0)
		{	
			printf("\t\t因为您还没注册成为管理人员!!\n");
			printf("\n\t请使用初始管理人员编号:abc和初始密码:123去登录系统!!(以后都可以使用)");
	        strcpy(store3[0].administrator_number,"abc");
	        strcpy(store3[0].administrator_name,"0");
	        strcpy(store3[0].administrator_sex,"0");
	        strcpy(store3[0].administrator_passwords,"123");
	        w3_fp(file,store3,1,0);	
	        k=r3_fp(file,store3);
		}
		printf("\n\n\t\t\t      请输入管理人员编号:");
	   	scanf("%s",pwd1);	
		printf("\n\t\t\t      请输入密码:");
		for(j=0;(ch=getch())!='\r';j++)
		{	
			if(j>0&&ch=='\b')
				{	
					putchar('\b');
					putchar(' ');
					putchar('\b');
					j=j-2;
				}
			else
			{
				pwd2[j]=ch;
				putchar('*');
			}
		}
		getchar();
		pwd2[j]='\0';	
		for(a=0,b=0;b<k;b++)
		{
			if((strcmp(pwd1,store3[b].administrator_number)==0)&&(strcmp(pwd2,store3[b].administrator_passwords)==0))
			{	
				a=1;
				system("cls");
	    		printf("\n\n\n\n\n\t\t\t成功进入到书店销售系统\n");
	   	 		printf("\n\n\n\n\n\t\t\t按回车继续!");
		   		while((h=getchar())!='\n')
	 			{
		   			printf("\n\n\t\t\t按回车继续!");
		   	 		getchar();
	    		}
		   		break;
			}
		}
		if(a==1)
		break;
		if(a==0)
		{
			printf("\n\n\t\t\t\t      用户名或密码错误!\n");
			if(i==1||i==2)
			{
				printf("\n\n\t\t\t\t\t\t按回车重新输入!");
				while((h=getchar())!='\n')
	  			{
		   			printf("\n\n\t\t\t\t\t\t按回车重新输入!");
		    		getchar();
		   		}
			}
		}
	}
	if(i>3)
	{
		printf("\n\t\t密码输入已达3次,你无权使用该系统,请退出!\n");
		exit(0);
	}
}
void main()
{
	int num1,num2,a,k;
	while(1)
	{
		system("cls");
		printf("\n\n\n\t\t   |----------------------------------------|\n");
		printf("\t\t   |            书店销售管理系统            |\n");
		printf("\t\t   |----------------------------------------|\n");
		printf("\t\t   |                登陆界面                |\n");
		printf("\t\t   |                                        |\n");
		printf("\t\t   |----------------------------------------|\n");
		printf("\n\t\t\t       销售人员登录--------1");
		printf("\n\n\t\t\t       管理人员登录--------2");
		printf("\n\n\t\t\t           退出系统--------0");
		printf("\n\n\n\t\t\t            请选择:--------");
		scanf("%d",&a);
		while(a<0||a>2)
		{
			printf("\n\n\t\t\t       重新输入0-2:--------");
			scanf("%d",&a);
		}
		switch(a)
		{
			case 1:k=PassWord1();break;
	    	case 2:PassWord2();
		}
		if(a==1)
		{
			if(k==0)
			{}
			else
			{	while(1)
				{   
					num1=Menu1();
					switch(num1)
					{
						case 1:sm();break;/*sales management销售管理*/
						case 2:vip1();break;/*vip_application会员申请*/
						case 3:ssm();break;/*Sales statistics management销售统计管理*/
						case 0:break;/*返回登陆界面*/
			    		case -1:exit(0);/*退出系统*/
					}
					if(num1==0)
           			break;
				}
			}
		}
		if(a==2)
		{
			while(1)
	    		{   
	    			num2=Menu2();
					switch(num2)
           			{
            			case 1:bwm();break;/*books warehouse management图书入库管理*/
              		  	case 2:bqs();break; /*book query statistics图书询查统计*/
	        	    	case 3:vip2();break;/*vip会员管理*/
	           		 	case 4:sys();break;/*system系统管理*/
	           		 	case 0:break;
	            		case -1:exit(0);/*退出系统*/
           			}
           			if(num2==0)
           			break;
	    		}
			}
			if(a==0)
			exit(0);
	}
}
