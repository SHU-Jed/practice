#include <stdio.h>
#include <string.h>
int get_int(int x){
	
	char a[10];
	sprintf(a,"%d",x);
	int len=strlen(a);
	/*bubbling sorting little-ended*/
	for (int i = 0; i < len; ++i)
		for (int j = i+1; j < len; ++j){
			if(a[i]>a[j]){
				char tmp =a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		
		
		int minNum;
		sscanf(a,"%d",&minNum);
		
		/*reverse array*/
		for(int j=0,k = len-1;j<len/2;j++,k--){
			char t= a[j];
			a[j] = a[k];
			a[k] = t;
			
		}
		int maxNum;
		sscanf(a,"%d",&maxNum);
		
		return maxNum - minNum ;
		
}

int main()
{
	printf("the output is %d",get_int(7132));
}