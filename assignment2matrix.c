//Assignment 2 to perform various operations on matrix 
#include<stdio.h> //standard i/p o/p file 
#include<stdlib.h> 
void inputmatrix(int matrix[20][20],int r,int c)          //user defined function to input a matrices 
{ 
	int i,j; 
	for(i=0;i<r;i++) 
	{ 
		for(j=0;j<c;j++) 
		{ 
			scanf("%d",&matrix[i][j]); 
		} 
	} 
} 

void displaymatrix(int matrix[20][20],int r,int c)      //user defined function to print two matrices 
{ 
	int i,j; 
	for(i=0;i<r;i++) 
	{ 
		for(j=0;j<c;j++) 
		{ 
			printf("%d\t",matrix[i][j]); 
		} 
	printf("\n");	 
	} 
} 

int addmatrix(int matrix1[20][20],int matrix2[20][20],int matrix3[20][20],int r1,int c1)//function to  add  2 matrices 
{ 
	int i,j; 
	for(i=0;i<r1;i++) 
	{ 
		for(j=0;j<c1;j++) 
		{ 
		matrix3[i][j]=matrix1[i][j]+matrix2[i][j]; 
		} 
	} 
} 

void mulmatrix(int matrix1[20][20],int matrix2[20][20],int matrix3[20][20],int r1,int c2,int c1)//function to 2 multiply matrix 
{ 
	int i,j,k; 
	for(i=0;i<r1;i++) 
	{ 
		for(j=0;j<c2;j++) 
		{ 
			matrix3[i][j]=0; 
			for(k=0;k<c1;k++) 
			{ 
				matrix3[i][j]=matrix3[i][j]+(matrix1[i][j]*matrix2[k][j]); 
			} 
		} 
	} 
} 

void transmatrix(int matrix[20][20],int matrix3[20][20],int r,int c) //function to take tranpose of a matrix 
{ 
	int i,j; 
	for(i=0;i<r;i++) 
	{ 
		for(j=0;j<c;j++) 
		{ 
			matrix3[j][i]=matrix[i][j]; 
		} 
	} 
} 

void saddlematrix(int matrix[20][20],int r,int c)  //user defined function to find saddle point 
{ 
	int i,j,k,min,max,col=0,count=0; 
	for(i=0;i<r;i++) 
	{ 
		min=matrix[i][0]; 
		for (j=0;j<c;j++) 
		{ 
			if(matrix[i][0]<min) 
			{ 
				min=matrix[i][j]; 
				col=j; 
			} 
		} 
		max=matrix[0][col]; 
		for(k=0;k<r;k++) 
		{ 
			if(matrix[k][col]>max) 
			{ 
				max=matrix[k][col]; 
			} 
		} 
		if(max==min) 
		{ 
			printf("\nSaddle point is:%d",max); 
			printf(" at location %d %d""\n",k,col); 
			count=count+1; 
		} 
	} 
	if(count==0) 
		{ 
			printf("\nThere is no saddle point"); 
		} 
} 






void main()                       //call to main function 
{ 
	int matrix1[20][20],matrix2[20][20],matrix3[20][20],r1,c1,r2,c2,ch; //variable declaration 
	printf("\nEnter size of matrix 1:"); 
	scanf("%d %d",&r1,&c1); 
	printf("\nEnter %d elements of matrix1:",r1*c1); 
	inputmatrix(matrix1,r1,c1); 
	printf("\nEnter size of matrix 2:"); 
	scanf("%d %d",&r2,&c2); 
	printf("\nEnter %d elements of matrix 2:",r2*c2); 
	inputmatrix(matrix2,r2,c2); 
	printf("\nMatrix1 is:\n"); 
	displaymatrix(matrix1,r1,c1); 
	printf("\nMatrix2 is:\n"); 
	displaymatrix(matrix2,r2,c2); 
	 
	 
	while(1)                                     //while loop to repeat menu 
	{	 
		printf("\n"); 
		printf("\n*************MENU**********"); 
		printf("\n1.Addition\n2.Multiplication\n3.Transpose\n4.Saddle point\n5.Exit\n");//Menu for operation 
		printf("\nEnter your choice:"); 
		scanf("%d",&ch); 
		switch(ch)                   //switch case for menu driven program 
		{ 
			case 1:                                                //case1:to add two matrix 
						if(r1==r2 && c1==c2) 
						{ 
							printf("\nAddition of two matrix is :"); 
							printf("\n"); 
							addmatrix(matrix1,matrix2,matrix3,r1,c1); 
						displaymatrix(matrix3,r2,c2);	 
						} 
						else 
						{ 
							printf("\nSorry!!!Addition is not possible"); 
						} 
						break; 
			case 2:                                                //case2:For multipilcation 
					if(c1==r2) 
					{ 
						printf("\nMultiplication  of two matrix is:"); 
						printf("\n"); 
						mulmatrix(matrix1,matrix2,matrix3,r1,c2,c1); 
						displaymatrix(matrix3,r1,c2);	 
					} 
					else 
					{ 
						printf("\nSorry!!!Multiplication is not possible"); 
					} 
			 		break; 
			case 3:                                              //case4:For transpose 
					printf("\nTranspose of matrix1:\n"); 
					transmatrix(matrix1,matrix3,r1,c1); 
					displaymatrix(matrix3,c1,r1); 
					printf("\nTranspose of matrix2:\n"); 
					transmatrix(matrix2,matrix3,r2,c2); 
					displaymatrix(matrix3,c2,r2); 
			 		break; 
			case 4:                                            //case4:For saddle point 
					printf("\nFor matrix1 is:\n"); 
					saddlematrix(matrix1,r1,c1); 
					printf("\nFor matrix2 is:\n"); 
					saddlematrix(matrix2,r2,c2); 
					break; 
		    case 5:                                              //case5:For exit 
		    		exit (0); 
		    		break; 
			default:break;				 
		} //end of switch case 
	}//end of while loop 
}//end of main function
