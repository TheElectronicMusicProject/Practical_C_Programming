#define SIZE 20

int
main (void)
{
    int index;
    int data[SIZE];
    int twice[SIZE];

    for (index = 0; index < SIZE; ++index)
    {
        data[index] = index;
        twice[index] = 2 * index;
    }

    return (0);
}