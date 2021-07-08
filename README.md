# Merge sort without recursion

This is a small project of mine made in order to practice a little bit of the **C** programing language and keep deliberatly programming aside from college homework. The idea is to create a version of the mergesort algorithm without the use of recursion.

## Mergesort recap

The mergesort algo is one of the first algos introduced in order to explain the concept of divide and conquer; stable sorting and **O( n * log( n ) )** sorting, as is very intuitive and easy to understand. It is, however, with its problems: it is quite obsolete compared with faster counterparts like radix or bucketsort and relies heavily on recursion.

Here it's **C** code

´´´

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

´´´

In a nutshell, algorithm splits the array in two ( roughly ) equal halves,sorts each recursevely, and then merges both sorted parts back in the original array in **O( n )** time, since this can be repeated, at most, **O( log( n ) )** times, then mergesort have a **O( n * log( n ) )** time complexity.

The following gif illustrates the mergesort beautifully.


