//Assignment No.2 Various Operations on Matrix using pointers..
#include<stdio.h> //standard i/p o/p file 
#include<stdlib.h>//standard file for library functions

int** inputmatrix(int **a, int r,int c)//user defined function to input a matrix using pointers
{
	a=malloc(r*sizeof(int*)); //dyanmic memory allocation using malloc
	int i,j;
	for(i=0;i<r;i++)
	{
		*(a+i)=(int*)malloc(c*sizeof(int)); //dyanmic memory allocation using malloc
		for(j=0;j<c;j++)
		{
			scanf("%d",*(a+i)+j);
		}
	}
return (a);
}

void displaymatrix(int **a, int r,int c) //user defined function to display a matrix using pointers
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",*(*(a+i)+j));
		}
		printf("\n");
	}
}

int** addmatrix(int**X,int **Y,int **a,int r,int c) //user defined function to add matrices using pointers
{
	a=malloc(r*sizeof(int*)); //dyanmic memory allocation using malloc
	int i,j;
	for(i=0;i<r;i++)
	{
		*(a+i)=(int*)malloc(c*sizeof(int));
		for(j=0;j<c;j++)
		{
		*(*(a+i)+j)=*(*(X+i)+j)+*(*(Y+i)+j); //dyanmic memory allocation using malloc
		}
	}
return (a);
}


int** mulmatrix(int** X,int**Y,int**a,int r1,int c2,int c1) //user defined function to multiply matrices using pointers
{
	a=malloc(r1*sizeof(int*)); //dyanmic memory allocation using malloc
	int i,j,k;
	for(i=0;i<r1;i++)
	{
		*(a+i)=(int*)malloc(c2*sizeof(int));  //dyanmic memory allocation using malloc
		for(j=0;j<c2;j++)
		{
			*(*(a+i)+j)=0;
			for(k=0;k<c1;k++)
			{
				*(*(a+i)+j)=*(*(a+i)+j)+(*(*(X+i)+j)* *(*(Y+k)+j));
			}
		}
	}
return (a);
}


int** transmatrix(int **X,int **a,int r,int c) //function to take tranpose of a matrix using pointers
{ 
	a=malloc(c*sizeof(int*));  //dyanmic memory allocation using malloc
	int i,j; 
	for(i=0;i<c;i++) 
	{ 
		*(a+i)=(int*)malloc(r*sizeof(int));  //dyanmic memory allocation using malloc

		for(j=0;j<r;j++) 
		{ 
			*(*(a+i)+j)=*(*(X+j)+i); 
		} 
	} 
	return(a);
} 

void saddlematrix(int **a,int r,int c)  //user defined function to find saddle point using pointers
{ 
	int i,j,k,min,max,col=0,count=0,row=0; 
	for(i=0;i<r;i++) 
	{ 
		min=*(*(a+i)+0); 
		for (j=0;j<c;j++)
		{ 
			if(*(*(a+i)+0)<min) 
			{ 
				min=*(*(a+i)+j); 
				col=j; 
			} 
		} 
		max=*(*(a+0)+col);
		for(k=0;k<r;k++) 
		{ 
			if(*(*(a+k)+col)>max) 
			{ 
				max=*(*(a+k)+col);
				row=k;
			} 
		} 
		if(max==min) 
		{ 
			printf("\nSaddle point is:%d",max); 
			printf(" at location %d %d""\n",row,col); 
			count=count+1; 
		} 
	} 
	if(count==0) 
		{ 
			printf("\nThere is no saddle point"); 
		} 
} 


void main() //call to main function
{
	int **a,**X, **Y,**Z; //variable decalartion
	int r1,c1,r2,c2,ch;
	printf("\nEnter size of matrix 1:");
	scanf("%d %d",&r1,&c1);
	printf("\nEnter %d elements of set 1:",r1*c1);
	X=inputmatrix(X,r1,c1);
	printf("\nEnter size of matrix 2:");
	scanf("%d %d",&r2,&c2);
	printf("\nEnter %d elements of set 2:",r2*c2);
	Y=inputmatrix(Y,r2,c2);
	printf("\nMatrix1 is:\n");
	displaymatrix(X,r1,c1);
	printf("\nMatrix2 is:\n");
	displaymatrix(Y,r2,c2);
	
	while(1) //use of while loop to repeat menu
	{
		printf("\n*************MENU**********");
		printf("\n1.Addition\n2.Multiplication\n3.Transpose\n4.Saddle point\n5.Exit");//Menu for operation
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch) //use of switch case to display menu
		{
			case 1: 
						if(r1==r2 && c1==c2)
						{
							printf("\nAddition of two matrix is :");
							printf("\n");
							a=addmatrix(X,Y,a,r1,c1);
							displaymatrix(a,r2,c2);	
						}
						else
						{
							printf("\nSorry!!!Addition is not possible");
						}
						break;
			case 2:
					if(c1==r2)
					{
						printf("\nMultiplication  of two matrix is:");
						printf("\n");
						a=mulmatrix(X,Y,a,r1,c2,c1);
						displaymatrix(a,r1,c2);	
					}
					else
					{
						printf("\nSorry!!!Multiplication is not possible");
					}
			 		break;
			case 3: 
					printf("\nTranspose of matrix1:\n");
					Z=transmatrix(X,a,r1,c1);
					displaymatrix(Z,c1,r1);
					printf("\nTranspose of matrix2:\n");
					Z=transmatrix(Y,a,r2,c2);
					displaymatrix(Z,c2,r2);
			 		break;
			case 4:
					printf("\nFor matrix1 is:\n");
					saddlematrix(X,r1,c1);
					printf("\nFor matrix2 is:\n");
					saddlematrix(Y,r2,c2);
					break;
		    case 5:
		    		exit (0);
		    		break;
			default:break;				
		}//end of switch case
	}//end of while loop
}//end of main function
	
	



