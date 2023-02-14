#include "Twelve.h"

Twelve::Twelve() : m_size{12}
{
    m_vector.reserve(m_size);
}

inline int number(){
    return rand() % 90 + 10;
}
Twelve::Twelve(int size) : m_size{12}
{
    m_vector.reserve(m_size);
    for(int i = 0; i < m_size; ++i){
        m_vector.push_back(number());
    }
}

void Twelve::show() {
    unsigned int microseconds = 20 * 1000000;
    unsigned int delay = microseconds / m_size;
    for(int i = 0; i < m_size; ++i){
        if(i % 4 == 0)
            cout << '\n';
        cout << m_vector[i] << '\t';
        cout.flush();
        usleep(delay);
    }
    cout << '\n';
}

void Twelve::editVector(int index) {
    if((index >= 0) && (index < m_size)){
        cout << "Введіть значення для елемента з індексом " << index << " : ";
        int value;
        cin >> value;
        m_vector[index] = value;
        cout << "Вектор відредаговано!\n";
    }
}

vector<int>& Twelve::getVector() {
    return m_vector;
}

void Twelve::quickShowing() {
    for(int i = 0; i < m_size; ++i){
        cout << m_vector[i] << ' ';
    }
    cout << "\n";
}

