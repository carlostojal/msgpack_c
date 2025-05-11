//
// Created by carlostojal on 5/10/25.
//

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "types.h"

/**
 * @brief Serialize an integer.
 *
 * @param in Input integer to serialize.
 * @param out Serialization output buffer.
 * @param out_len Length of the serialized data.
 * @return Status code.
 */
int serializer_serialize_int(int in, unsigned char *out, unsigned int *out_len);

/**
 * @brief Serialize a string.
 *
 * @param in Input string.
 * @param in_len Input string length.
 * @param out Serialization output buffer.
 * @param out_len Length of the serialized data.
 * @return Status code.
 */
int serializer_serialize_string(char *in, unsigned int in_len, unsigned char *out, unsigned int *out_len);

/**
 * @brief Serialize a boolean.
 *
 * @param in Input boolean (0 for false, 1 for true).
 * @param out Serialization output buffer.
 * @return Status code.
 */
int serializer_serialize_bool(char in, unsigned char *out);

/**
 * @brief Serialize a float.
 *
 * @param in Input floating-point number.
 * @param out Serialization output buffer.
 * @param out_len Output length.
 * @return Status code.
 */
int serializer_serialize_float(float in, unsigned char *out, unsigned int *out_len);

#endif //SERIALIZER_H
