/*
So basically in this problem, we'll have 2 scenarios
i) 1 disk ii) more than 1 disk
WK for case 1 and for the other one
	i)firstly send all the disks excpet largest one to the temp pole	(recursion)
	ii)then the last disk to Dest pole	
	iii)disks in temp to dest 	(recursion)
*/

#include <stdio.h>

int hanoi(int n, char SOURCE, char TEMP, char DEST){
	int steps = 0;
	if(n == 1){
		printf("Move disk %d from %c to %c.\n" , n, SOURCE, DEST);
		steps++;
	} else if (n == 0){
		printf("Rest Assure..You don't need to do anything.\n");
	} else {
		steps += hanoi(n-1, SOURCE,DEST,TEMP);					//from source to the temp pole (s --> t)
		printf("Move disk %d from %c to %c.\n" , n, SOURCE, DEST);steps++;
		steps += hanoi(n-1, TEMP,SOURCE,DEST);					//from temp to the dest pole (t --> d)
	}
	return steps;
}

int main(){
	int n;
	printf("Enter the number of disks : ");
	scanf("%d", &n);
	printf("\n");
	int count = hanoi(n, 'A', 'B', 'C');
	printf("\nTotal no. of Steps = %d\n", count);
	return 0;
}
