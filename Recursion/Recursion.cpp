// With Numbers

// 1 Decimal to binary
/*
#include <iostream>
using namespace std;
string decimalToBinary(int n, string result)
{
    if (n == 0)
        return result;
    result = to_string(n % 2) + result;
    return decimalToBinary(n / 2, result);
}

int main()
{
    cout << decimalToBinary(233, "");
}
*/
// 2 Divide & conquer
/*
// 2.1 Binary search
#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int x)
{
    if (left > right)
    {
        return -1;
    }
    int mid = (left + right) / 2;
    if (x == arr[mid])
    {
        return mid;
    }
    if (x < arr[mid])
    {
        return binarySearch(arr, left, mid - 1, x);
    }

    return binarySearch(arr, mid + 1, right, x);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binarySearch(arr, 0, 9, 8) << endl;
}
// 2.2 fibonacci
#include <iostream>
using namespace std;
int fib(int x)
{
    if ((x == 1) || (x == 0))
    {
        return (x);
    }
    else
    {
        return (fib(x - 1) + fib(x - 2));
    }
}
int main()
{
    int x, i = 0;
    cout << "Enter the number of terms of series : ";
    cin >> x;
    cout << "Fibonnaci Series : ";
    while (i < x)
    {
        cout << " " << fib(i);
        i++;
    }
    return 0;
}
// 2.3 Merge sort
#include <iostream>
using namespace std;
void merge(int data[], int start, int mid, int end)
{
    int temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;
    // while both sub-array have values, then try and merge them in sorted order
    while (i <= mid && j <= end)
        if (data[i] <= data[j])
        {
            temp[k] = data[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = data[j];
            k++;
            j++;
        }
    // Add the rest of the values from the left sub-array into the result
    while (i <= mid)
    {
        temp[k] = data[i];
        k++;
        i++;
    }
    // Add the rest of the values from the right sub-array into the result
    while (j <= end)
    {
        temp[k] = data[j];
        k++;
        j++;
    }
    for (i = start; i <= end; i++)
    {
        data[i] = temp[i - start];
    }
}
void mergeSort(int data[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(data, start, mid);
        mergeSort(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}
int main()
{
    int data[] = {-5, 20, 10, 3, 2, 0};
    mergeSort(data, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << data[i] << " ";
    }
}
*/
// 3 Sum of natural numbers
/*
#include <iostream>
using namespace std;
int naturalSum(int x)
{
    if (x <= 1)
        return x;
    else
        return x + naturalSum(x - 1);
}
int main()
{
    cout << naturalSum(5);
}
*/
// 4 Sum of powers
/*
#include <iostream>
using namespace std;

int multiply(int x, int y)
{
    if (y)
        return (x + multiply(x, y - 1));
    else
        return 0;
}
int pow(int a, int b)
{
    if (b)
        return multiply(a, pow(a, b - 1));
    else
        return 1;
}
int main()
{
    cout << pow(2, 3);
}
*/

// With strings

// 1 Palindrome
/*
#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string s)
{
    int n = s.length() - 1;
    if (n == 0 || n == 1)
        return true;
    if (s[0] == s[n])
        return isPalindrome(s.substr(1, n - 1));
    return false;
}
int main()
{
    string s;
    cin >> s;
    if (isPalindrome(s) == true)
        cout << "YES";
    else
        cout << "NO";
}
*/
// 2 String reversal
/*
#include <iostream>
using namespace std;
string stringReversal(string s, int n)
{
    if (n < 0)
    {
        return "";
    }
    else
        return s[n] + stringReversal(s, n - 1);
}
int main()
{
    cout << stringReversal("abcd", 4);
}
*/
