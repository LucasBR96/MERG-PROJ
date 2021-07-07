#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#include "sorting.h"

// Your standard mergesort code ---------------------------------------------------
arr * init_arr( int seq[], int n ){

	arr * A = ( arr * ) malloc( sizeof( arr ) );
	A -> n = n;
	A -> seq = seq;
	return A;

}

void print_arr( arr * A ){
	
	printf("\n");
	for( int i = 0; i < A -> n ; i++ )
		if( i == 0 )
			printf( "[ %d,", ( A -> seq )[ i ] );
		else if( i + 1 == A -> n )
			printf(" %d ]", ( A -> seq )[ i ] );
		else
			printf( " %d,", ( A -> seq )[ i ] );
}

void intercal_arrs( arr * A, arr * B, arr * C ){

	int i , j , k , m1 , m2;
	
	j = 0;
	k = 0;
	for( i = 0; i < C -> n; i++ ){
		
		m1 = INT_MAX;
		if( j < A -> n );
			m1 = ( A -> seq )[ j ];

		m2 = INT_MAX;
		if( k < B -> n );
			m1 = ( B -> seq )[ k ];

		if( m1 > m2 ){
			( C -> seq )[ i ] = m2;
			k++;
		}else{	
			( C -> seq )[ i ] = m1;
			j++;
		}
	}
}

void merge_sort( arr * A){

	if( ( A -> n ) <= 1 )
		return;

	int n1 = ( A -> n)/2;
	int * seq1 = ( int * ) malloc( n1*sizeof( int ) );
	for( int i = 0; i < n1 ; i++)
		seq1[ i ] = ( A -> seq )[ i ];
	arr * A1 = init_arr( seq1 , n1 ); 
	merge_sort( A ); // rec here

	int n2 = ( A -> n ) - n1; 
	int * seq2 = ( int * ) malloc( n2*sizeof( int ) );
	for( int i = 0; i < n2; i++ )
		seq2[ i ] = ( A -> seq )[ i + n1 ];
	arr * A2 = init_arr( seq2, n2 ); 
	merge_sort( A2 ); // also here
	
	intercal_arrs( A1, A2, A );
}

// -----------------------------------------------------------------------------------------------------


// Now with the new mergesort --------------------------------------------------------------------------

node * init_no( int n ){
	node * nd = ( node * ) malloc( sizeof( node ) );
	nd -> n = n;
	nd -> next = NULL;

	return nd;
}

node * intercal( node * h1 , node * h2 ){

	// O( 1 ) extra space
	node *h         = NULL;
	node *aux       = NULL;
	node *aux_prime = NULL;
	node ** h_prime;

	while( ( h1 != NULL) && ( h2 != NULL ) ){
		
		h_prime = &h1;
		aux_prime = h1;
		if( ( h1 -> n) > ( h2 -> n ) ){
			h_prime = &h2;
			aux_prime = h2;
		}

		*h_prime = aux_prime -> next;
		aux_prime -> next = NULL;

		if( h == NULL )
			h = aux_prime;
		else
			aux -> next = aux_prime;
		aux = aux_prime;
	}

	h_prime = NULL;
	if( h1 != NULL )
		h_prime = &h1;
	else if( h2 != NULL)
		h_prime = &h2;
	aux -> next = *h_prime;
	*h_prime = NULL;

	return h;
}

void print_lklst( node * h ){
	
	if( h == NULL )
		return;

	printf( "X| " );
	node * q;
	for( q = h; ( q -> next ) != NULL; q = q -> next )
		printf( "%d -> ", q -> n );
	printf( "%d" , q -> n );
}

q_node * init_qnd(){

	 q_node * nd = ( q_node * ) malloc( sizeof( q_node ) );
	 nd->head = NULL;
	 nd->next = NULL;

	 return nd;
}

queue * init_queue( ){

	 queue * L = ( queue * ) malloc( sizeof( queue ) );
	 L -> start = NULL;
	 L -> end   = NULL;

	 return L;
}

void append( queue * L , node * nod ){
	
	q_node * q = init_qnd();
	( q -> head ) = nod;

	if( ( ( L -> start ) == NULL ) && ( ( L -> end ) == NULL ) ){
		L -> start = q;
		L -> end = q;
	}else{

		( L -> end ) -> next = q;
		( L -> end ) = q;
	}
}

node * pop( queue * L ){

	if( ( ( L -> start ) == NULL ) && ( ( L -> end ) == NULL ) )
		return NULL;
	
	q_node * q = L -> start;
	L -> start = ( L -> start ) -> next;
	if( ( L -> start ) == NULL )
		L -> end = NULL;
	
	node * nod = q -> head;
	q -> head = NULL;
	q -> next = NULL;
	free( q );

	return nod;
}

queue * from_arr( arr * A ){
	
	int m;
	node * no;

	queue *L = init_queue();
	for( int i = 0; i < ( A -> n ); i++ ){
		m  = ( A -> seq )[ i ];
		no = init_no( m );
		append( L , no );
	}return L;
}

void print_queue( queue * L ){
	
	printf( "\n" );

	q_node * q = L -> start;
	while( q != NULL ){
		print_lklst( q -> head );
		printf( "\n" );
		q = q -> next;
	}

	for( int i = 0; i < 25; i++ )
		printf( "-" );
}

void iter_mergesort( arr * A, int demo ){
	
	if( ( A -> n ) <= 1 )
		return ;

	node * h1;
	node * h2;
	node * h;

	queue * L = from_arr( A );
	if( demo ){
		print_arr( A );
		print_queue( L );
	}

	while( L -> start != L -> end ){
		h1 = pop( L );
		h2 = pop( L );
		h = intercal( h1 , h2 );
		append( L , h );
		
		if( demo )
			print_queue( L );
	}

	node * aux;
	for( int i = 0; i < ( A -> n ); i++ ){
		( A -> seq )[ i ] = ( h -> n );
		
		aux = h;
		h = h -> next;
		aux -> next = NULL;
		free( aux );
	}

	if( demo )
		print_arr( A );

	return ;
}
