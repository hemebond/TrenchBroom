/*
 Copyright 2020 Kristian Duske

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute,
 sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or
 substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
 NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT
 OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include <iostream>
#include <tuple>

namespace kdl {

namespace detail {
template <typename T, size_t Idx> void print_tuple_element(std::ostream& str, const T& t) {
  str << std::get<Idx>(t) << ", ";
}

template <typename T, size_t... Idx>
void print_tuple(std::ostream& str, const T& t, std::index_sequence<Idx...>) {
  (..., print_tuple_element<T, Idx>(str, t));
}
} // namespace detail

template <typename... T> struct streamable_tuple_wrapper { const std::tuple<T...>& tuple; };

template <typename... T>
streamable_tuple_wrapper<T...> make_streamable(const std::tuple<T...>& tuple) {
  return streamable_tuple_wrapper<T...>{tuple};
}

template <typename... T>
std::ostream& operator<<(std::ostream& lhs, const streamable_tuple_wrapper<T...>& rhs) {
  lhs << "{";
  constexpr auto size = std::tuple_size_v<std::tuple<T...>>;
  if constexpr (size > 0u) {
    kdl::detail::print_tuple(lhs, rhs.tuple, std::make_index_sequence<size - 1u>{});
    lhs << std::get<size - 1u>(rhs.tuple);
  }
  lhs << "}";
  return lhs;
}
} // namespace kdl
