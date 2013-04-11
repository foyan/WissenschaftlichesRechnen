#include<cmath>
#include<map>
#include<stdexcept>
#include<string>
#include<sstream>

#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

template<typename T>

class Matrix
{
    public:
        Matrix<T>(int cols, int rows) {
            this->_items = new map<int, T>();
            this->_cols = cols;
            this->_rows = rows;

            for (int i = 0; i < this->_cols * this->_rows; i++) {
                (*(this->_items))[i] = 0;
            }
        }

        virtual ~Matrix() {
            delete this->_items;
        }

        int get_index(int col, int row) {
            return this->_cols * row + col;
        }

        string to_string() {
            stringstream s;
            s << "[";
            string cdel = "";
            for (int r = 0; r < this->_rows; r++) {
                s << cdel;
                string rdel = "";
                for (int c = 0; c < this->_cols; c++) {
                    s << rdel << this->at(c, r);
                    rdel = ",";
                }
                cdel = ";";
            }
            s << "]";
            return s.str();
        }

        T at(int col, int row) {
            return this->at(this->get_index(col, row));
        }

        T at(int index) {
            return (*(this->_items))[index];
        }

        void set(int index, T value) {
            (*(this->_items))[index] = value;
        }

        void set(int col, int row, T value) {
            this->set(this->get_index(col, row), value);
        }

        Matrix scale(T factor) {
            Matrix result(this->_cols, this->_rows);
            for (int i = 0; i < this->_cols * this->_rows; i++) {
                result.set(i, this->at(i) * factor);
            }

            return result;
        }

        Matrix negate() {
            return this->scale(-1);
        }

        Matrix plus(Matrix &other) {
            if (this->_cols != other._cols || this->_rows != other._rows) {
                throw runtime_error("Matrix dimensions do not agree.");
            }

            Matrix result(this->_cols, this->_rows);
            for (int i = 0; i < this->_cols * this->_rows; i++) {
                result.set(i, this->at(i) + other.at(i));
            }

            return result;
        }

        Matrix minus(Matrix &other) {
            Matrix neg = other.negate();
            return this->plus(neg);
        }

        Matrix times(Matrix &other) {
            if (this->_cols != other._rows) {
                throw runtime_error("Matrix dimensions do not agree.");
            }

            Matrix result(other._cols, this->_rows);

            for (int i = 0; i < result._rows; i++) {
                for (int j = 0; j < result._cols; j++) {
                    T cij = 0;
                    for (int k = 0; k < this->_cols; k++) {
                        cij += this->at(k, i) * other.at(j, k);
                    }
                    result.set(j, i, cij);
                }
            }

            return result;
        }

        double norm() {
            double n = 0;
            for (int i = 0; i < this->_rows*this->_cols; i++) {
                n += (this->at(i) * this->at(i));
            }
            return sqrt(n);
        }

    private:
        map<int, T>* _items;
        int _cols;
        int _rows;

};

#endif // MATRIX_H
