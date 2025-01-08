# include <stdio.h>
# include <stdlib.h>

void ex1(){
    int x = 0;
    int y = 0;

    printf("write first input: ");
    scanf("%d", &x);
    printf("write second input: ");
    scanf("%d", &y);

    // q) a
    if (x>y){
        printf("bigger number is %d\n", x);
    }
    else if (y>x)
    {
        printf("bigger number is %d\n", y);
    }
    else{
        printf("numbers are equal\n");
    }

    // q) b
    int res = x + y;
    printf("result of summation is %d\n", res);
    printf("result of multiplication is %d\n", x*y);
}

void ex2(){
    int a = 0;

    printf("enter a whole number: ");
    scanf("%d", &a);
    
    int i = 0;
    for (i; i<=a; i++){
        printf("%d,", i);
    }

    printf("\nnow in decreasing order\n");
    for (i--; i>=0; i--) {
        printf("%d,", i);
    }
    printf("\n");
}

void ex3(){
    int a = 0;

    printf("enter value for a: ");
    scanf("%d", &a);

    int i = 0;

    while(i < a){
        printf("%d,", i);
        i++;
    }

    printf("\n now in decreasing order \n");
    i--;
    while(i >= 0){
        printf("%d,", i);
        i--;
    }
    
}

void ex4(){
    int len = 5;
    int arr[len];



    int M = -2147483648;
    int m = 2147483647;
    int S = 0;

    for (int i=0; i<len; i++){
        printf("enter %d numbers: ", len - i);
        scanf("%d", &arr[i]);

        if (arr[i] > M) M = arr[i];
        if (arr[i] < m) m = arr[i];

        S += arr[i];
    }

    printf("max numbe is %d, min number is %d, and sum is %d\n", M, m, S);
}

void ex5(){
    int len = 20;
    char parola[len];

    printf("write here a string to be redacted: ");
    scanf("%s", parola);

    int i = 0;
    while (parola[i] != '\0') {
        if ((parola[i] <= '9') && (parola[i] >= '0')) parola[i] = '*';
        i++;
    }

    printf("%s\n",parola);
}
int main(){
    //ex5();

    printf("%d", rand());
    return 0;
}
