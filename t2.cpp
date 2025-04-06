// 566
#include <iostream>
#include <cmath>
#include <ctime>

int **genrateMatrix(int &n, int &m)
{
    std::cout << "Enter 'N' size of mathix: ";
    std::cin >> n;

    std::cout << "Enter 'M' size of mathix: ";
    std::cin >> m;

    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }

    return matrix;
}

void outputMatrix(int **MM, int n, int m)
{
    std::cout << "Matrix: " << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << MM[i][j] << ' ';
        }
        std::cout << "\n";
    }
}

int* flatMatrix(int **matr, int n, int m)
{
    int *falttenedMatrix = new int[n * m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int index = i * m + j;
            falttenedMatrix[index] = matr[i][j];
        }
    }
    
    return falttenedMatrix;
}

int **genrateReMatrix(int **MM, int n, int m, int &reN, int &reM)
{
    int *flattenedMatrix = flatMatrix(MM, n, m);

    do
    {
        std::cout << "Enter new 'N' size of mathix: ";
        std::cin >> reN;
        std::cout << "Enter new 'M' size of mathix: ";
        std::cin >> reM;

        if (reM * reN != n * m)
        {
            std::cout << "Input valid values, (NxM ~ new NxM)";
        }
    } while (reM * reN != n * m);

    int **reMatrix = new int *[reN];
    for (int i = 0; i<reN; i++) {
        reMatrix[i]=new int[reM];
    }


    for(int i=0; i<reN; i++){
        for(int j=0; j<reM; j++) {
            reMatrix[i][j] = flattenedMatrix[i*reM+j];
        }
    }

    delete[] flattenedMatrix;
    return reMatrix;
}

int main()
{
    int **MM, **rMM;
    int mSize{0}, nSize{0}, reMSize{0}, reNSize{0};
    MM = genrateMatrix(nSize, mSize);
    outputMatrix(MM, nSize, mSize);
    rMM = genrateReMatrix(MM,nSize,mSize, reNSize, reMSize);
    outputMatrix(rMM, reNSize, reMSize);


    return 0;
}
