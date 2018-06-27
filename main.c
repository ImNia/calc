#include <stdio.h>
#include "calc.h"


int main()
{
	int operation;
	int first, second;
    char buf[10];
	for(;;){
		printf("Select:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
		
		operation = fgets(buf, sizeof(buf), 0);
		printf("Enter number first: ");
		first = fgets(buf, sizeof(buf), 0);
		printf("\nEnter number second: ");
		second = fgets(buf, sizeof(buf), 0);

		switch(operation){
			case '1':
				printf("\n%d", sum(first, second));
				break;
			case '2':
				printf("\n%d", sub(first, second));
				break;
			case '3':
				printf("\n%d", mul(first, second));
				break;
			case '4':
				printf("\n%.4f", div(first, second));
				break;
			default:
				break;
		}
	}
	return 0;
}
