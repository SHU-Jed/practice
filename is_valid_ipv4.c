#include <stdio.h>

int is_valid_ipv4(char* ip){
	if(ip==NULL|| *ip=='\0')
		return -2;
	int tmp[4];
	
	sscanf(ip,"%d.%d.%d.%d",&tmp[0],&tmp[1],&tmp[2],&tmp[3]);
	for(int i=0;i<4;i++){
		if(tmp[i]<0||tmp[i]>255)
			return -1;
	
	}
}
void main(){
	char* ip ="192.168.1.11";
	int yes = is_valid_ipv4(ip);
	printf("%d\n",yes);
}
