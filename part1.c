#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * file;
    file = fopen("input", "r");

    int max = 0;
    char boardingpass[10];
    while (fgets(boardingpass, 11, file))
    {
        if (boardingpass[0] != '\n')
        {
            int rowmin = 0; int rowmax = 127;
            int columnmin = 0; int columnmax = 7;
            for (size_t i = 0; i < strlen(boardingpass); i++)
            {
                    if (boardingpass[i] == 'F') { rowmax -= (rowmax - rowmin) / 2 + 1; }
                    if (boardingpass[i] == 'B') { rowmin += (rowmax - rowmin) / 2 + 1; }
                    if (boardingpass[i] == 'L') { columnmax -= (columnmax - columnmin) / 2 + 1; }
                    if (boardingpass[i] == 'R') { columnmin += (columnmax - columnmin) / 2 + 1; }
            }
            if (boardingpass[6] == 'F') { rowmax = rowmin; }
            if (boardingpass[9] == 'L') { columnmax = columnmin; }

            printf("%s\t%d\t%d\t%d\n", boardingpass, rowmax, columnmax, (rowmax * 8 + columnmax));

            if (max < (rowmax * 8 + columnmax)) { max = rowmax * 8 + columnmax; }
        }
    }
    
    printf("highest seat id: %d\n", max);

    return 0;
}
