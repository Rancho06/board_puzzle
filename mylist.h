#ifndef MY_LIST_H
#define MY_LIST_H
/*
    Copy your mylist.h file from PA2
*/
template<typename T> class MyList{
    private:
    T* ptr;
    int Size, Cap;
    public:
    MyList();
    ~MyList();
    void push_back(T);
    int size() const;
    T at(int) const;
    void remove(T val);
    void clear();
};

template<typename T> void MyList<T>::clear(){
	Size=0;
};


template<typename T> MyList<T>::MyList(){
    Size=0;
    Cap=10;
    ptr=new T[10];
};

template<typename T> MyList<T>::~MyList(){
    delete[] ptr;
};

template<typename T>void MyList<T>::push_back(T str){
    if (Size<Cap) {
        ptr[Size]=str;
        Size++;
    }
    else{
        T* ptr2;
        ptr2=new T[2*Size];
        for (int i=0; i<Size; i++) {
            ptr2[i]=ptr[i];
        }
        Cap*=2;
        delete[] ptr;
        ptr=ptr2;
        ptr[Size]=str;
        Size++;
    }
};

template<typename T>int MyList<T>::size() const{
    return Size;
};

template<typename T> T MyList<T>::at(int index) const{
    return ptr[index];
};

template<typename T> void MyList<T>::remove(T val){
	for(int i=0;i<Size;i++){
		if(ptr[i]==val){
			for(int k=i+1;k<Size;k++){
				ptr[k-1]=ptr[k];
			}
			Size--;
			return;
		}
	}
	return;
};


#endif
