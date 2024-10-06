#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(0,"Portuguese");
    int n,i;
    printf("Quantos números você deseja ordenar: ");
    scanf("%d",&n);
    int v[n];
    for(i=0;i<n;i++){
        printf("Valor %d: ",i+1);
        scanf("%d",&v[i]);}


    for(int j=0;j<n-1;j++){
        for(i=0;i<n-1-j;i++){
            if(v[i]>v[i+1]){
            int temp=v[i];
            v[i]=v[i+1];
            v[i+1]=temp;
        }
    }
} printf("\n");
    for(i=0;i<n;i++){
        printf("Valor %d = %d\n",i+1,v[i]);
    }

    return 0;
}
