// There are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.

# include <stdio.h>
# include <stdlib.h>

// their neighbors
int max(int a1, int a2){
	return a1 > a2 ? a1 : a2;
}

int candy(int ratings[], int n) {
    int*p = NULL;
    int s = 0;
    int i = 0;
    int t = 0;

    p = (int*)malloc(sizeof(int)*n);

    for(i = 0; i <= n-1; i++){
    	p[i] = 1;
    }

    for(i = 1; i <= n-1; i++){
    	p[i] = ratings[i] > ratings[i-1] ? p[i-1] : 1;
    }

    s += p[n-1];
    t = 1;
    for(i = n-2; i >= 0; i --){
    	if(ratings[i] > ratings[i+1]){
    		t += 1;
    		p[i] = max(p[i], t);
    	}
    	else{
    		t = 1;
    	}
    	s += p[i]; 
    }

    return s;
}

int main(){
	int ratings[] = {10, 32, 43, 55, 40, 11};
	printf("%d\n", candy(ratings, 6));
	return 0;
}