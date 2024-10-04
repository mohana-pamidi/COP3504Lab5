#include "StringData.h"
#include <ctime>
#include <iostream>
#include <chrono>

int linear_search(std::vector<std::string> container, std::string element){


    for(int i = 0; i < container.size(); i++)

        //iterating through data in container

        if (element == container[i]){

            return i;

        }
        
    return -1;
}

int binary_search(std::vector<std::string> container, std::string element){
    int low = 0;
    int high = container.size() - 1;
    int middle = 0;
    std::string guess;

    while(low <= high){

        middle = (low + high) / 2 ;

        guess = container[middle];

        if (element > guess)
        {
            
            low = middle + 1;

        }
        else if(element < guess)
        {

            high = middle - 1;

        }
        else if(element == guess)
        {
            return middle;
        }

    }

    return -1;
}

int main(){
    std::chrono::system_clock::time_point beg_time; 
    std::chrono::system_clock::time_point end_time;
    std::chrono::duration<double> time_elapsed; 
    int index;

    //load data into container
    std::vector<std::string> container = getStringData();

    //element algorithm is searching for
    std::string element = "mzzzz";

    //start timer
    beg_time =  std::chrono::system_clock::now(); 

    index = linear_search(container, element);

    end_time = std::chrono::system_clock::now();

    time_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end_time - beg_time);
    //print out time it took to run

    std::cout<<"Linear searching " << element << " found at " << index << " in: " << time_elapsed.count() << std::endl;


    beg_time = std::chrono::system_clock::now();

    index = binary_search(container, element);

    end_time = std::chrono::system_clock::now();

    time_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end_time - beg_time);

    std::cout << "Binary searching " << element << " found at " << index << " in: " <<  time_elapsed.count() << std::endl;

}
