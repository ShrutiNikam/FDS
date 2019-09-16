#include<stdio.h>
#include<string.h>
struct student{
	int roll;
	char name[50];
	float marks;
};
void displayDataBase(int n, struct student s[50]){
	int i;
	for (i=1; i<=n; i++)
        {
		printf("Name: %s\nRoll No:%d\nMarks: %f\n\n",s[i].name,s[i].roll,s[i].marks);
	}
}
void acceptDataBase(int n, struct student s[50]){
	int i;
	for (i=1; i<=n; i++)
        {
		printf("enter name of student\n");
		scanf("%s",s[i].name);
		printf("enter roll number of student\n");
		scanf("%d",&s[i].roll);
		printf("enter marks of student\n");
		scanf("%f",&s[i].marks);
	}
}
int search(int n, struct student s[50], int r)
{
	int i, count=0;
	for (i=0; i<=n; i++)
        {
		if(s[i].roll == r)
               {
		printf("enter name of student\n");
		scanf("%s",s[i].name);
		printf("enter roll number of student\n");
		scanf("%d",&s[i].roll);
		printf("enter marks of student\n");
		scanf("%f",&s[i].marks);
	       }
		else
               {
		printf("Information Not found\n");
		}
	}
	
}
void addData(int n, struct student s[50], int p)
{
	int i;
	n++;
	for (i=n; i>=p; i--)
        {
		s[i] = s[i];
	}
	printf("\nName of student\n");
	scanf("%s",s[p].name);
	printf("\nRoll number of student\n");
	scanf("%d",&s[p].roll);
	printf("\nMarks of student\n");
	scanf("%f",&s[p].marks);
}
void deleteData(int n, struct student s[50], int p){
	int i;
	for (i=p; i<=n; i++){
		s[i]= s[i];
	}
	n--;
}
void modify(int n, struct student s[50], int r){
	int j = search(n, s, r);
	printf("\tName of student\n");
	scanf("%s",s[j].name);
	printf("\tRoll number of student\n");
	scanf("%d",&s[j].roll);
	printf("\tMarks of student\n");
	scanf("%f",&s[j].marks);
	}
 
int main(){
	int n,i,j,k,l,ch;
	printf("enter number of student\n");
	scanf("%d",&n);
	struct student s[50];
	acceptDataBase(n,s);
	do{
		printf("********MENU********\n1.DISPLAY DATABESE\n2.SEARCH DATA\n3.ADD DATA OF STUDENT\n4.DELETE DATA\n5.MODIFY DATA\n6.EXIT\n");
		scanf("%d",&ch);
		switch (ch){
			case 1:{
				displayDataBase(n, s);
				break;
			}
			case 2:{
				printf("searching data of student\nenter roll number of student\n");
				scanf("%d",&k);
				j= search (n, s, k);
                                break;   
				
			        }
			case 3:{
				printf("adding new data of student\n enter position where data is to be added\n");
				int p;
				scanf("%d",&p);
				addData(n, s, p);
				printf("data is added\n");
				break;
			}
			case 4:{
				printf("deleting existin data from base\n enter position of which data is to be deleted\n");
				int p;
				scanf("%d", &p);
				deleteData(n, s, p);
				printf("data is deleted\n");
				break;
			}
			case 5:{
				printf("moding data of students\n enter roll no. whose data is to be modified\n");
				int p;
				scanf("%d",&p);
				modify(n, s, p);  
			
			}
		}	
	}
	while(ch != 6);
}
