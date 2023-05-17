#include <iostream>

const int generations = 200;
const int width = 200;

const int ruleset[] = {0, 1, 0, 1, 1, 0, 1, 0};

int rules(int cell1, int cell2, int cell3)
{
    if (cell1 && cell2 && cell3) return ruleset[0];
    else if (cell1 && cell2 && !cell3) return ruleset[1];
    else if (cell1 && !cell2 && cell3) return ruleset[2];
    else if (cell1 && !cell2 && !cell3) return ruleset[3];
    else if (!cell1 && cell2 && cell3) return ruleset[4];
    else if (!cell1 && cell2 && !cell3) return ruleset[5];
    else if (!cell1 && !cell2 && cell3) return ruleset[6];
    else if (!cell1 && !cell2 && !cell3) return ruleset[7];
    return 0;
}

void visualize(int cells[], char* visualization)
{
    for (int i = 1; i < width - 1; i++)
    {
        if (cells[i]) visualization[i] = '#';
        else visualization[i] = ' ';
    }

    visualization[0] = '@';
    visualization[width - 1] = '@';
}

void initializeArray(int* arr, int width)
{
    for (int i = 0; i < width; i++)
    {
        arr[i] = 0;
    }

    arr[width / 2] = 1;
}

int main()
{
    int *cells = new int[width];
    int *tempCells = new int[width];
    
    initializeArray(cells, width);
    initializeArray(tempCells, width);

    char thing[width];
    visualize(cells, thing);
    std::cout.write(thing, width);
    std::cout << std::endl;

    for (int i = 0; i < generations; i++)
    {
        for (int cell = 1; cell < width - 1; cell++)
        {
            tempCells[cell] = rules(cells[cell - 1], cells[cell], cells[cell + 1]);
        }
        std::copy(tempCells, tempCells + width, cells);

        visualize(cells, thing);
        std::cout.write(thing, width);
        std::cout << std::endl;
    }

    delete[] cells;
    delete[] tempCells;

    return 0;
}
