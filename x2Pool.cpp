//
//  x2Pool.cpp
//  XenonFoundation
//
//  Created by William Harrison on 1/4/14.
//  Copyright (c) 2014 William Harrison Development. All rights reserved.
//

#include "x2Pool.h"
#include <vector>

template <typename obj> x2Pool<obj>::x2Pool(size_t chunk_size) throw (std::invalid_argument, std::bad_alloc) {
    if (chunk_size == 0) throw std::invalid_argument("chunk size for x2Pool::x2Pool(size_t cs) must be > 0");
    m_chunkSize = chunk_size;
    x2_alloc();
}

template <typename obj> void x2Pool<obj>::x2_alloc() {
    for (size_t i = 0; i < m_chunkSize; ++i) {
        m_list.push(std::make_shared<obj>());
    }
}

template <typename obj> std::shared_ptr<obj> x2Pool<obj>::new_obj() {
    if (m_list.empty()) x2_alloc();
    auto o = m_list.front();
    m_list.pop();
    return o;
}

template <typename obj> void x2Pool<obj>::release_obj(std::shared_ptr<obj> o) {
    m_list.push(o);
}

template <typename obj> x2Pool<obj>::x2Pool(const x2Pool& src) {
    throw std::bad_alloc();
}
