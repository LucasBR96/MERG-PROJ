#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#include "sorting.c"

int is_sorted( arr * A ){
	
	for( int i = 1; i < ( A -> n ); i++ )
		if( ( A -> seq )[ i ] < ( A -> seq[ i - 1 ] ) )
			return 0;
	return 1;
}

void test1(){

	FILE *f = fopen("./src/test_cases.txt", "r");

	int num_cases;
	fscanf( f , "%d", &num_cases );

	int n;
	int * seq;
	arr * A;

	char sep[ 25 ] = "-------------------------";
	for( int i = 0; i < num_cases; i++ ){

		fscanf( f , "%d" , &n );
		seq = ( int * ) malloc( sizeof( int )*n );
		for( int j = 0; j < n; j++ )
			fscanf( f , "%d", &seq[ j ]);

		A = init_arr( seq , n );
		print_arr( A );
		iter_mergesort( A , 0 );
		print_arr( A );
		printf( "\n" );

		if( is_sorted( A ) )
			printf( "Ordenada \n" );
		else
			printf( "Não ordenada \n" );
		printf( "%s \n", sep );

		free( seq );

	}

	fclose( f );
}

void test2(){
	
	FILE *f = fopen("./src/test_cases.txt", "r" );

	int num_cases;
	fscanf( f , "%d", &num_cases );

	int n;
	int * seq;
	arr * A;
	for( int i = 0; i < num_cases; i++ ){

		fscanf( f , "%d" , &n );
		seq = ( int * ) malloc( sizeof( int )*n );
		for( int j = 0; j < n; j++ )
			fscanf( f , "%d", &seq[ j ] );
		A = init_arr( seq , n );
		iter_mergesort( A , 1 );

		free( seq );
	}

	fclose( f );
}

int main(){

	//test1();
	//printf("\n\n");
	test2();
	// long size;
	// char *buf;
	// char *ptr;


	// size = pathconf(".", _PC_PATH_MAX);
	// if ((buf = (char *)malloc((size_t)size)) != NULL)
	// 	 ptr = getcwd(buf, (size_t)size);
	// 
	// printf( "%s\n" , ptr );
	return 0;
}


