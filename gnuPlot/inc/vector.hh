#pragma once


template <typename T, int SIZE>
class Vector
{
public:
    T value[SIZE];

    Vector<T,SIZE> operator+(Vector<T,SIZE> vec){
        Vector<T,SIZE> result;
        for(int i =0;i<SIZE;i++){
            result.value[i] = value[i] + vec.value[i];
        }
    }

    friend std::ostream &operator<<(std::ostream &stream, Vector<T, SIZE> vec)
    {

        for (int i = 0; i < SIZE; i++)
        {
            stream << vec.value[i] << " ";
        }
        stream << std::endl;
        return stream;
    }
    friend std::istream &operator>>(std::istream &stream, Vector<T, SIZE> &vec)
    {

        for (int i = 0; i < SIZE; i++)
        {
            stream >> vec.value[i];
        }

        return stream;
    }
};
