
#include <iostream>
#include <list>
#include <boost/thread.hpp>
#include <windows.h>
#include "curses.h"

const int from = 0;
const int to = 4096;

std::list<boost::thread*> thread_pool;

class Worker
{
public:
	Worker(int interval_from,int interval_to){
		from = interval_from;
		to = interval_to;
		std::cout<<"Worker created:  ["<<from<<" "<<to<<" ]\n";}
	Worker(){/*std::cout<<"Worker constructor called for: "<<this<<"\n";*/}
	~Worker(){/*std::cout<<"Worker destructor called for: "<<this<<"\n";*/}
	void operator()(){
		/*std::cout<<"Worker is working at: "<<this<<"\n";*/
		for(int number = from;number<=to;++number)
		{
			for(int i = 2;i<number;++i)
			{
				if(number % i == 0) break;
			}
			//prime number found
		}
		
	}
	Worker(Worker& work){/*std::cout<<"Copy constructor: "<<this<<" <- "<<&work<<"\n";*/}
private:
	int from;
	int to;
};

int main()
{
	//curses
	initscr();
	curs_set(0);
	int a = LINES;
	WINDOW* win = newwin(0, 0, 0, 0);
	wmove(win,10,10);
	wprintw(win,"Hello");
	wrefresh(win);
	int i = 0;
	while(true)
	{
		wmove(win,0,0);
		wprintw(win,"%d",i);

		wmove(win,0,10);
		wprintw(win,"%d",100-i);

		wrefresh(win);
		Sleep(100);
		++i;
	}
	
	//end

	/*const unsigned int thread_num = boost::thread::hardware_concurrency();
	std::cout<<"Thread number is: "<<thread_num<<"\n";
	
	const int num_per_thread = (to - from + 1) / thread_num;
	const int remainder = (to - from + 1) % thread_num;

	for(unsigned int i = 0;i<thread_num;++i)
	{
		if(i == thread_num  - 1)
		{
			Worker worker(from + i * num_per_thread,from + i * num_per_thread + num_per_thread - 1 + remainder);
			thread_pool.push_back(new boost::thread(worker));
		}
		else
		{
			Worker worker(from + i * num_per_thread,from + i * num_per_thread + num_per_thread - 1);
			thread_pool.push_back(new boost::thread(worker));
		}
	}
	

	//for(unsigned int i = 0;i>thread_num;++i)
	//	thread_pool[i].yield();

	std::list<boost::thread*>::iterator begin = thread_pool.begin();
	std::list<boost::thread*>::iterator end = thread_pool.end();
	for(std::list<boost::thread*>::iterator it = begin;it!=end;++it)
	(*it)->join();

	for(std::list<boost::thread*>::iterator it = begin;it!=end;++it)
	delete (*it);*/
	
	return 0;
}