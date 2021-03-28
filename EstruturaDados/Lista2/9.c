#include <stdio.h>

void hanoi(int n,char o,char d,char a){
	if(n==1){ 
		printf("(%c,%c)\n",o ,d);
		return;
	}
	hanoi(n-1,o,a,d);
	printf("(%c,%c)\n",o ,d);
	hanoi(n-1,a,d,o);
}

int main(){
	int n;
	scanf("%d",&n);
	hanoi(n,'O','D','A');
	return 0;
}