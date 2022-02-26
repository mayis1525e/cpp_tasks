#include <iostream>

template<class T>
class Vectr{
private:
	int m_size;
	int m_cap;
	T* m_arr;

	void copy() {
		T* tmp = new T[m_cap];
		for(int i = 0; i < m_size; i++){
			tmp[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = tmp;
	}	

	void copy(T* tmp) {
		m_arr = new T[m_cap];
		for(int i = 0; i < m_size; i++){
			m_arr[i] = tmp[i];
		}
	}


public:
	Vectr(const Vectr &obj) {
		m_size = obj.m_size;
		m_cap = obj.m_cap;
		copy(obj.m_arr);
	}

	Vectr& operator=(const Vectr& obj){
		m_size = obj.m_size;
		m_cap = obj.m_cap;
		copy(obj.m_arr);
		return *this;
	}

	Vectr() {
		m_size = 0;
		m_cap = 1;
		m_arr = new T[m_cap];
	}
	~Vectr() {
		delete[] m_arr;
	}

	void push_back(T element) {
		m_arr[m_size] = element;
		++m_size;
		if (m_size == m_cap) {
			m_cap *= 2;
			copy();
		}
	}

	void pop_back() {
		m_arr[m_size] = 0;
		--m_size;
		if (!empty() && (m_size <= m_cap/2)) {
			m_cap /= 2;
			copy();
		}
	}

	void push_front(T element) {
		++m_size;
		if (m_size == m_cap) {
			m_cap *= 2;
			T* tmp = new T[m_cap];
			tmp[0] = element;
			for(int i = 1; i < m_size; i++){
				tmp[i] = m_arr[i-1];
			}
			delete[] m_arr;
			m_arr = tmp;
		} else {
			T* tmp = new T[m_cap];
			tmp[0] = element;
			for(int i = 1; i < m_size; i++){
				tmp[i] = m_arr[i-1];
			}
			delete[] m_arr;
			m_arr = tmp;
		}
	}

	void pop_front() {
                --m_size;
                if (!empty() && (m_size <= m_cap/2)) {
                        m_cap /= 2;
                        T* tmp = new T[m_cap];
                        for(int i = 0; i < m_size; i++){
                                tmp[i] = m_arr[i+1];
                        }
                        delete[] m_arr;
                        m_arr = tmp;
                } else {
                        T* tmp = new T[m_cap];
                        for(int i = 0; i < m_size; i++){
                                tmp[i] = m_arr[i+1];
                        }
                        delete[] m_arr;
                        m_arr = tmp;
                }

        }

	void insert(T element, int insert_index){
		if(insert_index <= m_size){
			++m_size;
			T* tmp = new T[m_cap];
			for(int i = 0, j = 0; i < m_size; i++, j++){
				if(insert_index == i){
					tmp[i] = element;
					j--;
					continue;
				}
				tmp[i] = m_arr[j];

			}
			delete[] m_arr;
			m_arr = tmp;
			if (m_size == m_cap) {
				m_cap *= 2;
				copy();
			}
		}

	}

	void insert(T* arr, int size, int insert_index){
		if(insert_index <= m_size && insert_index >= 0){
			m_size += size;
			if(m_cap <= m_size){
				m_cap = (m_size + 1);
			}
			T* tmp = new T[m_cap];
			for(int i = 0, j = 0; i < m_size; i++, j++){
				if(insert_index == i){
					for(int k = 0; k < size; k++, i++){ 
						tmp[i] = arr[k];
					}
					--i;
					--j;
					continue;
				}
				tmp[i] = m_arr[j];
			}
			delete[] m_arr;
			m_arr = tmp;
			if (m_size == m_cap) {
				m_cap *= 2;
				copy();
			}

		}
	}

	void erase(int sum_del_elem, int index){
		if(sum_del_elem + index <= m_size && index >= 0){
			m_size -= sum_del_elem;
			m_cap -=sum_del_elem;
			T* tmp = new T[m_cap];
			for(int i = 0, j = 0; i < m_size; i++, j++){
				tmp[i] = m_arr[j];
				if(i == index){
					j += sum_del_elem;
				}
			}
		}
	}

	int size(){
		return m_size;
	}

	bool empty(){
		return !m_size;
	}

	T& operator[](int index){
		return m_arr[index];
	}

};




int main(){
	Vectr<int> vector;
	Vectr<int> vector1;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	vector.push_back(6);

	//vector[4] = 17;

	//vector.pop_back();
	//vector.pop_back();
	
	//vector.push_front(15);
	//vector.push_front(16);

	//vector.insert(99,3);	
	//vector.insert(99,5);	
	//vector.insert(99,0);	
	
	int arr[5] = {51,52,53,54,55};
	
	vector.insert(arr,5,6); // (insert array, size of array, index of first insert element)

	vector.erase(3,6);   // (sum of delete elements, index of first delete element

	//vector.pop_front();
	
	Vectr<int> vector2 = vector1 = vector;	

	std::cout << "vector is empty ->" << std::boolalpha << vector.empty() << std::endl;
	std::cout << "vector size is -> " << vector.size() << std::endl;

	for(int i = 0; i < vector.size(); i++){
		std::cout << "vector2 " << i << " index element is -> "<< vector[i] << std::endl;
	}

	return 0;

}



