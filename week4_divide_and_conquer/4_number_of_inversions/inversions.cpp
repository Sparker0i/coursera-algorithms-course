#include <iostream>
#include <vector>

using std::vector;

int merge(vector<int> arr, vector<int> temp, int left, int mid, int right)
{
    int i, j, k;
    int count_of_inversions = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            count_of_inversions = count_of_inversions + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return count_of_inversions;
}

long long merge_sort(vector<int> arr, vector<int> temp, int left, int right)
{
    int mid;
    long long count_of_inversions = 0;
    if (right > left)
    {
        mid = (left + right)/2;

        count_of_inversions += merge_sort(arr, temp, left, mid);
        count_of_inversions += merge_sort(arr, temp, mid + 1, right);

        count_of_inversions += merge(arr, temp, left, mid + 1, right);
    }
    return count_of_inversions;
}

int main(int argv, char** args)
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    vector<int> temp(n);
    std::cout << merge_sort(a, temp, 0, n - 1) << std::endl;
    return 0;
}
