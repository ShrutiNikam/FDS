//assignment 1 perform operations on sets usin 1-D array.

#include<stdio.h>          //standard i/o header file 
#include<stdlib.h>


void main()               //call to main function
{                         //beginning of main function
	int m,n,A[20],B[20],ch,re[40],resize,Z1[40],Z2[40],diff1,diff2,sym[20],symsize;//variable declaration
	
	printf("\nEnter size of set1:");//no.of elements in set1
	scanf("%d",&m);
	printf("\nEnter %d elements of set1 are:",m);
	input_array(A,m);
	
	printf("\nEnter size of set2:");//no.of elements in set2
	scanf("%d",&n);
	printf("\nEnter %d elements of set2 are:",n);
	input_array(B,n);
while(1)	
{
	printf("\n.......Menu......\n1.Intersection\n2.Difference\n3.Union\n4.Symmetric Difference\n5.Exit");//Menu for options.
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1:printf("Intersection of both sets are:");          //for intersection
		       intersec(A,m,B,n);
		       break;
		case 2:printf("\nDiffrence (A-B) is:");                  //for difference
		       diff1=difference(A,m,B,n,Z1);
		       display(Z1,diff1);
		       printf("\nDiffrence (B-A) is:");
		       diff2=difference(B,n,A,m,Z2);
		       display(Z2,diff2);
               break;
        case 3:printf("\nUnion of two sets are:");           //for union
               resize=iunion(A,m,B,n,re);
               display(re,resize);
               break;
		case 4:printf("\nSymmetric Difference is:");       //for symmetric difference
		       symsize=iunion(Z1,diff1,Z2,diff2,sym);
		       display(sym,symsize);
			   break;
		case 5:
		       exit (0);	   
		default:break;
		
	}
}                      // end of while statement
}                      //end of main function
void input_array(int X[20],int s)//for accepting no.
{
	int i,j;
	for(i=0;i<s;i++)
	{
		scanf("%d",&X[i]);
		for(j=0;j<i;j++)
		{
			if(X[j]==X[i])
			{
				printf("\nNo,duplicate please.");
				i--;
			}
		}		
	}
}

void intersec(int X[20],int p,int Y[20],int s)//for same element in two sets
{
	int i,j;
	for(i=0;i<p;i++)
	{
		for(j=0;j<s;j++)
		{
			if(X[i]==Y[j])
			printf("\n%d",X[i]);
		}
		
	}
}
int difference(int X[20],int p,int Y[20],int s,int Z[40])//without same element in each set
{
	int i,j,k=0;
	for(i=0;i<p;i++)
	{
		for(j=0;j<s;j++)
		{
			if(X[i]==Y[j])
			break;
		}
		if(j==s)
		{
		Z[k]=X[i];
		k++;
		}
    }
    return(k);
}
void display(int X[20],int p)//to display  elements
{
	int i;
	for(i=0;i<p;i++)
	{
		printf("\n%d",X[i]);
	}
}
int iunion(int X[20],int p,int Y[20],int s,int re[40])//for union
{
	int i,j,k;
	for(i=0;i<p;i++)
	{
		re[i]=X[i];
	}
	
	for(j=0;j<s;j++)//for set 2 
	{
		for(k=0;k<p;k++)//for set 1 compare
		{
			if(Y[j]==X[k])
			{
				break;
			}
		}
		if(k==p)
		{
			re[i]=Y[j];
			i++;
		}
	}
	return(i);
			
}

