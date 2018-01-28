//Xin Yang
//xy213
#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>  
#include <math.h>
#include <iterator>
using namespace std;

bool greatersix(int num)
{
	return num > 6 ? true : false;
}

void printhalf(int num)
{
	cout << floor(num / 2) << " ";
}

int main()
{

	int initial[] = { 3, 4, 6, 2, 9, 1, 5, 0, 7, 8 };
	deque<int> queue;
	// 1. add to end one by one
	for (int i = 0; i < 10; i++)
	{
		queue.push_back(initial[i]);
	}

	// 2. remove 7
	queue.erase(remove(queue.begin(), queue.end(), 7), queue.end());
	
	// 3. replace 6 with 10
	replace_if(queue.begin(), queue.end(), greatersix, 10);

	// 4. get sum
	int sum = accumulate(queue.begin(), queue.end(), 0);

	cout << "The sum of the numbers 0 to 9 after removing 7 and replacing values greater than 6 with 10 is: " << sum << endl << endl;
	// 4. add to front
	queue.push_front(sum);

	// 5. count greater than 6
	int count6 = count_if(queue.begin(), queue.end(), greatersix);

	cout << "Now the number of elements greater than 6 is: " << count6 << endl << endl;

	// 6. output half
	cout << "The half of every element in the deque is: ";
	for_each(queue.begin(), queue.end(), printhalf);
	cout << endl << endl;


	// 7. sort
	sort(queue.begin(), queue.end());

	// 8. find location 6
	cout << "After sorting, the location of 6 is at index: ";
	deque<int>::iterator findsix;
	int pos = find(queue.begin(), queue.end(), 6) - queue.begin();

	cout << pos << endl << endl;



	// 9. copy and print comma
	cout << "The items in the deque are: ";
	ostream_iterator<int> os(cout, ",");
	copy(queue.begin(), queue.end(), os);
	cout << endl << endl;
	system("pause");
	return 0;
}
