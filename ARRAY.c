#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

// Function prototypes
int *creating_1d_array(int n);
void display_1d_array(int *a, int n);
void finding_smallest_number_in_1d_array(int *a, int n);
void finding_largest_number_in_1d_array(int *a, int n);
void second_largest_element_in_1d_array(int *a, int n);
void forming_number();
void leaders_of_array(int *a, int n);
void swap(int *a, int *b);
void max_dif(int *a, int n);
void frequencies_in_array(int *a, int n);
bool check_if_sorted(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
        {
            return 0;
        }
    }
    return 1;
}
int max_profit(int *price, int start, int end);
void move_all_zeros_to_end(int *a, int n);
void reverse(int *a, int *n);
void finding_duplicates(int *arr, int n);
void insert_element(int *a, int *n);
void inserting_element_in_a_sorted_array(int *a, int *n);
void delete_element(int *a, int *n);
void deleting_element_in_a_sorted_array(int *a, int *n);
void left_rotate_an_array(int *a, int n);
void mergin_two_unsorted_array();
void sorted_array_merging();
int main()
{
    int t;
    printf("Enter number of test cases -> ");
    scanf("%d", &t);

    while (t--)
    {
        int c, n, *a;
        printf("\nEnter the choice which you want -> \n1) Inserting in array\n2) finding largest element\n3) finding second largest element\n4) finding smallest element\n5) finding duplicates\n6) forming number\n7) inserting element in a sorted array\n8) deleting an element\n9) deleting element in a sorted array\n10) left rotate the given array by k \n11) reverse array\n12) Merging two unsorted arrays\n13) merging sorted arrays\n14) move all zeros to end\n15) Leaders of an array\n16) Frequencies of all elements in array \n17) Max diff in array\n 18)Stock by and sell\n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            insert_element(a, &n);
            free(a); // Free the allocated memory
            break;

        case 2:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            finding_largest_number_in_1d_array(a, n);
            free(a); // Free the allocated memory
            break;

        case 3:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            finding_smallest_number_in_1d_array(a, n);
            free(a); // Free the allocated memory
            break;

        case 4:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            second_largest_element_in_1d_array(a, n);
            free(a); // Free the allocated memory
            break;

        case 5:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            finding_duplicates(a, n);
            free(a); // Free the allocated memory
            break;

        case 6:
            forming_number();
            free(a); // Free the allocated memory
            break;
        case 7:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            inserting_element_in_a_sorted_array(a, &n);
            free(a); // Free the allocated memory
            break;
        case 8:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            delete_element(a, &n);
            free(a); // Free the allocated memory
            break;
        case 9:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            deleting_element_in_a_sorted_array(a, &n);
            free(a); // Free the allocated memory
            break;
        case 10:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            left_rotate_an_array(a, n);
            free(a); // Free the allocated memory
            break;
        case 11:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            reverse(a, &n);
            free(a); // Free the allocated memory
            break;
        case 12:
            mergin_two_unsorted_array();
            free(a); // Free the allocated memory
            break;
        case 13:
            sorted_array_merging();
            free(a); // Free the allocated memory
            break;
        case 14:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            move_all_zeros_to_end(a, n);
            free(a); // Free the allocated memory
            break;
        case 15:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            leaders_of_array(a, n);
            free(a); // Free the allocated memory
            break;
        case 16:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            frequencies_in_array(a, n);
            free(a); // Free the allocated memory
            break;
        case 17:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            max_dif(a, n);
            free(a); // Free the allocated memory
            break;
        case 18:
            printf("Enter number of elements -> ");
            scanf("%d", &n);
            a = creating_1d_array(n);
            display_1d_array(a, n);
            int profit = max_profit(a, 0, n - 1);
            printf("THE MAX PROFIT IS -> %d", profit);
            free(a); // Free the allocated memory
            break;
        default:
            printf("\nInvalid choice\n");
            free(a); // Free the allocated memory
        }
    }

    return 0;
}

int *creating_1d_array(int n)
{
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("[%d] -> ", i + 1);
        scanf("%d", &a[i]);
    }
    return a;
}

void display_1d_array(int *a, int n)
{
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void finding_smallest_number_in_1d_array(int *a, int n)
{
    int smallest = INT_MAX, position_counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < smallest)
        {
            smallest = a[i];
            position_counter = i;
        }
    }
    printf("Smallest element -> %d at position -> %d\n", smallest, position_counter + 1);
}

