#include <iostream>
using namespace std;

int main()
{
    int size_arr;
    int sum = 0;

    cout << "Input the numbers of elements to be stored in array: ";
    cin >> size_arr;

    int arr1[size_arr], arr2[size_arr];

    // First loop: Input, copying elements, and calculating sum of even numbers
    cout << "Input " << size_arr << " elements of the array: " << endl;
    for (int i = 0; i < size_arr; i++) {
        cout << "element-" << i + 1 << " : ";
        cin >> arr1[i];

        // Copy to second array
        arr2[i] = arr1[i];

        // Sum even numbers
        if (arr1[i] % 2 == 0) {
            sum += arr1[i];
        }
    }

    // Second loop: Display the elements of both arrays
    cout << "Elements stored in the first array are: ";
    for (int i = 0; i < size_arr; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Elements copied into the second array are: ";
    for (int i = 0; i < size_arr; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Display the sum of even numbers
    cout << "Sum of even elements from the array: " << sum << endl;

    return 0;
}

