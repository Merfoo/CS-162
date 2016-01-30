#ifndef LIST_H
#define LIST_H

#include <iostream>

template<class T>
class List
{
    public:
		List()
		{
			m_list = 0;
			m_length = 0;
			m_maxLength = 1;
		};

		List(const List<T>& rhs)
		{
			if (m_list != 0)
			{
				delete[] m_list;
				m_list = 0;
			}

			m_length = rhs.m_length;
			m_maxLength = rhs.m_maxLength;
			m_list = new T[m_maxLength];

			for (int i = 0; i < m_length; i++)
				m_list[i] = rhs.m_list[i];
		}

		~List()
		{
			if (m_list != 0)
			{
				delete[] m_list;
				m_list = 0;
			}
		}

		List<T>& operator=(const List<T>& rhs)
		{
			if (m_list != 0)
			{
				delete[] m_list;
				m_list = 0;
			}

			m_length = rhs.m_length;
			m_maxLength = rhs.m_maxLength;
			m_list = new T[m_maxLength];

			for (int i = 0; i < m_length; i++)
				m_list[i] = rhs.m_list[i];

			return *this;
		}

        void addItem(T item)
		{
			if (m_length >= m_maxLength || m_length == 0)
			{
				m_maxLength *= 2;
				T* list = new T[m_maxLength];

				/*for (int i = 0; i < m_maxLength; i++)
					list[i] = 0;*/

				for (int i = 0; i < m_length; i++)
					list[i] = m_list[i];

				delete[] m_list;
				m_list = list;
			}

			m_list[m_length] = item;
			m_length++;
		}

		void removeItem(int index)
		{
			if (m_length - 1 == m_maxLength / 2)
				m_maxLength /= 2;

			T* list = new T[m_maxLength];

			for (int i = 0; i < m_length; i++)
			{
				if (i == index)
					continue;

				if (i < index)
					list[i] = m_list[i];

				else
					list[i - 1] = m_list[i];
			}

			delete[] m_list;
			m_list = list;
			m_length--;
		}

		T getItem(int index)
		{
			return m_list[index];
		}

		void setItem(int index, T item)
		{
			m_list[index] = item;
		}

		void printList()
		{
			for (int i = 0; i < m_maxLength; i++)
				std::cout << m_list[i] << std::endl;
		}

		int getLength()
		{
			return m_length;
		}

    private:
        T* m_list;
        int m_length;
        int m_maxLength;
};

#endif // LIST_H