void finding_largest_number_in_1d_array(int *a, int n)
{
    int largest = INT_MIN, position_counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
            position_counter = i;
        }
    }
    printf("Largest element -> %d at position -> %d\n", largest, position_counter + 1);
}

void second_largest_element_in_1d_array(int *a, int n)
{
    int largest = INT_MIN, position_counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
            position_counter = i;
        }
    }
    int second_largest = a[0];
    int second_largest_position = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != position_counter)
        {
            if (a[i] > second_largest)
            {
                second_largest = a[i];
                second_largest_position = i;
            }
        }
    }
    printf("Second largest element -> %d at position -> %d\n", second_largest, second_largest_position + 1);
}

void forming_number()
{
    int number_of_digits;
    printf("Enter number of digits: ");
    scanf("%d", &number_of_digits);

    int *a = creating_1d_array(number_of_digits);
    int number = 0;
    for (int i = 0; i < number_of_digits; i++)
    {
        number = number * 10 + a[i];
    }
    printf("The number is -> %d\n", number);
    free(a); // Free the allocated memory
}

void finding_duplicates(int *arr, int n)
{
    int found_duplicates = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                found_duplicates = 1;
                printf("Duplicates are found at positions -> %d, %d\n", i + 1, j + 1);
            }
        }
    }
    if (!found_duplicates)
    {
        printf("No duplicates found\n");
    }
}

