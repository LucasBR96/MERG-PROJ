# Merge sort without recursion

This is a small project of mine made in order to practice a little bit of the **C** programing language and keep deliberatly programming aside from college homework. The idea is to create a version of the mergesort algorithm without the use of recursion.

## Mergesort recap

The mergesort algo is one of the first algos introduced in order to explain the concept of divide and conquer; stable sorting and **O( n * log( n ) )** sorting, as is very intuitive and easy to understand. It is, however, with its problems: it is quite obsolete compared with faster counterparts like radix or bucketsort and relies heavily on recursion.

Here it's **C** code

	void mergesort( int arr[], int n){

		if( n <= 1 )
			return;

		int n1 = n/2;
		int * arr1 = ( int * ) malloc( n1*sizeof( int ) );
		for( int i = 0; i < n1 ; i++)
			arr1[ i ] = arr[ i ]; 
		merge_sort( arr1, n1 ); // rec here

		int n2 = n - n1; 
		int * arr2 = ( int * ) malloc( n2*sizeof( int ) );
		for( int i = 0; i < n2; i++ )
			arr2[ i ] = arr[ i + n1 ];
		merge_sort( arr2 , n2 ); // also here
		
		intercal_arrs( arr1, n1, arr2, n2, arr, n );
	}

In a nutshell, algorithm splits the array in two ( roughly ) equal halves,sorts each recursevely, and then merges both sorted parts back in the original array in **O( n )** time, since this can be repeated, at most, **O( log( n ) )** times, then mergesort have a **O( n * log( n ) )** time complexity.

The following gif illustrates the mergesort beautifully.


## Non recursive version

This project proposes, out of plain curiosity and deliberate practice, a variation of the mergesort algorithm where no recursion is used. with the help oflinked lists and queues, the iter_mergesort works like this:

1. create a queue of linked lists.
2. for every value of the array, create a linked with a single node on it, and add it to the queue.
3. pop the first two lists of queue.
4. merge them and keep them sorted.
5. append them to the end of the queue.
6. repeat steps 3 to 5 until there is only one list left on the queue.
7. write the values of the remaing list back into the original array.

This is better illustrated by the following pictures.


The time complexity of this algorithm is the same as the recursive version: **O( n * log( n ) )**, Lets call a "period" the events where each linked list is popped from the queue, merged, and then appended at the end. If the queue has **n** distincts lists before a period, then it shall have **n/2** lists. Thus, an array wih **n** elements will go through at most **log( n )** periods. Each period will have O( n ) steps, as the execution time is given by the sum of all merges. Thus, we have O( n * log( n ) ) time.
