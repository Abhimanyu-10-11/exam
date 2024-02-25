#include<stdio.h>

void towers(int n, char A, char B, char C)
	{
		if(n==1)
		{
			printf("MOVE DISK 1 FROM ROD %c TO ROD %c\n",A,B);
			return;
		}
		towers(n-1,A,C,B);
		printf("MOVE DISK %d FROM ROD %c TO ROD %c\n",n,A,B);
		towers(n-1,C,B,A);
	}

	void main()
	{
		int n;
		printf("ENTER THE NUMBER OF DISKS\n");
		scanf("%d",&n);
		printf("MOVES MADE\n");
		towers(n,'A','C','B');
	}
