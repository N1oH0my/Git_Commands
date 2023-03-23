#include <iostream>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>
#include <vector>
#include <list>
#include <algorithm>
//-------------------//
#include <fstream>
#include <string>
#include<sstream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::map;
using std::set;

void bubble_sort(int* array, int n);

void barrier_sort(int* a, int n);

void quickSort(int* array, int size);

void quickSort2(int* arr, int left, int right);

void InsertionSort(int* arr, int n);

int binarySearch(int a[], const int& item, int low, int high);
void insertionSort(int a[], int n);

void shellSort(int arr[], int n);
void printArray(int arr[], int n);

void selection_sort(int* arr, int n);

void mergeSort(int* A, int left, int right);

void counting_sort(int* arr, int size);

int* distributive_counting_sort(int* array, size_t n);
//----------------------------
template <class type>
void shaker_sort(std::vector<type>& vec)
{
    bool is_sorted;
    int right = vec.size() - 1;
    int left = 1;
    int last_swap_index;

    auto swap_if = [&vec, &is_sorted, &last_swap_index](int i)
    {
        if (vec[i - 1] > vec[i])
        {
            std::swap(vec[i - 1], vec[i]);
            is_sorted = false;
            last_swap_index = i;
        }
    };

    do {
        is_sorted = true;

        for (int i = left; i <= right; ++i)
            swap_if(i);
        right = last_swap_index - 1;

        for (int i = right; i >= left; --i)
            swap_if(i);
        left = last_swap_index + 1;

    } while (is_sorted == false);
}

template <class type>
void init(std::vector<type>& vec, const char* filename)
{
    std::ifstream in(filename);
    int num;
    while (in.good())
    {
        in >> num;
        vec.push_back(num);
    }

}

