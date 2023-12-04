#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#include <stdbool.h>
#include <stdint.h>

#define CPU_TYPE             CPU_TYPE_32
#define CPU_BIT_ORDER        LSB_FIRST
#define CPU_BYTE_ORDER       LOW_BYTE_FIRST

#define _Bool unsigned char

typedef  _Bool                  boolean;         //_Bool = unsigned char range (0-1)
typedef  int8_t                 sint8;           //int8_t = signed char 
typedef  uint8_t                uint8;           //uint8_t = unsigned char
typedef  char                   char_t
typedef  int16_t                sint16;          //int16_t = signed short  
typedef  uint16_t               uint16;          //uint16_t = unsigned short
typedef  int32_t                sint32;          //int32_t  = signed long       
typedef  uint32_t               uint32;          //uint32_t = unsigned long  
typedef  int64_t                sint64;          //int64_t  = signed long long    
typedef  uint64_t               uint64;          //uint64_t = unsigned long long
 
typedef  float                  float32;         
typedef  double                 float64;         


typedef volatile int8_t vint8_t;
typedef volatile uint8_t vuint8_t;

typedef volatile int16_t vint16_t;
typedef volatile uint16_t vuint16_t;

typedef volatile int32_t vint32_t;
typedef volatile uint32_t vuint32_t;

typedef volatile int64_t vint64_t;
typedef volatile uint64_t vuint64_t;

#endif