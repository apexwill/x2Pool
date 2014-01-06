//
//  x2Pool.h
//  XenonFoundation
//
//  Created by William Harrison on 1/4/14.
//  Copyright (c) 2014 William Harrison Development. All rights reserved.
//

#ifndef __XenonFoundation__x2Pool__
#define __XenonFoundation__x2Pool__

#include <iostream>
#include <stdexcept>
#include <memory>
#include <queue>

#define X2_CHUNK_SIZE 1024

template <typename obj> class x2Pool
{
    
public:
    
    x2Pool(size_t chunk_size = X2_CHUNK_SIZE) throw (std::invalid_argument, std::bad_alloc);
    
    std::shared_ptr<obj> new_obj();
    void release_obj(std::shared_ptr<obj> o);
    
protected:
    
    std::queue<std::shared_ptr<obj> > m_list;
    size_t m_chunkSize;
    void x2_alloc();
    
private:
    
    x2Pool(const x2Pool<obj>&);
    x2Pool<obj>& operator = (const x2Pool<obj>&);
};

#endif /* defined(__XenonFoundation__x2Pool__) */
