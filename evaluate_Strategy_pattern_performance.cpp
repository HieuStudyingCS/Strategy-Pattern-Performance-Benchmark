#include <bits/stdc++.h>
using namespace std;

class Sorter
{
public:
    void sort(int arr[], int n, const string &type)
    {
        if (type == "bubble")
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }
        else if (type == "selection")
        {
            for (int i = 0; i < n - 1; i++)
            {
                int minIdx = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] < arr[minIdx])
                    {
                        minIdx = j;
                    }
                }
                swap(arr[i], arr[minIdx]);
            }
        }
    }

    void print(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class SortStrategy
{
public:
    virtual ~SortStrategy() = default;
    virtual void sort(int arr[], int n) = 0;
};

class BubbleSort : public SortStrategy
{
public:
    void sort(int arr[], int n) override
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

class SelectionSort : public SortStrategy
{
public:
    void sort(int arr[], int n) override
    {
        for (int i = 0; i < n - 1; i++)
        {
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIdx])
                {
                    minIdx = j;
                }
            }
            swap(arr[i], arr[minIdx]);
        }
    }
};

class SortContext
{
private:
    SortStrategy *strategy;

public:
    SortContext(SortStrategy *s)
        : strategy(s)
    {
    }

    void setStrategy(SortStrategy *s)
    {
        strategy = s;
    }

    void execute(int arr[], int n)
    {
        if (strategy != nullptr)
        {
            strategy->sort(arr, n);
        }
    }

    void print(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

template <typename Callable>
double measureMilliseconds(Callable &&callable)
{
    const auto start = chrono::steady_clock::now();
    callable();
    const auto end = chrono::steady_clock::now();
    return chrono::duration<double, std::milli>(end - start).count();
}

template <typename Callable>
void runBenchmark(const string &label, const vector<int> &baseData, Callable &&callable)
{
    vector<int> data = baseData;
    const double duration = measureMilliseconds([&]()
                                                { callable(data.data(), static_cast<int>(data.size())); });

    cout << label << " | thoi gian: " << duration << " ms"
         << " | da sap xep: " << boolalpha << is_sorted(data.begin(), data.end()) << endl;
}

vector<int> generateData(int n, int seed = 42)
{
    mt19937 rng(seed);
    uniform_int_distribution<int> dist(0, 1000000);

    vector<int> data(n);
    for (int &value : data)
    {
        value = dist(rng);
    }
    return data;
}

int main()
{
    cout << "=== Vi du nho de kiem tra ket qua ===" << endl;

    int sample1[] = {5, 2, 9, 1, 3, 6, 7, 2, 7};
    int sample2[] = {5, 2, 9, 1, 3, 6, 7, 2, 7};
    int sample3[] = {5, 2, 9, 1, 3, 6, 7, 2, 7};
    int sample4[] = {5, 2, 9, 1, 3, 6, 7, 2, 7};
    int n = 9;

    Sorter sorter;
    sorter.sort(sample1, n, "bubble");
    sorter.print(sample1, n);
    sorter.sort(sample2, n, "selection");
    sorter.print(sample2, n);

    BubbleSort bubble;
    SelectionSort selection;
    SortContext context(&bubble);
    context.execute(sample3, n);
    context.print(sample3, n);
    context.setStrategy(&selection);
    context.execute(sample4, n);
    context.print(sample4, n);

    cout << endl
         << "=== Do thoi gian thuat toan tren du lieu lon ===" << endl;

    const vector<int> benchmarkData = generateData(3000);

    runBenchmark("Non-strategy | bubble", benchmarkData, [&](int *arr, int size)
                 { sorter.sort(arr, size, "bubble"); });

    runBenchmark("Non-strategy | selection", benchmarkData, [&](int *arr, int size)
                 { sorter.sort(arr, size, "selection"); });

    runBenchmark("Strategy | bubble", benchmarkData, [&](int *arr, int size)
                 {
        context.setStrategy(&bubble);
        context.execute(arr, size); });

    runBenchmark("Strategy | selection", benchmarkData, [&](int *arr, int size)
                 {
        context.setStrategy(&selection);
        context.execute(arr, size); });

    return 0;
}