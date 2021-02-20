#include <iostream>
#include <string>

using namespace std;

template< class T>
void showarray(T data[], int n) {
	for(int i=0;i<n;i++)
		cout << data[i] << " ";
}

template<class T>
void merge(T data[], T temp_array[], int low, int middle, int high) {
	

	for(int i=low;i<=high;i++) {
		temp_array[i] = data[i];
	}
	
	int i = low;
	int j = middle + 1;
	int k = low;
	

	while( (i<=middle) && (j<=high) ) {	
		if( temp_array[i] <= temp_array[j] ) {
			data[k] = temp_array[i];
			i++;
		} else {
			data[k] = temp_array[j];
			j++;
		}
		
		k++;
	}
	
    while (i <= middle) {
        data[k] = temp_array[i];
        k++;
        i++;
    }
	
    while (j <= high) {
        data[k] = temp_array[j];
        k++;
        j++;
    }
}

template<class T>
void mergesort(T data[], T temp[], int low, int high) {
	
	if( low >= high) {
		return;
	}		
	
	int middle_index = (low+high)/2;
	
	mergesort(data, temp, low, middle_index);
	mergesort(data, temp, middle_index+1, high);
	merge(data, temp, low, middle_index, high);
}

template<class T>
void sort(T data[], T temp[], int n) {
	mergesort(data, temp, 0, n-1);
}

main() {
    
	char data[] = {'b','a','c','z'};
	int n = sizeof(data)/sizeof(data[0]);
	
	char temp[n];
	
	sort(data, temp, n);
	showarray(data, n);
}