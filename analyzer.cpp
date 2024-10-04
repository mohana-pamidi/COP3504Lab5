#include <iostream>
#include "StringData.h"

int linear_search(std::vector<std::string> container, std::string element)
{
    for (int i = 0; i < container.size(); i++)
    {
        if (container[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(std::vector<std::string> container, std::string element)
{
    int lower_bound = 0;
    int upper_bound = container.size() -1;

    while (lower_bound <= upper_bound)
    {
        int mid = ((lower_bound + upper_bound) / 2);

        if (container[mid] == element){
            return mid;
        }
        else if (container[mid].compare(element) < 0){
            lower_bound = mid + 1;
        }
        else{
            upper_bound = mid - 1;
        }
    }
    return -1;
}


int main()
{
    std::vector<std::string> numbers = getStringData();
    std::chrono::system_clock::time_point start_time;
    std::chrono::system_clock::time_point end_time;
    std::chrono::duration<double> elapsed_time;
    int result = 0;

    std::string to_search_one = "not_here";

    start_time = std::chrono::system_clock::now();
    result = linear_search(numbers, to_search_one);
    end_time = std::chrono::system_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "The result of linear search for not_here is:" << result << std::endl;
    std::cout << "The time used of linear search for not_here is:" << elapsed_time << std::endl;
    std::cout << std::endl;


    start_time = std::chrono::system_clock::now();
    result = binary_search(numbers, to_search_one);
    end_time = std::chrono::system_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "The result of binary search for not_here is:" << result << std::endl;
    std::cout << "The time used of binary search for not_here is:" << elapsed_time << std::endl;
    std::cout << std::endl;

    std::string to_search_two = "mzzzz";

    start_time = std::chrono::system_clock::now();
    result = linear_search(numbers, to_search_two);
    end_time = std::chrono::system_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "The result of linear search for mzzzz is:" << result << std::endl;
    std::cout << "The time used of linear search for mzzzz is:" << elapsed_time << std::endl;
    std::cout << std::endl;

    start_time = std::chrono::system_clock::now();
    result = binary_search(numbers, to_search_two);
    end_time = std::chrono::system_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "The result of binary search for mzzzz is:" << result << std::endl;
    std::cout << "The time used of binary search for mzzzz is:" << elapsed_time << std::endl;
    std::cout << std::endl;


    std::string to_search_three = "aaaaa";

    start_time = std::chrono::system_clock::now();
    result = linear_search(numbers, to_search_three);
    end_time = std::chrono::system_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "The result of linear search for aaaaa is:" << result << std::endl;
    std::cout << "The time used of linear search for aaaaa is:" << elapsed_time << std::endl;
    std::cout << std::endl;

    start_time = std::chrono::system_clock::now();
    result = binary_search(numbers, to_search_three);
    end_time = std::chrono::system_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "The result of binary search for aaaaa is:" << result << std::endl;
    std::cout << "The time used of binary search for aaaaa is:" << elapsed_time << std::endl;
    std::cout << std::endl;
}

