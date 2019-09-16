//Assignment 6 to to open a  file and perform various operations on it.

#include<stdio.h>//standard i/p o/p file
struct student //using user defined data type structure to enter a record consisting of roll no and name
{
	int rollno;
	char name[20]; 
};
	
void create(char fname[20]) //user defined function to create a file and input records in it
{
	struct student s;
	int i,n;
	FILE *fp;
	fp=fopen(fname,"a+");
	printf("\nEnter how many no of records you want to input?");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter rollno and name:");
		scanf("%d %s",&s.rollno,s.name);
		fwrite(&s,sizeof(s),1,fp);
	}
	fclose(fp);
}

void display(char fname[20]) //user defined function to display records
{
	struct student s;
	FILE *fp;
	fp=fopen(fname,"r");
	if(fp==NULL)
	{
	printf("Error");
	}
	else
	{
		while(fread(&s,sizeof(s),1,fp)!=0)
		{
			printf("\n%d \t%s",s.rollno,s.name);
			printf("\n");
		}
	}
	fclose(fp);
}

void insert(char fname[20], struct student s) //function to insert a record at end of file
{	
	FILE*fp;
	fp=fopen(fname,"r+");
	if(fp==NULL)
	{
		fp=fopen(fname,"w");
	}
	else
	{
		fseek(fp,0,2);
		fwrite(&s,sizeof(s),1,fp);
		fclose(fp);
	}
}

int search(char fname[20],struct student s,int rollno) //function to search a record
{
	FILE *fp;
	int count=0;
	fp=fopen(fname,"r")	;
	while(fread(&s,sizeof(s),1,fp)!=0)
	{
		if(rollno==s.rollno)
		{	
			return count;
		}
		else
		{
			count++;
		}
	}
	return(-1);
	fclose(fp);
}

void modify(char fname[20],struct student s,int rollno)  //function to modify a particular record
{
	int k;
	FILE*fp;
	fp=fopen(fname,"r+");
	while(fread(&s,sizeof(s),1,fp)!=0)
	{
		if(s.rollno==rollno)
		{
			fseek(fp,-sizeof(s),1);
			printf("Enter modified data:\n");
			printf("Enter roll no. and name:");
			scanf("%d %s",&s.rollno,s.name);
			fwrite(&s,sizeof(s),1,fp);
		}
	}
	fclose(fp);
}

void delete(char fname[20],struct student s,int rollno) //function to delete a record
{
	int k;
	FILE*fp;
	FILE*fp1;
	fp=fopen(fname,"r");
	fp1=fopen("temp","w");
	while(fread(&s,sizeof(s),1,fp)!=0)
	{
		if(rollno!=s.rollno)
		{
			fwrite(&s,sizeof(s),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	remove(fname);
	rename("temp",fname);
}



void main()  // call to main function
{
	int i,j,k,l; // variable declaration
	FILE *fp; //declaring a file pointer 
	int choice;
	int rollno;
	char fname[20];
	struct student s;
	printf("\nEnter name of file:");
	scanf("%s",fname);
	create(fname);
	
	do //use of do while loop to repeat menu
	{
		printf("\n");
		printf("\n..................MENU.................");
		printf("\n1.Display\n2.Insert\n3.Search\n4.Modify\n5.Delete\n6.Exit");
		printf("\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);                                                                                                                                                                                                                            
		
		switch(choice) //switch case to display menu
		{
			case 1:		printf("\nRollno\tName"); //to display record
						display(fname);
						break;
			case 2: 	printf("\nEnter Roll No:"); // to insert a record
						scanf("%d",&rollno);
						k=search(fname,s,rollno);
						if(k!=-1)    // to avoid duplication
						{
							printf("\nSorry roll no already exist.");
						}
						else
						{
							printf("\nEnter Name:");
							scanf("%s",s.name);
							s.rollno=rollno;
							insert(fname,s);
							printf("Record inserted successfully.");
						}
						break;
			case 3:		printf("\nEnter the roll no to be searched:"); // to search a record
						scanf("%d",&rollno);
						j=search(fname,s,rollno);
						if(j!=-1)
						{
							printf("Record found at position %d",j);
						}
						else
						{
							printf("Sorry!!!No  such record found.");
						}
						break;
			case 4:		printf("\nEnter the roll no to be modified:");  //to modify a record
						scanf("%d",&rollno);
						k=search(fname,s,rollno);
						if (k!=-1)
						{
							modify(fname,s,rollno);
						}
						else
						{
							printf("\nSorry!!!No  such record  found.");
						}				
						break;
			case 5:		printf("\nEnter the roll no to be deleted:"); //to delete a record
						scanf("%d",&rollno);
						l=search(fname,s,rollno);
						if (l!=-1)
						{
							delete(fname,s,rollno);
							printf("Record deleted successfully.");
						}
						else
						{
							printf("Sorry!!!No  such record found.");
						}				
						break;
			case 6:break;
			default:printf("\nWrong choice.");
			break;
		} //end of switch case
	}while(choice<6); //end ofdo while loop
	printf("\n");
} //end of main function
