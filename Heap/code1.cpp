#include<iostream>
using namespace std;

class heap{
    public:
    int arr[1000];
    int size;

    heap() { // Constructor to initialize size
        size = 0;
    }
   
    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){ // Start from 1 since heaps use 1-based indexing
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    
    void deletee() {
    if (size == 0) {
        cout << "Heap is empty" << endl;
        return;  // Return after printing the message
    }

    arr[1] = arr[size];
    size--;

    int i = 1;
    while (i <= size) {
        int leftindex = 2 * i;
        int rightindex = 2 * i + 1;
        int largest = i;

        // Find the largest among the current node and its children
        if (leftindex <= size && arr[leftindex] > arr[largest]) {
            largest = leftindex;
        }
        if (rightindex <= size && arr[rightindex] > arr[largest]) {
            largest = rightindex;
        }

        // If the largest is not the current node, swap and continue
        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;
        } else {
            break;  // No need to continue if the heap property is satisfied
        }
    }
}

void heapify(int arr[],int n ,int i){
        int leftindex = 2 * i;
        int rightindex = 2 * i + 1;
        int largest = i;

        // Find the largest among the current node and its children
        if (leftindex <= n && arr[leftindex] > arr[largest]) {
            largest = leftindex;
        }
        if (rightindex <= n && arr[rightindex] > arr[largest]) {
            largest = rightindex;
        }

        // If the largest is not the current node, swap and continue
        if (largest != i) {
            swap(arr[i], arr[largest]);
           heapify(arr,n,largest);
        }
}


void heapsort(int arr[],int n){
    int size =n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1); 
    }
}


};

int main()
{
    heap h1;
    h1.insert(60);
    h1.insert(40);
    h1.insert(50);
    h1.insert(30);
    h1.insert(20);

    h1.print();

    h1.deletee();
    h1.print(); 

    return 0;
}
