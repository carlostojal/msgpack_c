//
// Created by carlostojal on 5/10/25.
//

#ifndef TYPES_H
#define TYPES_H

#define MSGPACK_MAX_OBJECTS     128
#define MSGPACK_MAX_STRING_LEN  1024
#define MSGPACK_MAX_ARRAY_LEN    1024
#define MSGPACK_MAX_MAP_LEN      1024

#define MSGPACK_MAX_BUFFER_LEN   4096

/**
 * @brief Enumerator of MessagePack object types.
 */
enum msgpack_object_type_e {
    MSGPACK_OBJECT_POSITIVE_FIXINT = 0x00,
    MSGPACK_OBJECT_FIXMAP = 0x80,
    MSGPACK_OBJECT_FIXARRAY = 0x90,
    MSGPACK_OBJECT_FIXSTR = 0xA0,
    MSGPACK_OBJECT_NIL = 0xC0,
    MSGPACK_OBJECT_FALSE = 0xC2,
    MSGPACK_OBJECT_TRUE = 0xC3,
    MSGPACK_OBJECT_BIN = 0xC4,
    MSGPACK_OBJECT_EXT = 0xC5,
    MSGPACK_OBJECT_FLOAT32 = 0xCA,
    MSGPACK_OBJECT_FLOAT64 = 0xCB,
    MSGPACK_OBJECT_UINT8 = 0xCC,
    MSGPACK_OBJECT_UINT16 = 0xCD,
    MSGPACK_OBJECT_UINT32 = 0xCE,
    MSGPACK_OBJECT_UINT64 = 0xCF,
    MSGPACK_OBJECT_INT8 = 0xD0,
    MSGPACK_OBJECT_INT16 = 0xD1,
    MSGPACK_OBJECT_INT32 = 0xD2,
    MSGPACK_OBJECT_INT64 = 0xD3,
    MSGPACK_OBJECT_STR8 = 0xD9,
    MSGPACK_OBJECT_STR16 = 0xDA,
    MSGPACK_OBJECT_STR32 = 0xDB,
    MSGPACK_OBJECT_ARRAY16 = 0xDC,
    MSGPACK_OBJECT_ARRAY32 = 0xDD,
    MSGPACK_OBJECT_MAP16 = 0xDE,
    MSGPACK_OBJECT_MAP32 = 0xDF,
    MSGPACK_OBJECT_NEGATIVE_FIXING = 0xE0
};

/**
 * @brief MessagePack object payload.
 */
union msgpack_object_payload_u {
    int int_;                           ///< Integer object.
    float float_;                       ///< Float object.
    char str_[MSGPACK_MAX_STRING_LEN];  ///< String object.
    unsigned char map_[MSGPACK_MAX_MAP_LEN];  ///< Map object.
    unsigned char array_[MSGPACK_MAX_ARRAY_LEN];  ///< Array object.
};

/**
 * @brief MessagePack object.
 */
struct msgpack_object_s {

    /// Object type
    enum msgpack_object_type_e type;

    /// Object content.
    union msgpack_object_payload_u payload;
};

/**
 * @brief MessagePack instance.
 */
struct msgpack_s {

    /// Array of objects
    struct msgpack_object_s objects[MSGPACK_MAX_OBJECTS];

    /// Number of objects in this instance.
    unsigned int len;

    /// MessagePack encoded buffer.
    unsigned char buffer[MSGPACK_MAX_BUFFER_LEN];

    /// Buffer length.
    unsigned int buffer_len;
};

#endif //TYPES_H
