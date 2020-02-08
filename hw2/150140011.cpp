//O. Kürşat Karayılan
// 150140011

#include <iostream>
#include <fstream>
using namespace std;

struct event
{
	string name;
	int val;
	int time;		//0 for starttime and 1 for endtime
	
};

event heap[1000];
int size=0;

int parent(int i){
	return (i-1)/2;
}

int left(int i){
	return 2*i+1;
}

int right(int i){
	return 2*i+2;
}

void swap(int a, int b){
	event temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void insert(string name, int val, int time){
	int i = size;
	heap[i].name = name;
	heap[i].val = val;
	heap[i].time = time;
	size++;

	while(i != 0 && heap[parent(i)].val > heap[i].val){
		swap(i, parent(i));
		i = parent(i);
	}
}

void heapify(int i){
	int l = left(i);
	int r = right(i);
	int min = i;

	if((l < size) && (heap[l].val < heap[min].val)){
		min = l;
	}
	if((r < size) && (heap[r].val < heap[min].val)){
		min = r;
	}

	if(min != i){
		swap(i, min);
		heapify(min);
	}
}

void removeMin(){
	if(size==1){
		size--;
	}else{
		heap[0] = heap[size - 1];
		size--;
		heapify(0);
	}
}

int main(int argc, char *argv[]){
	string name, starttime, endtime;
	ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile) {
   		cerr << "Unable to open file";
    	exit(1);
	}

	while(!inFile.eof()){
		inFile >> name;
		inFile >> starttime;
		inFile >> endtime;
		insert(name, stoi(starttime), 0);
		insert(name, stoi(endtime), 1);
	}
	inFile.close();

	for(int i=1; i<1000; i++){		//virtual clock
		if(size==0){
			cout << "TIME " << i << ": NO MORE EVENTS, SCHEDULER EXITS" << endl;
			break;
		}
		if(heap[0].val != i){
			cout << "TIME " << i << ": NO EVENT" << endl;
		}
		while(heap[0].val == i){
		    if(size==0) break;
			if(heap[0].time == 0){
				cout << "TIME " << i << ": " << heap[0].name << " STARTED" << endl;
				removeMin();
			}
			else if(heap[0].time == 1){
				cout << "TIME " << i << ": " << heap[0].name << " ENDED" << endl;
				removeMin();
			}
		}
		if(size==0){
			cout << "TIME " << i << ": NO MORE EVENTS, SCHEDULER EXITS" << endl;
			break;
		}
	}



	return 0;
}

