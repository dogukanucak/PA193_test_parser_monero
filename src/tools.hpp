//
//  hash.hpp
//  tree_hash_clear
//
//  Created by Kristián Kozák on 06/11/2017.
//  Copyright © 2017 MUNI. All rights reserved.
//

#ifndef tools_hpp
#define tools_hpp

#include <stdio.h>
#include "config.hpp"
#include <istream>
#include <vector>

namespace tools {
    
    /**
     Serialize varint to a vector (append the bytes)

     @param out_vect push back the bytes to this vect
     @param val value to serialize
     @return 0 if ok, negative otherwise
     */
    int write_varint(std::vector<unsigned char> & out_vect, unsigned long val);
    
    /**
     Read a serialized varint from a stream

     @param in stream to read the varint from
     @param val where to save the varint
     @return 0 if ok, negative otherwise
     */
    int read_varint(std::istream & in, unsigned long & val);
    
    /**
     Skips a serialized varint in the input stream.

     @param in stream to read from
     @return number of bytes skipped if ok, negative val if error
     */
    int skip_varint(std::istream & in);
    
    /**
     Skips a desired amount of bytes in stream and checks whether the stream did not end in the process.

     @param in stream to skip the bytes in
     @param length how many bytes to skip
     @return length if ok, negative val if error
     */
    int skip_bytes(std::istream & in, int length);
    
    /**
     Executes Keccak hash function with parameters extracted from monero.
     
     @param input input to the hash function
     @param input_byte_len length of the input
     @param output where to store the output (32 bytes, needs to be allocated beforehand!)
     */
    void hash(const unsigned char *input, size_t input_byte_len, char unsigned *output);
    
    /**
     Calculate root hash of a Merkle tree with the leaves being hashes of transactions.
     
     @param hash_buffer concatenated hashes of transactions (32 bytes each hash)
     @param buf_len length of the hash buffer (=> must be a multiple of 32)
     @param root_hash where to store the root hash (32 bytes, needs to be allocated beforehand!)
     */
    int tree_hash(const unsigned char *hash_buffer, size_t buf_len, unsigned char *root_hash);
}

#endif /* tools_hpp */
