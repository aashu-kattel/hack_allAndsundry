#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int n;
    cout << "enter array size" << endl;
    cin >> n;
    int a[n];
    cout << "enter elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) //since last element will already be sorted so n-1
    {
        int min_index = i; // here i= sorted part, j=unsorted part
        for (int j = i; j <= n - 1; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j; //we can swap here as well, but swapping is expensive, so we do it just once after loops
            }
        }
        swap(a[i], a[min_index]);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " , " << endl;
        }
    }
}
