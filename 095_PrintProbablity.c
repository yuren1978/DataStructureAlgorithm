//need more time to digest
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int g_maxValue=6;

void ProbablityInner(int original, int current, int sum, int* probablity){
	if(current==1){
		probablity[sum-original]++;
	}
	else {
		for (int i=1; i<g_maxValue; ++i) {
			ProbablityInner(original, current-1,i+sum, probablity);		
		}
	}
}

void Probablity(int number , int* probablity){
	for (int i=1; i<g_maxValue; ++i) {
		ProbablityInner(number, number, i, probablity);	}
} 



void PrintProbablity(int number){
	if(number<1)
		return;
		
	int maxSum=number*g_maxValue;
	int* probablity=malloc(sizeof(int)*(maxSum-number+1));
	for (int i=number; i<maxSum; ++i) {
		probablity[i-number]=0;
	}	
	
	Probablity(number, probablity);
	
	int total=pow((double)g_maxValue, number);
	
	for (int i=number; i<=maxSum; ++i) {
		double ratio=(double) probablity[i-number]/total;
		printf("%d: %e \n", i, ratio);
	}
	
	free(probablity);
}


void PrintProbablityIterative(int number){
	if(number<1)
		return;
	
	int* probab[2];
	
	probab[0]=malloc(sizeof(int)*(g_maxValue*number+1));	probab[1]=malloc(sizeof(int)*(g_maxValue*number+1));	
	for (int i=0; i<g_maxValue*number+1; ++i) {
		probab[0][i]=0;
		probab[1][i]=0;	
	}
	
	int flag=0;
	for (int i=1; i<g_maxValue; ++i) {
		probab[flag][i]=1;
	}
	
	for (int k=2; k<=number; ++k) {
		for (int i=0; i<k; ++i) {
			probab[1-flag][i]=0;	
		}
		
		for (int i=k; i<g_maxValue*k ; ++i) {
			probab[1-flag][i]=0;
			for (int j=1; j<=i && j<=g_maxValue; ++j) {
				probab[1-flag][i]+=probab[flag][i-j];	
			}
		}
		
		flag=1-flag;	
	}
	
	double total=pow((double)g_maxValue, number);
	for (int i=number; i<g_maxValue*number; ++i) {
		double ratio=(double) probab[flag][i]/total;
		printf("%d: %e\n", i, ratio);
	}
	
	free(probab[0]);
	free(probab[1]);
}


int main(int argc, char *argv[]) {
	PrintProbablity(2);
	printf("Iterative \n ");
	PrintProbablityIterative(2);
}