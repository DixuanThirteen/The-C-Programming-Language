#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(){
	int x , n , i;
	
	scanf("%d",&n);	
	
	int v[n];
	
	for(i = 0 ; i <= n ; i++){
		scanf("%d",&v[i]);
	}
	
	for(i = 0 ; i <= n ; i++){
		printf("%d",v[i]);
	}
	
	scanf("%d",&x);
	
	printf("%d",binsearch(x,v,n));
	
	return 0;
} 

int binsearch(int x, int v[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid;
    }

    return (v[low] == x) ? low : -1;
}
