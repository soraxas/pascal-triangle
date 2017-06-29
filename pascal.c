#include <stdio.h>
#include <stdlib.h>

// method signature
int * pascal(int);
void printIntPtr(int, int *);

int main(int argc, char** argv){
        if (argc < 2) { // check argument number
                printf("Missing Argument\n");
                return -1;
        }
        // get argument to int
        char *p; // for checking error
        int num = strtol(argv[1], &p, 10);
        if (*p != '\0') { // indicate error in casting
                printf("Invalid Argument\n");
                return -1;
        }
        if (num < 0) { // non-valid pascal triabgle
                printf("Invalid Argument\n");
                return -1;
        }
        free(pascal(num));
        return 0;
}

int * pascal(int n){
        if (n < 0) {
                // should not reaching here, throw error
                printf("Invalid Argument\n");
                return NULL;
        }
        if (n == 0) {
                int * ptr = malloc(sizeof(int) * (n+1));
                ptr[0] = 1;
                printIntPtr(1,ptr);
                return ptr;
        }
        if (n == 1) {
                free(pascal(0)); // print the base case
                int * ptr = malloc(sizeof(int) * (n+1));
                ptr[0] = 1;
                ptr[1] = 1;
                printIntPtr(2,ptr);
                return ptr;
        }
        if (n > 1) {
                // get the previous case
                int * pre_ptr = pascal(n-1);
                // malloc a new ptr for this pascal
                int * ptr = malloc(sizeof(int) * (n+1));

                // set the left & right most base case.
                ptr[0] = 1;
                ptr[n] = 1;

                // loop through the middle part to set value
                int pre_a = 0;
                int pre_b = 1;
                for(int i = 1; i <= n-1; ++i) {
                        ptr[i] = pre_ptr[pre_a++];
                        ptr[i] += pre_ptr[pre_b++];
                }
                printIntPtr(n+1, ptr); //print
                // free previous ptr
                free(pre_ptr);
                return ptr;
        }
}

void printIntPtr(int size, int * ptr){
        for (int i = 0; i < size; ++i) {
                printf("%i", ptr[i]);
                if ( i != size -1 ) {
                        printf(" ");
                }
        }
        printf("\n");
}
