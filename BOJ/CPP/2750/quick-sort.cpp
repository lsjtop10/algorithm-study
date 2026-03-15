#include <iostream>
#include <vector>

using namespace std;

void scanArr(vector<int> &arr, int n);
void printArr(vector<int> &arr);
//퀵소트 알고리즘 사용
void sortArr(vector<int> &arr, int begin, int end);
void swapElement(vector<int> &arr, int from, int to);

int main(int argc, char* argv[]) {

	vector<int> data;
	int num = 0;
	//N개의 수를 입력받기
	
	cin >> num;
	scanArr(data, num);
	sortArr(data, 0, num - 1);
	printArr(data);
    return 0;
	
}

void printArr(vector<int> &arr){
	
	for(vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++){
		cout << *iter << endl;
	}
}

void scanArr(vector<int> &arr, int n){

	for (int i = 0; i < n; i++){
		int in = 0;
		cin >> in;
		arr.push_back(in);
	}
	
}

void sortArr(vector<int> &arr, int begin, int end){
	

	//begin > end이면
	//더 이상 정렬할 것이 없다는 뜻 -> 종료
	if (begin >= end){
		return;
	}
	
	int pivot = arr[end];
	int low = begin;
	int high = end - 1;
	
	//end를 pivot으로 삼고
	//pivot 보다 작은 수를 담는 low
	//pivot 보다 같거나 큰 수를 담는 high
	
	
	while(low <= high){
		while(arr[low] < pivot){
			low++;
		}	
		
		while(arr[high] > pivot){
			high--;
		}
		
		if(low <= high){
			swapElement(arr, low, high);
			low++;
			high--;
		}
	}
	
	
	swapElement(arr, low, end);
	
	sortArr(arr,low,end);
	sortArr(arr,begin,high);
}

void swapElement(vector<int> &arr, int from, int to){
	int temp = arr[from];
	arr[from] = arr[to];
	arr[to] = temp;
}