#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void ex1(){
    int array[5];
    int i = 0;
    for (i=0; i<5; i++){
        array[i] = i;
    }

    int *p1, *p2;

    p1 = &array[0];
    p2 = &array[4];


    while(p1 <= p2){
        *p1 = 99;
        *p1++;
    }

    p1 = &array[0];
    for(i=0; i<5; i++){
        printf("%d,", *p1);
        p1++;
    }

}

void ex2(){
    int len = 10;
    char to_no_digits[len];
    scanf("%s", &to_no_digits[0]);

    char *p = &to_no_digits[0];

    while(*p != '\0'){
        if (isdigit(*p)){
            *p = '*';
        }
        *p++;
    }

    printf("%s \n", &to_no_digits[0]);


}

void ex3(){
    int n1[5], n2[5];

    for(int i = 0; i<5; i++){
        printf("%d of 1st: ", i);
        scanf("%d", &n1[i]);
        printf("\n %d of 2nd: ", i);
        scanf("%d", &n2[i]);

        printf("\n");
    }
    

    int *p1 = &n1[0];
    int *p2 = &n2[4];


    for(int i = 0; i < 5; i++){

        int cp = *p1;
        *p1 = *p2;
        *p2 = cp;

        *p1++;
        *p2--;
    }

    printf("array1: ");
    for(int i = 0; i<5; i++){
        printf("%d,", n1[i]);
    }
    printf("\n");

    printf("array2: ");
    for(int i = 0; i<5; i++){
        printf("%d,", n2[i]);
    }
    printf("\n");
}

int ex4(int arr[], int x, int len, int *c){
    int res = 404;
    bool f = false;


    if (len > 0){
        int *p = &arr[0];

        for(int i = 0; i < len; i++){
            if (x == *p) {
                *c += 1;
                if (!f){
                    res = i;
                    f = true;
                }
            }
            *p++;
        }
    }
    return res;
}

void main(){
    int len = 5;
    int arr[5] = {2,8,8,0,8};
    int occ = 0;
    
    int val = ex4(arr, 8, len, &occ);

    printf("location: %d, count: %d\n", val, occ);
}