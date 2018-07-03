#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    double (*function)(double); //переменная для хранения адреса функции из библиотеки libcalc.so
	int operation;
	int first, second;
    char buf[10];

    handle = dlopen("/home/agnia/study/eltex/calc/dlfcn/c_file/libcalc.so", RTLD_LAZY);
    if(!handle){
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

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
                    function = dlsym(handle, "sum");
		    		printf("\nAnswer: %f\n", (*function)((first, second)));
		    		break;
		    	case 2:
                    function = dlsym(handle, "sub");
		    		printf("\nAnswer: %f\n", (*function)((first, second)));
		    		break;
			    case 3:
                    function = dlsym(handle, "mul");
			    	printf("\nAnswer: %f\n", (*function)((first, second)));
			    	break;
			    case 4:
                    function = dlsym(handle, "divis");
			    	printf("\nAnswer: %.4f\n", (*function)((first, second)));
			    	break;
		    	default:
                    operation = 5;
				    break;
		    }
        }else
            break;
        
	}
    dlclose(handle);
	return 0;
}
