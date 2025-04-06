//599

#include <iostream>
#include <string>

//идея сворована у михаила но я чуть-чуть додумал
 

std::string* findMinIndexSum(std::string word1[], int size1, std::string word2[], int size2, int* resultSize)
{
    int maxPossible = size1 < size2 ? size1 : size2;
    std::string* result = new std::string[maxPossible];
    int resultIndex = 0;
    int minIndexSum = 2147483647;
    
    for (int i = 0; i < size1; ++i)
    {
        for (int j = 0; j < size2; ++j)
        {
            if (word1[i] == word2[j])
            {
                int currentSum = i + j;
                if (currentSum < minIndexSum)
                {
                    minIndexSum = currentSum;
                    resultIndex = 0;
                    result[resultIndex++] = word1[i];
                }
                else if (currentSum == minIndexSum)
                {
                    result[resultIndex++] = word1[i];
                }
            }
        }
    }
    
    *resultSize = resultIndex;
    return result;
}

void printResults(std::string results[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << results[i];
        if (i < count - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

void getWordLists(std::string** list1, int* size1, std::string** list2, int* size2)
{
    std::cout << "Get quantity of words in list: ";
    std::cin >> *size1;
    
    *list1 = new std::string[*size1];
    std::cout << "Get the words:" << std::endl;
    for (int i = 0; i < *size1; ++i)
    {
        std::cin >> (*list1)[i];
    }
    
    std::cout << "Get quantity of words in list: ";
    std::cin >> *size2;
    
    *list2 = new std::string[*size2];
    std::cout << "Get the words:" << std::endl;
    for (int i = 0; i < *size2; ++i)
    {
        std::cin >> (*list2)[i];
    }
}

int main()
{
    std::string *list1, *list2;
    int count1 = 0, count2 = 0;
    int resultCount = 0;

    getWordLists(&list1, &count1, &list2, &count2);
    
    std::string* commonWords = findMinIndexSum(list1, count1, list2, count2, &resultCount);
    
    std::cout << "Common: ";
    printResults(commonWords, resultCount);
    delete[] commonWords;
    delete[] list1;
    delete[] list2;
    
    return 0;
}