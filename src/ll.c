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
#include "ll.h"

ll_result_t ll_insert(ll_t** ll, void *data) {
  if (ll == NULL) {
    return LL_RESULT_ERROR;
  }

  ll_t* tmp = malloc(sizeof(ll_t));

  if (tmp == NULL) {
    return LL_RESULT_ERROR;
  }

  tmp->data = data;
  tmp->next = *ll;
  *ll = tmp;

  return LL_RESULT_OK;
}

ll_result_t ll_remove(ll_t** ll, void *data) {
  if (ll == NULL) {
    return LL_RESULT_ERROR;
  }

  for (ll_t *curr = *ll, *last = NULL; curr != NULL; last = curr, curr = curr->next) {
    if (curr->data == data) {
      ll_t* next = curr->next;

      free(curr);

      if (last != NULL) {
        last->next = next;
      } else {
        *ll = next;
      }

      return LL_RESULT_OK;
    }
  }

  return LL_RESULT_ERROR;
}

void ll_execute(ll_t* ll, ll_func_t func) {
  for (ll_t* curr = ll; curr != NULL; curr = curr->next) {
    (*func)(curr->data);
  }
}
