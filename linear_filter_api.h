#ifndef LINEAR_FILTER_API_H_
#define LINEAR_FILTER_API_H_

/*
 * linear filter structure
 */
typedef struct {
	int len_a;
	float* a;
	float* taps_a;
	int index_a;
	int len_b;
	float* b;
	float* taps_b;
	int index_b;
} linear_filter;

typedef linear_filter* p_linear_filter;

/*
 * filter function
 */
p_linear_filter filter_init(float*, int, float*, int);
float filter_filter(p_linear_filter, float*);
void filter_release(p_linear_filter);

#endif /*LINEAR_FILTER_API_H_*/

