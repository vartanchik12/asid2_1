#include <bintree.h>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <iomanip>


using namespace std;


size_t lcg(size_t& i) {
    return (i * 1021 + 24631) % 116640;
}


int main() {

    BinSearchTree<int> setbin;

    auto begin = std::chrono::steady_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 10000; i++)
            setbin.insert(lcg(i));
    auto end = std::chrono::steady_clock::now();

    auto insert_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Average time for insert 10 000: " << std::fixed << std::setprecision(5) << static_cast<double>(insert_time.count()) / 100 << " ms\n";

    begin = std::chrono::steady_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 10000; i++) {
            setbin.insert(lcg(i));
            setbin.contains(lcg(i));
        }
    end = std::chrono::steady_clock::now();
    auto contains_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin) - insert_time;
    std::cout << "Average time for search 10 000: " << std::fixed << std::setprecision(5) << static_cast<double>(contains_time.count()) / 100 << " ms\n";

    begin = std::chrono::steady_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 10000; i++) {
            setbin.insert(lcg(i));
            setbin.erase(lcg(i));
        }
    end = std::chrono::steady_clock::now();
    auto erase_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin) - insert_time;
    std::cout << "Average time for erase 10 000: " << std::fixed << std::setprecision(5) << static_cast<double>(erase_time.count()) / 100 << " ms\n";



    vector<int> v1000, v10000, v100000;

    begin = std::chrono::steady_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 1000; i++)
            v1000.erase(std::remove(v1000.begin(), v1000.end(), lcg(i)), v1000.end());
    end = std::chrono::steady_clock::now();
    insert_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Average time for find 1 000: " << std::fixed << std::setprecision(5) << static_cast<double>(insert_time.count()) / 100 << " ms\n";

    begin = std::chrono::steady_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 10000; i++)
            v1000.erase(std::remove(v1000.begin(), v1000.end(), lcg(i)), v1000.end());
    end = std::chrono::steady_clock::now();
    insert_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Average time for find 10 000: " << std::fixed << std::setprecision(5) << static_cast<double>(insert_time.count()) / 100 << " ms\n";

    begin = std::chrono::steady_clock::now();
    for (size_t j = 0; j < 100; j++)
        for (size_t i = 0; i < 100000; i++)
            v1000.erase(std::remove(v1000.begin(), v1000.end(), lcg(i)), v1000.end());
    end = std::chrono::steady_clock::now();
    insert_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Average time for find 100 000: " << std::fixed << std::setprecision(5) << static_cast<double>(insert_time.count()) / 100 << " ms\n";

}



/*Binary tree
Average time for insert 1000: 0.09000 ms
Average time for insert 10000: 1.01000 ms
Average time for insert 100000: 12.35000 ms

Average time for search 1000: 0.08000 ms
Average time for search 10000: 0.90000 ms
Average time for search 100000: 6.06000 ms

Average time for erase 1000: 0.08000 ms
Average time for erase 10000: 0.7000 ms
Average time for erase 100000: 4.37000 ms

Vector
Average time for insert 1000: 0.03000 ms
Average time for insert 10000: 0.33000 ms
Average time for insert 100000: 3.97000 ms

Average time for search 1000: 0.21000 ms
Average time for search 10000: 2.03000 ms
Average time for search 100000: 18.44000 ms

Average time for erase 1000: 0.45000 ms
Average time for erase 10000: 4.40000 ms
Average time for erase 100000: 35.50000 ms
*/