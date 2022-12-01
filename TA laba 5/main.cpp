#include "Node1.cpp"
#include "List1.cpp"
#include "Node2.cpp"
#include "List2.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"

void Sort1(int size) {
    cout << "<==[Сортировка слиянием в односвязном списке]==>" << endl;

    List1<int>* lst = new List1<int>();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 20);

    for (int i = 0; i < size; i++)
        lst->PushBack(new Node1<int>(dist(gen)));

    cout << "Исходный массив:" << endl;
    lst->Show();

    auto start_time = std::chrono::steady_clock::now();

    lst->MergeSort();

    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    cout << "Отсортированный массив:" << endl;
    lst->Show();

    cout << "time: " << elapsed_ns.count() << "ns" << endl;
    cout << endl;
}
void Sort2(int size) {
    cout << "<==[Сортировка вставками в двухсвязном списке]==>" << endl;

    List2<int>* lst = new List2<int>();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 20);

    for (int i = 0; i < size; i++)
        lst->PushBack(new Node2<int>(dist(gen)));

    cout << "Исходный массив:" << endl;
    lst->Show();

    auto start_time = std::chrono::steady_clock::now();

    lst->InsertionSort();
    
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    cout << "Отсортированный массив:" << endl;
    lst->Show();

    cout << "time: " << elapsed_ns.count() << "ns" << endl;
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    int size = 13;

    Sort1(size);
    Sort2(size);
}
