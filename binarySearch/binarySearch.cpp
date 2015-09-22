#include <iostream>
using namespace std;

int binarySearch(int key[], int size, int value);

main(){
	int num[16] = {3,5,9,24,15,63,66,68,70,72,73,81,84,90,91,93};

	int count = 0;
	cout << binarySearch(num,16,72) << "\n";
}
int binarySearch(int key[], int size, int value){

	int low=0, high=size-1, mid;
	int count=0;

	while(low < high){
		mid = (low+high)/2;
		count++;
		if(key[mid]>value){
			high=mid-1;
			count++;
		}else if(key[mid]<value){
			low=mid+1;
			count++;
		}else return mid;
		return count;
	}

	return -1;
}