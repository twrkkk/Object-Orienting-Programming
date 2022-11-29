#pragma once
#include <iostream>
#include <fstream>
#include <string>

template<typename T>
class DLIST
{
private:
	struct NODE
	{
		T info;
		NODE* next, * prev;
		NODE(T info, NODE* next = nullptr, NODE* prev = nullptr) :info(info), next(next), prev(prev) {}
		~NODE()
		{
			next = nullptr;
			prev = nullptr;
		}
	};
	using ptrNODE = NODE*;

	ptrNODE begin, end;
	size_t size;
public:
	DLIST() { begin = nullptr; end = nullptr; }
	DLIST(std::ifstream& file)
	{
		T elem;
		file >> elem;
		first_node(elem);
		ptrNODE place;
		while (!file.eof())
		{
			T elem; file >> elem;
			/*place = find_place(begin, elem);
			if (place)
				add_before(place, elem);
			else
				add_after(end, elem);*/
			add_after(end, elem);
		}
		file.close();
	};
	~DLIST()
	{
		while (size != 0)
			Delete(begin);
	};

	void first_node(T elem)
	{
		begin = new NODE(elem);
		end = begin;
	};
	bool empty()
	{
		return begin == nullptr;
	};
	ptrNODE find_place(ptrNODE begin, T elem)
	{
		ptrNODE p = begin;
		while (p && p->info < elem)
			p = p->next;
		return p;
	};
	void add_after(ptrNODE ptr, T elem)
	{
		ptrNODE p = new NODE(elem, ptr->next, ptr);
		if (ptr == end)
			end = p;
		else
			ptr->next->prev = p;
		ptr->next = p;
	};
	void add_before(ptrNODE ptr, T elem)
	{
		ptrNODE p = new NODE(elem, ptr->next, ptr);
		if (ptr == end)
			end = p;
		else
			ptr->next->prev = p;
		ptr->next = p;
	};

	DLIST merge(const DLIST& another_list)
	{
		static DLIST<T> new_list;
		new_list.first_node(begin->info);
		ptrNODE beg = begin->next;
		while (beg != end->next)
		{
			new_list.add_after(new_list.get_end(), beg->info);
			beg = beg->next;
		}

		beg = another_list.get_begin();
		while (beg != another_list.get_end()->next)
		{
			new_list.add_after(new_list.get_end(), beg->info);
			beg = beg->next;
		}

		return new_list;
	}
	DLIST merge_sorted(const DLIST& another_list)
	{
		static DLIST<T> new_list;
		new_list.first_node(begin->info);
		ptrNODE first = get_begin()->next, second = another_list.get_begin();
		while (first && second)
		{
			T elem;
			if (first->info > second->info)
			{
				elem = second->info;
				second = second->next;
			}
			else
			{
				elem = first->info;
				first = first->next;
			}
			new_list.add_after(new_list.get_end(), elem);
		}
		while (first)
		{
			new_list.add_after(new_list.get_end(), first->info);
			first = first->next;
		}
		while (second)
		{
			new_list.add_after(new_list.get_end(), second->info);
			second = second->next;
		}
		return new_list;
	};

	ptrNODE& Delete(ptrNODE& ptr)
	{
		ptrNODE p = ptr;
		if (ptr == begin)
		{
			begin = p->next;
			ptr = begin;
			if (p && p->next && size != 0)
				p->next->prev = nullptr;
		}
		else
			if (ptr == end)
			{
				end = p->prev;
				ptr = end;
				if (p->prev)
					p->prev->next = nullptr;
			}
			else
			{
				ptr = ptr->next;
				p->next->prev = p->prev;
				p->prev->next = p->next;
			}
		static ptrNODE a;
		a = p->next;

		delete p;
		size--;
		return a;
	};
	ptrNODE& del_before(ptrNODE& ptr)
	{
		ptrNODE tmp = ptr->prev;
		ptr->prev = tmp->prev;
		if (!tmp->prev)
			begin = ptr;
		else
			tmp->prev->next = ptr;

		static ptrNODE a;
		a = tmp->next;

		delete tmp;
		size--;
		return a;
	};
	ptrNODE& del_after(ptrNODE& ptr)
	{
		ptrNODE tmp = ptr->next;
		ptr->next = tmp->next;
		if (!tmp->next)
			end = ptr;
		else
			tmp->next->prev = ptr;

		static ptrNODE a;
		a = tmp->next;

		delete tmp;
		size--;
		return a;
	};

	ptrNODE get_begin() const
	{
		return begin;
	}
	ptrNODE get_end() const
	{
		return end;
	}
	size_t get_size() const
	{
		return size;
	}

	void set_begin(ptrNODE _begin)
	{
		begin = _begin;
	}
	void set_end(ptrNODE _end)
	{
		end = _end;
	}
	void set_size(size_t _size)
	{
		size = _size;
	}

	std::string to_string() const
	{
		std::string result;
		ptrNODE ptr = begin;
		while (ptr)
		{
			result += std::to_string(ptr->info) + ' ';
			ptr = ptr->next;
		}
		result += '\n';
		return result;
	};
};
