#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book
{
    int id;
    char title[50];
    char author[50];
};

struct Book books[MAX];
int count = 0;

/* Add Book */
void addBook()
{
    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);

    getchar();

    printf("Enter Book Title: ");
    fgets(books[count].title, sizeof(books[count].title), stdin);

    printf("Enter Author Name: ");
    fgets(books[count].author, sizeof(books[count].author), stdin);

    count++;

    printf("Book Added Successfully!\n");
}

/* Display Books */
void displayBooks()
{
    if(count == 0)
    {
        printf("\nNo Books Available!\n");
        return;
    }

    printf("\n===== BOOK LIST =====\n");

    for(int i = 0; i < count; i++)
    {
        printf("\nBook %d\n", i + 1);
        printf("ID     : %d\n", books[i].id);
        printf("Title  : %s", books[i].title);
        printf("Author : %s", books[i].author);
    }
}

/* Swap */
void swap(struct Book *a, struct Book *b)
{
    struct Book temp = *a;
    *a = *b;
    *b = temp;
}

/* Partition for Quick Sort */
int partition(int low, int high)
{
    int pivot = books[high].id;
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(books[j].id < pivot)
        {
            i++;
            swap(&books[i], &books[j]);
        }
    }

    swap(&books[i + 1], &books[high]);

    return i + 1;
}

/* Quick Sort */
void quickSort(int low, int high)
{
    if(low < high)
    {
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

/* Binary Search */
int binarySearch(int key)
{
    int left = 0;
    int right = count - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(books[mid].id == key)
            return mid;

        if(books[mid].id < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

/* Search Book */
void searchBook()
{
    if(count == 0)
    {
        printf("\nNo Books Available!\n");
        return;
    }

    int id;

    quickSort(0, count - 1);

    printf("\nEnter Book ID to Search: ");
    scanf("%d", &id);

    int index = binarySearch(id);

    if(index == -1)
    {
        printf("Book Not Found!\n");
    }
    else
    {
        printf("\nBook Found!\n");
        printf("ID     : %d\n", books[index].id);
        printf("Title  : %s", books[index].title);
        printf("Author : %s", books[index].author);
    }
}

/* Main Function */
int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Sort Books (Quick Sort)\n");
        printf("4. Search Book (Binary Search)\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                if(count == 0)
                {
                    printf("No Books Available!\n");
                }
                else
                {
                    quickSort(0, count - 1);
                    printf("Books Sorted Successfully by ID!\n");
                }
                break;

            case 4:
                searchBook();
                break;

            case 5:
                printf("Program Ended.\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
