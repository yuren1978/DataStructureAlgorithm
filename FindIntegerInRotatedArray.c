int FindPosInArray(int* a, int length, int value){
	int posOfIndex=-1;
	int start=0,
	int end=length-1;
	while(start<end){
		int middle=(start+end)/2;
		if(a[middle]==value){
			posOfIndex=middle;
			break;
		}
		else{//not the middle value
			if(a[middle+1]<a[end]){
				if(a[middle+1]<=value && a[end]>=value){
					start=middle+1;
				}
				else{
					end=middle-1;
				}
			}
			else{
				if(a[start]<=value && a[middle-1]>=value){
					end=middle-1;
				}
				else{
					start=middle+1;
				}
			}
		}
	}
	if(a[start]==value){
		posOfIndex=start;
	}
	return posOfIndex;
}

int main(int argc, char const *argv[])
{

	int a[]={7,8,9, 1,2,3,4,5,6}
	int length=sizeof(a)/sizeof(*a);	
	int pos=FindPosInArray(a, 4);
	return 0;
}