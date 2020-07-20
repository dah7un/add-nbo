#include <stdio.h> 	// for printf
#include <arpa/inet.h> //for ntohl
#include <stdint.h> 	// for uint32_t

int main(int argc, char *argv[]){

	FILE *F1, *F2;
	uint32_t num1, num2, sum;
	int i;
	
	if(argc<3){
		printf("syntax : %s <file1> <file2>\n", argv[0]);
		return 0;
	}	


	F1 = fopen(argv[1],"rb");
	F2 = fopen(argv[2],"rb");

	fread(&num1, 1, 4, F1);
	num1 = ntohl(num1);
	
	fread(&num2, 1, 4, F2);
	num2 = ntohl(num2);
	
	sum = num1+num2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);
	
	
	fclose(F1);
	fclose(F2);
	
	return 0;
}
