#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main()
{
	int operation;
	int first, second;
    char buf[10];
	for(;;){
		printf("Select:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n\nSelect an action: ");
		
		fgets(buf, sizeof(buf) - 1, stdin);
        operation = atoi(buf);
        if(operation == 1 || operation == 2 || operation == 3 || operation == 4)
        {
		    printf("Enter number first: ");
		    fgets(buf, sizeof(buf) - 1, stdin);
            first = atoi(buf);
		    printf("Enter number second: ");
		    fgets(buf, sizeof(buf) - 1, stdin);
            second = atoi(buf);

		    switch(operation){
		    	case 1:
		    		printf("\nAnswer: %d\n", sum(first, second));
		    		break;
		    	case 2:
		    		printf("\nAnswer: %d\n", sub(first, second));
		    		break;
			    case 3:
			    	printf("\nAnswer: %d\n", mul(first, second));
			    	break;
			    case 4:
			    	printf("\nAnswer: %.4f\n", divis(first, second));
			    	break;
		    	default:
                    operation = 5;
				    break;
		    }
        }else
            break;
        
	}
	return 0;
}
