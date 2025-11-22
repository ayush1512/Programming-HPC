#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

void add_thread_part(const vector<float> &A, const vector<float> &B, vector<float> &C, size_t start, size_t end)
{
    for (size_t i = start; i < end; ++i)
    {
        C[i] = A[i] + B[i];
    }
}

int main()
{
    const size_t N = 100000000;
    const size_t num_threads_in_this_sys = std::thread::hardware_concurrency();
    vector<float> A(N, 1.0f), B(N, 2.0f), C(N);

    vector<thread> threads; // Creating a thread pool
    size_t per_thread_data = N / num_threads_in_this_sys;
    auto start = chrono::high_resolution_clock::now();

    for (size_t t = 0; t < num_threads_in_this_sys; ++t)
    {
        size_t s = t * per_thread_data;
        size_t e = (t == num_threads_in_this_sys - 1) ? N : s + per_thread_data;

        threads.emplace_back(add_thread_part, cref(A), cref(B), ref(C), s, e);
    }

    for (auto &&th : threads)
    { // & => l-value-reference, && => r-value-reference
        th.join();
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> diff = end - start;
    cout << "Multi-threaded duration: with threads of < " << num_threads_in_this_sys << "> =>" << diff.count() << "s" << endl;

    cout << "Total threads: " << num_threads_in_this_sys << endl;
}