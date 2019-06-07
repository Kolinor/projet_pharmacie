//---------------------------------------------------------------------------

#ifndef VectorH
#define VectorH
//---------------------------------------------------------------------------

template <class T> class Vector
{

	private:
		T * tab;
		unsigned long taille;
		unsigned long nombre;

		void reallocMem();

	public:
		Vector();
		unsigned long size();


		T& operator[](int pos);

		T pop_back();
		T pop_front();
		void push_back(T valeur);
		void push_front(T valeur);



};


template <typename T> void Vector<T>::reallocMem()
{
	taille *= 2;
	T * tmp = new T[taille];
	for(unsigned long i = 0 ; i < size(); i++)
	{
		tmp[i] = tab[i];
	}

	delete tab;
	tab = tmp;
	taille *= 2 ;
}

template <class T> Vector<T>::Vector()
{
	taille = 5;
	nombre = 0;
	tab = new T[taille];
}


template <class T> void Vector<T>::push_back(T valeur)
{
	if (nombre >= taille-1) {
		reallocMem();
	}

	unsigned long i = nombre;
	tab[i] = valeur;
	nombre++;


}

template <class T> void Vector<T>::push_front(T valeur)
{
	if (nombre+1 > taille) {
		reallocMem();
	}

	T * tmp = new T[taille+1];

	for (unsigned long i = 0; i < size(); i++) {
		tmp[i+1] = tab[i];
	}
	delete tab;
	tmp[0] = valeur;
	tab = tmp;
	nombre++;


}

template <class T> T Vector<T>::pop_back()
{
	return tab[nombre--];

}

template <class T> T Vector<T>::pop_front()
{
	T var = tab[0];

	T * tmp = new T[taille-1];
	for (unsigned long i = 0; i < size()-1; i++) {
		tmp[i] = tab [i+1];
	}
	delete tab;
	tab = tmp;
	nombre--;
	return var;

}

template <class T> T& Vector<T>::operator[](int pos)
{
	return tab[pos];
}

template <class T> unsigned long Vector<T>::size()
{
	return nombre;
}


#endif
