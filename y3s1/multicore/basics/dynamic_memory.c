#include<stdio.h>
#include<stdlib.h>

int ex1(){
    int input;
    int len = 0;

    int *array = 0;

    while(1){
        scanf("%d", &input);
        if (input==0){
            break;
        }

        len++;
        array = realloc(array, sizeof(input)*len);
        if (array == NULL){
            printf("\ncannot assign more space!\n");
            return(1);
        }

        array[len - 1] = input;
    }
    // do sum and display
    int sum = 0;
    for(int i = 0; i<len; i++){
        printf("%d,", array[i]);
        sum += array[i];
    }

    printf("\nsum of elements: %d\n", sum);

    int *p = array;
    int min = RAND_MAX;
    int max = -min;

    for(int i = 0; i<len; i++){
        if (*p < min) min = *p;
        if (*p > max) max = *p;
        *p++;
    }

    printf("the max is %d, the min is %d\n", max, min);

    free(array);

}

int ex2(){
    struct Auto{
        int price;
        char model[10];
        int cc;
        char engine[10];
    }car1, car2, car3;

    struct Auto *p;
    int price, cc;
    char* m, e;

    for(int i =0; i<3;i++){

        switch (i)
        {
        case 0:
            p = &car1;
            break;
        case 1:
            p = &car2;
            break;
        case 2:
            p = &car3;
            break;

        default:
            break;
        }

        printf("\nenter price:");
        scanf("%d", &p->price);
        printf("\nenter model:");
        scanf("%s", p->model);
        printf("\nenter cc:");
        scanf("%d", &p->cc);
        printf("\nenter engine:");
        scanf("%s", p->engine);




    }

    printf("\ncar1: %d, %s, %d, %s", car1.price, car1.model, car1.cc, car1.engine);
    printf("\ncar2: %d, %s, %d, %s", car2.price, car2.model, car2.cc, car2.engine);
    printf("\ncar3: %d, %s, %d, %s\n", car3.price, car3.model, car3.cc, car3.engine);
}

int ex3(){
    typedef struct Libri{
        char titolo[20];
        int prezzo;
    }libro;

    libro biblioteca[2];
    libro *p;

    for(int i = 0; i<2; i++){
        p = &biblioteca[i];

        printf("\nenter titolo:");
        scanf("%s", p->titolo);

        printf("\nenter price:");
        scanf("%d", &p->prezzo);
    } 

    if (*biblioteca[0].titolo == *biblioteca[1].titolo){
        if (biblioteca[0].prezzo == biblioteca[1].prezzo){
            return 0;
        }
    }
    return 1;
    
}

int ex4(){
    union Data{
        int i;
        char c;
    } data;

    printf("mem of data %ld, mem of single datatypes: %ld\n", sizeof(data), sizeof(int)+sizeof(char));
    
    return 0;
}

int trim(char *p){
    while(1){
        if (*p == '\n' || *p == '\0') {
            *p = '\0';
            return 0;
        }
        else{
            *p++;
        }
    }
}

int pinput(char *p){
    fgets(p, sizeof(char[10]), stdin);
    fflush(stdin);
    trim(p);
}

int ex5(){
    struct Autos{
        char model[10];
        char engine[10];
        struct Autos *next; 
    };

    struct Autos l;
    struct Autos *p = &l;

    printf("set model of your car, leave empty to finish adding them:");
    fgets(p->model, sizeof(char[10]), stdin);
    fflush(stdin); // otherwise it would be reading the same things over and over
    if(p->model[0] == '\n'){
        printf("\nNo cars inserted\n");
        return 1;
    }
    else{
        trim(p->model); 

        printf("\nenter engine:");
        pinput(p->engine);

        while(1){
            p->next = malloc(sizeof(struct Autos));
            p = p->next;
            if (p == NULL){
                printf("\nno more space, pointer is NULL\n");
                return 1;
            }

            printf("set model of your car, leave empty to finish adding cars:");
            fgets(p->model, sizeof(char[10]), stdin);
            fflush(stdin);
            if (p->model[0] == '\n') {
                printf("\nno more cars\n");
                break;
            }
            trim(p->model);
            printf("\nenter engine:");
            pinput(p->engine);
        }
    }

    // now to print it
    p = &l;
    int i = 1;
    while(p->next!=NULL){
        printf("car%d, model:%s, engine:%s\n", i, p->model, p->engine);
        i++;
        p=p->next;
    }
    
}
struct Element
    {
        int value;
        struct Element *next;
    };

struct Element crealista(){
    struct Element l;
    struct Element *p = &l;

    char *inp;

    while(1){
        printf("enter the values of a list, leave empty to stop inserting elements:");
        fgets(inp, sizeof(char[10]), stdin);
        fflush(stdin);

        if (inp[0] == '\n'){
            printf("\nno input was given\n");
            p->next = 0;
            break;
        }
        trim(inp);
        p->next = malloc(sizeof(struct Element));
        p->value = atoi(inp);
        p = p->next;
    }
    return l;

}

void stampa(struct Element l){
    struct Element *p = &l;

    while(p->next != 0){
        printf("%d,",p->value);
        p = p->next;
    }
}

int ex6(){

    struct Element l = crealista();
    //l = eliminaultimo();
    //eliminadecimo(l);
    //eliminaultimo(l);
    stampa(l);
    free(&l);
    return 0;

}

int main(){
    printf("\nfunction finished with error code %d\n", ex6());
}