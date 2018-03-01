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
struct bookstore_time/*����ʱ��*/
{  
	int year;
	int month;
    int day;
};
struct bookstore1
{	
	char book_number[10];/*ͼ����*/
	char book_name[50];/*����*/
 	char book_author[20];/*����*/
 	float  book_money;/*�۸�*/
	char book_publisher[20];/*������*/
 	char book_variety[12];/*ͼ�����*/
	int book_amount;/*����������*/
	int book_reserves;/*�ܿ�����*/
}store1[N],store11[N];
struct bookstore2
{	
	char sale_number[8];/*������Ա���*/
 	char sale_name[8];/*������Ա����*/
 	char sale_sex[2];/*�Ա�*/
 	char sale_passwords[10];/*��¼����*/
}store2[N];
struct bookstore3
{	
	char administrator_number[8];/*����Ա���*/
 	char administrator_name[8];/*����Ա����*/
 	char administrator_sex[2];/*�Ա�*/
 	char administrator_passwords[10];/*��¼����*/
}store3[N];
struct bookstore4
{	
	int  customer_number;/*�˿ͺ�*/
 	char customer_name[8];/*�˿�����*/
	char customer_sex[2];/*�Ա�*/
 	int  customer_vip;/*�Ƿ��Ա*/
 	char customer_bookid[10];/*����ͼ����*/
 	int  customer_buy;/*��������*/
 	float customer_price;
 	struct bookstore_time time;/*����ʱ��*/
}store4[N];
struct bookstore5
{
	char vip_number[8];/*��Ա��*/
 	char vip_name[8];/*��Ա����*/
 	char vip_sex[2];/*�Ա�*/
 	char vip_level[5];/*��Ա����*/
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
	    printf("\n\t\t��û�����ͼ����Ϣ!!\n");
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
	    printf("\n\t\t��û�����������Ա��Ϣ!!\n");
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
	    printf("\n\t\t��û����ӹ�����Ա��Ϣ!!\n");
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
		printf("\n\t\t��û�й˿���Ϣ!!\n");
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
	    printf("\n\t\t��û�л�Ա��Ϣ!!\n");
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
		printf("�Ƿ����ͼ����Ϣ(y/n):");
		ch=getchar();
		ch=getchar();
		if(ch=='y')
		{
			k=r1_fp(a,store11);
			m=k;
			printf("\t�����Ҫ��ͼ����Ϣ:\n");
			while(flag)
			{
				printf("ͼ����:");
				scanf("%s",store1[book_information_count].book_number);
				printf("����:");
				scanf("%s",store1[book_information_count].book_name);
				printf("����:");
				scanf("%s",store1[book_information_count].book_author);
				for(i=0;i<k;i++)
				{
					if(strcmp(store11[i].book_name,store1[book_information_count].book_name)==0)
					if(strcmp(store11[i].book_author,store1[book_information_count].book_author)==0)
					{
						printf("�Ȿ�����Ϣ�Ѿ������,�����Ҫ��������:");
	    				scanf("%d",&store11[i].book_amount);
	    				store11[i].book_reserves+=store11[i].book_amount;
	    				w1_fp(a,store11,k,0);
	    				printf("���ѳɹ���ӱ�ͼ����Ϣ,�Ƿ�������?<0(��)/1(��)>:");
	   				 	scanf("%d",&flag);
	   				 	break;
	   				 }
				}
				if(i==k)
				{
					printf("�۸�:");
					scanf("%f",&store1[book_information_count].book_money);
					printf("������:");
					scanf("%s",store1[book_information_count].book_publisher);
					printf("ͼ�����:");
					scanf("%s",store1[book_information_count].book_variety);
					printf("����������:");
					scanf("%d",&store1[book_information_count].book_amount);
					store1[book_information_count].book_reserves=0;
					store1[book_information_count].book_reserves=store1[book_information_count].book_amount;
					printf("\n");
					printf("���ѳɹ����ͼ����Ϣ,�Ƿ�������?<0(��)/1(��)>:");
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
			printf("\n\t\t�������%d��ͼ��",k+book_information_count);
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
	printf("\t\t|          ������۹���ϵͳ(������Ա)        |\n");
	printf("\t\t|                  ���۹���                  |\n");
	printf("\t\t|                  �˿͹���                  |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************�˿͹�����Ϣ!!!*************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|               -1---�˳�ϵͳ                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	d=r4_fp(file1,store4);
	while(flag)
	{	
		m=0;
	    printf("�˿ͺ�:");
	    scanf("%d",&store4[c_count].customer_number);
	    printf("�˿�����:");
	    scanf("%s",store4[c_count].customer_name);
	    printf("�˿��Ա�:");
	    scanf("%s",store4[c_count].customer_sex);
	    printf("�Ƿ��Ա<0(��)/1(��)>:");
        scanf("%d",&store4[c_count].customer_vip);
	    while(store4[c_count].customer_vip<0||store4[c_count].customer_vip>1)
        {
        	printf("������0����1");
		    scanf("%d",&store4[c_count].customer_vip);
	    }
	    if(store4[c_count].customer_vip==1)
	    {
	    	printf("�������Ա��:");
	        scanf("%s",ch);
	        k=r5_fp(file2,store5);
            for(m=0,a=0;a<k;a++)
	        {
	        	if(strcmp(store5[a].vip_number,ch)==0)
	            {
	            	printf("��Ա��:%-10s��Ա����:%-10s��Ա�Ա�:%-10s��Ա�ȼ�:%-10s",store5[a].vip_number,store5[a].vip_name,store5[a].vip_sex,store5[a].vip_level);
	                printf("\n");
	                m=1;
	                break;
	             }
	         } 
	         if(m==0)
	         {
	         	printf("��û�д��û��Ļ�Ա��Ϣ!!\n");
	            store4[c_count].customer_vip=0;	
	         }
	    }
	    m=0;
	    printf("����ͼ����:");
	    scanf("%s",store4[c_count].customer_bookid);
	    printf("��������:");
	    scanf("%d",&store4[c_count].customer_buy);
	    printf("����ʱ��(����:2015 06 28):");
 	    scanf("%d%d%d",&store4[c_count].time.year,&store4[c_count].time.month,&store4[c_count].time.day);
        printf("ͼ�鵥���۸�:");
        k=r1_fp(file,store1);
        for(j=0;j<k;j++)
	    {
	        if(strcmp(store4[c_count].customer_bookid,store1[j].book_number)==0)
	        {
	           	printf("%-5.2f\n",store1[j].book_money);
	           	store4[c_count].customer_price=store1[j].book_money*store4[c_count].customer_buy;
	            printf("�����ܼ�:%-5.2f\n",store4[c_count].customer_price);
	            store1[j].book_reserves=store1[j].book_reserves-store4[c_count].customer_buy;
	            printf("�����ʣ����:%d\n",store1[j].book_reserves);
	            m=1;
	            w1_fp(file,store1,k,0);
	            break;
	         }
	     } 
	     if(m==0)
	     printf("�Ȿͼ����Ϣ��û�����,�۸���!!\n");
	     c_count++;
         printf("�Ƿ�Ҫ��������?<0(��)/1(��)>:");
	     scanf("%d",&flag);    
	}
	if(d==0)
	w4_fp(file1,store4,c_count,0);
	else
	w4_fp(file1,store4,c_count,1);
	printf("\n\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|          ������۹���ϵͳ(������Ա)        |\n");
	printf("\t\t|                 ��Ա����                   |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************�������Ա��Ϣ!!!************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               0---������һ��               |\n");
	printf("\t\t|               -1---�˳�ϵͳ                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n\n\n");
	printf("\t�Ƿ������Ա��Ϣ<0(��)/1(��)>:");
	scanf("%d",&j);
	while(j<0||j>1)
    {
    	printf("����������(��ѡ��˵����<0-1>");
    	scanf("%d",&j);
    }
    if(j==1)
	{	
		k=r5_fp(file,store5);
		while(flag)
	    {
	    	printf("\t����µĻ�Ա��Ϣ:\n");
	        printf("��Ա��:");
	        scanf("%s",store5[vip_application_count].vip_number);
	        printf("��Ա����:");
	        scanf("%s",store5[vip_application_count].vip_name);
			printf("�Ա�:");
			scanf("%s",store5[vip_application_count].vip_sex);
			printf("��Ա����:");
			scanf("%s",store5[vip_application_count].vip_level);
			printf("\n");
			vip_application_count++;
			printf("���ѳɹ�����µĻ�Ա��Ϣ,�Ƿ�������?<0(��)/1(��)>:");
			scanf("%d",&flag);
	    }
	    if(k==0)
	    {
			w5_fp(file,store5,vip_application_count,0);
	    }
	    else
	    w5_fp(file,store5,vip_application_count,1);
		k=r5_fp(file,store5);
		printf("�������%d����Ա��Ϣ",k);
		printf("\n");
	}
	printf("\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|               ������۹���ϵͳ             |\n");
	printf("\t\t|               ����ͳ�ƹ���ϵͳ             |\n");
	printf("\t\t|                   ����ͳ��                 |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************�����б�(day)!!!************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|                -1---�˳�ϵͳ               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r4_fp(file,store4);
    while(flag)
    {	
    	money=0;
    	a=0;
    	printf("��������Ҫ�鿴��������(����:2015 06 30):");
    	scanf("%d%d%d",&year,&month,&day);
    	printf("\t��������������С����!\n");
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
			printf("\n\tͼ����\tÿ����������(����)\tÿ�������ܶ�(����)\n");
    		for(i=0;i<a;i++)
    		{	
    			printf("\t%s\t\t%d\t\t\t%.2f\t",amount[i].f,amount[i].i,amount[i].j);
    			money+=amount[i].j;
    			printf("\n");
    		}
    		printf("\n\t\t\t\t\t\t�����۶�:%-5.2f\n",money);
		}
		else
		printf("\n\t\t������˼!����û�����ۼ�¼!!!");
    	printf("\n\t\t\t�Ƿ������ѯ������?<0(��)--1(��)>:");
    	scanf("%d",&flag);
    	while(flag<0||flag>1)
    	{
    		printf("\t\t��ѡ��0����1");
    		scanf("%d",&flag);
    	}
    }
    printf("\n\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|               ������۹���ϵͳ             |\n");
	printf("\t\t|               ����ͳ�ƹ���ϵͳ             |\n");
	printf("\t\t|                   ����ͳ��                 |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************�����б�(month)!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|                -1---�˳�ϵͳ               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r4_fp(file,store4);
    while(flag)
    {
    	money=0;
    	a=0;
    	printf("��������Ҫ�鿴������(����:2015 06):");
    	scanf("%d%d",&year,&month);
    	printf("\t��������������С����!\n");
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
			printf("\n\tͼ����\tÿ����������(����)\tÿ�������ܶ�(����)\n");
    		for(i=0;i<a;i++)
    		{	
    			printf("\t%s\t\t%d\t\t\t%.2f\t",amount[i].f,amount[i].i,amount[i].j);
    			money+=amount[i].j;
    			printf("\n");
    		}
    		printf("\n\t\t\t\t\t\t�����۶�:%-5.2f\n",money);
		}
		else
		printf("\n\t\t������˼!����û�����ۼ�¼!!!");
    	printf("\n\t\t\t�Ƿ������ѯ������?<0(��)--1(��)>:");
    	scanf("%d",&flag);
    	while(flag<0||flag>1)
    	{
    		printf("\t\t��ѡ��0����1");
    		scanf("%d",&flag);
    	}
    }
    printf("\n\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|               ������۹���ϵͳ             |\n");
	printf("\t\t|               ����ͳ�ƹ���ϵͳ             |\n");
	printf("\t\t|                  ������ͳ��                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************�����б�(season)!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|                -1---�˳�ϵͳ               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r4_fp(file,store4);
    while(flag)
    {	
    	money=0;
    	a=0;
    	c=0;
    	printf("��������Ҫ�鿴�ļ���(����:2015 1----��ʾ2015���һ����):");
    	scanf("%d%d",&year,&season);
    	printf("\t��������������С����!\n");
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
			printf("\n\tͼ����\tÿ����������(������)\tÿ�������ܶ�(������)\n");
    		for(i=0;i<a;i++)
    		{	
    			printf("\t%s\t\t%d\t\t\t%.2f\t",amount[i].f,amount[i].i,amount[i].j);
    			money+=amount[i].j;
    			printf("\n");
    		}
    		printf("\n\t\t\t\t\t\t�����۶�:%-5.2f\n",money);
		}
		else
		printf("\n\t\t������˼!����û�����ۼ�¼!!!");
    	printf("\n\t\t\t�Ƿ������ѯ������?<0(��)--1(��)>:");
    	scanf("%d",&flag);
    	while(flag<0||flag>1)
    	{
    		printf("\t\t��ѡ��0����1");
    		scanf("%d",&flag);
    	}
    }
    printf("\n\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|               ������۹���ϵͳ             |\n");
	printf("\t\t|                 ͼ��������               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************������ͼ����Ϣ!!!************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               0---������һ��               |\n");
	printf("\t\t|               -1---�˳�ϵͳ                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n\n\n");
	book_information();/*book informationͼ����Ϣ*/
	printf("\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>:");
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
	printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|                 ͼ���ѯͳ��               |\n");
	printf("\t\t|                 ��������ѯ��               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************ͼ����Ϣ�б�!!!*************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|                -1---�˳�ϵͳ               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r1_fp(file,store1);
	while(flag)
	{
		m=0;
		printf("�������������:");
		scanf("%s",ch);
		for(j=0;j<k;j++)
		{
			if(strcmp(ch,store1[j].book_publisher)==0)
	 		{
	 			printf("������:%-10sͼ����:%-10s����:%-10s����:%-10s",store1[j].book_publisher,store1[j].book_number,store1[j].book_name,store1[j].book_author);
	 			printf("\n�۸�:%-5.2fͼ�����:%-10s�ܿ�����:%-5d",store1[j].book_money,store1[j].book_variety,store1[j].book_reserves);
	 			printf("\n");
	 			m++;
	 		}
	 	}
	 	if(m==0)
	 	printf("�Բ���,û�д˳������ͼ��!!\n\n");
	 	printf("�Ƿ����ѯ��?<0(��)/1(��)>:");
		scanf("%d",&flag);
	}
	printf("\n\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|                 ͼ���ѯͳ��               |\n");
	printf("\t\t|                 ������ѯ��                 |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************ͼ����Ϣ�б�!!!*************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|                -1---�˳�ϵͳ               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r1_fp(file,store1);
	while(flag)
	{
		m=0;
		printf("������������:");
		scanf("%s",ch);
		for(j=0;j<k;j++)
		{
			if(strcmp(ch,store1[j].book_author)==0)
	 		{
	 			printf("����:%-10sͼ����:%-10s����:%-10s������:%-10s",store1[j].book_author,store1[j].book_number,store1[j].book_name,store1[j].book_publisher);
	 			printf("\n�۸�:%-5.2fͼ�����:%-10s�ܿ�����:%-5d",store1[j].book_money,store1[j].book_variety,store1[j].book_reserves);
	 			printf("\n");
	 			m++;
	 		}
	 	}
	 	if(m==0)
		printf("�Բ���,û�д����ߵ�ͼ��!!\n\n");
	 	printf("�Ƿ����ѯ��?<0(��)/1(��)>:");
		scanf("%d",&flag);
	}
	printf("\n\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|                 ͼ���ѯͳ��               |\n");
	printf("\t\t|                 ������ѯ��                 |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************ͼ����Ϣ�б�!!!*************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|                -1---�˳�ϵͳ               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r1_fp(file,store1);
	while(flag)
	{
		m=0;
		printf("����ͼ������:");
		scanf("%s",ch);
		for(j=0;j<k;j++)
		{
			if(strcmp(ch,store1[j].book_name)==0)
	 		{
	 			printf("����:%-10sͼ����:%-10s����:%-10s������:%-10s",store1[j].book_name,store1[j].book_number,store1[j].book_author,store1[j].book_publisher);
	 			printf("\n�۸�:%-5.2fͼ�����:%-10s�ܿ�����:%-5d",store1[j].book_money,store1[j].book_variety,store1[j].book_reserves);
	 			printf("\n");
	 			m++;
	 		}
	 	}
	 	if(m==0)
	 	printf("�Բ���,û�д����Ƶ�ͼ��!!\n\n");
	 	printf("�Ƿ����ѯ��?<0(��)/1(��)>:");
		scanf("%d",&flag);
	}
	printf("\n\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|                 ͼ���ѯͳ��               |\n");
	printf("\t\t|                ��ͼ�����ѯ��              |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|****************ͼ����Ϣ�б�!!!*************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|                -1---�˳�ϵͳ               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	k=r1_fp(file,store1);
	while(flag)
	{
		m=0;
		printf("����ͼ�����:");
		scanf("%s",ch);
		for(j=0;j<k;j++)
		{
			if(strcmp(ch,store1[j].book_variety)==0)
	 		{
	 			printf("ͼ�����:%-10sͼ����:%-10s����:%-10s������:%-10s",store1[j].book_variety,store1[j].book_number,store1[j].book_author,store1[j].book_publisher);
	 			printf("\n�۸�:%-5.2f����:%-10s�ܿ�����:%-5d",store1[j].book_money,store1[j].book_name,store1[j].book_reserves);
	 			printf("\n");
	 			m++;
	 		}
	 	}
	 	if(m==0)
	 	printf("�Բ���,û�д�����ͼ��!!\n\n");
	 	printf("�Ƿ����ѯ��?<0(��)/1(��)>:");
		scanf("%d",&flag);
	}
	printf("\n\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
    printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|                  ��Ա����                  |\n");
	printf("\t\t|                  ��Ա��Ϣ                  |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************��Ա��Ϣ�б�!!!**************|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               0---������һ��               |\n");
	printf("\t\t|               -1---�˳�ϵͳ                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n\n\n");
	k=r5_fp(file,store5);
	for(j=0;j<k;j++)
	{
	 	printf("��Ա��:%-10s��Ա����:%-10s��Ա�Ա�:%-10s��Ա�ȼ�:%-10s",store5[j].vip_number,store5[j].vip_name,store5[j].vip_sex,store5[j].vip_level);
	 	printf("\n");
	}
	printf("\n\t\t�������%d����Ա��Ϣ",k);
	printf("\n\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|                   ϵͳ����                 |\n");
	printf("\t\t|               �����Ϊ������Ա             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************����������Ա��Ϣ!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|                -1---�˳�ϵͳ               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	printf("\t�Ƿ�����������Ա��Ϣ<0(��)/1(��)>:");
	scanf("%d",&j);
	while(j<0||j>1)
    {
    	printf("����������(��ѡ��˵����<0-1>");
    	scanf("%d",&j);
    }
    if(j==1)
    {	
    	d=r2_fp(file,store2);
		while(flag)
	    {
	    	printf("\t����µ�������Ա��Ϣ:\n");
	        printf("������Ա���:");
	        scanf("%s",store2[sale_count].sale_number);
	        printf("������Ա����:");
	        scanf("%s",store2[sale_count].sale_name);
			printf("�Ա�:");
			scanf("%s",store2[sale_count].sale_sex);
			printf("��¼����:");
			scanf("%s",store2[sale_count].sale_passwords);
			printf("\n");
			sale_count++;
			printf("���ѳɹ�����µ�������Ա��Ϣ,�Ƿ�������?<0(��)/1(��)>:");
			scanf("%d",&flag);
	    }
	    if(d==0)
		w2_fp(file,store2,sale_count,0);
		else
		w2_fp(file,store2,sale_count,1);
		k=r2_fp(file,store2);
		printf("�������%d��������Ա��Ϣ",k);
		printf("\n");
	}	
	printf("\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|                   ϵͳ����                 |\n");
	printf("\t\t|               �����Ϊ������Ա             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************����������Ա��Ϣ!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|                -1---�˳�ϵͳ               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	printf("\t�Ƿ����������Ա��Ϣ<0(��)/1(��)>:");
	scanf("%d",&j);
	while(j<0||j>1)
    {
    	printf("����������(��ѡ��˵����<0-1>");
    	scanf("%d",&j);
    }
    if(j==1)
    {
    	d=r3_fp(file,store3);
		while(flag)
	    {
	    	printf("\t����µĹ�����Ա��Ϣ:\n");
	        printf("������Ա���:");
	        scanf("%s",store3[manage_count].administrator_number);
	        printf("������Ա����:");
	        scanf("%s",store3[manage_count].administrator_name);
			printf("�Ա�:");
			scanf("%s",store3[manage_count].administrator_sex);
			printf("��¼����:");
			scanf("%s",store3[manage_count].administrator_passwords);
			printf("\n");
			manage_count++;
			printf("���ѳɹ�����µĹ�����Ա��Ϣ,�Ƿ�������?<0(��)/1(��)>:");
			scanf("%d",&flag);
	    }
	    if(d==0)
		w3_fp(file,store3,manage_count,0);
		else
		w3_fp(file,store3,manage_count,1);
		k=r3_fp(file,store3);
		printf("�������%d��������Ա��Ϣ",k);
		printf("\n");
	}	
	printf("\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|                   ϵͳ����                 |\n");
	printf("\t\t|               ����������Ա����             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************����������Ա����!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|                -1---�˳�ϵͳ               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	printf("\t�Ƿ����������Ա����<0(��)/1(��)>:");
	scanf("%d",&j);
	while(j<0||j>1)
    {
    	printf("����������(��ѡ��˵����<0-1>");
    	scanf("%d",&j);
    }
    if(j==1)
    {
		while(flag)
	    {	
	    	k=r2_fp(file,store2);	
	    	printf("\t������Ҫ���ĵ�������Ա���:");
	        scanf("%s",ch);
	        for(m=0,i=0;i<k;i++)
	        {	
	        	if(strcmp(store2[i].sale_number,ch)==0)
	            {
	            	printf("������Ա���:%-10s������Ա����:%-10s�Ա�:%-10s��¼����:%-10s",store2[i].sale_number,store2[i].sale_name,store2[i].sale_sex,store2[i].sale_passwords);
	                printf("\n");
	                printf("\n�µĵ�¼����:");
			 		scanf("%s",store2[i].sale_passwords);
			 		w2_fp(file,store2,k,0);
	                m=1;
	                break;
	             }
	         } 
	         if(m==0)
	         {
	         	printf("��û�д�������Ա��Ϣ!!\n");
	         }
			 printf("\n\t\t\t�Ƿ��������?<0(��)/1(��)>:");
			 scanf("%d",&flag);
	    }
	}	
	printf("\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|                   ϵͳ����                 |\n");
	printf("\t\t|               ���Ĺ�����Ա����             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************���Ĺ�����Ա����!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|                0---������һ��              |\n");
	printf("\t\t|                -1---�˳�ϵͳ               |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n");
	printf("\t�Ƿ���Ĺ�����Ա����<0(��)/1(��)>:");
	scanf("%d",&j);
	while(j<0||j>1)
    {
    	printf("����������(��ѡ��˵����<0-1>");
    	scanf("%d",&j);
    }
    if(j==1)
    {
		while(flag)
	    {	
	    	k=r3_fp(file,store3);	
	    	printf("\t������Ҫ���ĵĹ�����Ա���:");
	        scanf("%s",ch);
	        for(m=0,i=0;i<k;i++)
	        {	
	        	if(strcmp(store3[i].administrator_number,ch)==0)
	            {
	            	printf("������Ա���:%-10s������Ա����:%-10s",store3[i].administrator_number,store3[i].administrator_name);
	                printf("�Ա�:%-10s��¼����:%-10s",store3[i].administrator_sex,store3[i].administrator_passwords);
	                printf("\n");
	                printf("\n�µĵ�¼����:");
			 		scanf("%s",store3[i].administrator_passwords);
			 		w3_fp(file,store3,k,0);
	                m=1;
	                break;
	             }
	         } 
	         if(m==0)
	         {
	         	printf("��û�д˹�����Ա��Ϣ!!\n");
	         }
			 printf("\n\t\t\t�Ƿ��������?<0(��)/1(��)>:");
			 scanf("%d",&flag);
	    }
	}	
	printf("\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
    printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|                   ϵͳ����                 |\n");
	printf("\t\t|               ������Ա��Ϣ�б�             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************������Ա��Ϣ�б�!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               0---������һ��               |\n");
	printf("\t\t|               -1---�˳�ϵͳ                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n\n\n");
	k=r2_fp(file,store2);
	for(j=0;j<k;j++)
	{
	 	printf("������Ա���:%-10s������Ա����:%-10s�Ա�:%-10s��¼����:%-10s",store2[j].sale_number,store2[j].sale_name,store2[j].sale_sex,store2[j].sale_passwords);
	 	printf("\n");
	}
	printf("\n\t\t�������%d��������Ա��Ϣ",k);
	printf("\n\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
    printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|                   ϵͳ����                 |\n");
	printf("\t\t|               ������Ա��Ϣ�б�             |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|***************������Ա��Ϣ�б�!!!**********|\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|               0---������һ��               |\n");
	printf("\t\t|               -1---�˳�ϵͳ                |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\n\n\n");
	k=r3_fp(file,store3);
	for(j=0;j<k;j++)
	{
	 	printf("������Ա���:%-10s������Ա����:%-10s�Ա�:%-10s��¼����:%-10s",store3[j].administrator_number,store3[j].administrator_name,store3[j].administrator_sex,store3[j].administrator_passwords);
	 	printf("\n");
	}
	printf("\n\t\t�������%d��������Ա��Ϣ",k);
	printf("\n\t\t\t��ѡ��˵����<-1-0>:");
    scanf("%d",&i);
    while(i<-1||i>0)
    {
    	printf("����������(��ѡ��˵����<-1-0>");
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
	    printf("\t\t|          ������۹���ϵͳ(������Ա)        |\n");
	    printf("\t\t|                  ���۹���                  |\n");
	    printf("\t\t|--------------------------------------------|\n");
	    printf("\t\t|               1---�˿͹���                 |\n");
        printf("\t\t|               0---������һ��               |\n");
        printf("\t\t|--------------------------------------------|\n");
        printf("\t\t\t��ѡ��˵����<0-1>:");
        scanf("%d",&i);
        while(i<0||i>1)
        {
        	printf("����������(��ѡ��˵����<0-1>:");
    	    scanf("%d",&i);
        }
        switch(i)
        {
        	case 1:customers();break;/*customers�˿͹���*/
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
		printf("\t\t|          ������۹���ϵͳ(������Ա)        |\n");
		printf("\t\t|                   ��Ա����                 |\n");
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|                 1---��Ա����               |\n");
   		printf("\t\t|                 0---������һ��             |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t��ѡ��˵����<0-1>:");
    	scanf("%d",&i);
   	 	{
   	 		while(i<0||i>1)
    		{
    			printf("����������(��ѡ��˵����<0-1>:");
    			scanf("%d",&i);
    		}
    		switch(i)
    		{
    			case 1:vip_application();break;/*vip_application��Ա����*/
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
		printf("\t\t|          ������۹���ϵͳ(������Ա)        |\n");
		printf("\t\t|               ����ͳ�ƹ���                 |\n");
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|               1---����ͳ��                 |\n");
    	printf("\t\t|               2---����ͳ��                 |\n");
    	printf("\t\t|               3---������ͳ��               |\n");
   		printf("\t\t|               0---������һ��               |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t��ѡ��˵����<0-3>:");
    	scanf("%d",&i);
    	while(i<0||i>3)
    	{
    		printf("����������(��ѡ��˵����<0-3>:");
    		scanf("%d",&i);
    	}
    	switch(i)
    	{	
    		case 1:day();break;/*day����ͳ��*/
	 		case 2:month();break;/*month����ͳ��*/
	 		case 3:season();break;/*season������ͳ��*/
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
		printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
		printf("\t\t|                ͼ��������                |\n");
	    printf("\t\t|--------------------------------------------|\n");
	    printf("\t\t|               1---ͼ�������Ϣ             |\n");
   		printf("\t\t|               0---������һ��               |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t��ѡ��˵����<0-1>:");
    	scanf("%d",&i);
   	 	{
   	 		while(i<0||i>1)
    		{
    			printf("����������(��ѡ��˵����<0-1>:");
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
		printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
		printf("\t\t|                 ͼ��ѯ��ͳ��               |\n");
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|               1---��������ѯ��             |\n");
    	printf("\t\t|               2---������ѯ��               |\n");
    	printf("\t\t|               3---������ѯ��               |\n");
    	printf("\t\t|               4---��ͼ�����ѯ��           |\n");
    	printf("\t\t|               0---������һ��               |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t��ѡ��˵����<0-4>:");
    	scanf("%d",&i);
    	while(i<0||i>4)
    	{
    		printf("����������(��ѡ��˵����<0-4>:");
    		scanf("%d",&i);
    	}
    	switch(i)
    	{
    		case 1:publisher();break;/*publisher������ѯ��*/
	 		case 2:author();break;/*author����ѯ��*/
			case 3:book();break;/*����ѯ��*/
	 		case 4:books_categories();break;/*ͼ�����ѯ��*/
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
		printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
		printf("\t\t|                   ��Ա����                 |\n");
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|                1---��Ա��Ϣ�б�            |\n");
   		printf("\t\t|                0---������һ��              |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t��ѡ��˵����<0-1>:");
    	scanf("%d",&i);
   	 	{
   	 		while(i<0||i>1)
    		{
    			printf("����������(��ѡ��˵����<0-1>:");
    			scanf("%d",&i);
    		}
    		switch(i)
    		{
    			case 1:vip_message();break;/*vip_message��Ա��Ϣ�б�*/
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
		printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
		printf("\t\t|                   ϵͳ����                 |\n");
		printf("\t\t|--------------------------------------------|\n");
		printf("\t\t|             1---�����Ϊ������Ա           |\n");
		printf("\t\t|             2---�����Ϊ������Ա           |\n");
		printf("\t\t|             3---����������Ա����           |\n");
		printf("\t\t|             4---���Ĺ�����Ա����           |\n");
		printf("\t\t|             5---������Ա��Ϣ�б�           |\n");
		printf("\t\t|             6---������Ա��Ϣ�б�           |\n");
		printf("\t\t|             0---������һ��                 |\n");
    	printf("\t\t|--------------------------------------------|\n");
    	printf("\t\t\t��ѡ��˵����<0-6>:");
    	scanf("%d",&i);
    	while(i<0||i>6)
    	{
    		printf("����������(��ѡ��˵����<0-6>:");
    		scanf("%d",&i);
    	}
    	switch(i)
    	{
    		case 1:sale_apply();break;/*�����Ϊ������Ա*/
	 		case 2:manage_apply();break;/*�����Ϊ������Ա*/
			case 3:sale_change();break;/*����������Ա��Ϣ*/
			case 4:manage_change();break;/*���Ĺ�����Ա��Ϣ*/
	 		case 5:sale_list();break;/*������Ա��Ϣ�б� */
	 		case 6:manage_list();break;/*������Ա��Ϣ�б� */
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
	printf("\t\t|          ������۹���ϵͳ(������Ա)        |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|              1---���۹���                  |\n");
	printf("\t\t|              2---��Ա����                  |\n");
    printf("\t\t|              3---����ͳ�ƹ���              |\n");
    printf("\t\t|              0---���ص�½����              |\n");
    printf("\t\t|             -1---�˳�ϵͳ                  |\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t\t��ѡ�����˵����<-1-3>:");
    scanf("%d",&i);
    while(i<-1||i>3)
    {
    	printf("����������(��ѡ�����˵����<-1-3>:");
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
	printf("\t\t|           ������۹���ϵͳ(������Ա)       |\n");
	printf("\t\t|--------------------------------------------|\n");
	printf("\t\t|              1---ͼ��������              |\n");
	printf("\t\t|              2---ͼ��ѯ��ͳ��              |\n");
    printf("\t\t|              3---��Ա����                  |\n");
    printf("\t\t|              4---ϵͳ����                  |\n");
    printf("\t\t|              0---���ص�½����              |\n");
    printf("\t\t|             -1---�˳�ϵͳ                  |\n");
    printf("\t\t|--------------------------------------------|\n");
    printf("\t\t\t��ѡ�����˵����<-1-4>:");
    scanf("%d",&i);
    while(i<-1||i>4)
    {
    	printf("����������(��ѡ�����˵����<-1-4>");
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
		printf("\t\t  |          ������۹���ϵͳ(������Ա)        |\n");
		printf("\t\t  |--------------------------------------------|\n");
		k=r2_fp(file,store2);
		if(k==0)
		{	
			printf("\n\t\t��ûע���Ϊ������Ա!!\n");
			printf("\t\t���ҹ�����Աע�����ܵ�¼ϵͳ!!");
			getchar();
			printf("\n\n\n\t\t\t���س����ص�½����!");
		    while((h=getchar())!='\n')
		   	{
		    	printf("\n\n\t\t\t���س���½����!");
			   	getchar();
		   	}
			return k;
			
		}
		printf("\n\n\t\t\t      ������������Ա���:");
	    scanf("%s",pwd1);	
		printf("\n\t\t\t      ����������:");
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
		    	printf("\n\n\n\n\n\t\t\t�ɹ����뵽�������ϵͳ\n");
		   	 	printf("\n\n\n\n\n\t\t\t���س�����!");
		    	while((h=getchar())!='\n')
		   		{
		    		printf("\n\n\t\t\t���س�����!");
			   	 	getchar();
		    	}
		    	break;
			}
		}
		if(a==1)
		break;
		if(a==0)
		{
			printf("\n\n\t\t\t      �û������������!\n");
			if(i==1||i==2)
			{
				printf("\n\n\t\t\t\t\t���س���������!");
				while((h=getchar())!='\n')
		   		{
		    		printf("\n\n\t\t\t\t\t���س���������!");
			    	getchar();
		    	}
			}
		}
	}
	if(i>3)
	{
		printf("\n\t\t���������Ѵ�3��,����Ȩʹ�ø�ϵͳ,���˳�!\n");
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
		printf("\t\t  |          ������۹���ϵͳ(������Ա)        |\n");
		printf("\t\t  |--------------------------------------------|\n");
		k=r3_fp(file,store3);
		if(k==0)
		{	
			printf("\t\t��Ϊ����ûע���Ϊ������Ա!!\n");
			printf("\n\t��ʹ�ó�ʼ������Ա���:abc�ͳ�ʼ����:123ȥ��¼ϵͳ!!(�Ժ󶼿���ʹ��)");
	        strcpy(store3[0].administrator_number,"abc");
	        strcpy(store3[0].administrator_name,"0");
	        strcpy(store3[0].administrator_sex,"0");
	        strcpy(store3[0].administrator_passwords,"123");
	        w3_fp(file,store3,1,0);	
	        k=r3_fp(file,store3);
		}
		printf("\n\n\t\t\t      �����������Ա���:");
	   	scanf("%s",pwd1);	
		printf("\n\t\t\t      ����������:");
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
	    		printf("\n\n\n\n\n\t\t\t�ɹ����뵽�������ϵͳ\n");
	   	 		printf("\n\n\n\n\n\t\t\t���س�����!");
		   		while((h=getchar())!='\n')
	 			{
		   			printf("\n\n\t\t\t���س�����!");
		   	 		getchar();
	    		}
		   		break;
			}
		}
		if(a==1)
		break;
		if(a==0)
		{
			printf("\n\n\t\t\t\t      �û������������!\n");
			if(i==1||i==2)
			{
				printf("\n\n\t\t\t\t\t\t���س���������!");
				while((h=getchar())!='\n')
	  			{
		   			printf("\n\n\t\t\t\t\t\t���س���������!");
		    		getchar();
		   		}
			}
		}
	}
	if(i>3)
	{
		printf("\n\t\t���������Ѵ�3��,����Ȩʹ�ø�ϵͳ,���˳�!\n");
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
		printf("\t\t   |            ������۹���ϵͳ            |\n");
		printf("\t\t   |----------------------------------------|\n");
		printf("\t\t   |                ��½����                |\n");
		printf("\t\t   |                                        |\n");
		printf("\t\t   |----------------------------------------|\n");
		printf("\n\t\t\t       ������Ա��¼--------1");
		printf("\n\n\t\t\t       ������Ա��¼--------2");
		printf("\n\n\t\t\t           �˳�ϵͳ--------0");
		printf("\n\n\n\t\t\t            ��ѡ��:--------");
		scanf("%d",&a);
		while(a<0||a>2)
		{
			printf("\n\n\t\t\t       ��������0-2:--------");
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
						case 1:sm();break;/*sales management���۹���*/
						case 2:vip1();break;/*vip_application��Ա����*/
						case 3:ssm();break;/*Sales statistics management����ͳ�ƹ���*/
						case 0:break;/*���ص�½����*/
			    		case -1:exit(0);/*�˳�ϵͳ*/
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
            			case 1:bwm();break;/*books warehouse managementͼ��������*/
              		  	case 2:bqs();break; /*book query statisticsͼ��ѯ��ͳ��*/
	        	    	case 3:vip2();break;/*vip��Ա����*/
	           		 	case 4:sys();break;/*systemϵͳ����*/
	           		 	case 0:break;
	            		case -1:exit(0);/*�˳�ϵͳ*/
           			}
           			if(num2==0)
           			break;
	    		}
			}
			if(a==0)
			exit(0);
	}
}
