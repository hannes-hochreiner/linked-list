/** MIT License
 * 
 * Copyright 2019 Hannes Hochreiner <hannes@hochreiner.net>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __LL_H__
#define __LL_H__

#include <stdlib.h>
#include <stddef.h>

typedef enum ll_result {
  LL_RESULT_OK, /** OK */
  LL_RESULT_ERROR /** ERROR */
} ll_result_t;

/** Linked-list structure
 */
typedef struct ll {
  void *data; /** data pointer */
  struct ll* next; /** pointer to next element; last element points to NULL */
} ll_t;

/** Callback function
 * @param data pointer to the data member of the ll structure
 */
typedef void(*ll_func_t)(void *data);

/** Insert a node at the beginning of the list
 * 
 * @param ll pointer to the linked list (i.e. first node of the linked list)
 * @param data pointer to the data
 * @returns LL_RESULT_OK on success; LL_RESULT_ERROR otherwise
 */
ll_result_t ll_insert(ll_t** ll, void *data);
/** Remove a node from the list
 * 
 * The first node having its data member set to data will be removed from the list.
 * 
 * @param ll pointer to the linked list (i.e. first node of the linked list)
 * @param data pointer to the data
 * @returns LL_RESULT_OK on success; LL_RESULT_ERROR otherwise
 */
ll_result_t ll_remove(ll_t** ll, void *data);
/** Execute callback on all nodes of the list
 * 
 * Convenience function calling the supplied function on all nodes of the list.
 * The data member of the node is passed to the callback function.
 * 
 * @param ll pointer to the linked list (i.e. first node of the linked list)
 * @param func callback function
 */
void ll_execute(ll_t* ll, ll_func_t func);

#endif
