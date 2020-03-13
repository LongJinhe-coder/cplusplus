#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
// using namespace std::experimental::filesystem;
string local_path = "/home/longjinhe/Documents/cpp_document/homework4/";

const int fileNum = 16;
const int fileSize = 2048 * 2048;
const int INIT_N_ROW = fileSize;
int *expand(int *data, int rows, int more);

void generate(string local_path)
{
    srand((unsigned int)time(0));
    for (int i = 0; i < fileNum; i++)
    {
        clock_t start = clock();
        ofstream outfile(local_path + "cpp_" + std::to_string(i) + ".txt", ios::trunc);
        if (i < fileNum - 1)
        {
            for (int j = 0; j < fileSize; j++)
            {
                if (j == fileSize - 1)
                {
                    outfile << rand();
                }
                else
                {
                    outfile << rand() << '\t';
                }
            }
            outfile.close();
            clock_t end = clock();
            cout << (double)(end - start) / CLOCKS_PER_SEC << "s are spent on generating "
                 << "cpp_" << i << ".txt with " << fileSize << " numbers contained" << endl;
        }
        else
        {
            const int max = 1000, min = 100;
            int lastFilesize = fileSize - rand() % (max - min) + min;
            for (int j = 0; j < lastFilesize; j++)
            {
                if (j == lastFilesize - 1)
                {
                    outfile << rand();
                }
                else
                {
                    outfile << rand() << '\t';
                }
            } 
            outfile.close();
            clock_t end = clock();
            cout << (double)(end - start) / CLOCKS_PER_SEC << "s are spent on generating "
                 << "cpp_" << i << ".txt with " << lastFilesize << " numbers contained" << endl;
        }
    }
};

int partition(int *a, int low, int high)
{
    int index=a[low];
    int key = a[low];
    while (low<high)
    {
        while(low<high&&a[high]>=key)
        high--;
        a[low]=a[high];
        while (low<high&&a[low]<=key)
        low++;
        a[high]=a[low];
        
    }
    a[low]=index;
    return low;
};

void quick_sort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = partition(a, low, high);
        quick_sort(a, low, mid - 1);
        quick_sort(a, mid + 1, high);
    }
}

void sort(string local_path)
{
    for (int i = 0; i < fileNum; i++)
    {
        clock_t start = clock();
        cout << "sorting "
             << "cpp_" << i << ".txt now ..." << endl;
        int *data = new int[INIT_N_ROW];
        ifstream inflie(local_path + "cpp_" + std::to_string(i) + ".txt");
        int realRows = 0, allowedRows = INIT_N_ROW;
        while (!inflie.eof())
        {
            inflie >> data[realRows];
            realRows++;
            if (realRows >= allowedRows)
            {
                int *temp;
                if (!(temp = expand(data, realRows, INIT_N_ROW)))
                    break;
                else
                    data = temp;
                allowedRows += INIT_N_ROW;
            }
        }
 
        inflie.close();
        quick_sort(data, 0, realRows - 1);
        ofstream outflie(local_path + "cpp_" + std::to_string(i) + ".txt", ios::out);
        for (int j = 0; j < realRows; j++)
        {
            if (j == realRows - 1)
            {
                outflie << data[j];
            }
            else
            {
                outflie << data[j] << '\t';
            }
        }
        outflie.close();
        delete[] data;
        clock_t end = clock();
        cout << (double)(end - start) / CLOCKS_PER_SEC << "s has been spent on sorting "<<local_path
             << "cpp_" << i << ".txt" << endl;
    }
};

void merge(string local_path)
{
    int *allData = new int[INIT_N_ROW];
    int realRows = 0, allowedRows = INIT_N_ROW;
    clock_t start = clock();
    cout << "merging all documents now ..." << endl;
    for (int i = 0; i < fileNum; ++i)
    {
        ifstream inflie(local_path + "cpp_" + std::to_string(i) + ".txt");
        while (!inflie.eof())
        {
            inflie >> allData[realRows];
            realRows++;
            if (realRows >= allowedRows)
            {
                int *temp;
                if (!(temp = expand(allData, realRows, INIT_N_ROW)))
                    break;
                else
                    allData = temp;
                allowedRows += INIT_N_ROW;
            }
        }
        inflie.close();
    }
    quick_sort(allData, 0, realRows - 1);
    ofstream outflie(local_path + "cpp_" + std::to_string(fileNum) + ".txt", ios::trunc);
    for (int j = 0; j < realRows; ++j)
    {
        outflie << allData[j] << '\t';
    }

    outflie.close();
    clock_t end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << "s has been spent on merging and sorting all documents" << endl;
};

void print(string local_path)
{
    int printNum = 16, lastPrintNum = 256;
    int printData[printNum], lastPrintData[lastPrintNum];
    for (int i = 0; i <= fileNum; i++)
    {
        ifstream infile(local_path + "cpp_" + std::to_string(i) + ".txt");
        if (i < fileNum)
        {
            cout << "文件cpp_" << i << ".txt"
                 << " 前" << printNum << "个数据如下:" << endl;
            for (int j = 0; j < printNum; j++)
            {
                infile >> printData[j];
                cout.setf(ios_base::left);
                cout.width(12);
                if (j % 8 == 0 && j != 0)
                {
                    cout << endl;
                }
                cout << printData[j];
            }
            cout << endl;
        }
        else if (i == fileNum)
        {
            cout << "文件cpp_" << i << ".txt"
                 << " 前" << lastPrintNum << "个数据如下:" << endl;
            for (int j = 0; j < lastPrintNum; j++)
            {
                infile >> lastPrintData[j];
                cout.setf(ios_base::left, ios_base::adjustfield);
                cout.width(12);
                if (j % 8 == 0 && j != 0)
                {
                    cout << endl;
                }
                cout << lastPrintData[j];
            }
            cout << endl;
        }

        infile.close();
    }
};

int *expand(int *data, int rows, int more)
{
    int *temp = new int[rows + more];
    if (temp)
    { //allocation succeed
        for (int i = 0; i < rows; i++)
            *(temp + i) = *(data + i);
        delete[] data;
    }
    return temp;
}

int main()
{
    cout << "Step1:simulatingsamplesforexperiments\n";
    generate(local_path);
    cout << endl;
    cout << "Step2:sortingindividualdataunits\n";
    sort(local_path);
    cout << endl;
    cout << "Step3:mergingsort\n";
    merge(local_path);
    cout << endl;
    cout << "Step4:printingresultduesubmissionchecking\n";
    print(local_path);
}
