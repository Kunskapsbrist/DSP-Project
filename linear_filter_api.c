
#include "linear_filter_api.h"
#include <stdlib.h>
#include <string.h>

/*
 * function: filter_init
 */
p_linear_filter filter_init(float* i_a, int i_len_a, float* i_b, int i_len_b)
{
	linear_filter* filter_obj = (linear_filter*)malloc(sizeof(linear_filter));

	filter_obj->len_a = i_len_a;
	filter_obj->a = (float*)malloc(i_len_a*sizeof(float));
	filter_obj->taps_a = (float*)malloc(i_len_a*sizeof(float));

	memset(filter_obj->taps_a, 0, filter_obj->len_a*sizeof(float));
	memcpy(filter_obj->a, i_a, filter_obj->len_a*sizeof(float));

	filter_obj->len_b = i_len_b;
	filter_obj->b = (float*)malloc(i_len_b*sizeof(float));
	filter_obj->taps_b = (float*)malloc(i_len_b*sizeof(float));

	memset(filter_obj->taps_b, 0, filter_obj->len_b*sizeof(float));
	memcpy(filter_obj->b, i_b, filter_obj->len_b*sizeof(float));

	filter_obj->index_a = 0;
	filter_obj->index_b = 0;

	return filter_obj;
}

/*
 * function: filter_filter
 */
float filter_filter(p_linear_filter filter_obj, float* p_x)
{
	float y;
	int j;

	filter_obj->index_b = (filter_obj->index_b + filter_obj->len_b - 1) % filter_obj->len_b;
	filter_obj->taps_b[filter_obj->index_b] = *p_x;
	y = 0;
	for (j = 0; j < (filter_obj->len_b); j++){
		// INSERT HERE YOUR CODE FOR THE ACTUAL FILTERING
		y += filter_obj->b[j]*filter_obj->taps_b[(j+filter_obj->index_b)%filter_obj->len_b];
	}
	filter_obj->index_a = (filter_obj->index_a + filter_obj->len_a - 1) % filter_obj->len_a;
	for (j = 1; j < (filter_obj->len_a); j++){
			// INSERT HERE YOUR CODE FOR THE ACTUAL FILTERING
			y -= filter_obj->a[j]*filter_obj->taps_a[(j+filter_obj->index_a)%filter_obj->len_a];
		}
	filter_obj->taps_a[filter_obj->index_a] = y;
	return y;
}



/*
 * function: filter_release
 */
void filter_release(p_linear_filter filter_obj)
{
	free(filter_obj->a);
	free(filter_obj->taps_a);
	free(filter_obj->b);
	free(filter_obj->taps_b);
	free(filter_obj);
}