void insert_element(int *a, int *n)
{
    int x;
    int position;
    printf("\nEnter the number you want to insert -> ");
    scanf("%d", &x);
    printf("Enter the position in which you want to insert -> ");
    scanf("%d", &position);

    for (int i = *n - 1; i >= position; i--)
    {
        a[i + 1] = a[i];
    }
    a[position] = x;
    *n += 1;

    printf("\nAfter insertion -> ");
    display_1d_array(a, *n);
}
void inserting_element_in_a_sorted_array(int *a, int *n)
{

    int x;
    printf("\nEnter the number you want to insert -> ");
    scanf("%d", &x);

    if (!check_if_sorted(a, *n))
    {
        printf("\nThe array is not sorted !!!\n");
        return;
    }

    int i = *n - 1;
    while (i >= 0 && a[i] > x)
    {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = x;
    (*n)++;

    printf("\nAfter insertion -> ");
    display_1d_array(a, *n);
}
void deleting_element_in_a_sorted_array(int *a, int *n)
{

    int x;
    printf("\nEnter the number you want to delete -> ");
    scanf("%d", &x);

    if (!check_if_sorted(a, *n))
    {
        printf("\nThe array is not sorted !!!\n");
        return;
    }

    int i = 0;
    while (i < *n && a[i] != x)
    {
        i++;
    }

    if (i == *n)
    {
        printf("\nElement %d not found in the array.\n", x);
        return;
    }

    for (int j = i; j < *n - 1; j++)
    {
        a[j] = a[j + 1];
    }

    (*n)--;

    printf("\nAfter deletion -> ");
    display_1d_array(a, *n);
}
void delete_element(int *a, int *n)
{
    int position;
    printf("Enter the position in which you want to delete -> ");
    scanf("%d", &position);

    for (int i = position; i < *n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    *n -= 1;

    printf("\nAfter deletion -> ");
    display_1d_array(a, *n);
}
void left_rotate_an_array(int *arr, int n)
{
    int d;
    printf("\nEnter by which number you want to rotate the array : ");
    scanf("%d", &d);
    int p = 1;
    while (p <= d)
    {
        int last = arr[0];
        for (int i = 1; i < n; i++)
        {
            arr[i - 1] = arr[i];
        }
        arr[n - 1] = last;
        p++;
    }
    printf("\nAfter rotating -> ");
    display_1d_array(arr, n);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int *a, int *n)
{

    for (int i = 0; i < *n / 2; i++)
    {
        swap(&a[i], &a[*n - i - 1]);
    }
    printf("\nAfter reversing -> ");
    display_1d_array(a, *n);
}
void mergin_two_unsorted_array()
{
    int n1, n2;
    printf("Enter the number of elements in ARRAY 1 : ");
    scanf("%d", &n1);
    printf("Enter the number of elements in ARRAY 2 : ");
    scanf("%d", &n2);
    int *a, *b, *result;
    result = (int *)malloc((n1 + n2) * sizeof(int));
    a = creating_1d_array(n1);
    b = creating_1d_array(n2);
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        result[k++] = a[i];
    }
    for (int i = 0; i < n2; i++)
    {
        result[k++] = b[i];
    }
    printf("\nAfter merging -> ");
    for (int i = 0; i < n1 + n2; i++)
    {
        printf(" %d ", result[i]);
    }
    free(a);
    free(b);
    free(result);
}
void sorted_array_merging()
{
    int n1, n2;
    printf("Enter the number of elements in ARRAY 1 : ");
    scanf("%d", &n1);
    printf("Enter the number of elements in ARRAY 2 : ");
    scanf("%d", &n2);
    int *a, *b, *result;
    result = (int *)malloc((n1 + n2) * sizeof(int));
    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    a = creating_1d_array(n1);
    b = creating_1d_array(n2);
    int k = 0, i = 0, j = 0;
    if (check_if_sorted(a, n1) && check_if_sorted(b, n2))
    {
        while (i < n1 && j < n2)
        {
            if (a[i] < b[j])
            {
                result[k++] = a[i++];
            }
            else
            {
                result[k++] = b[j++];
            }
        }
        if (i == n1)
        {
            while (j < n2)
            {
                result[k++] = b[j++];
            }
        }
        else if (j == n2)
        {
            while (i < n1)
            {
                result[k++] = a[i++];
            }
        }
    }
    printf("\nAfter merging -> ");
    for (int i = 0; i < n1 + n2; i++)
    {
        printf(" %d ", result[i]);
    }
    free(a);
    free(b);
    free(result);
}
void move_all_zeros_to_end(int *a, int n)
{
    /*      NAIVE APPROACH
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] != 0)
            {
                swap(&a[i], &a[j]);
            }
        }
    }
    */
    //    EFFICIENT APPROACH
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(&a[i], &a[counter]);
            counter++;
        }
    }
    printf("\nAfter moving -> ");
    display_1d_array(a, n);
}
void leaders_of_array(int *a, int n)
{ //    NAIVE SOLUTION
    // for (int i = 0; i < n; i++)
    // {
    //     bool flag = false;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] <= arr[j])
    //         {
    //             flag=true;
    //             break;
    //         }
    //     }
    //     if(flag==false)
    //     {
    //         cout<<arr[i]<<" ";
    //     }
    // }
    int current_leader = a[n - 1];
    printf(" %d ", current_leader);
    for (int i = n - 2; i >= 0; i--)
    {
        if (current_leader < a[i])
        {
            current_leader = a[i];
            printf(" %d ", current_leader);
        }
    }
}
void frequencies_in_array(int *a, int n)
{
    int freq = 1;
    int i = 1;
    while (i <= n)
    {
        while (i < n && a[i] == a[i - 1])
        {
            freq++;
            i++;
        }
        // cout << a[i - 1] << " " << freq << endl;
        printf("%d  -> %d\n", a[i - 1], freq);
        i++;
        freq = 1;
    }
    if (n == 1 && a[n - 1] != a[n - 2])
    {
        printf("%d  -> %d", a[i - 1], 1);
    }
}
void max_dif(int *a, int n)
{
    /* naive solution
    int result = a[1] - a[0];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            result = max(result, a[j] - a[i]);
        }
    }
    cout << result;
    */
    int result = a[1] - a[0];
    int min_value = a[0];
    for (int j = 1; j < n; j++)
    {
        result = fmax(result, a[j] - min_value);
        min_value = fmin(min_value, a[j]);
    }
    printf("\nresult -> %d\n", result);
    /*
    ANother apporach
    // Initialize Result
    int maxDiff = -1;

    // Initialize max element from right side
    int maxRight = arr[n-1];

    for (int i = n-2; i >= 0; i--)
    {
        if (arr[i] > maxRight)
            maxRight = arr[i];
        else
        {
            int diff = maxRight - arr[i];
            if (diff > maxDiff)
            {
                maxDiff = diff;
            }
        }
    }
    return maxDiff;
    */
}
int max_profit(int *price, int start, int end)
{
    // int start = 0, end = n - 1;
    if (end <= start)
    {
        return 0;
    }
    int profit = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (price[j] > price[i])
            {
                // int current_profit = price[j] - price[i] + max_profit(price, start, i - 1) + max_profit(price, j + 1, end);
                // profit = max(profit, current_profit);
                int current_profit = price[j] - price[i] + max_profit(price, start, i - 1) + max_profit(price, j + 1, end);
                profit = fmax(profit, current_profit);
            }
        }
    }
    return profit;
    /*      Efficient solution
    int max_profit_efficient(int *price, int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (price[i] > price[i - 1])
        {
            profit += price[i] - price[i - 1];
        }
    }
    return profit;
}*/
}