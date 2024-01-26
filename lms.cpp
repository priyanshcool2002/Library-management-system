#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <direct.h>

using namespace std;

FILE *ptr;
void title() 
{
	printf("\n\n\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARY MANAGEMENT SYSTEM  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
}
void delay(int x)
{
	int i, k;
	for (i = 0; i < x; i++)
		k = i;
}
void date() //display current date 
{
	int d, m, y;
	char day[3], month[4], year[3];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	d = tm.tm_mday;
	itoa(d, day, 10);
	printf("%02s /", day);

	m = tm.tm_mon + 1;
	itoa(m, month, 10);
	printf(" %02s /", month);

	y = tm.tm_year + 1900;
	itoa(y, year, 10);
	printf(" %s", year);
}
void AB()
{
    _mkdir("LMS");
    _mkdir("LMS\\B_list");
    char nb[5],c[] = "   ";
    char n[]="\n";
    char b_name[30];
    char slrN[10];
    cout<<"ADD NEW BOOKS\n";
    cout<<"Enter Book Name: ";
    cin>>b_name;
    cout<<"Enter Serial Number: ";
    cin>>slrN;
    cout<<"Number of Books: ";
    cin>>nb;
    ptr = fopen(b_name,"w");
    fprintf(ptr,nb);
    fclose(ptr);
    strcat(slrN,c);
    strcat(slrN,b_name);
    strcat(slrN,c);
    strcat(slrN,n);
    ptr = fopen("LMS\\B_list\\b.txt", "a+");
    fprintf(ptr,slrN);
    fclose(ptr);
    cout<<"Successfuly added";
    delay(1000000000);
}
void BI()
{
    _mkdir("LMS");
    _mkdir("LMS\\B_list");
    char p[5], S_N[20];
    int i;
    char ch[100]=" ";
    char date[10];
    char b_name[30],gap[]="\t\t\t",n[]="\n";
    cout<<"Enter Student Name: ";
    cin>>S_N;
    cout<<"Enter Book Name: ";
    cin>>b_name;
    ptr = fopen(b_name,"r");
    fscanf(ptr,"%s",p);
    i = atoi(p);
    fclose(ptr);
    if(i>0)
    {
        cout<<"Date of Issue : ";
        cin>>date;
        ptr = fopen(S_N,"a+");
        strcat(ch,"Student Name: ");
        strcat(ch,S_N);
        strcat(ch,n);
        strcat(ch,"Book Name: ");
        strcat(ch,b_name);
        strcat(ch,n);
        strcat(ch,"Date of issue: ");
        strcat(ch,date);
        strcat(ch,n);
        fprintf(ptr,ch);
        fclose(ptr);
        ptr = fopen(b_name,"w");
        string a = to_string(i-1);
        for(int j = 0;a[j]!='\0';j++)
        p[j]=a[j];
        cout<<p;
        fprintf(ptr,p);
        fclose(ptr);
    }
    else
    cout<<"Sorry This book is not available in the library";

    delay(1000000000);
}
void BR()
{
    char S_N[20];
    char date[10];
    char ch[100]=" ";
    char b_name[30],gap[]="\t\t\t",n[]="\n";
    fflush(stdin);
    cout<<"Enter Student Name: ";
    cin>>S_N;
    fflush(stdin);
    cout<<"Enter Book Name: ";
    cin>>b_name;
    cout<<"Date of return : ";
    cin>>date;
    ptr = fopen(S_N,"a+");
    strcat(ch,"Book Name: ");
        strcat(ch,b_name);
        strcat(ch,n);
        strcat(ch,"Date of return: ");
        strcat(ch,date);
        strcat(ch,n);
        fprintf(ptr,ch);
    fclose(ptr);
    int i;
    char p[5];
    ptr = fopen(b_name,"r");
    fscanf(ptr,"%s",p);
    i = atoi(p);
    fclose(ptr);
    ptr = fopen(b_name,"w");
    string a = to_string(i+1);
    for(int j = 0;a[j]!='\0';j++)
        p[j]=a[j];
    fprintf(ptr,p);
    fclose(ptr);
}
int main()
{
    
	int a=0;
    while(a!=9)
	{
		system("cls");
        system("color f5");
        title();
        cout<<"Date: ";
        date();
        cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\tChoose following option \n";
        cout<<"\n\t\t\t\t1. Add Book\n";
        cout<<"\n\t\t\t\t2. Book Issue\n";
        cout<<"\n\t\t\t\t3. Book Return\n";
        cout<<"\n\t\t\t\t9. Exit \n";
    
	    fflush(stdin);
        cout<<"\n\t\t\tYour Option : ";
        cin>>a;
        switch(a)
        {
            case 1: AB();break;//Add book (AB)
            case 2: BI();break;// Book Issue (BI)
            case 3: BR();break;// Book Return (BR)
            case 9:exit(1);break;
	    	default : cout<<"You entered wrong input.\nGive correct option.\n";
        }
	}
}