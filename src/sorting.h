typedef struct no{
	int n;
	struct no * next;
}node;

typedef struct qnd{
	node * head;
	struct qnd * next;
}q_node;

typedef struct qq_ue{
	q_node * start;
	q_node * end;
}queue;

typedef struct{
	int n;
	int * seq;
}arr;

// --- The old algo --------------------------

arr * init_arr( int seq[] , int n );
void print_arr( arr * A );
void intercal_arrs(  arr * A, arr * B, arr * C );
void merge_sort( arr * A );

// --- The new algo --------------------------

node * init_no( int n );
node * intercal( node * h1 , node * h2 );
void print_lklst( node * h );

q_node * init_qnd( );

void append( queue * L, node * nod );
node * pop( queue * L );
queue * from_arr( arr * A );
void print_queue( queue * L );

void iter_mergesort( arr * A, int demo );
