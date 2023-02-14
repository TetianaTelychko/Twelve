#ifndef ITEA_TWELVE_H
#define ITEA_TWELVE_H
#include <iostream>
#include <unistd.h>
#include <vector>
using namespace std;

class Twelve {
private:
    std::vector<int> m_vector;
    int m_size;

    static void shakerSort(std::vector<int> &vec){
        int left = 0;
        int right = vec.size() - 1;
        while(left <= right){
            for(int i = right; i > left; --i){
                if(vec[i] < vec[i - 1]){
                    std::swap(vec[i], vec[i - 1]);
                }
            }
            ++left;

            for(int i = left; i < right; ++i){
                if(vec[i] > vec[i + 1]){
                    std::swap(vec[i], vec[i + 1]);
                }
            }
            --right;
        }
    }

public:
    Twelve();
    Twelve(int size);

    void show();
    void quickShowing();
    void editVector(int index);
    std::vector<int>& getVector();

    static int getCommon(Twelve &twelve1, Twelve &twelve2){
        std::vector<int> buffer1 = twelve1.getVector();
        std::vector<int> buffer2 = twelve2.getVector();
        shakerSort(buffer1);
        shakerSort(buffer2);
        int common = 0;
        for(int i1 = 0, i2 = 0; (i1 < 12) && (i2 < 12); ){
            if(buffer1[i1] == buffer2[i2]){
                ++common;
                ++i1;
                ++i2;
            }
            else if(buffer1[i1] < buffer2[i2]){
                ++i1;
            }
            else{
                ++i2;
            }
        }
        return common;
    }
};


#endif //ITEA_TWELVE_H
