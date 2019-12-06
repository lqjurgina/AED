#include <stdio.h>
#include <stdlib.h>

typedef struct buf{
    void * data;
    int data_type;
}Buffer;

int main(){
    int counter = 1;
    int v,i;
    int *vt;
    float v1;
    float *v1t;
    double v2;
    double *v2t;
    Buffer * buffer = (Buffer*)malloc(sizeof(Buffer));
    int op;
    while(1){
        scanf("%d", &op);
        if(op > 3)
            break;
        if(counter > 1){
                buffer = (Buffer*)realloc(buffer, counter*sizeof(Buffer));
        }
        buffer[counter-1].data_type = op;
        /*Se for int*/
        if(op == 1){
            scanf("%d", &v);
            buffer[counter-1].data=&v;
            //vt = (int*)buffer[counter-1].data;
            //printf("%d\n", *vt);
        }
        /*Se for float*/
        else if(op == 2){
            scanf("%f", &v1);
            buffer[counter-1].data = &v1;
            //v1t = (float*)buffer[counter-1].data;
            //printf("%.2f\n", *v1t);
        }
        /*Se for double*/
        else if(op == 3){
            scanf("%lf", &v2);
            buffer[counter-1].data = &v2;
            //v2t = (double*)buffer[counter-1].data;
            //printf("%.2lf\n", *v2t);
        }
        counter++;
        //printf("");
    }
    printf("Printa em ordem de insercao no vetor\n");
    /*Printa em ordem*/
    for(i = 0; i < counter; i++){
        /*Se for int*/
        if(buffer[i].data_type == 1){
            vt = (int*)buffer[i].data;
            printf("%d\n", *vt);
        }
        /*Se for float*/
        if(buffer[i].data_type == 2){
            v1t = (float*)buffer[i].data;
            printf("%.2f\n", *v1t);
        }
        /*Se for double*/
        if(buffer[i].data_type == 3){
            v2t = (double*)buffer[i].data;
            printf("%.2lf\n", *v2t);
        }
    }

    /*Printa por tipo de dado*/
    printf("Tipo de dado\n");
    /*Int*/
    printf("Dado Int\n");
    for(i = 0; i < counter; i++){
        if(buffer[i].data_type == 1){
            vt = (int*)buffer[i].data;
            printf("%d\n", *vt);
        }
    }
    /*Float*/
    printf("Dado Float\n");
    for(i = 0; i < counter; i++){
        if(buffer[i].data_type == 2){
            v1t = (float*)buffer[i].data;
            printf("%.2f\n", *v1t);
        }
    }
    /*Double*/
    printf("Dado double\n");
    for(i = 0; i < counter; i++){
        if(buffer[i].data_type == 3){
            v2t = (double*)buffer[i].data;
            printf("%.2lf\n", *v2t);
        }
    }
    free(buffer);
    free(vt);
    free(v1t);
    free(v2t);
    return 0;
}
