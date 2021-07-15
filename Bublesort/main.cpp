#include <iostream>

using namespace std;


void memoryAllocation( int *arr, int n);
void memoryFree( int *arr);
void insertRandomValue(int *arr, int n);
void printArray (int *arr, int n);
void babelSort(int *arr, int n, int mode);
void selectionSort(int *arr, int n, int mode);
void insertionSort(int *arr, int n, int mode);

int main() {

    int *arr;
    int n;
    int mode, modeSort;

    cout<<"Podaj dlugość tablicy:  ";
    cin>>n;

    cout<<"Podaj sposób sortowania:"<<endl;
    cout<<"1 - babelSort, 2 - selectionSort, 3 - insertionSort, 4 - wyjście z programu"<<endl;
    cin>>modeSort;

    cout<<"1 - rosnąco, 2 - malejąco ";
    cin>>mode;

    memoryAllocation(arr, n);
    insertRandomValue(arr, n);
    printArray (arr, n);
    if(modeSort == 1){
        babelSort(arr, n, mode);
    }
    if(modeSort == 2){
        selectionSort(arr, n, mode);
    }
    if(modeSort == 3){
        insertionSort(arr, n, mode);
    }
    if(modeSort == 4){
        return 0;
    }
    printArray (arr, n);
    memoryFree (arr);

    return 0;
}


void memoryAllocation(int *arr, int n){
    arr=new int[n];
}

void memoryFree(int *arr){
    delete []arr;
}


void insertRandomValue(int *arr, int n){
    int a,b;
    cout<<"Enter a range: ";
    cin>>a;
    cin>>b;

    for(int i =0 ; i < n; i++){
        arr[i] = rand()%(b-a+1)+a;
    }

}

void printArray (int *arr, int n){

    for(int i =0 ; i < n; i++){
        cout<<arr[i]<< " ";
    }
    cout << endl;
}


void babelSort(int *arr, int n, int mode) {
    int temp;

    if(mode == 1){
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    if(mode == 2){
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < n-i; j++)
            {
                if(arr[j] < arr[j+1])
                {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
}

void insertionSort(int *arr, int n, int mode)
{

    int temp;
    int i, j;

    if(mode ==1){
        for (i = 1; i < n; i++)
        {
            temp = arr[i];

            for (int j = i - 1;j >= 0 && arr[j] > temp;j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
    if(mode ==2){
        for(j = 1; j < n; j++)
        {
            temp = arr[j];
            for(i = j - 1; (i >= 0) && (arr[i] < temp); i--)
            {
                arr[i+1] = arr[i];
            }
            arr[i+1] = temp;
        }
    }
}

void selectionSort(int *arr, int n, int mode)
{
    int i, j, min_idx, temp;

    if(mode == 1){
        for (i = 0; i < n-1; i++)
        {
            min_idx = i;
            for (j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
    if(mode==2){
        for (i = 0; i < n; ++i)
        {
            min_idx = i;
            for (j = i+1; j < n; j++)
                if (arr[j] > arr[min_idx])
                    min_idx = j;

            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

