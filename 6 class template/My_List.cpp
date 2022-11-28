//#include "My_list.h"
//#include <functional>
//
//template<typename T>
//DLIST<T>::DLIST(std::ifstream& file, T elem)
//{
//	T elem;
//	file >> elem;
//	first_node<T>(elem);
//	ptrNODE<T> place;
//	while (!file.eof())
//	{
//		T elem; file >> elem;
//		place = find_place(begin, elem);
//		if (place)
//			add_before(place, elem);
//		else
//			add_after(end, elem);
//	}
//	file.close();
//}
//
//template<typename T>
//void DLIST<T>::first_node(T elem)
//{
//	begin = new NODE<T>(elem);
//	end = begin;
//}
//
//template<typename T>
//bool DLIST<T>::empty()
//{
//	return begin == nullptr;
//}
//
//template<typename T>
//ptrNODE<T> DLIST<T>::find_place(ptrNODE<T> begin,  T elem)
//{
//	ptrNODE<T> p = begin;
//	while (p && p->info.compare(elem) < 0)
//		p = p->next;
//	return p;
//}
//
//template<typename T>
//void DLIST<T>::add_after(ptrNODE<T> ptr,  T elem)
//{
//	ptrNODE p = new NODE<T>(elem, ptr->next, ptr);
//	if (ptr == end)
//		end = p;
//	else
//		ptr->next->prev = p;
//	ptr->next = p;
//}
//
//template<typename T>
//void DLIST<T>::add_before(ptrNODE<T> ptr,  T elem)
//{
//	ptrNODE p = new NODE<T>(elem, ptr->next, ptr);
//	if (ptr == end)
//		end = p;
//	else
//		ptr->next->prev = p;
//	ptr->next = p;
//}
//
//template<typename T>
//DLIST<T>::~DLIST()
//{
//	while (!empty())
//		Delete(begin);
//}
//
//template<typename T>
//ptrNODE<T>& DLIST<T>::del_after(ptrNODE<T>& ptr)
//{
//	ptrNODE tmp = ptr->next;
//	ptr->next = tmp->next;
//	if (!tmp->next)
//		end = ptr;
//	else
//		tmp->next->prev = ptr;
//	
//	static ptrNODE<T> a;
//	a = tmp->next;
//
//	delete tmp;
//	size--;
//	return a;
//}
//
//template<typename T>
//std::string DLIST<T>::to_string() const
//{
//	std::string result;
//	ptrNODE<T> ptr = begin;
//	while (ptr)
//	{
//		result += ptr->info + ' ';
//		ptr = ptr->next;
//	}
//	result += '\n';
//	return result;
//}
//
//template<typename T>
//ptrNODE<T>& DLIST<T>::del_before(ptrNODE<T>& ptr)
//{
//	ptrNODE<T> tmp = ptr->prev;
//	ptr->prev = tmp->prev;
//	if (!tmp->prev)
//		begin = ptr;
//	else
//		tmp->prev->next = ptr;
//
//	static ptrNODE<T> a;
//	a = tmp->next;
//
//	delete tmp;
//	size--;
//	return a;
//}
//
//template<typename T>
//ptrNODE<T>& DLIST<T>::Delete(ptrNODE<T>& ptr)
//{
//	ptrNODE p = ptr;
//	if (ptr == begin)
//	{
//		begin = p->next;
//		ptr = begin;
//		if (p->next)
//			p->next->prev = nullptr;
//	}
//	else
//		if (ptr == end)
//		{
//			end = p->prev;
//			ptr = end;
//			if (p->prev)
//				p->prev->next = nullptr;
//		}
//		else
//		{
//			ptr = ptr->next;
//			p->next->prev = p->prev;
//			p->prev->next = p->next;
//		}
//	static ptrNODE<T> a;
//	a = p->next;
//
//	delete p;
//	size--;
//	return a;
//}
