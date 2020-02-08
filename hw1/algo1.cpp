//Oğuzhan Kürşat Karayılan
//150140011

#include <iostream>
#include <string> 				
#include <ctime> 				//calculating time
#include <fstream>				//for reading and writing
using namespace std; 

void merge(int arr[], int p, int r, int q){
	int i, j, k;
	int temp[r+1];
	i = p;
	k = p;
	j = q + 1;
	while(i<=q && j<=r){
		if(arr[i]<arr[j]){
			temp[k] = arr[i];
			k++;
			i++;
		}
		else{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
	while(i<=q){
		temp[k] = arr[i];
		k++;
		i++;
	}
	while(j<=r){
		temp[k] = arr[j];
		k++;
		j++;
	}
	for(i=p;i<k;i++){
		 ;
	}
}

void mergesort(int arr[], int p, int r){
	if(p<r){
		int q = (p+r)/2;
		mergesort(arr, p, q);
		mergesort(arr, q+1, r);
		merge(arr, p, r, q);
	}
}

void bubblesort(int arr[], int N){
	int i = N;
	bool sorted = false;
	while(i>1 and sorted == false){
		sorted = true;
		for(int j = 1; j<i; j++){
			if(arr[j]<arr[j-1]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				sorted = false;
			}
		}
		i = i-1;
	}
}

void writeoutput(int arr[], int N){

	ofstream output;
	output.open("output.txt");
	for(int i=0;i<N;i++){
		output << arr[i] << endl;
	}
}
  
int main(int argc, const char* argv[]) 
{ 
	clock_t start;
	double duration;
	string sort_method = argv[1];
	string amount = argv[2];
	string file = argv[3];
	ifstream inFile;
	int N = stoi(amount);
	int arr[N]; 

	inFile.open(file);
	if(!inFile){
		cout << "Cant open the file";
		exit(1);
	}

	for(int i = 0; i<N; i++){
		inFile >> arr[i];
	}

	inFile.close();


    if(sort_method == "b"){			//Bubblesort
    	
    	start = clock();
    	bubblesort(arr, N);
    	duration = (clock() - start) / (double) CLOCKS_PER_SEC;

    	writeoutput(arr, N);
    	cout << "Bubblesort called. Time consumed: " << duration << endl;

    }

    else if(sort_method == "m"){ 	//Mergesort
    	
    	start = clock();
    	mergesort(arr, 0, N-1);
    	duration = (clock() - start) / (double) CLOCKS_PER_SEC;

    	writeoutput(arr, N);
    	cout << "Mergesort called. Time consumed: " << duration << endl;
    }
  
    return 0; 
}