template <class type>
void print(std::vector<type>& vec)
{
    int size = vec.size();
    for (int i = 0; i < size; ++i)
        std::cout << vec[i] << " ";
}
//----------------------------
//-------------------------------------------MAIN--------------------------------------------------//
int main() {
	
	
	cout << endl;
	cin.get();
	return 0;
}
//----------------------------------------------bubble_sort----------------------------------------------------//
void bubble_sort(int* array, int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = n - 1; j > i; --j)
			if (array[j - 1] > array[j])
				std::swap(array[j - 1], array[j]);
}
//-----------------------------------------------barrier_sort---------------------------------------------------//
void barrier_sort(int* a, int n)
{
	int bound, t;
	bound = n;//âûáèðàåì ãðàíèöó ñïðàâà äëÿ ñðàâíèâàåìûõ ýëåìåíòîâ
	do {
		t = 0;//ïðåäïîëàãàåì, ÷òî íà äàííîì ïðîõîäå àëãîðèòìà îáìåíîâ íå áóäåò, ò.å. âñå ýë-òû óïîðÿäî÷åíû
		//ñðâíèâàåì âñå ñîñåäíèå ýëåìåíòû
		for (int i = 0; i < bound - 1; i++)
			if (a[i] > a[i + 1]) {
				std::swap(a[i], a[i + 1]);
				t = i;//çàïîìèíàåì ìåñòî ïîñëåäíåãî îáìåíà
			}
		bound = t + 1;//çàïîìèíàåì ìåñòî ïîñëåäíåãî îáìåíà êàê ïðàâóþ ãðàíèöó
	} while (t != 0);
}
//-----------------------------------------------quickSort---------------------------------------------------//
void quickSort(int* array, int size) {
    int i = 0;
    int j = size - 1;

    int mid = array[size / 2];

    do {
        while (array[i] < mid)
            ++i;

        while (array[j] > mid)
            --j;


        if (i <= j) {
            std::swap(array[i], array[j]);
            ++i;
            --j;
        }

    } while (i <= j);

    if (j > 0)
        quickSort(array, j + 1);

    if (i < size)
        quickSort(array + i, size - i);
}
//-----------------------------------------------quickSort-without opornogo el--------------------------------------------------//
void quickSort2(int* arr, int left, int right)
{
    if (left < right) {
        int i = left, j = right;
        while (i < j)
        {
            while (i < j && arr[j] >= arr[i])
                --j;
            std::swap(arr[i], arr[j]);

            while (i < j && arr[j] >= arr[i])
                ++i;
            std::swap(arr[i], arr[j]);
        }
        quickSort2(arr, left, i - 1);
        quickSort2(arr, j + 1, right);
    }
}
//-----------------------------------------------InsertionSort---------------------------------------------------//
void InsertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
            std::swap(arr[j - 1], arr[j]);
}
//-----------------------------------------------binarySearch---------------------------------------------------//
int binarySearch(int a[], const int& item, int low, int high)
{
    int pos = low;
    while (low <= high && pos == low) {
        int mid = low + (high - low) / 2;
        if (item == a[mid])
            pos = mid + 1;
        else if (item < a[mid])
            high = mid - 1;
        else
        {
            low = mid + 1;
            pos = low;
        }
    }
    return pos;
}
// ñîðòèðîâêà âñòàâêàìè ñ áèíàðíûì ïîèñêîì
void insertionSort(int a[], int n)
{
    int i, loc, j, selected;
    for (i = 1; i < n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            // íàéòè ìåñòî, êóäà íóæíî âñòàâèòü âûáðàííûé ýëåìåíò
            loc = binarySearch(a, a[i], 0, i - 1);
            // Ïåðåìåñòèòå âñå ýëåìåíòû ïîñëå íàéäåííîãî ìåñòà, ÷òîáû ñîçäàòü ìåñòî äëÿ âñòàâêè
            j = i - 1;
            selected = a[i];
            while (j >= loc) { a[j + 1] = a[j];	j--; }
            a[j + 1] = selected;
        }
    }
}
//-----------------------------------------------shellSort---------------------------------------------------//
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            for (j; j >= gap && arr[j - gap] > temp; j -= gap)//èùåì ìåñòî ýëåìåíòó temp â ïîäìàññèâå 
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n\n";
}
//-----------------------------------------------selection_sort---------------------------------------------------//
void selection_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;
        std::swap(arr[i], arr[min_index]);
    }
}
//-----------------------------------------------mergeSort---------------------------------------------------//
void mergeSort(int* A, int left, int right)
{
    if (left == right) //åñëè ãðàíèöû ñîìêíóëèñü, îñòàíàâëèâàåì
    {
        return;
    }
    int middle = (left + right) / 2; //îïðåäåëÿåì ñåðåäèíó
    mergeSort(A, left, middle); //âûçûâàåì äëÿ ëåâîé ïîëîâèíû
    mergeSort(A, middle + 1, right); //âûçûâàåì äëÿ ïðàâîé ïîëîâèíû
    int* tmp = new int[right]; //äîïîëíèòåëüíûé ìàññèâ
    int first = left; //íà÷àëî ïåðâîãî ïóòè
    int second = middle + 1; //íà÷àëî âòîðîãî ïóòè
    for (int i = 0; i < right - left + 1; i++) //äëÿ âñåõ ýëåìåíòîâ äîïîëíèòåëüíîãî ìàññèâà
    {
        //áóäåì çàïèñûâàòü â äîïîëíèòåëüíûé ìàññèâ ìåíüøèé èç ýëåìåíòîâ äâóõ ïóòåé

        //èëè îñòàòîê ïåðâîãî ïóòè åñëè second > right
        if ((second > right) || ((first <= middle) && (A[first] < A[second])))
        {
        tmp[i] = A[first];
        first++;
        }
        else
        {
        tmp[i] = A[second];
        second++;
        }
    }
        //ïåðåïèñûâàåì ñôîðìèðîâàííóþ ïîñëåäîâàòåëüíîñòü â èñõîäíûé ìàññèâ
    for (int i = 0; i < right - left + 1; i++)
    {
        A[left + i] = tmp[i];
    }
}
//-----------------------------------------------counting_sort---------------------------------------------------//
void counting_sort(int* arr, int size)
{
    int* count = new int[size] {0};
    int elem1, elem2;
    for (int i = size - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
            if (arr[i] >= arr[j])
                count[i] = count[i] + 1;
            else
                count[j] = count[j] + 1;
    }
    int i = 0, j = 0, k = 0;
    while (i < size) {
        elem1 = arr[i]; j = count[i];
        while (i != j) {
            elem2 = arr[j];
            arr[j] = elem1;
            elem1 = elem2;
            k = count[j];
            count[j] = j;
            j = k;
        }
        arr[i] = elem1;
        count[i] = i - 1;
        ++i;
    }
    delete[] count;
}
//------------------------Error-----------------------distributive_counting_sort---------------------------------------------------//
int* distributive_counting_sort(int* array, size_t n)
{
    //size_t sizeC = max - min + 1;
    //size_t* C = new size_t[max - min + 1]{ 0 }; // çàïîëíÿåì ìàññèâ C íóëÿìè
    //for (size_t i = 0; i < n; ++i)
    //    ++C[array[i]]; // çàïèñûâàåì â ìàññèâ C êîëè÷åñòâî êàæäîãî ýëåìåíòà èç èñõîäíîãî ìàññèâà
    //for (size_t i = 1; i < sizeC; ++i)
    //    C[i] += C[i - 1]; // ñ÷èòàåì ÷àñòè÷íûå ñóììû
    //int* result = new int[n];
    //for (int i = n - 1; i >= 0; --i) { // çàïèñûâàåì â âûõîäíîé ìàññèâ ðåçóëüòàò
    //    result[C[array[i]] - 1] = array[i];
    //    --C[array[i]];
    //}

    //return result;
    //delete[] C;
}
//-----------------------------------------------barrier_sort---------------------------------------------------//
//-----------------------------------------------barrier_sort---------------------------------------------------//
